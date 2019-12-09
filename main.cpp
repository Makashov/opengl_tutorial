#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

    const GLint w = 1024, h = 768;

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    GLFWwindow * window;
    window = glfwCreateWindow(w, h, "Title", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glewError));
        return EXIT_FAILURE;
    }

    if (!GLEW_VERSION_3_0) {
        return EXIT_FAILURE;
    }

    const GLubyte * p = glGetString(GL_SHADING_LANGUAGE_VERSION);
    cout << "Graphics driver version: " << p << endl;

    const GLubyte * glsl = glGetString(GL_SHADING_LANGUAGE_VERSION);
    cout << "GLSL version: " << glsl << endl;

    if (GLEW_ARB_vertex_array_object) {
        printf("OK");
    }

    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, w, h);
        glClearColor(0, 0, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}