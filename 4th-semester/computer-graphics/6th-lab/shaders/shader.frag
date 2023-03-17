#version 330 core
out vec4 FragColor;

in vec3 fragPos;
in vec2 texCoords;

uniform sampler2D texture;

void main()
{
    FragColor = texture2D(texture, texCoords);
}
