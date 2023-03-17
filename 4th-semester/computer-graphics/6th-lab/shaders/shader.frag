#version 330 core
out vec4 FragColor;

in vec3 fragPos;
in vec2 texCoords;

uniform sampler2D texture;
uniform bool showOnlyRedAndGreen;
uniform bool invert;

void main()
{
    if (showOnlyRedAndGreen)
    {
        vec4 textureColor = texture2D(texture, texCoords);
        if (invert)
        {
            FragColor = vec4(1 - textureColor.r, 1 - textureColor.g, 0.0, 1.0);
        }
        else
        {
            FragColor = vec4(textureColor.r, textureColor.g, 0.0, 1.0);
        }
    }
    else
    {
        if (invert)
        {
            vec4 textureColor = texture2D(texture, texCoords);
            FragColor = vec4(1 - textureColor.r, 1 - textureColor.g, 1 - textureColor.b, 1.0);
        }
        else
        {
            FragColor = texture2D(texture, texCoords);
        }
    }
}
