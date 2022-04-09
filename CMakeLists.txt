cmake_minimum_required(VERSION 3.10)

project ("NumericalAnalysis")

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 CONFIG REQUIRED)

macro(link_eigen)
    set(ALL_SOURCE ${ARGN})
    foreach(SOURCE ${ALL_SOURCE})
        set(TARGET_NAME ${SOURCE})
        string(REPLACE "./" "" TARGET_NAME ${TARGET_NAME})
        string(REPLACE ".cpp" "" TARGET_NAME ${TARGET_NAME})
        add_executable(${TARGET_NAME} ${SOURCE})
        target_link_libraries(${TARGET_NAME} PRIVATE Eigen3::Eigen)
    endforeach(SOURCE ${ALL_SOURCE})
endmacro(link_eigen)

add_subdirectory("linear_equation")
add_subdirectory("eigen_value")
add_subdirectory("nonlinear_equation")
add_subdirectory("interpolation")