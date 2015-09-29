/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 29/09/2015
****************************************************************************/


#include "test.h"

//----------------------------------------------------------------------------

test::test(int id){

    this->api = new AGE();

    cout << "AGE options" << endl;
    cout << endl << "API version: " << API_VERSION << endl << endl;

    switch(id){

        case 1:
            this->test1();
            break;

        case 2:
            this->test2();
            break;

        case 3:
            this->test3();
            break;

        case 4:
            this->test4();
            break;

        case 5:
            this->test5();
            break;

        case 6:
            this->test6();
            break;

        case 7:
            this->test7();
            break;

        default:
            cout << endl;
            cout << "TOOLS:" << endl;
            cout << "   ADC: age ADC <image_file> <gan_file>" << endl;

            cout << endl;
            cout << "TESTS:" << endl;
            cout << "   Usage: age test <test_number>" << endl;
            cout << "   1: Six files are loaded and one is a missing file" << endl;
            cout << "   2: Memory manage & dynamic load system form images" << endl;
            cout << "   3: Fade screen & drawsquare function" << endl;
            cout << "   4: Moving an image to check collisions" << endl;
            cout << "   5: Area collision system example" << endl;
            cout << "   6: Animation system example" << endl;
            cout << "   7: Label system example" << endl;
            cout << "   8: Collision point system example" << endl;
            cout << endl;
    }


}

test::~test(){
    //dtor
}

//----------------------------------------------------------------------------

void test::test1(){

    cout << "Test 1 - START" << endl;

    this->api->configure(600,600, "window", "Test 1");
    this->api->loadAPI();
    this->api->refresh();
    this->api->pause(2*1000);


    cout << endl;
    cout << "DEPLOY" << endl;
    cout << "Launch 1" << endl;
    this->api->deployImage("test/1.png", 20, 20);
    cout << "Landed 1" << endl;
    cout << "Launch 2" << endl;
    this->api->deployImage("test/2.jpg", 20, 300);
    cout << "Landed 2" << endl;
    cout << "Launch 3" << endl;
    this->api->deployImage("test/3.jpg", 300, 20);
    cout << "Landed 3" << endl;
    cout << "Launch 4" << endl;
    this->api->deployImage("test/4.jpg", 300, 300);
    cout << "Landed 4" << endl;
    cout << "Launch 5" << endl;
    this->api->deployImage("test/5.jpg", 150, 150);
    cout << "Landed 5" << endl;
    cout << "Launch 6" << endl;
    this->api->deployImage("test/INVALID_FILE", 150, 20);
    cout << "Landed 6" << endl;


    cout << endl;
    cout << "CHECKING 1" << endl;
    cout << "Texture index pointer: " << this->api->getTextureIndex() << endl;
    cout << "Try -: " << this->api->getTextureIndex()->getSrc(-1) << endl;
    cout << "Try 0: " << this->api->getTextureIndex()->getSrc(0) << endl;
    cout << "Try 1: " << this->api->getTextureIndex()->getSrc(1) << endl;
    cout << "Try 2: " << this->api->getTextureIndex()->getSrc(2) << endl;
    cout << "Try 3: " << this->api->getTextureIndex()->getSrc(3) << endl;
    cout << "Try 4: " << this->api->getTextureIndex()->getSrc(4) << endl;
    cout << "Try 5: " << this->api->getTextureIndex()->getSrc(5) << endl;
    cout << endl;

    this->api->refresh();
    cout << "Must see images now" << endl;
    this->api->pause(6*1000);

    this->api->terminate();

    cout << "Test 1 - END" << endl;


}


//----------------------------------------------------------------------------

void test::test2(){

    cout << "Test 2 - START" << endl;

    int counter = 300;
    int update_counter = 0;
    int status = -1;
    bool keep_working = true;
    SDL_Event event;

    this->api->configure(700,400, "window", "Test 2");
    this->api->loadAPI();

    cout << endl << "IMAGE LOAD WILL START IN 10 SECONDS" << endl;
    this->api->pause(10000);

    cout << endl << "ALL FILES DEPLOYED - Next is 1" << endl;
    cout << "1 is loaded with id " << this->api->deployImage("test/1.png", 0, 0) << endl;
    cout << "2 is loaded with id " << this->api->deployImage("test/2.jpg", 150, 0) << endl;
    cout << "3 is loaded with id " << this->api->deployImage("test/3.jpg", 300, 0) << endl;
    cout << "4 is loaded with id " << this->api->deployImage("test/4.jpg", 450, 0) << endl;
    cout << "5 is loaded with id " << this->api->deployImage("test/5.jpg", 0, 150) << endl;
    cout << "6 is loaded with id " << this->api->deployImage("test/6.jpg", 150, 150) << endl;
    cout << "7 is loaded with id " << this->api->deployImage("test/7.jpg", 300, 150) << endl;
    cout << "8 is loaded with id " << this->api->deployImage("test/8.png", 450, 150) << endl;
    cout << this->api->getTextureIndex()->getCounter() << " elements are loaded" << endl;
    this->api->refresh();

    while(keep_working){

        counter++;
        update_counter++;
        this->api->clearScreen();
        this->api->moveImage(0, 0, 0);
        this->api->moveImage(1, 150, 0);
        this->api->moveImage(2, 300, 0);
        this->api->moveImage(3, 450, 0);
        this->api->moveImage(4, 0, 150);
        this->api->moveImage(5, 150, 150);
        this->api->moveImage(6, 300, 150);
        this->api->moveImage(7, 450, 150);
        SDL_PollEvent( &event );
        this->api->refresh();
        //cout << endl << "UPDATEO - " << update_counter << endl;
        this->api->pause(16);

        if (counter >= 300){

            counter = -1;
            status++;

            switch(status){

                case 0:
                    cout << endl << "1 is soft deleted - Next is 2" << endl;
                    this->api->freeImage(0);
                    break;

                case 1:
                    cout << endl << "2 is soft deleted - Next is 3" << endl;
                    this->api->freeImage(1);
                    break;

                case 2:
                    cout << endl << "3 is soft deleted - Next is 4" << endl;
                    this->api->freeImage(2);
                    break;

                case 3:
                    cout << endl << "4 is soft deleted - Next is 5" << endl;
                    this->api->freeImage(3);
                    break;

                case 4:
                    cout << endl << "5 is soft deleted - Next is 6" << endl;
                    this->api->freeImage(4);
                    break;

                case 5:
                    cout << endl << "6 is soft deleted - Next is 7" << endl;
                    this->api->freeImage(5);
                    break;

                case 6:
                    cout << endl << "7 is soft deleted - Next is 8" << endl;
                    this->api->freeImage(6);
                    break;

                case 7:
                    cout << endl << "8 is soft deleted - 5-8 will be recovered from memory" << endl;
                    this->api->freeImage(7);
                    break;

                case 8:
                    cout << endl << "1-4 are new files, 5-8 are recovered from memory - 1 will be hard deleted from memory" << endl;
                    cout << "5 is loaded with id " << this->api->deployImage("test/5.jpg", 0, 150) << endl;
                    cout << "6 is loaded with id " << this->api->deployImage("test/6.jpg", 150, 150) << endl;
                    cout << "9 is loaded with id " << this->api->deployImage("test/9.png", 0, 0) << endl;
                    cout << "10 is loaded with id " << this->api->deployImage("test/10.jpg", 150, 0) << endl;
                    cout << "7 is loaded with id " << this->api->deployImage("test/7.jpg", 300, 150) << endl;
                    cout << "8 is loaded with id " << this->api->deployImage("test/8.png", 450, 150) << endl;
                    cout << "11 is loaded with id " << this->api->deployImage("test/11.jpg", 300, 0) << endl;
                    cout << "12 is loaded with id " << this->api->deployImage("test/12.png", 450, 0) << endl;
                    cout << this->api->getTextureIndex()->getCounter() << " elements are loaded" << endl;
                    break;

                case 9:
                    cout << endl << "1 is hard deleted - Next is 2" << endl;
                    this->api->deleteImage(0);
                    break;

                case 10:
                    cout << endl << "2 is hard deleted - Next is 3" << endl;
                    this->api->deleteImage(1);
                    break;

                case 11:
                    cout << endl << "3 is hard deleted - Next is 4" << endl;
                    this->api->deleteImage(2);
                    break;

                case 12:
                    cout << endl << "4 is hard deleted - Next is 5" << endl;
                    this->api->deleteImage(3);
                    break;

                case 13:
                    cout << endl << "5 is hard deleted - Next is 6" << endl;
                    this->api->deleteImage(4);
                    break;

                case 14:
                    cout << endl << "6 is hard deleted - Next is 7" << endl;
                    this->api->deleteImage(5);
                    break;

                case 15:
                    cout << endl << "7 is hard deleted - Next is 8" << endl;
                    this->api->deleteImage(6);
                    break;

                case 16:
                    cout << endl << "8 is hard deleted - No more images should be in memory" << endl << endl;
                    this->api->deleteImage(7);
                    break;

                case 17:
                    break;

                case 18:
                    break;

                case 19:
                    break;

                case 20:
                    break;

                default:
                    keep_working = false;

            }

        }

    }


    this->api->terminate();

    cout << "Test 2 - END" << endl;

}


//----------------------------------------------------------------------------

void test::test3(){

    cout << "Test 3 - START" << endl << endl;

    int counter = -1;
    SDL_Event event;
    bool keep_working = true;

    this->api->configure(886,480, "window", "Test 3");
    this->api->loadAPI();
    this->api->refresh();


    while(keep_working){

        switch(counter){

            case 200:
                cout << "Deploying background" << endl;
                this->api->deployImage("test/bg01.png", 0, 0);
                break;

            case 400:
                cout << "Drawing a red square" << endl;
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                break;

            case 800:
                cout << "Drawing a yellow line" << endl;
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                break;

            case 1200:
                cout << "Drawing a transparent dark blue square" << endl;
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                this->api->drawSquare(20, 220, 100, 100, 0x00, 0x88, 0x88, 0x80);
                break;

            case 1500:
                cout << "Fading screen" << endl;
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                this->api->drawSquare(20, 220, 100, 100, 0x00, 0x88, 0x88, 0x80);
                this->api->fadeScreen(50);
                break;

            case 1600:
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                this->api->drawSquare(20, 220, 100, 100, 0x00, 0x88, 0x88, 0x80);
                this->api->fadeScreen(100);
                break;

            case 1700:
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                this->api->drawSquare(20, 220, 100, 100, 0x00, 0x88, 0x88, 0x80);
                this->api->fadeScreen(150);
                break;

            case 1800:
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                this->api->drawSquare(20, 220, 100, 100, 0x00, 0x88, 0x88, 0x80);
                this->api->fadeScreen(200);
                break;

            case 1900:
                this->api->deployImage("test/bg01.png", 0, 0);
                this->api->drawSquare(20, 20, 100, 100, 0xFF, 0x00, 0x00);
                this->api->drawLine(20, 120, 120, 200, 0xDD, 0xDD, 0x00);
                this->api->drawSquare(20, 220, 100, 100, 0x00, 0x88, 0x88, 0x80);
                this->api->fadeScreen(255);
                break;


            case 2300:
                keep_working = false;
                break;

        }

        counter++;
        this->api->refresh();
        SDL_PollEvent( &event );
        this->api->pause(API_FPS);

    }



    this->api->terminate();

    cout << "Test 3 - END" << endl;

}


//----------------------------------------------------------------------------

void test::test4(){

    bool keep = true;
    bool mouse = false;
    SDL_Event* event;
    int x = 500;
    int y = 200;

    cout << "Test 4 - START" << endl;
    cout << "Press keys to move, left click to control with mouse." << endl;
    cout << "Press <ESC> to exit." << endl;
    cout << "Movement events will be notified, when dog collision with other images, a square will be colored" << endl;
    cout << "When dog collision with other images, an area will be colored" << endl << endl;

    this->api->configure(1200,700, "window", "Test 4");
    this->api->loadAPI();
    event = this->api->getEventHandler();
    this->api->refresh();

    this->api->deployImage("test/7.jpg");
    this->api->deployImage("test/13.png");
    this->api->deployImage("test/1.png");
    this->api->deployImage("test/2.jpg");
    this->api->deployImage("test/8.png");

    while (keep){

        while( SDL_PollEvent( event ) != 0 ){

            if( event->type == SDL_KEYDOWN){

                switch( event->key.keysym.sym ){

                        case SDLK_UP:
                            cout << "UP" << endl;
                            y = y-1;
                            break;

                        case SDLK_DOWN:
                            cout << "DOWN" << endl;
                            y = y+1;
                            break;

                        case SDLK_LEFT:
                            cout << "LEFT" << endl;
                            x = x-1;
                            break;

                        case SDLK_RIGHT:
                            cout << "RIGHT" << endl;
                            x = x+1;
                            break;

                       case SDLK_ESCAPE:
                            cout << "Bye" << endl;
                            keep = false;
                            break;

                    }

            }else if((event->type == SDL_MOUSEMOTION) && (mouse)){
                cout << "MOUSE MOVING" << endl;
                x = event->motion.x;
                y = event->motion.y;


            }else if(event->type == SDL_MOUSEBUTTONDOWN){

                if(event->button.button == SDL_BUTTON_LEFT){
                    cout << "MOUSE MODE CHANGED" << endl;
                    mouse = not mouse;
                    SDL_ShowCursor((int) not mouse);

                }

            }


        }

        this->api->drawSquare(0, 0, 1200, 700, 0, 0, 0);
        this->api->moveImage(0, x, y);
        this->api->moveImage(1, 200, 220);
        this->api->moveImage(2, 260, 400);
        this->api->moveImage(3, 600, 300);
        this->api->moveImage(4, 1000, 350);

        if (this->api->checkTexturesCollision(0,1)){
            this->api->drawSquare(20, 680, 100, 20, 0x66, 0xFF, 0x33);
        }

        if (this->api->checkTexturesCollision(0,2)){
            this->api->drawSquare(120, 680, 100, 20, 0xCF, 0x00, 0x00);
        }

        if (this->api->checkTexturesCollision(0,3)){
            this->api->drawSquare(220, 680, 100, 20, 0xC6, 0xC6, 0xC6);
        }

        if (this->api->checkTexturesCollision(0,4)){
            this->api->drawSquare(320, 680, 100, 20, 0xCB, 0x0B, 0xC0);
        }

        this->api->refresh();
        this->api->pause(16);

    }

    this->api->terminate();

    cout << "Test 4 - END" << endl;

}


//----------------------------------------------------------------------------

void test::test5(){

    bool keep = true;
    bool show = false;
    SDL_Event* event;
    int bg;
    int dog;
    int red;
    int white;
    int green;
    int tux;
    int optimus;
    int asimov;
    int area_white_1;
    int area_white_2;
    int area_green_1;
    int area_green_2;
    int area_dog;
    int area_tux;
    int area_optimus;
    int area_asimov;
    int free_area_1;
    int free_area_2;
    int free_area_main_1;
    int free_area_main_2;
    int free_area_main_3;
    int free_area_main_4;
    int x = 20;

    cout << "Test 5 - START" << endl << endl;
    cout << "Press keys to move." << endl << endl;
    cout << "Press <SPACE> to show/hide collision areas." << endl;
    cout << "Press <ESC> to exit." << endl;
    cout << "Program will check collision events and notify with colored squares." << endl << endl;

    this->api->configure(1200,700, "window", "Test 5");
    this->api->loadAPI();
    event = this->api->getEventHandler();
    this->api->refresh();

    bg = this->api->deployImage("test/fbg.png");
    dog = this->api->deployImage("test/7.jpg");
    red = this->api->deployImage("test/1.png");
    white = this->api->deployImage("test/2.jpg");
    green = this->api->deployImage("test/3.jpg");
    tux = this->api->deployImage("test/10.jpg");
    optimus = this->api->deployImage("test/5.jpg");
    asimov = this->api->deployImage("test/8.png");

    area_dog = this->api->linkCollisionAreaToTexture(dog, "area for dog", 90, 20, 30, 100);

    area_white_1 = this->api->linkCollisionAreaToTexture(white, "area 1 for white", 30, 10, 50, 120);
    area_white_2 = this->api->linkCollisionAreaToTexture(white, "area 2 for white", 10, 80, 160, 30, 0xE7, 0x00, 0x00);

    area_green_1 = this->api->linkCollisionAreaToTexture(white, "area 1 for green", 30, 10, 50, 120);
    area_green_2 = this->api->linkCollisionAreaToTexture(white, "area 2 for green", 10, 80, 160, 30);

    area_tux = this->api->linkCollisionAreaToTexture(tux, "area for tux", 20, 20, 110, 100);

    area_optimus = this->api->linkCollisionAreaToTexture(optimus, "area for optimus", 50, 50, 95, 95);
    area_asimov = this->api->linkCollisionAreaToTexture(asimov, "area for asimov", 60, 60, 55, 55);

    free_area_1 = this->api->linkCollisionAreaToScreen("free area 1", 390, 360, 40, 110);
    free_area_2 = this->api->linkCollisionAreaToScreen("free area 2", 410, 370, 110, 40);

    free_area_main_1 = this->api->linkCollisionAreaToScreen("main area 1", 600, 20, 50, 150);
    free_area_main_2 = this->api->linkCollisionAreaToScreen("main area 2", 600, 190, 50, 150);
    free_area_main_3 = this->api->linkCollisionAreaToScreen("main area 3", 600, 360, 50, 150);
    free_area_main_4 = this->api->linkCollisionAreaToScreen("main area 4", 960, 360, 50, 150);

    while (keep){

        while( SDL_PollEvent( event ) != 0 ){

            if( event->type == SDL_KEYDOWN){

                switch( event->key.keysym.sym ){

                        case SDLK_LEFT:
                            x = x-4;
                            break;

                        case SDLK_RIGHT:
                            x = x+5;
                            break;

                       case SDLK_SPACE:
                            show = !show;
                            break;

                       case SDLK_ESCAPE:
                            keep = false;
                            break;

                    }

            }

        }

        this->api->moveImage(bg, 0, 0);

        this->api->moveImage(red, 300, 20);
        this->api->moveImage(white, 330, 190);
        this->api->moveImage(green, 900, 20);
        this->api->moveImage(tux, 900, 190);

        this->api->moveImage(dog, x+20, 20);
        this->api->moveImage(dog, x+20, 190);
        this->api->moveImage(dog, x+20, 360);
        this->api->moveImage(optimus, x+20, 530);
        this->api->moveImage(asimov, 900-x, 530);

        this->api->moveCollisionArea(free_area_main_1, x+600, 20);
        this->api->moveCollisionArea(free_area_main_2, x+600, 190);
        this->api->moveCollisionArea(free_area_main_3, x+600, 360);

        if (show){
            this->api->drawCollisionArea(dog, area_dog);
            this->api->drawCollisionArea(white, area_white_1);
            this->api->drawCollisionArea(white, area_white_2);
            this->api->drawCollisionArea(green, area_green_1);
            this->api->drawCollisionArea(green, area_green_2);
            this->api->drawCollisionArea(tux, area_tux);
            this->api->drawCollisionArea(optimus, area_optimus);
            this->api->drawCollisionArea(asimov, area_asimov);
            this->api->drawCollisionArea(free_area_1);
            this->api->drawCollisionArea(free_area_2);
            this->api->drawCollisionArea(free_area_main_1);
            this->api->drawCollisionArea(free_area_main_2);
            this->api->drawCollisionArea(free_area_main_3);
            this->api->drawCollisionArea(free_area_main_4);
        }

        if (this->api->checkTexturesCollision(red, dog, x+20, 20)){
            this->api->drawSquare(0, 20, 20, 150, 0xE5, 0x00, 0x00);
        }

        if (this->api->checkTextureBindedAreaCollision(dog, x+20, 190, white, area_white_1)){
            this->api->drawSquare(0, 190, 20, 75, 0xCC, 0xCC, 0xCC);
        }

        if (this->api->checkTextureBindedAreaCollision(dog, x+20, 190, white, area_white_2)){
            this->api->drawSquare(0, 265, 20, 75, 0x20, 0x20, 0x20);
        }

        if (this->api->checkAreaCollision(free_area_1, dog, x+20, 360, area_dog)){
            this->api->drawSquare(0, 360, 20, 75, 0xE0, 0xAE, 0x00);
        }

        if (this->api->checkAreaCollision(free_area_2, dog, x+20, 360, area_dog)){
            this->api->drawSquare(0, 435, 20, 75, 0xA0, 0xAE, 0x60);
        }

        if (this->api->checkTextureAreaCollision(green, free_area_main_1)){
            this->api->drawSquare(1180, 20, 20, 150, 0x05, 0xB5, 0x00);
        }

        if (this->api->checkAreaBindAreaCollision(free_area_main_2, tux, area_tux)){
            this->api->drawSquare(1180, 190, 20, 150, 0x00, 0x6C, 0xEF);
        }

        if (this->api->checkAreasCollision(free_area_main_3, free_area_main_4)){
            this->api->drawSquare(1180, 360, 20, 150, 0x32, 0xF4, 0x83);
        }

        if (this->api->checkBindAreasCollision(optimus, area_optimus, asimov, area_asimov)){
            this->api->drawSquare(1180, 530, 20, 150, 0x50, 0x80, 0xA3);
        }


        this->api->refresh();
        this->api->pause(16);

    }

    this->api->terminate();

    cout << "Test 5 - END" << endl;

}


//----------------------------------------------------------------------------

void test::test6(){

    bool keep = true;
    bool show = false;
    SDL_Event* event;
    int walk;
    int walk_frame1 = 0;
    int walk_frame2 = 3;
    int walk_frame3 = 5;
    int walk_frame4 = 5;
    int x1 = (rand() % 1300);
    int x2 = (rand() % 1300);
    int y3 = (rand() % 700);
    int y4 = (rand() % 700);


    cout << "Test 6 - START" << endl << endl;
    cout << "Press <ESC> to exit." << endl;
    cout << "Images & animations have been transformed, only one image & one animation area allocated in memory." << endl << endl;
    cout << "Animations are loaded & reproduced." << endl << endl;

    this->api->configure(1200,700, "window", "Test 6");
    this->api->loadAPI();
    event = this->api->getEventHandler();
    this->api->refresh();

    walk = this->api->deployAnimation("test/lucas_dash.gan");
    this->api->deployImage("test/5.jpg");

    while (keep){

        while( SDL_PollEvent( event ) != 0 ){

            if( event->type == SDL_KEYDOWN){

                switch( event->key.keysym.sym ){

                       case SDLK_SPACE:
                            show = !show;
                            break;

                       case SDLK_ESCAPE:
                            keep = false;
                            break;

                    }

            }

        }

        this->api->clearScreen(0x00, 0x97, 0xbd);

        this->api->moveImage(0, 10, 10);
        this->api->moveImage(0, 1040, 10, 0, 0, nullptr, AGE_FLIPH);
        this->api->moveImage(0, 10, 540, 0, 0, nullptr, AGE_FLIPV);
        this->api->moveImage(0, 1040, 540, 0, 0, nullptr, AGE_FLIPHV);

        walk_frame1 = this->api->moveAnimation(walk, walk_frame1, x1, 190);
        walk_frame2 = this->api->moveAnimation(walk, walk_frame2, x2, 350, 0, nullptr, AGE_FLIPH);
        walk_frame3 = this->api->moveAnimation(walk, walk_frame3, 480, y4, 270, nullptr, AGE_FLIPN);
        walk_frame4 = this->api->moveAnimation(walk, walk_frame4, 660, y3, 90, nullptr, AGE_FLIPN);

        x1 = x1 + 5;
        x2 = x2 - 8;
        y3 = y3 + 6;
        y4 = y4 - 9;

        if(x1>1300){x1 = -60;}
        if(x2<-70){x2 = 1240;}
        if(y3>760){y3 = -60;}
        if(y4<-70){y4 = 750;}

        this->api->refresh();
        this->api->pause(100);

    }

    this->api->terminate();

    cout << "Test 6 - END" << endl;

}


//----------------------------------------------------------------------------

void test::test7(){

    bool keep = true;
    bool opt = true;
    int example = 0;
    SDL_Event* event;
    int font1 = -1;
    int font2 = -1;
    int font3 = -1;
    int font4 = -1;
    int font6 = -1;
    int label11 = -1;
    int label12 = -1;
    int label21 = -1;
    int label22 = -1;
    int label31 = -1;
    int label32 = -1;
    int label41 = -1;
    int label42 = -1;
    int label51 = -1;
    int label52 = -1;
    int labelX1 = -1;
    int labelX2 = -1;
    int labelR1 = -1;
    int labelR2 = -1;
    int labelR3 = -1;
    int labelR4 = -1;
    int labelR5 = -1;
    int labelR6 = -1;
    int labelR7 = -1;
    int labelR8 = -1;
    int labelR9 = -1;

    cout << "Test 7 - START" << endl << endl;
    cout << "Different strings will be displayed" << endl << endl;

    this->api->configure(1200,700, "window", "Test 7");
    this->api->loadAPI();
    event = this->api->getEventHandler();
    this->api->refresh();

    cout << "Loading fonts:" << endl;
    font1 = this->api->deployFont("test/OpenSans-Regular.ttf", 12, "1");
    cout << "OpenSans 12 loaded with id: " << font1 << endl;
    font2 = this->api->deployFont("test/OpenSans-Regular.ttf", 16, "2");
    cout << "OpenSans 16 loaded with id: " << font2 << endl;
    font3 = this->api->deployFont("test/OpenSans-Regular.ttf", 32, "3");
    cout << "OpenSans 32 loaded with id: " << font3 << endl;
    font4 = this->api->deployFont("test/AlexBrush-Regular.ttf", 36, "4");
    cout << "Alex brush 36 loaded with id: " << font4 << endl;
    cout << "Trying to load again OpenSans 12. ID: " << this->api->deployFont("test/OpenSans-Regular.ttf", 12, "1") << endl;
    cout << "Trying to load again Alex brush 15. ID: " << this->api->deployFont("test/AlexBrush-Regular.ttf", 15, "4") << endl << endl;
    font6 = this->api->deployFont("test/AlexBrush-Regular.ttf", 32, "6");
    cout << "Alex brush 32 loaded with id: " << font6 << endl;

    cout << "Deploying labels: "<< endl;
    label11 = this->api->deployLabel("Regular label", font1, AGE_RENDER_N, 200, 250, 230);
    cout << "Label11: " << label11 << endl;
    label12 = this->api->deployLabel("Regular label with border", font1, AGE_RENDER_N, 200, 250, 230, false, 0, 0, 0, 0, true, 0, 140, 232, 56);
    cout << "Label12: " << label12 << endl;

    label21 = this->api->deployLabel("This label also has a border, but with a margin of 7px", font2, AGE_RENDER_N, 20, 20, 20, false, 0, 0, 0, 0, true, 7, 255, 0, 180);
    cout << "Label21: " << label21 << endl;
    label22 = this->api->deployLabel("We are using now a yellow background", font2, AGE_RENDER_N, 20, 20, 20, true, 0, 255, 255, 0);
    cout << "Label22: " << label22 << endl;

    label31 = this->api->deployLabel("Backgrounds also has a margin value. This is 9px", font3, AGE_RENDER_N, 0, 0, 0, true, 9, 150, 0, 255);
    cout << "Label31: " << label31 << endl;
    label32 = this->api->deployLabel("Backgrounds & borders are compatible", font3,AGE_RENDER_N,  0, 0, 0, true, 4, 255, 255, 153, true, 4, 255, 50, 0);
    cout << "Label32: " << label32 << endl;

    label41 = this->api->deployLabel("This label uses a new font & a different color", font4, AGE_RENDER_N, 60, 255, 0, true, 5);
    cout << "Label41: " << label41 << endl;
    label42 = this->api->deployLabel("Press space to change the colors of this label", font4, AGE_RENDER_N, 0, 0, 0, true, 12, 255,255,255,true, 6,0,0,0);
    cout << "Label42: " << label42 << endl;

    label51 = this->api->deployLabel("Labels can rotate, but this is incompatible with borders & backgrounds", font2, AGE_RENDER_N, 120, 255, 75, true, 9, 255, 255, 255);
    cout << "Label51: " << label51 << endl;
    label52 = this->api->deployLabel("But there are no problems with flipping", font2, AGE_RENDER_N, 40, 40, 10, true, 9, 255, 255, 255, true, 7, 0,0,0);
    cout << "Label52: " << label52 << endl;

    labelX1= this->api->deployLabel("An invalid font id where used to create this label, so AGE uses the default font. The next label, uses an invalid label id.", 9999, AGE_RENDER_N, 200, 250, 230);
    cout << "LabelX1: " << labelX1 << " -> " << "This label uses a wrong font" << endl;
    labelX2= 9999999;
    cout << "LabelX2: " << labelX2 << " -> " << "This is a wrong label id" << endl;

    labelR1 = this->api->deployLabel("Press <INTRO> to continue.", font3, AGE_RENDER_N, 120, 255, 75, true, 9, 255, 30, 40);
    labelR2 = this->api->deployLabel("Probably you have noticed the ugly look of the characters.", font6, AGE_RENDER_N, 250, 0, 55, true, 9, 255, 255, 143);
    labelR3 = this->api->deployLabel("That happens because we don't have use any render (AGE_RENDER_N). There are 2 solutions", font6, AGE_RENDER_N, 250, 0, 55, true, 9, 255, 255, 143);
    labelR4 = this->api->deployLabel("First one is use of AGE_RENDER_S, the result is much better.", font6, AGE_RENDER_S, 250, 0, 55, true, 9, 204, 255, 255);
    labelR5 = this->api->deployLabel("The problem is that this method requires more resources and the use of background is mandatory.", font6, AGE_RENDER_S, 250, 0, 55, true, 9, 204, 255, 255);
    labelR6 = this->api->deployLabel("This is the default look of this mode if you don't provide any color for background.", font6, AGE_RENDER_S, 250, 0, 55);
    labelR7 = this->api->deployLabel("The other option is AGE_RENDER_B. It requires even (a little) more resources.", font6, AGE_RENDER_B, 250, 0, 55, true, 9, 255, 193, 255);
    labelR8 = this->api->deployLabel("The good news are that this mode can be used without background.", font6, AGE_RENDER_B, 225, 255, 200);
    labelR9 = this->api->deployLabel("Press <SPACE> to change the looking of this label created with render.", font6, AGE_RENDER_S, 250, 0, 55, true, 9, 255, 193, 255 );

    while (keep){

        while( SDL_PollEvent( event ) != 0 ){

            if( event->type == SDL_KEYDOWN){

                switch( event->key.keysym.sym ){

                    case SDLK_ESCAPE:
                            keep = false;
                            break;

                    case SDLK_RETURN:
                            example = 1;

                    case SDLK_SPACE:

                            opt = not opt;

                            if (opt){

                                this->api->setLabelValue(label42, "Press space to change the colors of this label");
                                this->api->setLabelColor(label42, 0,0,0);
                                this->api->setLabelBg(label42, true, 12, 255,255,255);
                                this->api->setLabelBorder(label42, true, 6,0,0,0);
                                this->api->setLabelColor(labelR9, 0,0,0);
                                this->api->setLabelBg(labelR9, true, 9, 255,255,255);

                            }else{

                                this->api->setLabelValue(label42, "Press space to restore the label to default values");
                                this->api->setLabelColor(label42, 255,255,255);
                                this->api->setLabelBg(label42, true, 12,0,0,0);
                                this->api->setLabelBorder(label42, true, 6,255,255,255);
                                this->api->setLabelColor(labelR9, 250, 0, 55);
                                this->api->setLabelBg(labelR9, true, 9, 255, 193, 255);
                            break;

                    }

                }

            }

        }

        this->api->clearScreen(0x00, 0x97, 0xbd);

        if(example == 0){

            this->api->moveLabel(label11, 30, 10);
            this->api->moveLabel(label12, 30, 50);
            this->api->moveLabel(label21, 30, 90);
            this->api->moveLabel(label22, 30, 140);
            this->api->moveLabel(label31, 30, 190);
            this->api->moveLabel(label32, 30, 280);
            this->api->moveLabel(label41, 30, 380);
            this->api->moveLabel(label42, 30, 480);
            this->api->moveLabel(labelX1, 30, 550);
            this->api->moveLabel(labelX2, 30, 590);
            this->api->moveLabel(label51, 660, 160, 330, nullptr, AGE_FLIPN);
            this->api->moveLabel(label52, 865, 250, 0, nullptr, AGE_FLIPH);
            this->api->moveLabel(labelR1, 790, 650);

        }else{

            this->api->moveLabel(labelR2, 20, 20);
            this->api->moveLabel(labelR3, 20, 70);
            this->api->moveLabel(labelR4, 20, 130);
            this->api->moveLabel(labelR5, 20, 180);
            this->api->moveLabel(labelR6, 20, 230);
            this->api->moveLabel(labelR7, 20, 280);
            this->api->moveLabel(labelR8, 20, 330);
            this->api->moveLabel(labelR9, 20, 530);

        }

        this->api->refresh();
        this->api->pause(33);

    }

    this->api->terminate();

    cout << "Test 7 - END" << endl;

}


//----------------------------------------------------------------------------
