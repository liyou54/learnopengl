#include "./header/DisplayManager.h"
#include "./header/Display.h"
#include "./header/Loader.h"
#include "./header/RawModel.h"
#include "./header/Render.h"
#include "./header/StaticShader.h"
#include "./header/Enums.h"
#include "./header/LoadTexture.h"
#include <iostream>

int main()
{   
    float positions[]{
         .0f,  .5f, .0f,
         .5f, -.5f, .0f,
        -.5f, -.5f, .0f,
        -.5f,  .5f, .0f
    };
    unsigned int indexData[]{
        0,1,2,
        // 1,2,3

    };
    float texposition[]{
        .0,.0,
        1.,0.,
        .5,1.
    };

    EMDisplayState mDisplayState;
    LoadTexture mTexture;
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

        mDisplayState = mDisplayMgr.UpdateDisplay();
        if(mDisplayState==EMDisplayState::STATE_RELOAD){
            mShader.ReloadShader();
        }
    }
    mShader.CleanUp();
    mLoader.CleanUp();
    mDisplayMgr.CloseDisplay();

    return 0;
}
