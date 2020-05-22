#include "../header/StaticShader.h"
const char * VERTEX_SHADER_FILEPATH = "D:\\job\\opengl\\src\\Shader\\vertexShader.vs";
const char * FRAGMENT_SHADER_FILEPATH = "D:\\job\\opengl\\src\\Shader\\fragmentShader.fs";
StaticShader::StaticShader()
:ShaderProgram(VERTEX_SHADER_FILEPATH,FRAGMENT_SHADER_FILEPATH)
{
}

StaticShader::~StaticShader()
{
}