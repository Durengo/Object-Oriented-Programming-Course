cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
project(OOP)

file(GLOB_RECURSE P1
        "${PROJECT_SOURCE_DIR}/Practice_1/source/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_1/source/*.cpp"
        )

add_executable(Practice_1
        "${PROJECT_SOURCE_DIR}/Practice_1/main.cpp"
        ${P1}
        )

add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/fmt")
include_directories("${PROJECT_SOURCE_DIR}/vendor/fmt/include")

target_link_libraries(Practice_1 PUBLIC fmt::fmt)