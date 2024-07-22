cmake_minimum_required(VERSION 3.5)

set(MODULE_NAME Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(${MODULE_NAME} )
add_executable(${MODULE_NAME} ./SandboxApp.cpp)

add_compile_definitions(BG_PLATFORM_WINDOWS)

#set(INC_DIRS)
#list(APPEND INC_DIRS
#    ../Bagel/src
#    ../Bagel/src/Bagel
#)
#target_include_directories(${MODULE_NAME}
#    PUBLIC 
#    ${INC_DIRS}
#)

#target_sources(${MODULE_NAME}
#    PUBLIC
#        ./SandboxApp.cpp)

target_link_libraries(${MODULE_NAME} PUBLIC Bagel:Bagel )
