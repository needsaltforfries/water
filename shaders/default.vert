#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 myColor;
out vec3 norm;
out vec3 pos;

uniform mat4 model;
uniform mat4 camMatrix;
uniform float dT;
uniform float step;
vec3 vCol;

float random (in vec2 _st) {
    return fract(sin(dot(_st.xy,
                         vec2(12.9898,78.233)))*
        43758.5453123);
    }

void main(){
    float x = aPos.x;
    float z = aPos.z;

    float lacunarity = 2.0;
    float gain = 0.5;

    float amplitude = 0.25;
    float w = 1.0;
    //sum waves
    float y = 0.0;

    //these two floats are used to calculate the normal
    float dX = 0.0;
    float dZ = 0.0;
    
    float maxWaves = 8;

    float randomDir1 = random(vec2(0.0, 0.0));
    float randomDir2 = random(vec2(1.0, 0.0));

    for(float i = 1; i <= maxWaves; ++i){
        //FBM
        w *= lacunarity;
        amplitude *= gain;
        //calculate wave height
        y += amplitude*sin((x)*w + dT);
        y += amplitude*sin((z)*w + dT);
        //use these for binormal and tangent
        dX += w*amplitude*cos((x+step)*w + dT);
        dZ += w*amplitude*cos((z+step)*w + dT);
    }

    vec3 newPos = vec3(x, y, z);
    //calculate normal
    vec3 nextX = vec3(x+step, dX, z);
    vec3 nextZ = vec3(x, dZ, z+step);
    vec3 AB = vec3(newPos - nextX);
    vec3 AC = vec3(newPos - nextZ);

    norm = normalize(mat3(transpose(inverse(model))) * normalize(cross(AB, AC)));
    
    gl_Position = camMatrix * vec4(newPos, 1.0);
    pos = newPos;
    //FragColor = vec4(norm * 0.5 + 0.5, 1.0);
    myColor = vec4(pos, 1.0);
    //vCol = vec3(0.2, 0.2, 0.8);
    //myColor = vec4(vCol, 1.0);
}
