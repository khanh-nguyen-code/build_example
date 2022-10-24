cmake_minimum_required(VERSION 3.24)
project("loader")

set(CMAKE_CXX_STANDARD 17)

include_directories("include")

file(GLOB_RECURSE OBJECT_SRC "src/*.cpp")
add_library("Loader" SHARED ${OBJECT_SRC})
target_link_libraries("Loader" "m")

add_executable("main" "main.cpp")
target_link_libraries("main" "Loader")
