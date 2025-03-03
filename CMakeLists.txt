cmake_minimum_required(VERSION 3.20)

project(data_structure)

set(SRC_FILE main.c)

add_executable(launcher ${SRC_FILE})

add_subdirectory(liner/single_link)
add_subdirectory(sort)
add_subdirectory(common)

target_link_libraries(launcher single_link)
target_link_libraries(launcher quick_sort)