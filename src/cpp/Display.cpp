#include "../header/Display.h"

DisplayMode::DisplayMode():width(0),height(0){

}

DisplayMode::DisplayMode(int width, int height):width(width),height(height){
}

ContextAttribute::ContextAttribute():major(0), minor(0),bProfileCore(false){

}

ContextAttribute::ContextAttribute(int major, int minor)
        :major(major), minor(minor),bProfileCore(false){
 
}

void ContextAttribute::WithProfileCore(bool bUseProfileCore){
    this->bProfileCore = bUseProfileCore;
}

Display::Display():title(""),mWindow(nullptr){

}

void Display::SetTitle(const char* title){
    this->title = title;
}

void Display::Create(ContextAttribute attr){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, attr.major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, attr.minor);
    
    if(attr.bProfileCore){
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    this->mWindow =
    glfwCreateWindow(mDisplayMode.width,mDisplayMode.height,this->title,nullptr,nullptr);

    if(!this->mWindow){
        std::cout << "Creat Window Failded!\n";
        return;
    }
    glfwMakeContextCurrent(mWindow);

    if(!gladLoadGL()){
        std::cout<<"Failed to load glad!\n";
        Destroy();
    }
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    glfwSetFramebufferSizeCallback(mWindow,frameBufferSizeCallback);
}

void Display::frameBufferSizeCallback(GLFWwindow* window,int width,int height){
    glViewport(0,0,width,height);
}

EMDisplayState Display::Update(){

    glfwPollEvents();
    glfwSwapBuffers(mWindow);
    return processEvent();
}

void Display::Destroy(){
    glfwDestroyWindow(mWindow);
    glfwTerminate();
    mWindow = nullptr;
}

void Display::SetDisplayMode(DisplayMode mode){
    mDisplayMode = mode;
}
EMDisplayState Display::processEvent (){
    if(glfwGetKey(mWindow,GLFW_KEY_ESCAPE)==GLFW_PRESS){
        glfwSetWindowShouldClose(mWindow, true);
        return EMDisplayState::STATE_SUCCESS;
    }
    else if(glfwGetKey(mWindow,GLFW_KEY_R)==GLFW_PRESS){
        return EMDisplayState::STATE_RELOAD;
    }
}

bool Display::IsRequestClosed(){
    return glfwWindowShouldClose(mWindow);
}