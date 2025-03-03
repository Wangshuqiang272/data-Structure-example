add_library(quick_sort quick_sort.c)

target_include_directories(quick_sort PUBLIC ${CMAKE_SOURCE_DIR}/common)

target_link_libraries(quick_sort common)
