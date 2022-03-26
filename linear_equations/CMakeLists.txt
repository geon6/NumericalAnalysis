cmake_minimum_required(VERSION 3.10)

find_package(Eigen3 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(GaussElimination GaussElimination.cpp)
add_executable(ColumnPivot ColumnPivot.cpp)
add_executable(LU_Decomposition LU_Decomposition.cpp)

target_link_libraries(GaussElimination PRIVATE Eigen3::Eigen)
target_link_libraries(ColumnPivot PRIVATE Eigen3::Eigen)
target_link_libraries(LU_Decomposition PRIVATE Eigen3::Eigen)