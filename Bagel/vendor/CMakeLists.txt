cmake_minimum_required(VERSION 3.22)

project(Vendor VERSION 0.0.1)

add_library(Glad STATIC "./glad/src/glad.c")

target_include_directories(Glad
    PUBLIC 
    "./glad/include/"
)

set(IMGUI_FILES)
list(APPEND IMGUI_FILES 
    imgui/imconfig.h
    imgui/imgui.h
    imgui/imgui_internal.h
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h

    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_demo.cpp
)
add_library(ImGui STATIC ${IMGUI_FILES})

target_include_directories(ImGui
    PUBLIC 
    "./imgui/"
)

add_library(stb_image STATIC "./stb/stb_image.h" "./stb_image/stb_image.cpp")
target_include_directories(stb_image
    PUBLIC 
    "./stb/"
    "../src/"
)