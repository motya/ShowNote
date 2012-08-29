#ifndef TEXTMAP_HPP
#define TEXTMAP_HPP
#include <list>
#include <QString>
#include <boost/assign/list_of.hpp> // for 'list_of()'
#include <boost/assign.hpp>

using namespace std;
using namespace boost::assign; // bring 'list_of()' into scope

namespace TextMap
{
   static const std::vector<QString> map =
    list_of("Ab")("A")("A#")("Bb");
	//static const QStringList ( std::initiali
    static const int& size = map.size(); // TODO: use constexpr func

} //namespace TextMap

#endif // TEXTMAP_HPP
