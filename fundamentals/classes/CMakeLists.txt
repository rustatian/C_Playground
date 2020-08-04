project(jcn)
find_package(Boost)

if (Boost_FOUND)
    find_package(Boost COMPONENTS thread system REQUIRED)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

add_executable(${PROJECT_NAME} JustClassName.cpp)
target_link_libraries(${PROJECT_NAME} Boost::thread SDL2::SDL2main SDL2::SDL2-static)