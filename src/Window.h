#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
    GLFWwindow* m_Window;

public:
    Window(int width, int height, const std::string& title);
    ~Window();

    int shouldClose();
    void processInput();
    void render();
};



