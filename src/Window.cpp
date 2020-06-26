#include "Window.h"
#include <iostream>
#include <GL/glew.h>

Window::Window(int width, int height, const std::string& title)
{
    // Set up GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window creation
    m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (m_Window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(m_Window);

    // Initialise GLEW AFTER OpenGL context is created
    glewInit();
}

Window::~Window()
{
    glfwTerminate();
}

int Window::shouldClose()
{
    return glfwWindowShouldClose(m_Window);
}

void Window::processInput()
{
    glfwPollEvents();
    if(glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_Window, true);
}

void Window::render()
{
    //glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, nullptr);
    glDrawArrays(GL_TRIANGLES, 0, 6*6);

    glfwSwapBuffers(m_Window);
}
