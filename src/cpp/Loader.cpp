#include"../header/Loader.h"

Loader::Loader(){
    
}

Loader::~Loader(){

}


unsigned int Loader::CreateVAO (){
    unsigned int VAOID ;
    glGenVertexArrays(1,&VAOID);
    glBindVertexArray(VAOID);
    VAOS.push_back(VAOID);
    return VAOID;
}

void Loader::UnBindVAO (){
    glBindVertexArray(0);
}
void Loader::StoreDataToAttriList (int idx,float positions[],int size){
    unsigned int VBOID=0;
    glGenBuffers(1,&VBOID);
    glBindBuffer(GL_ARRAY_BUFFER,VBOID);
    glBufferData(GL_ARRAY_BUFFER,size,positions,GL_STATIC_DRAW);
    glVertexAttribPointer(idx,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    VBOS.push_back(VBOID);
}

void Loader::BindIndexBuffer (unsigned int indexBuffer[], int size){
    unsigned int IBOID;
    glGenBuffers(1, &IBOID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBOID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,indexBuffer,GL_STATIC_DRAW);
}

RawModel * Loader::LoadToVAO(float  positions[],int posSize, unsigned int indexData[],int indexSize){
    unsigned int VAOID = CreateVAO();
    BindIndexBuffer(indexData,indexSize);
    StoreDataToAttriList(0,positions,posSize);
    UnBindVAO();
    RawModel* tmpModel = new RawModel(VAOID,indexSize/sizeof(int));
    RawModelList.push_back(tmpModel);
    return tmpModel;
}


void Loader::CleanUp (){
    if(RawModelList.size()>0){
        for(auto* tmpModel : RawModelList){
            delete tmpModel;
        }
    }
    if(VAOS.size()>0){
    glDeleteVertexArrays(VAOS.size(),VAOS.data());
    }
    if(VBOS.size()>0){
    glDeleteBuffers(VBOS.size(),VBOS.data());
    }
}