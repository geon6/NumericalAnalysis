cmake_minimum_required(VERSION 3.10)

find_package(Eigen3 CONFIG REQUIRED)

add_executable(GaussElimination GaussElimination.cpp)
add_executable(ColumnPivot ColumnPivot.cpp)

target_link_libraries(GaussElimination PRIVATE Eigen3::Eigen)
target_link_libraries(ColumnPivot PRIVATE Eigen3::Eigen)