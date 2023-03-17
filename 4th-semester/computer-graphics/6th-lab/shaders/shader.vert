#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec3 fragPos;
out vec2 texCoords;

void main()
{
    texCoords = aTexCoords;
    gl_Position = vec4(aPos, 0.0, 1.0);
}
