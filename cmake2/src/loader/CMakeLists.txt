file(GLOB_RECURSE target_src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(${target} SHARED ${target_src})
target_include_directories(${target} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_directories(${target} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} 
)
target_link_libraries(${target} PRIVATE
)