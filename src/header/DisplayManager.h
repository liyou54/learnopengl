#pragma once
#include "Display.h"
#include "Enums.h"
class DisplayManager{
    private:
        Display mDisplay;
    public :
        DisplayManager();
        void CreateDisplay();
        EMDisplayState UpdateDisplay();
        void CloseDisplay();
        bool IsRequestClosed();

};