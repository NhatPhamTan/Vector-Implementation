set(source_list ${source_list} "vector.cpp")

add_library(vector-objs OBJECT ${source_list})
target_include_directories(vector-objs PUBLIC "${CMAKE_SOURCE_DIR}/include")
set_target_properties(vector-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)

add_library(vector-shared SHARED $<TARGET_OBJECTS:vector-objs>)
set_target_properties(vector-shared PROPERTIES OUTPUT_NAME "vector")
target_include_directories(vector-shared PUBLIC "${CMAKE_SOURCE_DIR}/include")