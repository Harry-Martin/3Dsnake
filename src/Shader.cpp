#include "Shader.h"

#include <GL/glew.h>
#include <sstream>
#include <fstream>
#include <iostream>

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

Shader::Shader(const std::string& filePath)
{
    ShaderSource ss = getSource(filePath);
    m_Program = compileShaders(ss.VertexSource.c_str(), ss.FragmentSource.c_str());
}

void Shader::use() const
{
    glUseProgram(m_Program);
}

void Shader::setUniformMat4f(const std::string& uniformName, glm::mat4& uniformData)
{
    unsigned int uniformLocation = glGetUniformLocation(m_Program, uniformName.c_str());
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &uniformData[0][0]);
}
