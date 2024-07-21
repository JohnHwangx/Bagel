cmake_minimum_required(VERSION 3.5)

project(Bagel VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

find_package(glm REQUIRED)

find_package(glfw3  REQUIRED)

set(PROJECT_SOURCES
        main.cpp
)

add_executable(Bagel ${PROJECT_SOURCES})

target_link_libraries(Bagel 
    PUBLIC 
        spdlog::spdlog
        glm::glm
        glfw
)