#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDial>
#include <QSignalMapper>
#include <map>
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

signals:
    void startClicked();
    void modeSelected( Mode::Mode );

public slots:
    void radioClicked(QWidget *);
    void onNoteChange(const QString& );

private:
    QSharedPointer<Ui::Widget> ui_;
    QSignalMapper *signalMapper_;
    std::map<QWidget*, Mode::Mode> widgetToMode_;
    std::list<QColor> noteColors_;
};

#endif // WIDGET_H
