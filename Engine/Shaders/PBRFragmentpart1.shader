#version 410 core

#define MAX_POINT_LIGHTS 50

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

out vec4 FragColor;

struct DirLight
{
    vec3 direction;
    vec3 color;
};

struct PointLight
{
    vec3 position;
    vec3 color;
};

uniform vec3 viewPos;

uniform DirLight dirLight;

uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int pointLightCount;

//Texture sampler
uniform sampler2D diffuseSampler;

//calculating directional light diffuse component
vec3 getDirLightComponent(vec3 lightDir, vec3 lightColor, vec3 normal)
{
    //Diffuse calculation
    float diffValue = max(dot(normal, lightDir), 0.0);
    vec3 diffuse =  diffValue * lightColor;

    //Specular calculation
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    return diffuse + specular;
}

vec3 calculateSinglePointLightComponent(PointLight light, vec3 normal)
{
    vec3 lightDir = normalize(light.position - FragPos);

    //Diffuse
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * light.color;

    //Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * light.color;

    return diffuse + specular;
}

vec3 getTotalPointLightComponent(vec3 normal)
{
    vec3 result = vec3(0.0);

    for (int i = 0; i < 2; i++)
    {
        result += calculateSinglePointLightComponent(pointLights[i], normal);
    }

    return result;
}

void main()
{
    vec3 ambient = vec3(0.1, 0.1, 0.1);

    //Normalizing the normal vector
    vec3 norm = normalize(Normal);

    //diffuse lighting for directional lighting calculation
    vec3 dirLightResult = getDirLightComponent(dirLight.direction, dirLight.color, norm);
    vec3 pointLightResult = getTotalPointLightComponent(norm);

    FragColor = vec4(dirLightResult + pointLightResult + ambient, 1.0);
}