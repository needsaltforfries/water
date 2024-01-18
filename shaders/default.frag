#version 330 core

out vec4 FragColor;
in vec3 myColor;
in vec2 texCoord;

uniform vec4 delta;
uniform sampler2D myTexture;

void main(){
    //FragColor = texture(myTexture, texCoord) * vec4(myColor.x, myColor.y, delta.z, 1.0);
    FragColor = vec4(0.0f, 0.0f, delta.z, 1.0);
}