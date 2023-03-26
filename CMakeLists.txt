cmake_minimum_required(VERSION 3.24)
project(act5)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5Widgets REQUIRED)
add_executable(act5 main.cpp canvas.h canvas.cpp window.h window.cpp graph.h graph.cpp)
target_link_libraries(act5 Qt5::Widgets)
