cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)
project(OOP)

include_directories(C:/vcpkg/installed/x64-windows/include)
LINK_DIRECTORIES(C:/vcpkg/installed/x64-windows/lib)

find_package(PkgConfig REQUIRED)
message(${PKG_CONFIG_FOUND})
pkg_check_modules(GTKMM_LIB REQUIRED IMPORTED_TARGET gtkmm-4.0)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED)

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
        "${PROJECT_SOURCE_DIR}/Practice_2/source/GUI/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/GUI/*.cpp"
        )

add_executable(Practice_2
        "${PROJECT_SOURCE_DIR}/Practice_2/P2.cpp"
        ${P2}
)

#add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/fmt")
#include_directories("${PROJECT_SOURCE_DIR}/vendor/fmt/include")

target_link_libraries(Practice_1 PUBLIC fmt::fmt)
target_link_libraries(Practice_2 PUBLIC fmt::fmt PkgConfig::GTKMM_LIB)