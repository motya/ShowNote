
#include <QApplication>
#include "widget.h"
#include "showman.hpp"
#include "statemap.hpp"
#include <list>
template<class Lhs, class Rhs>
  auto adding_func(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs+rhs) {return lhs + rhs;}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedPointer<Widget> widget ( new Widget );
    QSharedPointer<StateMap> stateMap ( new StateMap );
    QSharedPointer<ShowMan> showMan( new ShowMan(stateMap) );
    widget->connectToStateMap(stateMap);
    widget->connectToTextProvider(showMan.data());
    QObject::connect(stateMap.data(), SIGNAL(start()), showMan.data(), SLOT(onStart()));
    widget->show();
    std::list<int> x ( { 10, 20, 1, 4, 8, 16, 9 } );

    return a.exec();
}
