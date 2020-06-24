#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <sstream>
#include <fstream>


static void initGLFW()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

static GLFWwindow* createWindow(int width, int height, const char* title)
{
    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    return window;
}

struct ShaderSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderSource getSource(const std::string& filePath)
{
    enum ShaderType { NONE = -1, VERTEX = 0, FRAGMENT = 1};
    ShaderType currentType = NONE;

    std::string line;
    std::ifstream stream(filePath);
    std::stringstream source[2];

    while(std::getline(stream, line))
    {
        if (line.find("#Shader") != std::string::npos)
        {
            currentType = line.find("Vertex") != std::string::npos ? VERTEX : FRAGMENT;
            continue;
        }
        if (currentType != NONE)
            source[currentType] << line << "\n";
    }
    return { source[VERTEX].str(), source[FRAGMENT].str() };
}

static unsigned int compileShader(unsigned int type, const char* source)
{
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    int status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        char message[512];
        glGetShaderInfoLog(shader, sizeof(message), nullptr, message);
        std::cout << (type == GL_VERTEX_SHADER ? "[VERTEX SHADER] " : "[FRAGMENT SHADER] ") << message << std::endl;
    }
    return shader;
}

static unsigned int compileShaders(const char* vertexSource, const char* fragmentSource)
{
    unsigned int program = glCreateProgram();
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    int status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        char message[512];
        glGetProgramInfoLog(program, sizeof(message), nullptr, message);
        std::cout << "[SHADER PROGRAM LINKER] " << message << std::endl;
    }

    return program;
}

static void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

static void render(GLFWwindow* window)
{
    //glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

int main()
{
    initGLFW();
    GLFWwindow* window = createWindow(1920, 1080, "Test");
    glewInit();

    ShaderSource ss = getSource("../res/shaders/basic.shader");
    unsigned int program = compileShaders(ss.VertexSource.c_str(), ss.FragmentSource.c_str());
    glUseProgram(program);

    float vertices[6] = {
            -0.5f, -0.5f,
             0.0f,  0.5f,
             0.5f, -0.5f
    };
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        render(window);
    }

    glfwTerminate();
    return 0;
}
