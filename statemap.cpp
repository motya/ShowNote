#include "statemap.hpp"

StateMap::StateMap() :
    isStarted_(false)
{
}
StateMap::~StateMap()
{
}

int StateMap::interval() const
{
    return interval_;
}
Mode::Mode StateMap::mode() const
{
    return mode_;
}

void StateMap::setInterval( int newValue)
{
    interval_ = newValue;
    emit intervalChanged(interval_);
}

void StateMap::setMode ( Mode::Mode newMode)
{
    mode_ = newMode;
    emit modeChanged(mode_);
}

void StateMap::onStartClicked()
{
    isStarted_ = !isStarted_;
    emit (this->*(isStarted_ ? &StateMap::start : &StateMap::stop))();
}

