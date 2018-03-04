cmake_minimum_required(VERSION 3.9)
project(Lista2)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.64.0 COMPONENTS iostreams system filesystem)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(Lista2 main.cpp)
target_link_libraries(Lista2 ${Boost_LIBRARIES})