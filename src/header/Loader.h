#pragma once
#include "RawModel.h"
#include "glad/glad.h"
#include <Vector>
class Loader
{
private:
    std::vector<unsigned int> VAOS;
    std::vector<unsigned int> VBOS;
    std::vector<RawModel*> RawModelList;
    unsigned int CreateVAO();
    void UnBindVAO();
    void BindIndexBuffer(unsigned int indexBuffer[],int size);
    void StoreDataToAttriList(int idx,float positions[], int size );
public:
    void CleanUp();
    RawModel* LoadToVAO(float  positions[],int posSize, unsigned int indexData[],int indexSize);
    Loader(/* args */);
    ~Loader();
    
};

