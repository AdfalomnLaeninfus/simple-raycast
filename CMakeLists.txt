cmake_minimum_required(VERSION 3.6.0)
project(raiox VERSION 0.0.0 LANGUAGES C CXX)

file(GLOB source 
    "main.cpp"
    "src/*.c"
    "src/*.cpp"
)

set(includes 
    "include/"
)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} ${source})
include_directories(${includes})
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 m)