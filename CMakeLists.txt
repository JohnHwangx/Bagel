cmake_minimum_required(VERSION 3.5)

set(PROJ_NAME Bagel)
project(${PROJ_NAME} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

find_package(glm REQUIRED)

find_package(glfw3 REQUIRED)

# set(PROJECT_SOURCES
        # main.cpp
# )

# add_executable(${PROJ_NAME} ${PROJECT_SOURCES})
add_library(${PROJ_NAME} SHARED)

target_sources(${PROJ_NAME}
    PUBLIC
        ./Bagel/src/Test.cpp)

set(INC_DIRS)
list(APPEND INC_DIRS
    ./Bagel/src
)
target_include_directories(${PROJ_NAME}
    PUBLIC 
    ${INC_DIRS}
)

set(LINK_LIBS)
list(APPEND LINK_LIBS 
    spdlog::spdlog
    glm::glm
    glfw
)
target_link_libraries(${PROJ_NAME} 
    PUBLIC
        ${LINK_LIBS}
)

add_subdirectory(Sandbox)