#include "showman.hpp"
#include "statemap.hpp"
#include "textmap.hpp"

ShowMan::ShowMan(QSharedPointer<StateMap> stateMap, QObject *parent) :
    QObject(parent),
    stateMap_( stateMap ),
    timer_( new QTimer )
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
        vector<QString>::const_iterator iter = TextMap::map.begin();
        
        const int randomStep = qrand() % ( TextMap::size );
        advance( iter, randomStep);

        Q_ASSERT(iter != TextMap::map.end());
        emit show( *iter );
    } break;
    default: //TODO: throw an exception
        emit show ("ERROR");
    };
}
