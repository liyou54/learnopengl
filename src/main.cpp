#include "./header/DisplayManager.h"
#include "./header/Display.h"
#include "./header/Loader.h"
#include "./header/RawModel.h"
#include "./header/Render.h"
#include "./header/StaticShader.h"
#include <iostream>

int main()
{   
    float positions[]{
         .5f,  .5f, .0f,
         .5f, -.5f, .0f,
        -.5f, -.5f, .0f,
        -.5f,  .5f, .0f
    };
    unsigned int indexData[]{
        0,1,3,
        1,2,3
    };
    DisplayManager mDisplayMgr;
    mDisplayMgr.CreateDisplay();

    Render mRender;
    Loader mLoader;
    RawModel *mModel = mLoader.LoadToVAO(positions,sizeof(positions),indexData,sizeof(indexData)); 
    StaticShader mShader;
    while(!mDisplayMgr.IsRequestClosed()){
        mRender.Prepare();

        mShader.Start();
        mRender.OnRender(mModel);
        mShader.Stop ();

        mDisplayMgr.UpdateDisplay();
    }
    mShader.CleanUp();
    mLoader.CleanUp();
    mDisplayMgr.CloseDisplay();

    return 0;
}