#pragma once
#include "../header/Display.h"
class DisplayManager{
    private:
        Display mDisplay;
    public :
        DisplayManager();
        void CreateDisplay();
        void UpdateDisplay();
        void CloseDisplay();
        bool IsRequestClosed();

};