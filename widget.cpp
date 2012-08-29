#include <QBrush>
#include <vector>
#include <boost/assign/list_of.hpp> // for 'list_of()'
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include "widget.hpp"
#include "ui_widget.h"
using namespace boost::assign;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Widget),
    signalMapper_(new QSignalMapper(this))
   
{
   
    noteColors_ = list_of(Qt::red)(Qt::green)(Qt::blue); // TIP: include <vector> if it fails to use list_of
    ui_->setupUi(this);
    connectInternal();
    modeSelected(Mode::ModePlain);
}

Widget::~Widget()
{
}

void Widget::connectToStateMap( QSharedPointer<QObject> stateMap) const
{
    stateMap->connect(ui_->buttonStart, SIGNAL(clicked()), SLOT(onStartClicked()));
    stateMap->connect(ui_->dial, SIGNAL(valueChanged(int)), SLOT(setInterval(int)));
    stateMap->connect(ui_->spinBox, SIGNAL(valueChanged(int)), SLOT(setInterval(int)));
    stateMap->connect(this, SIGNAL(modeSelected(Mode::Mode)), SLOT(setMode(Mode::Mode)));
}

void Widget::connectInternal() const
{
    // link dial with spinbox
    ui_->spinBox->connect(ui_->dial, SIGNAL(valueChanged(int)), SLOT(setValue(int)));
    ui_->dial->connect(ui_->spinBox, SIGNAL(valueChanged(int)), SLOT(setValue(int)));

    connect(ui_->modeRadioPlain, SIGNAL(clicked()), signalMapper_, SLOT(map()));
    connect(ui_->modeRadioTriple, SIGNAL(clicked()), signalMapper_, SLOT(map()));
    connect(ui_->modeRadioTripleReverse, SIGNAL(clicked()), signalMapper_, SLOT(map()));

    signalMapper_->setMapping(ui_->modeRadioPlain, ui_->modeRadioPlain);
    signalMapper_->setMapping(ui_->modeRadioTriple, ui_->modeRadioTriple);
    signalMapper_->setMapping(ui_->modeRadioTriple, ui_->modeRadioTriple);

    connect (signalMapper_, SIGNAL(mapped(QWidget*)), this, SLOT(radioClicked(QWidget*)));
}

void Widget::radioClicked(QWidget *radioButton)
{
    emit modeSelected(widgetToMode_[radioButton]);
}

void Widget::connectToTextProvider(QObject *emitent)
{
    ui_->lineEdit->connect(emitent, SIGNAL(show(const QString&)), SLOT(setText(QString)));
    connect(emitent, SIGNAL(show(const QString&)), SLOT(onNoteChange(const QString&)));
}
void Widget::onNoteChange(const QString& )
{
    static int i = 0;
    QPalette palette( ui_->lineEdit->palette());

    {
        std::vector<QColor>::iterator colorIterator = noteColors_.begin();     
        std::advance(colorIterator, ++i % noteColors_.size() );
        palette.setBrush( QPalette::Text, QBrush(*colorIterator) );
    }

    ui_->lineEdit->setPalette(palette);
}
