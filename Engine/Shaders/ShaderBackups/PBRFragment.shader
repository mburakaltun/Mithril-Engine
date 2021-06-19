#version 330 core

in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;

uniform sampler2D myTexture;

void main()
{
    vec3 directionalLightDir = vec3(0.0, 1.0, 0.0);
    vec3 directionalLightColor = vec3(0.75, 0.75, 0.75);

    vec3 pointLightPos = vec3(0.0, 1.0, 0.0);
    vec3 pointLightColor = vec3(1.0, 1.0, 1.0);

    vec3 ambient = vec3(0.1, 0.1, 0.1);

    //Normalizing the normal vector
    vec3 norm = normalize(Normal);

    //diffuse lighting for directional lighting calculation
    directionalLightDir = normalize(directionalLightDir);
    float diffValue = max(dot(norm, directionalLightDir), 0.0);
    vec3 dirDiffuse = diffValue * directionalLightColor;

    //diffuse lighting for point lighting calculation
    vec3 pointLightDir = pointLightPos - FragPos;
    float distanceFromPointLight = length(pointLightDir);
    pointLightDir = normalize(pointLightDir);
    vec3 pointDiffuse = vec3(min(max(dot(norm, pointLightDir), 0.0) / distanceFromPointLight, 1.0)) * pointLightColor;

    FragColor = vec4(dirDiffuse + pointDiffuse + ambient, 1.0);
}