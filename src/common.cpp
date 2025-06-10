#include "common.h"
#include <stdexcept>
namespace learnopengl {

void GlogInit(const char* argv0)
{
    google::InitGoogleLogging(argv0);
    FLAGS_logtostderr = true; // Log to stderr
    FLAGS_colorlogtostderr = true; // Log to stderr with color
    FLAGS_stderrthreshold = google::GLOG_INFO; // Set the minimum log level to INFO
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// Initialize the GLFW library
void GlfwInit()
{

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    // Set the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

// glfw window creation
// --------------------
GLFWwindow* GlfwCreateWindow(int width, int height)
{

    GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    CHECK_NOTNULL(window);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}


}
