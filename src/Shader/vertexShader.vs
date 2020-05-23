#version 400 core

layout(location = 0) in vec3 mPosition;

out vec4 mOutColor;


void main(){
    gl_Position = vec4(mPosition.x,mPosition.y,mPosition.z,1.0f);

    mOutColor = vec4(mPosition.xyx+0.4,1.0f); 
    
}