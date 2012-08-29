#include <QApplication>
#include <QScopedPointer>
#include "showman.hpp"
#include "statemap.hpp"
#include "widget.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScopedPointer<Widget> widget ( new Widget );
    QSharedPointer<StateMap> stateMap ( new StateMap );
    QScopedPointer<ShowMan> showMan( new ShowMan(stateMap) );
    widget->connectToStateMap(stateMap);
    widget->connectToTextProvider(showMan.data());
    QObject::connect(stateMap.data(), SIGNAL(start()), showMan.data(), SLOT(onStart()));
    widget->show();

    return a.exec();
}
