cmake_minimum_required(VERSION 3.22)

set(MODULE_NAME Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${MODULE_NAME} 
    ./SandboxApp.cpp  
    ./Sandbox2D.cpp
    ./ExampleLayer.cpp
)

add_compile_definitions(BG_PLATFORM_WINDOWS)

target_link_libraries(${MODULE_NAME} PUBLIC 
    Bagel::Bagel
    ImGui
)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")  
    # Debug模式，添加DEBUG预处理器定义  
    target_compile_definitions(${MODULE_NAME} PRIVATE BG_DEBUG)
endif()

add_custom_command(
    TARGET ${MODULE_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets
)

add_custom_command(
    TARGET ${MODULE_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

file(GLOB_RECURSE project_cpps *.cpp *c *cc *h)
set(all_files_cpp ${project_cpps})
source_group_by_dir(all_files_cpp ${CMAKE_CURRENT_SOURCE_DIR})