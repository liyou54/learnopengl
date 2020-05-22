#pragma once

class RawModel
{
private:
    unsigned int VAOID;
    int vertexCount;
public:
    RawModel();
    RawModel(unsigned int VAOID, int vertexCount);
    ~RawModel();
    unsigned int getVAOID() const ;
    int getVertexCount() const ;
};


