/****************************************************************************
* Created for: AGE - Animation creator
* Dev line: AGE - Animation creator
* Creation day: 28/08/2015
* Last change: 29/09/2015
****************************************************************************/


#include "ADC.h"

//---------------------------------------------------------------------------

ADC::ADC(){

    this->age = new AGE();
    this->error = 0;
    this->error_label_limit = 0;
    this->event = nullptr;
    this->gan_src = "";
    this->image_src = "";
    this->image_w = 0;
    this->image_h = 0;
    this->image_x = 0;
    this->image_y = 0;
    this->keep = true;
    this->mouse_active = false;
    this->mouse_x = 0;
    this->mouse_y = 0;
    this->opt = 0;
    this->version = "v1.0.1";
    this->window_w = 0;
    this->window_h = 0;
    this->image_size = 1.0;
    this->total_frames = 0;
    this->strings_index = new AGEStringsIndex();
    this->active_frame = {0, 0, 0, 0, 0, 0};
    this->creating_frame = false;
    this->pointer_frame = 0;
    this->bg_color = {0,0,0,0};
    this->play_animation = false;
    this->animation_id = 0;
    this->animation_frame = 0;
    this->animation_delay = 5;
    this->animation_counter = 0;
    this->animation_pause = false;

}

ADC::~ADC()
{
    //dtor
}


//---------------------------------------------------------------------------

void ADC::init(string image_src, string gan_src){

    this->image_src = image_src;
    this->gan_src = gan_src;

    this->age->configure(600,600, "maximized", "ADC - " + this->version);
    this->age->loadAPI();
    this->event = this->age->getEventHandler();

    this->window_w = this->age->getWindowSize().w;
    this->window_h = this->age->getWindowSize().h;

    this->age->deployFont("AGE.ttf", 11, "");
    this->age->deployFont("AGE.ttf", 32, "");

    this->age->deployLabel("ERROR 1: file not found", 1, AGE_RENDER_S, 0xFF, 0xF8, 0x37, true, 12, 0xC0, 0, 0, true, 8, 0xFF, 0xF8, 0x37);
    this->age->deployLabel("ERROR 2: can't create GAN file", 1, AGE_RENDER_S, 0xFF, 0xF8, 0x37, true, 12, 0xC0, 0, 0, true, 8, 0xFF, 0xF8, 0x37);
    this->error_label_limit = this->age->deployLabel("ERROR 3: can't register this frame", 1, AGE_RENDER_S, 0xFF, 0xF8, 0x37, true, 12, 0xC0, 0, 0, true, 8, 0xFF, 0xF8, 0x37);

    this->age->deployLabel("MENU", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("0. None", 0, AGE_RENDER_B, 255, 255, 255, true, 4, 0, 0, 0);
    this->age->deployLabel("1. Zoom", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("2. Move image", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("3. Add single frame", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("4. Add regular frame", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("5. Edit frame", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("6. Delete frame", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("7. Select background color", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("8. Play the animation", 0, AGE_RENDER_B, 0, 0, 0);
    this->age->deployLabel("<ESC> To save & exit.", 0, AGE_RENDER_S, 0, 0, 0, true, 5,  0xCA, 0xCA, 0xCA);
    this->age->deployLabel("Use key numbers to select a tool.", 0, AGE_RENDER_S, 0, 0, 0, true, 5,  0xCA, 0xCA, 0xCA);

    this->checkFiles();
    this->loadGAN();

}


//---------------------------------------------------------------------------

void ADC::start(){

    while (this->keep){

        while( SDL_PollEvent( event ) != 0 ){

            if( event->type == SDL_KEYDOWN){

                switch( event->key.keysym.sym ){

                       case SDLK_ESCAPE:
                            if(this->total_frames > 0){this->createAnimation();}
                            keep = false;
                       break;

                       case SDLK_0:
                            this->opt=0;
                            this->age->setLabelValue(this->error_label_limit+12, "Use key numbers to select a tool.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = false;
                            this->active_frame = {0,0,0,0,0,0};
                       break;

                       case SDLK_1:
                            this->opt=1;
                            this->age->setLabelValue(this->error_label_limit+12, "+/- or mouse wheel to zoom in/out.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = false;
                            this->active_frame = {0,0,0,0,0,0};
                            this->creating_frame = false;
                       break;

                       case SDLK_2:
                            this->opt=2;
                            this->age->setLabelValue(this->error_label_limit+12, "Use arrow keys or mouse to move image.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = false;
                            this->active_frame = {0,0,0,0,0,0};
                       break;

                       case SDLK_3:
                            this->opt=3;
                            this->age->setLabelValue(this->error_label_limit+12, "Use mouse to create frame, arrow keys to move, J/L keys to modify W value and I/K keys to modify H value, <ENTER> to accept the frame.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = true;
                            this->active_frame = {0,0,0,0,0,0};
                       break;

                       case SDLK_4:
                            this->opt=4;
                            this->age->setLabelValue(this->error_label_limit+12, "Press <ENTER> to add the new frame (at least 1 previous frame is required to use this tool).");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = true;
                            this->active_frame = {0,0,0,0,0,0};
                       break;

                       case SDLK_5:
                            this->opt=5;
                            this->age->setLabelValue(this->error_label_limit+12, "User <REPAG> & <AVPAG> to select a frame, arrow keys to move, J/L keys to modify W value and I/K keys to modify H value.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = true;
                            this->pointer_frame = 0;
                            this->active_frame = {0,0,0,0,0,0};
                            this->setChangeableFrame();
                       break;

                       case SDLK_6:
                            this->opt=6;
                            this->age->setLabelValue(this->error_label_limit+12, "User <REPAG> & <AVPAG> to select a frame, <SUPR> to delete.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = true;
                            this->pointer_frame = 0;
                            this->active_frame = {0,0,0,0,0,0};
                            this->setChangeableFrame();
                       break;

                       case SDLK_7:
                            this->opt=7;
                            this->age->setLabelValue(this->error_label_limit+12, "Click on the image background to get the background color.");
                            this->changeMenu();
                            this->mouse_active=false;
                            this->creating_frame = false;
                            this->active_frame = {0,0,0,0,0,0};
                       break;

                       case SDLK_8:
                            if(this->total_frames > 0){
                                this->opt=8;
                                this->age->setLabelValue(this->error_label_limit+12, "<SPACE> to pause and resume animation, +/- to change speed, <ENTER> to finish.");
                                this->changeMenu();
                                this->mouse_active=false;
                                this->creating_frame = false;
                                this->active_frame = {0,0,0,0,0,0};
                                this->play_animation = true;
                                this->createAnimation();
                                this->loadAnimation();
                            }
                       break;

                       case SDLK_j:
                           if(this->opt == 3){
                                this->active_frame.w = this->active_frame.w - this->image_size;

                           }else if(this->opt == 5){

                                this->active_frame.w = this->active_frame.w - this->image_size;
                                this->frames[this->pointer_frame].w--;

                           }
                       break;

                       case SDLK_l:
                           if(this->opt == 3){
                                this->active_frame.w = this->active_frame.w + this->image_size;

                           }else if(this->opt == 5){

                                this->active_frame.w = this->active_frame.w + this->image_size;
                                this->frames[this->pointer_frame].w++;

                           }
                       break;

                       case SDLK_i:
                           if(this->opt == 3){
                                this->active_frame.h = this->active_frame.h - this->image_size;

                           }else if(this->opt == 5){

                                this->active_frame.h = this->active_frame.h - this->image_size;
                                this->frames[this->pointer_frame].h--;

                           }
                       break;

                       case SDLK_k:
                           if(this->opt == 3){
                                this->active_frame.h = this->active_frame.h + this->image_size;

                           }else if(this->opt == 5){

                                this->active_frame.h = this->active_frame.h + this->image_size;
                                this->frames[this->pointer_frame].h++;

                           }
                       break;

                       case SDLK_MINUS:
                           if(this->opt == 1){
                                this->image_size = this->image_size-1;

                           }else if(this->opt == 8){
                                this->animation_delay++;

                           }

                       break;

                       case SDLK_PLUS:
                           if(this->opt == 1){
                                this->image_size = this->image_size+1;

                           }else if(this->opt == 8){
                                this->animation_delay--;

                           }
                       break;

                       case SDLK_DELETE:
                           if(this->opt == 3){
                                this->active_frame = {0,0,0,0,0,0};

                            }else if(this->opt == 6){
                                this->deleteFrame();

                            }
                       break;

                       case SDLK_RCTRL:
                           this->printFrames();
                       break;

                       case SDLK_SPACE:
                            if (this->opt == 8){this->animation_pause = not this->animation_pause;}

                       break;

                       case SDLK_RETURN:

                           if (this->error == 3){
                                this->error = 0;

                           }else if(this->opt == 3){
                                this->registerFrame();
                                this->opt = 0;
                                this->age->setLabelValue(this->error_label_limit+12, "Use key numbers to select a tool.");
                                this->changeMenu();
                                this->mouse_active=false;
                                this->creating_frame = false;

                            }else if(this->opt == 4){
                                this->addRegularFrame();

                            }else if(this->opt == 8){
                                this->opt=0;
                                this->age->setLabelValue(this->error_label_limit+12, "Use key numbers to select a tool.");
                                this->changeMenu();
                                this->creating_frame = false;
                                this->active_frame = {0,0,0,0,0,0};
                                this->play_animation = false;
                                this->mouse_active=false;
                            }
                       break;

                       case SDLK_UP:
                           if(this->opt == 2){
                                this->image_y = this->image_y-(1*this->image_size);
                                this->active_frame.y = this->active_frame.y-(1*this->image_size);

                            }else if(this->opt == 3){
                                this->active_frame.y = this->active_frame.y - (this->image_size);

                            }else if(this->opt == 5){

                                this->active_frame.y = this->active_frame.y - (this->image_size);
                                this->frames[this->pointer_frame].y--;

                            }
                       break;

                       case SDLK_DOWN:
                           if(this->opt == 2){
                                this->image_y = this->image_y+(1*this->image_size);
                                this->active_frame.y = this->active_frame.y+(1*this->image_size);

                            }else if(this->opt == 3){
                                this->active_frame.y = this->active_frame.y + (this->image_size);

                            }else if(this->opt == 5){

                                this->active_frame.y = this->active_frame.y + (this->image_size);
                                this->frames[this->pointer_frame].y++;

                            }

                       break;

                       case SDLK_RIGHT:
                           if(this->opt == 2){
                                this->image_x = this->image_x+(1*this->image_size);
                                this->active_frame.x = this->active_frame.x+(1*this->image_size);

                            }else if(this->opt == 3){
                                this->active_frame.x = this->active_frame.x + (this->image_size);

                            }else if(this->opt == 5){

                                this->active_frame.x = this->active_frame.x + (this->image_size);
                                this->frames[this->pointer_frame].x++;

                            }
                       break;

                       case SDLK_LEFT:
                           if(this->opt == 2){
                                this->image_x = this->image_x-(1*this->image_size);
                                this->active_frame.x = this->active_frame.x+(1*this->image_size);

                            }else if(this->opt == 3){
                                this->active_frame.x = this->active_frame.x - (this->image_size);

                           }else if(this->opt == 5){

                                this->active_frame.x = this->active_frame.x - (this->image_size);
                                this->frames[this->pointer_frame].x--;

                            }
                       break;

                       case SDLK_PAGEUP:
                           if(this->opt == 5 or this->opt == 6){
                                this->setChangeableFrame(1);

                            }
                       break;

                       case SDLK_PAGEDOWN:
                           if(this->opt == 5 or this->opt == 6){
                                this->setChangeableFrame(-1);

                            }
                       break;

                }

            }else if( event->type == SDL_MOUSEBUTTONDOWN){

                this->mouse_active = true;

                if(this->opt == 3){

                    this->active_frame.x = event->motion.x;
                    this->active_frame.y = event->motion.y;
                    this->active_frame.w = 0;
                    this->active_frame.h = 0;

                }else if(this->opt == 7){

                    this->getImageColor(event->motion.x, event->motion.y);

                }

            }else if( event->type == SDL_MOUSEBUTTONUP){
                this->mouse_active = false;

            }else if( event->type == SDL_MOUSEMOTION){

                if(this->mouse_active == true && this->opt == 2){

                    this->image_x = this->image_x + event->motion.xrel;
                    this->image_y = this->image_y + event->motion.yrel;
                    this->active_frame.x = this->active_frame.x + event->motion.xrel;
                    this->active_frame.y = this->active_frame.y + event->motion.yrel;


                }else if(this->mouse_active == true && this->opt == 3){

                    this->active_frame.w = this->active_frame.w + event->motion.xrel;
                    this->active_frame.h = this->active_frame.h + event->motion.yrel;

                }

            }else if( event->type == SDL_MOUSEWHEEL){

                switch(event->button.x){

                       case AGE_EVENT_MOUSEWHEEL_UP:
                           if(this->opt == 1){

                                this->image_size = this->image_size+1;
                                this->active_frame.x = (this->active_frame.x / (this->image_size-1)) * this->image_size;
                                this->active_frame.y = (this->active_frame.y / (this->image_size-1)) * this->image_size;

                           }
                       break;

                       case AGE_EVENT_MOUSEWHEEL_DOWN:
                           if(this->opt == 1){

                                this->image_size = this->image_size-1;
                                this->active_frame.x = (this->active_frame.x / (this->image_size+1)) * this->image_size;
                                this->active_frame.y = (this->active_frame.y / (this->image_size+1)) * this->image_size;

                           }
                       break;

                }

            }

        }

        this->drawScreen();

        this->age->refresh();
        this->age->pause(33);

    }

}


//---------------------------------------------------------------------------

void ADC::drawScreen(){

    this->age->clearScreen(0x00, 0x97, 0xbd);

    switch(this->error){

        case 1:
            this->age->moveLabel(0, this->window_w/2 - this->age->getLabelSize(0).w/2, this->window_h/2 - this->age->getLabelSize(0).h/2);
        break;

        case 2:
            this->age->moveLabel(1, this->window_w/2 - this->age->getLabelSize(0).w/2, this->window_h/2 - this->age->getLabelSize(0).h/2);
        break;

        case 3:
            this->age->moveLabel(2, this->window_w/2 - this->age->getLabelSize(0).w/2, this->window_h/2 - this->age->getLabelSize(0).h/2);
        break;

        default:

            if(this->play_animation == true){
                this->drawAnimation();

            }else{

                this->drawImage();
                this->drawFrames();
                this->drawMenu();

            }

        break;

    }

}


//---------------------------------------------------------------------------

void ADC::drawMenu(){

    int counter = 1;

    if(not this->play_animation){
        this->age->drawSquare(0, 0, 187, 260, 0xCA, 0xCA, 0xCA);

        while(counter <= 10){

            this->age->moveLabel(this->error_label_limit+counter, 8, 8+(20*(counter-1)));
            counter++;

        }

        this->age->moveLabel(this->error_label_limit+11, 6, this->window_h-34);
        this->age->moveLabel(this->error_label_limit+12, 6, this->window_h-14);

        this->age->drawSquareBorder(20, 210, 120, 30, 0,0,0);
        this->age->drawSquareBorder(21, 211, 118, 28, 255,255,255);
        this->age->drawSquareBorder(22, 212, 116, 26, 0,0,0);
        this->age->drawSquare(23, 213, 115, 25, this->bg_color.r, this->bg_color.g, this->bg_color.b);

    }

}


//---------------------------------------------------------------------------

void ADC::checkFiles(){

    ifstream animation_file;
    string line;
    int limiter;

    if(this->age->checkFile(this->image_src) == false){
        this->error = 1;

    }else{

        this->age->deployImage(this->image_src);
        this->image_w = this->age->getImageSize(0).w;
        this->image_h = this->age->getImageSize(0).h;
        this->image_x = this->window_w/2 - this->image_w/2;
        this->image_y = this->window_h/2 - this->image_h/2;

    }

    if(this->age->checkFile(this->gan_src) == false){

        if(not (this->age->createFile(this->gan_src, ""))){
            this->error = 2;

        }else{

            animation_file.open(gan_src.c_str(), std::ios::in);
            while(getline(animation_file, line)){

                limiter = line.find("=", 0);
                if((int)limiter < 255){
                    strings_index->setElementData(strings_index->createRegister(line.substr(0, limiter)),
                                                  line.substr(0, limiter),
                                                  line.substr(limiter+1),
                                                  ""
                                                  );
                }

            }
            animation_file.close();

        }

    }


}


//---------------------------------------------------------------------------

void ADC::drawAnimation(){

    if(this->animation_delay < 2){this->animation_delay = 2;}
    if(this->animation_delay > 12){this->animation_delay = 12;}

    this->age->drawSquare(this->age->getWindowSize().w/6, this->age->getWindowSize().h/6, (this->age->getWindowSize().w/6)*4, (this->age->getWindowSize().h/6)*4, 0xca, 0xca, 0xca);
    this->age->moveAnimation(this->animation_id, this->animation_frame, this->age->getWindowSize().w/2-25, this->age->getWindowSize().h/2-25);

    if(not this->animation_pause){

        this->animation_counter++;

        if(this->animation_counter == this->animation_delay){

            this->animation_counter=0;
            this->animation_frame++;

        }

        if(this->animation_frame == this->total_frames){this->animation_frame = 0;}

    }

    this->age->moveLabel(this->error_label_limit+11, 6, this->window_h-34);
    this->age->moveLabel(this->error_label_limit+12, 6, this->window_h-14);

}


//---------------------------------------------------------------------------

void ADC::loadAnimation(){

    this->animation_id = this->age->deployAnimation(this->gan_src);

}


//---------------------------------------------------------------------------

void ADC::drawImage(){

    if(not this->play_animation){

        if(this->image_size < 1){
            this->image_size = 1;

        }

        this->age->moveImage(0, this->image_x, this->image_y, this->image_size, 0, nullptr, AGE_FLIPN);

    }

}


//---------------------------------------------------------------------------

void ADC::changeMenu(){

    int counter = 1;

    while (counter < 11){

        if(this->opt == counter-2){

            this->age->setLabelColor(this->error_label_limit+counter, 255, 255, 255);
            this->age->setLabelBg(this->error_label_limit+counter, true, 4, 0, 0, 0);

        }else{

            this->age->setLabelColor(this->error_label_limit+counter, 0, 0, 0);
            this->age->setLabelBg(this->error_label_limit+counter, false, 4, 0, 0, 0);

        }

        counter++;

    }

}


//---------------------------------------------------------------------------

void ADC::drawFrames(){

    int counter = 0;

    if(not this->play_animation){
        for(counter = 0; counter < 201; counter++){

            if(this->frames[counter].w == 0 and this->frames[counter].h == 0){
                break;

            }else{
                this->age->drawSquareBorder(this->frames[counter].x * this->image_size + this->image_x,
                                            this->frames[counter].y * this->image_size + this->image_y,
                                            this->frames[counter].w * this->image_size,
                                            this->frames[counter].h * this->image_size,
                                            10,
                                            203,
                                            0);

            }

        }

        if(this->creating_frame){

            for(counter = 0; counter < 3; counter++){

                this->age->drawSquareBorder(this->active_frame.x - ((this->active_frame.x - this->image_x) % (int)this->image_size) - counter,
                                            this->active_frame.y - ((this->active_frame.y - this->image_y) % (int)this->image_size) - counter,
                                            (this->active_frame.w - (this->active_frame.w % (int)this->image_size)) + counter * 2,
                                            (this->active_frame.h - (this->active_frame.h % (int)this->image_size)) + counter * 2,
                                            0xFF,
                                            0xF6,
                                            0x00
                                            );

            }

        }

    }

}


//---------------------------------------------------------------------------

void ADC::registerFrame(){

    if(this->total_frames < 200 and this->active_frame.x > 0 and this->active_frame.y > 0){

        this->frames[this->total_frames].x = (this->active_frame.x - this->image_x) / this->image_size;
        this->frames[this->total_frames].y = (this->active_frame.y - this->image_y) / this->image_size;
        this->frames[this->total_frames].w = this->active_frame.w / this->image_size;
        this->frames[this->total_frames].h = this->active_frame.h / this->image_size;

        this->total_frames++;
        this->creating_frame = false;
        this->active_frame = {0, 0, 0, 0, 0, 0};

    }else{
        this->error = 3;

    }

}


//---------------------------------------------------------------------------

void ADC::addRegularFrame(){

    if(this->total_frames == 1){

        this->frames[1] = {this->frames[0].x + this->frames[0].w,
                              this->frames[0].y,
                              this->frames[0].w,
                              this->frames[0].h,
                              0,
                              0
                              };
        this->total_frames = 2;

    }else if(this->total_frames > 1 and this->total_frames < 201){

        this->frames[this->total_frames] = {this->frames[this->total_frames-1].x + (this->frames[this->total_frames-1].x - this->frames[this->total_frames-2].x),
                              this->frames[this->total_frames-1].y,
                              this->frames[this->total_frames-1].w,
                              this->frames[this->total_frames-1].h,
                              0,
                              0
                              };
        this->total_frames++;

    }

}


//---------------------------------------------------------------------------

void ADC::printFrames(){

    int counter;

    cout << "Total frames: " << this->total_frames << endl << endl;

    for(counter=0; counter < 201; counter++){

        if(this->frames[counter].w == 0 and this->frames[counter].h == 0){
            break;

        }else{
            cout << counter << " " << this->frames[counter].x << " " << this->frames[counter].y << " " << this->frames[counter].w << " " << this->frames[counter].h << " " << this->frames[counter].row << " " << this->frames[counter].column << endl << endl << endl;

        }

    }

}


//---------------------------------------------------------------------------

void ADC::setChangeableFrame(int mod){

    this->pointer_frame = this->pointer_frame+mod;

    if(this->pointer_frame < 0){
        this->pointer_frame = this->total_frames - 1;

    }else if(this->pointer_frame == this->total_frames){
        this->pointer_frame = 0;

    }

    if(this->pointer_frame < this->total_frames){

        this->active_frame = {(this->frames[this->pointer_frame].x * (int)this->image_size) + this->image_x,
                              (this->frames[this->pointer_frame].y * (int)this->image_size) + this->image_y,
                              this->frames[this->pointer_frame].w * (int)this->image_size,
                              this->frames[this->pointer_frame].h * (int)this->image_size,
                              0,
                              0
                             };

    }

}


//---------------------------------------------------------------------------

void ADC::deleteFrame(){

    int counter = this->pointer_frame;

    while(this->frames[counter].x > 0){

        this->frames[counter] = this->frames[counter+1];
        counter++;

    }

    this->active_frame = {this->frames[this->pointer_frame].x * (int)this->image_size + this->image_x,
                          this->frames[this->pointer_frame].y * (int)this->image_size + this->image_y,
                          this->frames[this->pointer_frame].w * (int)this->image_size,
                          this->frames[this->pointer_frame].h * (int)this->image_size,
                          0,
                          0
                         };
    this->total_frames--;

}


//---------------------------------------------------------------------------

void ADC::getImageColor(int x, int y){

    x = (x - this->image_x) / this->image_size;
    y = (y - this->image_y) / this->image_size;

    this->bg_color = this->age->getPixelColor(0, x, y);


}


//---------------------------------------------------------------------------

void ADC::createAnimation(){

    ofstream animation_file;
    int counter;

    this->animation_pause = false;

    animation_file.open(this->gan_src.c_str(), std::ios::trunc);

    animation_file << "FILE=" << this->image_src << endl;
    animation_file << "DESCRIPTION=Must_change" << endl;
    animation_file << "BGCOLOR1=" << (int)this->bg_color.r << endl;
    animation_file << "BGCOLOR2=" << (int)this->bg_color.g << endl;
    animation_file << "BGCOLOR3=" << (int)this->bg_color.b << endl;
    animation_file << "IMAGES=" << this->total_frames << endl;
    animation_file << "INIT=0" << endl;

    for(counter = 0; counter < this->total_frames; counter++){

        animation_file << "IMAGE" << counter+1 << "X=" << this->frames[counter].x << endl;
        animation_file << "IMAGE" << counter+1 << "Y=" << this->frames[counter].y << endl;
        animation_file << "IMAGE" << counter+1 << "W=" << this->frames[counter].w << endl;
        animation_file << "IMAGE" << counter+1 << "H=" << this->frames[counter].h << endl;
        animation_file << "IMAGE" << counter+1 << "D=1" << endl;

    }

    animation_file.close();


}


//---------------------------------------------------------------------------

void ADC::loadGAN(){

    ifstream animation_file;
    string reg;
    string reg_value;
    string opt;
    Uint8 limiter;
    int counter;

    if(this->error == 0){
        animation_file.open(this->gan_src.c_str(), std::ios::in);

        while(getline(animation_file, opt)){

            limiter = opt.find("=", 0);
            if((int)limiter < 255){

                reg = opt.substr(0, limiter);
                reg_value = opt.substr(limiter+1);
                this->age->deployString(reg, reg_value, "");

            }

        }

        animation_file.close();

        this->bg_color = {(Uint8)atoi((this->age->getString(this->age->searchString("BGCOLOR1", 0), 1)).c_str()),
                          (Uint8)atoi((this->age->getString(this->age->searchString("BGCOLOR2", 0), 1)).c_str()),
                          (Uint8)atoi((this->age->getString(this->age->searchString("BGCOLOR3", 0), 1)).c_str()),
                          0
                         };
        this->total_frames = atoi((this->age->getString(this->age->searchString("IMAGES", 0), 1)).c_str());
        for(counter = 0; counter < this->total_frames; counter++){
            cout << counter << " - " << "IMAGE" + this->age->itos(counter+1) + "X" << endl;
            cout << counter << " - " << this->age->searchString("IMAGE" + this->age->itos(counter+1) + "X", 0) << endl;
            cout << endl;
            this->frames[counter] = {atoi((this->age->getString(this->age->searchString("IMAGE" + this->age->itos(counter+1) + "X", 0), 1)).c_str()),
                                     atoi((this->age->getString(this->age->searchString("IMAGE" + this->age->itos(counter+1) + "Y", 0), 1)).c_str()),
                                     atoi((this->age->getString(this->age->searchString("IMAGE" + this->age->itos(counter+1) + "W", 0), 1)).c_str()),
                                     atoi((this->age->getString(this->age->searchString("IMAGE" + this->age->itos(counter+1) + "H", 0), 1)).c_str())
                                    };

        }

    }

}


//---------------------------------------------------------------------------
