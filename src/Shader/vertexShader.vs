#version 400 core

in vec3 mPosition;
void main(){
    gl_Position = vec4(mPosition.xyz,1.0f);
    
}