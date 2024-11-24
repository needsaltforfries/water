#version 330 core

out vec4 FragColor;
in vec4 myColor;
in vec3 pos;
in vec3 norm;

uniform vec3 camPos;

void main(){
    vec3 amb = vec3(0.1, 0.1, 0.2);
    vec3 objCol = vec3(0.15, 0.15, 0.8);
    vec3 lightCol = vec3(1.0, 0.9, 0.8);
    vec3 lightPos = vec3(2.0, 2.0, 2.0);
    
    vec3 normal = normalize(norm);
    vec3 lightDir = normalize(lightPos - pos);

    //diff
    float d = max(dot(normal, lightDir), 0.0);
    vec3 diff = d*lightCol;

    //spec
    vec3 viewDir = normalize(camPos - pos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float shininess = 16.0;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = spec * lightCol; 

    vec3 col = vec3(amb + diff + specular);

    FragColor = vec4(col, 1.0);
    //FragColor = vec4(norm * 0.5 + 0.5, 1.0);
    //FragColor = vec4(vec3(d, d, d), 1.0);
    //FragColor = vec4(lightDir * 0.5 + 0.5, 1.0);
}