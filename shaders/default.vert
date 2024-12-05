#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 myColor;
out vec3 norm;
out vec3 pos;

uniform mat4 model;
uniform mat4 camMatrix;
uniform float dT;
uniform float step;

const float lacunarity = 1.42;
const float gain = 0.23;
const float maxWaves = 200.0;

//random function taken from Book of Shaders
float random(in vec2 _st) {
    return fract(sin(dot(_st.xy, vec2(12.9898, 78.233))) * 43758.5453123);
}

void main() {
    float x = aPos.x;
    float y = 0.0;
    float z = aPos.z;

    float a = 0.22;
    float w = 1.02;
    
    float dX = 0.0;
    float dZ = 0.0;

    for (float i = 1.0; i <= maxWaves; ++i) {

        float r1 = random(vec2(1.89 + aPos.x, 1.2 + aPos.z));
        float r2 = random(vec2(1.6 + aPos.z, 1.3 + aPos.x));
        vec2 r = 0.03 * normalize(vec2(r1, r2));
        y += a * sin(dot(aPos.xz, r) * w + i*dT);
        y += a * sin(aPos.x * w + i*dT);
        y += a * sin(aPos.z * w + i*dT);

        dX += r.x * a * w * cos(r.x*(x+step)) * sin(r.x*(x+step)*w + i*dT);
        dX += a * w * cos((x+step)) * sin((x+step)*w + i*dT);
        
        dZ += r.y * a * w * cos(r.y*(z+step)) * sin(r.y*(z+step)*w + i*dT);
        dZ += a * w * cos((z+step)) * sin((z+step)*w + i*dT);

        w *= lacunarity;
        a *= gain;
    }

    vec3 newPos = vec3(x+(dX), y, z+(dZ));
    vec3 nextX = vec3(x+step, y+(dX), z);
    vec3 nextZ = vec3(x, y+(dZ), z+step);

    vec3 AB = nextX - newPos;
    vec3 AC = nextZ - newPos;

    norm = normalize(cross(AB, AC));
    gl_Position = camMatrix * vec4(newPos, 1.0);
    pos = newPos;
    myColor = vec4(pos, 1.0);
}
