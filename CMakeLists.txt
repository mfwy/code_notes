cmake_minimum_required(VERSION 3.3.0)
project(DRAWER)
find_package(Pangolin REQUIRED)

add_compile_options(-std=c++11)

include_directories(include/ ${Pangolin_INCLUDE_DIRS} Json/)

add_library(drawer SHARED lib/Drawer.cpp)
target_link_libraries(drawer ${Pangolin_LIBRARIES})
add_library(CJson SHARED Json/cJSON.c)
add_library(CJO SHARED Json/CJsonObject.cpp)

add_executable(main  src/main.cpp)
target_link_libraries(main drawer ${Pangolin_LIBRARIES} CJO CJson)