cmake_minimum_required(VERSION 3.21)
project(MouseRotateSceneOpenGL1Qt6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets OpenGLWidgets REQUIRED)

add_executable(MouseRotateScene WIN32
    src/main.cpp
    src/scene.cpp
    src/scene.h
)

target_link_libraries(MouseRotateScene PRIVATE
    Qt6::Widgets
    Qt6::OpenGLWidgets
    opengl32
)

if(MINGW)
    target_link_options(MouseRotateScene PRIVATE
        -static
        $<$<CONFIG:Release>:-s>
    )
endif()
