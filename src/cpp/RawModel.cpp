#include"../header/RawModel.h"
RawModel::RawModel():VAOID(0),vertexCount(0){
}

RawModel::RawModel(unsigned int VAOID, int vertexCount):VAOID(VAOID),vertexCount(vertexCount){

}

RawModel::~RawModel(){
}

unsigned int RawModel::getVAOID() const {
    return VAOID;
    }

int RawModel::getVertexCount() const { 
    return vertexCount;
    }