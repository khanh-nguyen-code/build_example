cmake_minimum_required(VERSION 3.24)
project("example")

set(CMAKE_CXX_STANDARD 17)

include_directories(
    "include"
    "/opt/homebrew/include"
)

set(vendor

)
set(library_list) 

# generate libraries
file(GLOB library_dir_list "src/*")
foreach(library_dir ${library_dir_list})
    get_filename_component(library ${library_dir} NAME_WE)
    message("generating library ... " ${library})

    file(GLOB_RECURSE library_src ${library_dir}/*.cpp)
    add_library(${library} SHARED ${library_src})
    target_link_libraries(${library} ${vendor})

    list(APPEND library_list ${library})
    message("generating library ... " ${library} " done")
endforeach()



file(GLOB target_src_src_list "*.cpp")

foreach(target_src ${target_src_src_list})
    get_filename_component(target_out ${target_src} NAME_WE)
    message("generating target ... " ${target_out})

    add_executable(${target_out} ${target_src})
    target_link_libraries(${target_out} ${library_list} ${vendor})

    message("generating target ... " ${target_out} " done")
endforeach()


