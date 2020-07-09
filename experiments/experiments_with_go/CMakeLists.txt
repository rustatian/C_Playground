project(experimenst_with_go)

#include_directories(${benchmark_INCLUDE_DIRS})
#include_directories(headers)

add_library(awesome SHARED IMPORTED)
set_property(TARGET awesome PROPERTY IMPORTED_LOCATION /home/valery/Projects/repo/C_Playground/src/experiments_with_go/include/awesome.so)
add_executable(go_exp1 src/main.cpp include/main.hpp include/awesome.h)
target_link_libraries(go_exp1 awesome)