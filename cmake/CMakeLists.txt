cmake_minimum_required(VERSION 3.24)
project("example")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(default_build_type "Debug")


# set source and test directory
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(test_dir "${CMAKE_CURRENT_SOURCE_DIR}/test")

# include directories
include_directories(
    "include"
    "vendor/another_math/include"
)
# vendor library directories
link_directories(
    "vendor/another_math/build/lib"
)

# vendor: list of vendor packages to be linked with library and target
set(vendor
    "adder"
    "multiplier"
)

# library_list: placeholder for all building libraries
set(library_list)  

# set output dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# generate library build - add to library_list
file(GLOB target_dir_list "${source_dir}/*")
foreach(target_dir ${target_dir_list})
    get_filename_component(target ${target_dir} NAME_WE)
    message("generating library ... " ${target})

    file(GLOB_RECURSE target_src "${target_dir}/*.cpp")
    add_library(${target} SHARED ${target_src})
    target_link_libraries(${target} ${vendor})

    list(APPEND library_list ${target})
    message("generating library ... " ${target} " done")
endforeach()

# generate test build 
file(GLOB target_dir_list "${test_dir}/*")
foreach(target_dir ${target_dir_list})
    get_filename_component(target ${target_dir} NAME_WE)
    message("generating test ... " ${target})

    file(GLOB_RECURSE target_src "${target_dir}/*.cpp")
    add_executable(${target} ${target_src})
    target_link_libraries(${target} ${library_list} ${vendor})

    message("generating test ... " ${target} " done")
endforeach()
