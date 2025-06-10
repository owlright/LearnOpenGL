cmake_minimum_required(VERSION 3.10.0)
project(learn-opengl VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glog REQUIRED)

include_directories(include/)

add_library(glad src/glad/glad.c)
add_library(learn_opengl src/common.cpp)
target_link_libraries(learn_opengl PRIVATE glog::glog glfw glad)


link_libraries(OpenGL::GL glfw glog::glog glad learn_opengl)
add_executable(1_1_helloworld src/1_getting_started/1_1_helloworld.cpp )
add_executable(1_2_hello_triangle src/1_getting_started/1_2_hello_triangle.cpp)
