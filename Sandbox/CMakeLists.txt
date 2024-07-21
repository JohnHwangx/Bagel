cmake_minimum_required(VERSION 3.5)

set(MODULE_NAME Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${MODULE_NAME} )

target_sources(${MODULE_NAME}
    PUBLIC
        ./Application.cpp)

target_link_libraries(${MODULE_NAME} Bagel )