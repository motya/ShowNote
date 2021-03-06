#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDial>
#include <QSignalMapper>
#include <QMap>
#include <stack>
#include "mode.hpp"
//class StateMap;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void setText (const QString& text);
    //const QSharedPointer<Ui::Widget> ui() const;
    void connectToStateMap(QSharedPointer<QObject> stateMap) const;
    void connectToTextProvider(QObject *emitent);
    void connectInternal() const;



private:
    QSharedPointer<Ui::Widget> ui_;
    QSignalMapper *signalMapper_;
    QMap<QWidget*, Mode::Mode> widgetToMode_;
    std::vector<QColor> noteColors_;
    
public slots:
    void radioClicked(QWidget *);
    void onNoteChange(const QString& );
    
signals:
    void startClicked();
    void modeSelected( Mode::Mode );

};

#endif // WIDGET_H
