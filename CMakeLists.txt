cmake_minimum_required(VERSION 3.5)
project(Stochastic_Lattice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)



find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
add_executable( anyExecutable main.cpp)
target_link_libraries(anyExecutable ${Boost_LIBRARIES} )

