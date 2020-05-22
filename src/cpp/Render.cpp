#include"../header/Render.h"

Render::Render()
{
    // glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

Render::~Render()
{
}

void Render::Prepare(){
    glClearColor(.2f,.3f,.3f,1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    

}

void Render::OnRender(RawModel*& model){
    if(!model){
        return;
    }
    glBindVertexArray(model->getVAOID());
    glEnableVertexAttribArray(0);
    // glDrawArrays(GL_TRIANGLES,0,model->getVertexCount());
    glDrawElements(GL_TRIANGLES,model->getVertexCount(),GL_UNSIGNED_INT,0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}