cmake_minimum_required(VERSION 3.20)

project(data_structure)

set(SRC_FILE main.c)

# 这个命令需要加在add_exectuable命令前，不能放在该命令之后
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# 增加编译选项wall，生成全部警告信息
add_compile_options(-Wall)
# 增加编译选项-g，生成调试信息
add_compile_options(-g)

add_executable(launcher ${SRC_FILE})

add_subdirectory(liner/single_link)
add_subdirectory(sort)
add_subdirectory(common)
add_subdirectory(liner/static_link)
add_subdirectory(liner/bidire_circle_link)
add_subdirectory(stack/se_stack)
add_subdirectory(stack/link_stack)

set(library single_link 
            quick_sort 
            static_link 
            bidire_link 
            se_stack 
            link_stack)


target_link_libraries(launcher ${library})