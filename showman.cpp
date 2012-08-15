#include "showman.hpp"
#include "statemap.hpp"
#include "textmap.hpp"

ShowMan::ShowMan(QSharedPointer<StateMap> stateMap, QObject *parent) :
    QObject(parent),
    timer_( new QTimer ),
    stateMap_( stateMap )
{
    connect( timer_.data(), SIGNAL(timeout()), SLOT(onTimerTriggered()) );
}

void ShowMan::onStart() const
{
    timer_->start( stateMap_->interval() * intervalMultiplier );
}

void ShowMan::onTimerTriggered() const
{
    switch( stateMap_->mode() )
    {
    case Mode::ModePlain:
    {
        auto iterator = TextMap::map.begin();
        const int randomStep = qrand() % ( TextMap::size );
        advance( iterator, randomStep);

        Q_ASSERT(iterator != TextMap::map.end());
        emit show( *iterator );
    } break;
    default: //TODO: throw an exception
        emit show ("ERROR");
    };
}
