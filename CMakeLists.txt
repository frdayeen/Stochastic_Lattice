cmake_minimum_required(VERSION 3.5)
project(Stochastic_Lattice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")


find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_executable( mm main.cpp)
target_link_libraries(mm ${Boost_LIBRARIES} )



