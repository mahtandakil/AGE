/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 24/08/2015
****************************************************************************/


#include "test.h"

//----------------------------------------------------------------------------

test::test(int id){

    this->api = new AGE();

    cout << "AGE Test" << endl;
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
            cout << "Test 1: Six files are loaded and one is a missing file" << endl;
            cout << "Test 2: Memory manage & dynamic load system form images" << endl;
            cout << "Test 3: Fade screen & drawsquare function" << endl;
            cout << "Test 4: Moving an image to check collisions" << endl;
            cout << "Test 5: Area collision system example" << endl;
            cout << "Test 6: Animation system example" << endl;
            cout << "Test 7: Collision point system example" << endl;

//            cout << "Test 7: AGE button example" << endl;
//            cout << "Test 8: Music & FX" << endl;
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

    cout << "Test 4 - START" << endl << endl;
    cout << "Press keys to move, left click to control with mouse" << endl << endl;

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
    cout << "Move elements to check collision system. Press SPACE to show/hide collision areas" << endl << endl;

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


    cout << "Test 6 - START" << endl << endl;
    cout << "Animations are loaded & reproduced. Press button 'A' for attack and check collisions." << endl << endl;

    this->api->configure(1200,700, "window", "Test 6");
    this->api->loadAPI();
    event = this->api->getEventHandler();
    this->api->refresh();

    this->api->terminate();

    cout << "Test 6 - END" << endl;

}


//----------------------------------------------------------------------------

void test::test7(){

    bool keep = true;
    bool show = false;
    SDL_Event* event;

    cout << "Test 7 - START" << endl << endl;
    cout << "?????????????????" << endl << endl;

    this->api->configure(1200,700, "window", "Test 7");
    this->api->loadAPI();
    event = this->api->getEventHandler();
    this->api->refresh();

    this->api->terminate();

    cout << "Test 7 - END" << endl;

}

//----------------------------------------------------------------------------
