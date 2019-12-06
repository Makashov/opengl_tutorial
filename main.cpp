#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    const GLint w = 1024, h = 768;
    GLFWwindow * window;
    window = glfwCreateWindow(w, h, "glfw", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    const GLubyte * p = glGetString(GL_VERSION);

    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, w, h);
        glClearColor(0, 1, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
