cmake_minimum_required(VERSION 3.21)
project(Exam)

include_directories(/opt/homebrew/Cellar)
link_directories(/opt/homebrew/lib/)
link_directories(/opt/homebrew/Cellar/)
#link_directories(opt/homebrew/include)

find_package(CGAL)
find_package(OpenMP)
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Xpreprocessor -fopenmp -std=c++17 -fexceptions -Wall -Wextra -O2 -stdlib=libc++ -Wno-unused-parameter -Wno-macro-redefined")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.2.2/lib/cmake/")
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.2.2/QtWidgets/")

add_executable(JarvisMarch main.cpp ConvexHullAlgorithms.h CGALComponents.h)

target_link_libraries(JarvisMarch libgmp.a)
target_link_libraries(JarvisMarch libmpfr.a)
target_link_libraries(JarvisMarch CGAL)
target_link_libraries(JarvisMarch libomp.a)
target_link_libraries(JarvisMarch Qt6::Core)
target_link_libraries(JarvisMarch Qt6::Widgets)
target_link_libraries(JarvisMarch Qt6::Quick)
