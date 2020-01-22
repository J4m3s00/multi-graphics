#include <iostream>

#include <GLFW/glfw3.h>
#ifdef __WIN32 || __WIN64
#include <gl/GL.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#endif

#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl2.h>


int main() {
    GLFWwindow* window;
    if (!glfwInit()) {
        printf("Could not init glfw!");
    }

    window = glfwCreateWindow(1270, 720, "Multi", NULL, NULL);

    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void) io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        //IMGUI RENDERING
        ///////////////////
        ImGui::Begin("Hello ImGui");
        ImGui::Text("It is working!");
        ImGui::End();

        ///////////////////
        ImGui::Render();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);

    return 0;
}