cmake_minimum_required(VERSION 3.3.0)
project(DRAWER)

set(Boost_USE_STATIC_LIBS ON)

find_package(Pangolin REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)
add_compile_options(-std=c++11)

include_directories(include/ Json/ config/ ${Pangolin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
# message(status ${Boost_LIBRARY_DIRS})

add_library(drawer SHARED lib/Drawer.cpp)
target_link_libraries(drawer ${Pangolin_LIBRARIES})
add_library(CJson SHARED Json/cJSON.c)
add_library(CJO SHARED Json/CJsonObject.cpp)

add_executable(main  src/main.cpp)
target_link_libraries(main drawer CJO CJson ${Pangolin_LIBRARIES} ${OpenCV_LIBS} ${Boost_LIBRARIES} -lboost_serialization)