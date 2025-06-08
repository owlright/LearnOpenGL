#include <GL/glew.h> // 或者 <GL/gl.h>，根据你的环境
#include <GLFW/glfw3.h>
#include <iostream>

int main(int, char**)
{
    // 初始化GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // 创建一个窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Version", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    // 设置当前上下文
    glfwMakeContextCurrent(window);

    // 初始化GLEW（如果需要）
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    // 打印OpenGL版本
    const GLubyte* version = glGetString(GL_VERSION);
    if (version) {
        std::cout << "OpenGL Version: " << version << "\n";
    } else {
        std::cerr << "Failed to retrieve OpenGL version\n";
    }
    // 主循环
    while (!glfwWindowShouldClose(window)) {
        // 清空屏幕颜色
        glClear(GL_COLOR_BUFFER_BIT);

        // 交换缓冲区并处理事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // 清理并退出
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
