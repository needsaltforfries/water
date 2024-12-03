#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 myColor;
out vec3 norm;
out vec3 pos;

uniform mat4 model;
uniform mat4 camMatrix;
uniform float dT;
uniform float step;

const float lacunarity = 1.68;
const float gain = 0.43;
const float maxWaves = 10.0;

float random(in vec2 _st) {
    return fract(sin(dot(_st.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

void main() {
    float x = aPos.x;
    float y = 0.0;
    float z = aPos.z;

    float a = 0.5;
    float w = 1.0;
    
    float dX = 0.0;
    float dZ = 0.0;

    for (float i = 1.0; i <= maxWaves; ++i) {
        w *= lacunarity;
        a *= gain;

        float r1 = random(vec2(aPos.x, aPos.z));
        float r2 = random(vec2(1.0, 1.0));
        vec2 r = normalize(vec2(r1, r2));
        
        //y += a * sin(dot(r, aPos.xz)*w + dT);
        y += a * sin(aPos.x * w + i*dT);
        y += a * sin(aPos.z * w + i*dT);
        dX += a * w * cos((x+step)) * sin((x+step)*w + i*dT);
        dZ += a * w * cos((z+step)) * sin((z+step)*w + i*dT);
    }
    float offset = -0.0;
    vec3 newPos = vec3(x+(dX*step), y + offset, z+(dZ*step));
    vec3 nextX = vec3(x+step, y+(dX*step) + offset, z);
    vec3 nextZ = vec3(x, y+(dZ*step) + offset, z+step);

    vec3 AB = nextX - newPos;
    vec3 AC = nextZ - newPos;

    norm = normalize(cross(AB, AC));
    gl_Position = camMatrix * vec4(newPos, 1.0);
    pos = newPos;
    myColor = vec4(pos, 1.0);
}
