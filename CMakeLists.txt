cmake_minimum_required(VERSION 3.10.0)
project(learn-opengl VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glog REQUIRED)


add_executable(learn-opengl main.cpp src/glad/glad.c)
target_include_directories(learn-opengl PRIVATE include/)
target_link_libraries(learn-opengl OpenGL::GL glfw glog::glog)
