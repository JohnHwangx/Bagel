cmake_minimum_required(VERSION 3.22)

set(PROJ_NAME Bagel)
project(${PROJ_NAME} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

find_package(glm REQUIRED)

find_package(glfw3 REQUIRED)

file(GLOB_RECURSE HEAD_FILES "./Bagel/src/*.h")

set(LIB_NAME Bagel)
add_library(${LIB_NAME} STATIC ${HEAD_FILES})
target_sources(${LIB_NAME}
    PUBLIC
        Bagel/src/Bagel/Application.cpp
        Bagel/src/Bagel/Log.cpp
)

target_precompile_headers(${LIB_NAME} PRIVATE "Bagel/src/bgpch.h")

add_compile_definitions(BG_PLATFORM_WINDOWS)
add_compile_definitions(BG_BUILD_DLL)

set(INC_DIRS)
list(APPEND INC_DIRS
    ./Bagel/src
    ./Bagel/src/Bagel
)
target_include_directories(${LIB_NAME}
    PUBLIC 
    ${INC_DIRS}
)

set(LINK_LIBS)
list(APPEND LINK_LIBS 
    spdlog::spdlog
    glm::glm
    glfw
)
target_link_libraries(${LIB_NAME} 
    PUBLIC
        ${LINK_LIBS}
)

add_library(${PROJ_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})
add_subdirectory(Sandbox)
