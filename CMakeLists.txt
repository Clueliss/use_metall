cmake_minimum_required(VERSION 3.18)
project(use_metall)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

# fmt
find_package(fmt REQUIRED)

# boost
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)

# metall is not available from conan
FetchContent_Declare(
        metall
        GIT_REPOSITORY https://github.com/dice-group/metall.git
        GIT_TAG master
)

FetchContent_MakeAvailable(metall)

add_executable(write_data src/write_data.cpp)
add_executable(read_data src/read_data.cpp)

target_link_libraries(write_data
        Boost::Boost
        Metall
        Threads::Threads
        fmt::fmt)

target_link_libraries(read_data
        Boost::Boost
        Metall
        Threads::Threads
        fmt::fmt)
