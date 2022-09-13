cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
project(OOP)

file(GLOB_RECURSE P1
        "${PROJECT_SOURCE_DIR}/Practice_1/source/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_1/source/*.cpp"
        )



add_executable(Practice_1
        "${PROJECT_SOURCE_DIR}/Practice_1/P1.cpp"
        ${P1}
        )

file(GLOB_RECURSE P2
        "${PROJECT_SOURCE_DIR}/Practice_2/source/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/*.cpp"
        )

add_executable(Practice_2
        "${PROJECT_SOURCE_DIR}/Practice_2/P2.cpp"
        ${P2}
)

add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/fmt")
include_directories("${PROJECT_SOURCE_DIR}/vendor/fmt/include")

target_link_libraries(Practice_1 PUBLIC fmt::fmt)
target_link_libraries(Practice_2 PUBLIC fmt::fmt)