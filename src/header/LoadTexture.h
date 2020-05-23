#define STB_IMAGE_IMPLEMENTATION
#include "stb-master/stb_image.h"


class LoadTexture{
private:
    unsigned char * picdata;

public:
    int width, height,channels;
    unsigned char* ReadPic(const char *);
    void FreePic();

    

};
