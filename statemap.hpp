#ifndef STATEMAP_HPP
#define STATEMAP_HPP
#include <QObject>
#include <QSharedPointer>
#include "textmap.hpp"
#include "mode.hpp"

class Widget;

class StateMap : public QObject
{
    Q_OBJECT

//    friend class Widget;
public:

  //  StateMap() = default;
    StateMap();
    virtual ~StateMap();
    int interval() const;
    Mode::Mode mode() const;

protected slots:
    void setInterval( int newValue);
    void setMode ( Mode::Mode newMode);
    void onStartClicked();

signals:
    void intervalChanged( int newValue);
    void modeChanged( Mode::Mode newValue);
    void start();
    void stop();

private:
    int interval_;
    Mode::Mode mode_;
    bool isStarted_;
};

#endif // STATEMAP_HPP
