#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <glm/gtc/matrix_transform.hpp>


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

    glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, nullptr);

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

    // projection matrix
    glm::mat4 projection = glm::perspective(glm::radians(60.0f), (float)1920/(float)1080,
            0.1f, 100.0f);
    //glm::mat4 perspective = glm::ortho(-2.0f, 2.0f, 2.0f, -2.0f, -1.0f, 1.0f);

    // model matrix
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::translate(model, glm::vec3(-3.0f, 0.0f, -3.0f));

    // view matrix
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));

    // model view projection matrix
    glm::mat4 mvp = projection * view * model;

    unsigned int u_mvpLoc = glGetUniformLocation(program, "u_mvp");
    glUniformMatrix4fv(u_mvpLoc, 1, GL_FALSE, &mvp[0][0]);

    float vertices[] = {
            //front face
            -0.5f,  0.5f, -0.5f, // 0
            -0.5f, -0.5f, -0.5f, // 1
             0.5f, -0.5f, -0.5f, // 2
             0.5f,  0.5f, -0.5f, // 3

             //back face
            -0.5f,  0.5f, 0.5f, // 4
            -0.5f, -0.5f, 0.5f, // 5
             0.5f, -0.5f, 0.5f, // 6
             0.5f,  0.5f, 0.5f  // 7


    };

    unsigned int indices[] = {
            //front face
            0, 1, 2, // bottom left triangle
            2, 3, 0, // top right triangle

            //right face
            3, 2, 6,
            6, 7, 3,

            //left face
            4, 5, 1,
            1, 0, 4,

            //back face
            7, 6, 5,
            5, 4, 7,

            //top face
            4, 0, 3,
            3, 7, 4,

            //bottom face,
            1, 5, 6,
            6, 2, 1


    };
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 3 * 8 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);



    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        render(window);
    }

    glfwTerminate();
    return 0;
}
