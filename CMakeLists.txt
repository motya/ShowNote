
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )

## set CMAKE_CXX_FLAGS ( ${CMAKE_CXX_FLAGS} -std=c++0x )
## ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

file(GLOB HEADERS *.hpp)
MESSAGE( STATUS "HEADERS: "  ${HEADERS} )
source_group("Header Files" FILES ${HEADERS})

set ( SOURCES main.cpp showman.cpp statemap.cpp textmap.cpp widget.cpp)

find_package ( Qt 4.7.4 REQUIRED QtCore QtGui )

# <BOOST>

   find_package( Boost REQUIRED)
   set ( BOOST_ROOT CACHE PATH "Path to the boost root directory.")
    include_directories(${Boost_INCLUDE_DIRS})
# </BOOST>

include ( ${QT_USE_FILE} )

  # some .ui files

  SET ( UIS widget.ui )
  ## SET ( HEADERS showman.hpp statemap.hpp widget.h )



  # and finally this will run moc:
  QT4_WRAP_CPP( MOC_SRCS ${HEADERS} )
  # this will run uic on .ui files:
  QT4_WRAP_UI( HEADERS ${UIS} )

  # include ui headers
MESSAGE( STATUS "CMAKE_CURRENT_BUILD_DIR: " ${CMAKE_CURRENT_BUILD_DIR} )
MESSAGE( STATUS "QT_LIBRARIES: "  ${QT_LIBRARIES} )
#MESSAGE( STATUS "PATH: " $ENV{PATH} )

#the place where your .h will be generated
# if you put in a big project several CMakeList
# and for example you have CMakeList in a src/ui
# directory, you will have the .h created by uic
# in build/src/ui
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

add_executable ( ShowNote  ${SOURCES} ${MOC_SRCS} ${UI_HDRS} )
target_link_libraries ( ShowNote ${QT_LIBRARIES} )
