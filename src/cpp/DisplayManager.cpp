#include "../header/DisplayManager.h"

DisplayManager::DisplayManager(){

}

void DisplayManager::CreateDisplay(){
    mDisplay.SetTitle("firstWindow");
    mDisplay.SetDisplayMode(DisplayMode(640,480));
    ContextAttribute attr(4,0); 
    mDisplay.Create(attr);
    std::cout<<"GL_VERSION    :   "<<glGetString(GL_VERSION)<<"\n";
    std::cout<<"GL_RENDERER   :   "<<glGetString(GL_RENDERER)<<"\n";
}
EMDisplayState DisplayManager::UpdateDisplay(){
    mDisplay.Update();
}
void DisplayManager::CloseDisplay(){
    mDisplay.Destroy();
}
bool DisplayManager::IsRequestClosed(){
    return mDisplay.IsRequestClosed();
}