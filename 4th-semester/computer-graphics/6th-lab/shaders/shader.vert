#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec3 fragPos;
out vec2 texCoords;

uniform bool flip;

void main()
{
    if (flip)
    {
        texCoords = vec2(1 - aTexCoords.x, 1 - aTexCoords.y);
    }
    else
    {
        texCoords = aTexCoords;
    }
    gl_Position = vec4(aPos, 0.0, 1.0);
}
