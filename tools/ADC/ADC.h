/****************************************************************************
* Created for: AGE - Animation definition creator
* Dev line: AGE - Animation definition creator
* Creation day: 28/08/2015
* Last change: 29/09/2015
****************************************************************************/


#include "AGE.h"
#include "AGEPrefixedValues.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>


using namespace std;


#ifndef ADC_H
#define ADC_H


struct Area{
    int x;
    int y;
    int w;
    int h;
    int row;
    int column;
};


//---------------------------------------------------------------------------

class ADC
{
    public:
        ADC();
        virtual ~ADC();
        void init(string image_src, string gan_src);
        void start();

    protected:

    private:
        AGE* age;
        Uint8 error;
        SDL_Event* event;
        string gan_src;
        string image_src;
        double image_size;
        int image_h;
        int image_w;
        int image_x;
        int image_y;
        bool keep;
        bool mouse_active;
        int mouse_x;
        int mouse_y;
        Uint8 opt;
        string version;
        int window_w;
        int window_h;
        int error_label_limit;
        int total_frames;
        Area active_frame;
        Area frames[200];
        AGEStringsIndex* strings_index;
        bool creating_frame;
        int pointer_frame;
        AGE_Color bg_color;
        bool play_animation;
        int animation_id;
        int animation_frame;
        int animation_delay;
        int animation_counter;
        bool animation_pause;

        void addRegularFrame();
        void changeMenu();
        void checkFiles();
        void createAnimation();
        void deleteFrame();
        void drawAnimation();
        void drawFrames();
        void drawImage();
        void drawMenu();
        void drawScreen();
        void getImageColor(int x, int y);
        void loadAnimation();
        void loadGAN();
        void printFrames();
        void registerFrame();
        void scaleImage();
        void setChangeableFrame(int mod=0);

};

#endif // ADC_H
