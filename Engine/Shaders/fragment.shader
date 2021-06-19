#version 330 core
in vec2 texCoords;
out vec4 FragColor;
uniform sampler2D myTexture;

void main()
{
    FragColor = vec4(texture2D(myTexture, texCoords).rgb, 1.0);
}