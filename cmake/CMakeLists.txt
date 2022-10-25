cmake_minimum_required(VERSION 3.24)
project("example")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

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

# generate library build 
file(GLOB library_dir_list "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
foreach(library_dir ${library_dir_list})
    get_filename_component(library ${library_dir} NAME_WE)
    message("generating library ... " ${library})

    file(GLOB_RECURSE library_src "${library_dir}/*.cpp")
    add_library(${library} SHARED ${library_src})
    target_link_libraries(${library} ${vendor})

    list(APPEND library_list ${library})
    message("generating library ... " ${library} " done")
endforeach()



# generate target build
file(GLOB target_dir_list "${CMAKE_CURRENT_SOURCE_DIR}/test/*")
foreach(target_dir ${target_dir_list})
    get_filename_component(target ${target_dir} NAME_WE)
    message("generating target ... " ${target})

    file(GLOB_RECURSE target_src "${target_dir}/*.cpp")
    add_executable(${target} ${target_src})
    target_link_libraries(${target} ${library_list} ${vendor})

    message("generating target ... " ${target} " done")
endforeach()


