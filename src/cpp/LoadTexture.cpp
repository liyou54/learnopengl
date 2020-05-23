#include"../header/LoadTexture.h"

unsigned char * LoadTexture::ReadPic(const char * Path ){
    unsigned char * pic = stbi_load(Path,&width,&height,&channels,0);
    picdata = pic;
    return pic ;
}
void LoadTexture::FreePic(){
    stbi_image_free(picdata);
    width=0;
    height=0;
    channels=0;
}