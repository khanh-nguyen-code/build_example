file(GLOB_RECURSE target_src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(${target} ${target_src})
target_include_directories(${target} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

foreach(library ${library_list})
    target_include_directories(${target} PRIVATE
        "${source_dir}/${library}"
    )
endforeach()

target_link_directories(${target} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(${target} PRIVATE
)