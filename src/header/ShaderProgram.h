#pragma
#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class ShaderProgram
{
private:
    int LoadShader(const char* FilePath,int type);
    int vertexShaderID ;
    int fragmentShaderID;
    int programID;

    const char * vertexFilePath;
    const char * fragmentFilePath;
public:
    ShaderProgram(const char * vertexShaderPath,const char * fragmentShaderPath);
    void Start();
    void Stop();
    void ReloadShader();
    void CleanUp();
    int CreatProgram();
    ~ShaderProgram();
};

