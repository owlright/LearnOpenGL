cmake_minimum_required(VERSION 3.10.0)
project(learn-opengl VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW3 REQUIRED)

add_executable(learn-opengl main.cpp)
target_link_libraries(learn-opengl OpenGL::GL glfw glew)
