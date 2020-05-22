#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
class DisplayMode{
    public:
        int width;
        int height;

        DisplayMode();
        DisplayMode(int width, int height);
};

class ContextAttribute{
    public:
        int major;
        int minor;
        bool bProfileCore;
        ContextAttribute();
        ContextAttribute(int major, int minor);
        void WithProfileCore(bool bUseProfileCore);
};

class Display{
    private:
        DisplayMode mDisplayMode;
        struct GLFWwindow* mWindow;
        const char *title;
    public:
        Display();
        void SetTitle(const char *title);
        void SetDisplayMode(DisplayMode mode);
        void Create(ContextAttribute attr);
        void Update();
        void Destroy();
        static void frameBufferSizeCallback(GLFWwindow* window,int width,int height);
        bool IsRequestClosed();
    
    private:
        void processEvent();
};
