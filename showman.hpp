#ifndef SHOWMAN_HPP
#define SHOWMAN_HPP

#include <QObject>
#include <QSharedPointer>
#include <QTimer>
#include "statemap.hpp"

class ShowMan : public QObject
{
    Q_OBJECT
public:
    //ShowMan() = delete;
    ShowMan();
    explicit ShowMan(QSharedPointer<StateMap> stateMap, QObject *parent = 0);
    static const int intervalMultiplier = 10;

signals:

public slots:
    void onStart() const;
    void onTimerTriggered() const;

signals:
    void show(const QString& text) const;

protected:
    QSharedPointer<StateMap> stateMap_;
    QSharedPointer<QTimer> timer_;

};

#endif // SHOWMAN_HPP
