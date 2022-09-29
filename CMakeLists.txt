cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)
project(OOP)

include_directories(C:/vcpkg/installed/x64-windows/include)
LINK_DIRECTORIES(C:/vcpkg/installed/x64-windows/lib)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(FLTK CONFIG REQUIRED)

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
        "${PROJECT_SOURCE_DIR}/Practice_2/source/Core/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/Core/*.cpp"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/Input/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/Input/*.cpp"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/Person/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/Person/*.cpp"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/GUI/FLTK/*.h"
        "${PROJECT_SOURCE_DIR}/Practice_2/source/GUI/FLTK/*.cpp"
        )

add_executable(Practice_2
        "${PROJECT_SOURCE_DIR}/Practice_2/P2.cpp"
        ${P2}
)

target_include_directories(Practice_2 PUBLIC "${PROJECT_SOURCE_DIR}/Practice_2/source")

target_link_libraries(Practice_1 PUBLIC fmt::fmt)

target_precompile_headers(Practice_2 PUBLIC "${PROJECT_SOURCE_DIR}/Practice_2/source/PCH.h")

# # LOCAL BINARIES
# # FMT
# add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/fmt")
# target_include_directories(Practice_2 PUBLIC "${PROJECT_SOURCE_DIR}/vendor/fmt/include")
# # SPDLOG
# add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/spdlog")
# target_include_directories(Practice_2 PUBLIC "${PROJECT_SOURCE_DIR}/vendor/spdlog/include")
# # FLTK
# add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/fltk")
# target_include_directories(Practice_2 PUBLIC "${PROJECT_SOURCE_DIR}/vendor/fmt/include")
# # LOCAL BINARIES

target_link_libraries(Practice_2 PUBLIC 
fmt::fmt 
spdlog::spdlog
fltk
fltk_gl
fltk_forms
fltk_images
)