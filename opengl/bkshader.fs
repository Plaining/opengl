
#version 330 core
out vec4 FragColor;

in vec4 Pos;
in vec3 color;


void main() {
    FragColor = vec4(color,1.0f);
   }