#pragma once

#include <string>
#include <glm/matrix.hpp>


class Shader {
    unsigned int m_Program;
public:
    explicit Shader(const std::string& filePath);

    void use() const;
    void setUniformMat4f(const std::string& uniformName, glm::mat4& uniformData);


};



