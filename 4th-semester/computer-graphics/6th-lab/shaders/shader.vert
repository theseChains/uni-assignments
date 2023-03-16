#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormals;
layout (location = 2) in vec2 aTexCoords;

out vec3 fragPos;
out vec3 normals;
out vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    fragPos = vec3(model * vec4(aPos, 1.0));
    normals = mat3(transpose(inverse(model))) * aNormals;
    texCoords = aTexCoords;

    gl_Position = projection * view * vec4(fragPos, 1.0);
}
