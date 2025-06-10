#pragma once
// clang-format off
#include <glad/glad.h> // NOTICE: glad must come before glfw
#include <GLFW/glfw3.h>
#include <glog/logging.h>
// clang-format on

namespace learnopengl {
void GlogInit(const char* argv0);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void GlfwInit();
GLFWwindow* GlfwCreateWindow(int width, int height);

}