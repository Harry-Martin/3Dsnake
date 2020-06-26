cmake_minimum_required(VERSION 3.16)
project(3dsnake)

set(CMAKE_CXX_STANDARD 17)

add_executable(3dsnake src/main.cpp src/Window.cpp src/Window.h src/Shader.cpp src/Shader.h)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(3dsnake glfw GLEW OpenGL::GL)