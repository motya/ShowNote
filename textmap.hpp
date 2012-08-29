#ifndef TEXTMAP_HPP
#define TEXTMAP_HPP
#include <list>
#include <QString>

namespace TextMap
{
   static const std::list<QString> map =
   { "Ab", "A", "A#", "Bb" };
	//static const QStringList ( std::initiali
    static const int& size = map.size(); // TODO: use constexpr func

} //namespace TextMap

#endif // TEXTMAP_HPP
