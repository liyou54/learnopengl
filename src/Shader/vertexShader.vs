#version 400 core

layout(location = 0) in vec3 mPosition;

out vec4 mOutColor;

void main(){
    gl_Position = vec4(mPosition.xyz,1.0f);

    mOutColor = vec4((mPosition.x+0.2)/mPosition.y , mPosition.y/mPosition.x,mPosition.z*0.1,1.0f);
    
}