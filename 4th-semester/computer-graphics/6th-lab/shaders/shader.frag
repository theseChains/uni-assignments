#version 330 core
out vec4 FragColor;

in vec3 fragPos;
in vec2 texCoords;

uniform sampler2D texture;
uniform bool showOnlyRedAndGreen;

void main()
{
    if (showOnlyRedAndGreen)
    {
        vec4 textureColor = texture2D(texture, texCoords);
        FragColor = vec4(textureColor.r, textureColor.g, 0.0, 1.0);
    }
    else
    {
        FragColor = texture2D(texture, texCoords);
    }
}
