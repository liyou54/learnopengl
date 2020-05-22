#pragma
#include "RawModel.h"
#include "glad/glad.h"
class Render
{
private:
    /* data */
public:
    Render();
    ~Render();
    void Prepare();
    void OnRender(RawModel*& model);
};

