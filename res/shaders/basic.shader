#Shader Vertex
#version 330 core

layout(location = 0) in vec4 position;

out vec4 colour;

void main()
{
    gl_Position = position;
    colour = vec4(0.0f, 0.0f, 1.0f, 1.0f);
}


#Shader Fragment
#version 330 core
out vec4 final_colour;

in vec4 colour;

void main()
{
    final_colour = colour;
}