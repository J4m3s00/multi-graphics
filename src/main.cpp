#include <iostream>

#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>


int main() {
    GLFWwindow* window;
    if (!glfwInit()) {
        printf("Could not init glfw!");
    }

    window = glfwCreateWindow(1270, 720, "Multi", NULL, NULL);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    return 0;
}