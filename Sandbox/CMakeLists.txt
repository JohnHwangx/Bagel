cmake_minimum_required(VERSION 3.22)

set(MODULE_NAME Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${MODULE_NAME} ./SandboxApp.cpp)

add_compile_definitions(BG_PLATFORM_WINDOWS)

target_link_libraries(${MODULE_NAME} PUBLIC 
    Bagel::Bagel
)
