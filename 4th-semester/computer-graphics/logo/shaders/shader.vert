#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormals;

out vec3 fragPos;
out vec3 normals;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    fragPos = vec3(model * vec4(aPos, 1.0));
    normals = mat3(transpose(inverse(model))) * aNormals;

    gl_Position = projection * view * vec4(fragPos, 1.0);
}
