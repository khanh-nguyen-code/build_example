cmake_minimum_required(VERSION 3.24)
project("example")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# set source and test directory
set(source_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(test_dir "${CMAKE_CURRENT_SOURCE_DIR}/test")

# library_list: placeholder for all building libraries
set(library_list)  

# set output dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# generate library build - add to library_list
file(GLOB target_dir_list "${source_dir}/*")
foreach(target_dir ${target_dir_list} ${test_dir_list})
    get_filename_component(target ${target_dir} NAME_WE)
    message("generating library ... " ${target})

    add_subdirectory(${target_dir})

    list(APPEND library_list ${target})
    message("generating library ... " ${target} " done")
endforeach()

# generate test build 
file(GLOB target_dir_list "${test_dir}/*")
foreach(target_dir ${target_dir_list} ${test_dir_list})
    get_filename_component(target ${target_dir} NAME_WE)
    message("generating test ... " ${target})

    add_subdirectory(${target_dir})

    message("generating test ... " ${target} " done")
endforeach()
