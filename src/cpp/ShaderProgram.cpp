#include "../header/ShaderProgram.h"

ShaderProgram::ShaderProgram(const char * vertexShaderPath,const char * fragmentShaderPath)
{
    vertexShaderID = LoadShader(vertexShaderPath,GL_VERTEX_SHADER);
    fragmentShaderID = LoadShader(fragmentShaderPath,GL_FRAGMENT_SHADER);
    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    int success ;
    glGetProgramiv(programID,GL_LINK_STATUS,&success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(programID,512,nullptr,infoLog);
        std::cout << "Link Program Error : "<<infoLog<<std::endl;
    }

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

ShaderProgram::~ShaderProgram()
{
}

int ShaderProgram::LoadShader(const char* FilePath,int type){
    std::string strShaderCode;
    std::ifstream shaderFile;

    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try{
        std::stringstream shaderString;
        shaderFile.open(FilePath);
        shaderString<<shaderFile.rdbuf();

        shaderFile.close();
        strShaderCode = shaderString.str();
    }
    catch(std::exception e){
        std::cout << "Load Shader Error!\n";
        return -1;
    }

    int shaderID = glCreateShader(type);
    const char* cShaderCode = strShaderCode.c_str();
    glShaderSource(shaderID, 1, &cShaderCode, nullptr);
    glCompileShader(shaderID);

    int success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS,&success);
    if(!success){
        char InfoLog[512];
        glGetShaderInfoLog(shaderID,512,nullptr,InfoLog);
        std::cout <<"compile shader error : "<<InfoLog <<std::endl;
    }
    return shaderID;
}

void ShaderProgram::Start(){
    glUseProgram(programID);
}

void ShaderProgram::Stop(){
    glUseProgram(0);
}

void ShaderProgram::CleanUp(){
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDetachShader(programID,vertexShaderID);
    glDetachShader(programID,fragmentShaderID);
    glDeleteProgram(programID);
}