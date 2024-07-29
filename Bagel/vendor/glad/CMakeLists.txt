cmake_minimum_required(VERSION 3.22)

project(Glad VERSION 0.0.1)

add_library(Glad STATIC "./src/glad.c")

target_include_directories(Glad
    PUBLIC 
    "./include/"
)

# set_target_properties(Glad PROPERTIES  
#     LINKER_LANGUAGE C  
# )  
