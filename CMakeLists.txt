cmake_minimum_required(VERSION 3.22)

set(PROJ_NAME Bagel)
project(${PROJ_NAME} VERSION 0.0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

find_package(glm REQUIRED)

find_package(glfw3 REQUIRED)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE HEAD_FILES "./Bagel/src/*.h")

set(LIB_NAME Bagel)
add_library(${LIB_NAME} STATIC ${HEAD_FILES})
target_sources(${LIB_NAME}
    PUBLIC
        Bagel/src/Bagel/Core/Log.cpp
        Bagel/src/Bagel/Core/Layer.cpp
        Bagel/src/Bagel/Core/LayerStack.cpp
        Bagel/src/Bagel/Core/Application.cpp
        Bagel/src/Bagel/ImGui/ImGuiLayer.cpp
        Bagel/src/Bagel/ImGui/ImGuiBuild.cpp
        Bagel/src/Bagel/Renderer/Shader.cpp
        Bagel/src/Bagel/Renderer/Buffer.cpp
        Bagel/src/Bagel/Renderer/Texture.cpp
        Bagel/src/Bagel/Renderer/Renderer.cpp
        Bagel/src/Bagel/Renderer/Renderer2D.cpp
        Bagel/src/Bagel/Renderer/VertexArray.cpp
        Bagel/src/Bagel/Renderer/RendererAPI.cpp
        Bagel/src/Bagel/Renderer/RenderCommand.cpp
        Bagel/src/Bagel/Renderer/GraphicsContext.cpp
        Bagel/src/Bagel/Renderer/OrthographicCamera.cpp
        Bagel/src/Bagel/Renderer/OrthographicCameraController.cpp
        Bagel/src/Platform/OpenGL/OpenGLBuffer.cpp
        Bagel/src/Platform/OpenGL/OpenGLShader.cpp
        Bagel/src/Platform/OpenGL/OpenGLTexture.cpp
        Bagel/src/Platform/OpenGL/OpenGLContext.cpp
        Bagel/src/Platform/OpenGL/OpenGLVertexArray.cpp
        Bagel/src/Platform/OpenGL/OpenGLRendererAPI.cpp
        Bagel/src/Platform/Windows/WindowsWindow.cpp
        Bagel/src/Platform/Windows/WindowsInput.cpp
)

target_precompile_headers(${LIB_NAME} PRIVATE "Bagel/src/bgpch.h")

add_compile_definitions(BG_PLATFORM_WINDOWS)
add_compile_definitions(BG_BUILD_DLL GLFW_INCLUDE_NONE)

set(INC_DIRS)
list(APPEND INC_DIRS
    ./Bagel/src
    ./Bagel/src/Bagel
)
target_include_directories(${LIB_NAME}
    PUBLIC 
    ${INC_DIRS}
)

add_subdirectory(Bagel/vendor)

set(LINK_LIBS)
list(APPEND LINK_LIBS 
    spdlog::spdlog
    glm::glm
    glfw
    OpenGL::GL
    Glad
    ImGui
    stb_image
)
target_link_libraries(${LIB_NAME} 
    PUBLIC
        ${LINK_LIBS}
)

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR})

macro(source_group_by_dir source_files sgbd_cur_dir)
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
			#message(STATUS "INCLUDE_DIR_LIST = ${sgbd_group_name}")
            if(sgbd_nogroup)
                set(sgbd_group_name "\\")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
endmacro(source_group_by_dir)
file(GLOB_RECURSE project_cpps *.cpp *c *cc *h)
set(all_files_cpp ${project_cpps})
source_group_by_dir(all_files_cpp ${CMAKE_CURRENT_SOURCE_DIR})

message("${CMAKE_BUILD_TYPE}")
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")  
    # Debug模式，添加DEBUG预处理器定义  
    target_compile_definitions(${LIB_NAME} PRIVATE BG_DEBUG)
endif()

add_library(${PROJ_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})
add_subdirectory(Sandbox)
