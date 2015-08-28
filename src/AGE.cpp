/****************************************************************************
* Created for: ArcadeBox C
* Dev line: AGE v1
* Creation day: 11/02/2014
* Last change: 27/8/2015
****************************************************************************/


#include "AGE.h"


//---------------------------------------------------------------------------

AGE::AGE(){

    //this->event_handler;

    this->screen_x = 0;
    this->screen_y = 0;
    this->window = nullptr;
    this->window_mode = 0;
    this->window_title = "";
    this->wsurface = nullptr;

    this->animation_index = new AGEAnimationIndex();
    this->area_index = new AGECollisionAreaIndex();
    this->texture_index = new AGETextureListIndex();

    srand((int)this);

}

AGE::~AGE(){

    this->animation_index->freeList();
    this->area_index->freeList();
    this->texture_index->freeList();

}


//---------------------------------------------------------------------------

void AGE::configure(int x, int y, string window_mode, string window_title){

    this->screen_x = x;
    this->screen_y = y;
    this->window_title = window_title;

    if (window_mode == "fullscreen"){
        this->window_mode = SDL_WINDOW_FULLSCREEN;

    }else if(window_mode == "fullscreen_desktop"){
        this->window_mode = SDL_WINDOW_FULLSCREEN_DESKTOP;

    }else if(window_mode == "windowed"){
        this->window_mode = SDL_WINDOW_SHOWN;

    }else{
        this->window_mode = SDL_WINDOW_SHOWN;

    }


}

//---------------------------------------------------------------------------

int AGE::deployAnimation(string src, int x, int y){

    int result = -1;

    result = this->deployAnimation(src);
    this->moveAnimation(result, 0, x, y);

    return result;

}


//---------------------------------------------------------------------------

int AGE::deployAnimation(string src){

    int animation_id = -1;
    string opt;
    int counter;
    bool fail = false;
    AGEAnimationFrameIndex* frames = nullptr;
    string reg;
    string reg_value;
    AGEStringsIndex* strings_index = new AGEStringsIndex();
    Uint8 limiter;
    ifstream animation_file;
    SDL_Texture* temp_texture = nullptr;
    SDL_Surface* temp_surface = nullptr;
    int texture_w = 0;
    int texture_h = 0;

    animation_id = this->animation_index->searchByFile(src);

    //Animation is not registered, this block loads the image and creates the register
    if (animation_id == -1){

        //We search for an available register
        animation_id = this->animation_index->searchByAvailable(true);

        if (this->checkFile(src)){

            //If the file exists we read the animation information
            animation_file.open(src.c_str(), std::ios::in);
            while(getline(animation_file, opt)){

                limiter = opt.find("=", 0);
                if((int)limiter < 255){

                    reg = opt.substr(0, limiter);
                    reg_value = opt.substr(limiter+1);
                    strings_index->setElementData(strings_index->createRegister(reg), reg, reg_value, "");

                }

            }
            animation_file.close();

            frames = new AGEAnimationFrameIndex();
            animation_id = this->animation_index->createRegister(strings_index->getEntry2By1("DESCRIPTION"));
            this->animation_index->setElementData(animation_id,
                                                  frames,
                                                  strings_index->getEntry2By1("FILE").c_str(),
                                                  strings_index->getEntry2By1("DESCRIPTION").c_str(),
                                                  atoi(strings_index->getEntry2By1("BGCOLOR1").c_str()),
                                                  atoi(strings_index->getEntry2By1("BGCOLOR2").c_str()),
                                                  atoi(strings_index->getEntry2By1("BGCOLOR3").c_str()),
                                                  atoi(strings_index->getEntry2By1("IMAGES").c_str()),
                                                  atoi(strings_index->getEntry2By1("INIT").c_str())
                                                  );

            temp_surface = IMG_Load(strings_index->getEntry2By1("FILE").c_str());
            SDL_SetColorKey(temp_surface, SDL_TRUE, SDL_MapRGB(temp_surface->format, this->animation_index->getBgcolor1(animation_id), this->animation_index->getBgcolor2(animation_id), this->animation_index->getBgcolor3(animation_id)));
            temp_texture = SDL_CreateTextureFromSurface(this->renderer, temp_surface);
            SDL_FreeSurface(temp_surface);
            SDL_QueryTexture(temp_texture, nullptr, nullptr, &texture_w, &texture_h);
            this->animation_index->setTexture(animation_id, temp_texture);
            this->animation_index->setTexture_w(animation_id, texture_w);
            this->animation_index->setTexture_h(animation_id, texture_h);

            counter = 0;
            while(counter < atoi(strings_index->getEntry2By1("IMAGES").c_str()) ){

                frames->createRegister(strings_index->getEntry2By1("DESCRIPTION") + " - " + this->itos(counter));
                frames->setElementData(counter,
                                       atoi(strings_index->getEntry2By1("IMAGE" +  this->itos(counter+1) + "X").c_str()),
                                       atoi(strings_index->getEntry2By1("IMAGE" +  this->itos(counter+1) + "Y").c_str()),
                                       atoi(strings_index->getEntry2By1("IMAGE" +  this->itos(counter+1) + "W").c_str()),
                                       atoi(strings_index->getEntry2By1("IMAGE" +  this->itos(counter+1) + "H").c_str()),
                                       atoi(strings_index->getEntry2By1("IMAGE" +  this->itos(counter+1) + "D").c_str())
                                       );
                counter++;

            }

        //If the file is not valid, we return an invalid id
        }else{
            animation_id = -1;

        }

    //Animation was loaded previously, so the available flag is set to 'false' to avoid animation unload
    }else{
        this->animation_index->setAvailable(animation_id, false);

    }


    delete(strings_index);

    return animation_id;

}


//---------------------------------------------------------------------------

int AGE::deployImage(string src){

    SDL_Texture* temp_texture = nullptr;
    SDL_Surface* temp_surface = nullptr;
    int image_id = -1;

    image_id = this->texture_index->searchBySrc(src);

    //Image is not registered, this block loads the image and creates the register
    if (image_id == -1){

        //We search for an available register
        image_id = this->texture_index->searchByAvailable(true);

        if (this->checkFile(src)){

            temp_surface = IMG_Load(src.c_str());
            temp_texture = SDL_CreateTextureFromSurface(this->renderer, temp_surface);
            SDL_FreeSurface(temp_surface);

            //If we need to create a new register (there are not available registers)
            if(image_id == -1){
                image_id = this->texture_index->createRegister(src);

            //if we have found an available register for the new image
            }else{
                SDL_DestroyTexture(this->texture_index->getTexture(image_id));
                this->texture_index->setSrc(image_id, src);
            }

            this->texture_index->setTexture(image_id, temp_texture);

        //If the file is not valid, we return an invalid id
        }else{
            image_id = -1;

        }

    //Image was loaded previously, so the available flag is set to 'false' to avoid image unload
    }else{
        this->texture_index->setAvailable(image_id, false);

    }

    return image_id;

}


int AGE::deployImage(string src, int x, int y){

    int image_id = -1;

    image_id = this->deployImage(src);
    this->moveImage(image_id, x, y);

    return image_id;


}


//---------------------------------------------------------------------------

void AGE::moveCollisionArea(int id, int x, int y){

    this->area_index->setPosition(id, x, y);

}


//---------------------------------------------------------------------------

void AGE::moveBindCollisionArea(int texture_id, int area_id, int x, int y){

    this->texture_index->getElementById(texture_id)->getAreaIndex()->setPosition(area_id, x, y);

}

//---------------------------------------------------------------------------

int AGE::moveAnimation(int animation_id, int frame_id, int x, int y){

    AGEAnimationElement* animation;
    AGEAnimationFrameElement* frame;
    SDL_Texture* texture;
    bool available = false;
    int w;
    int h;
    int next = -1;

    animation = this->animation_index->getElementById(animation_id);
    available = this->animation_index->getAvailable(animation_id);
    texture = animation->getTexture();

    if ((texture == nullptr) || (animation == nullptr) || (available == true)){

        this->applyImage(this->missing_image, x, y, API_IMAGES_MISSINGIMAGEFILE_W, API_IMAGES_MISSINGIMAGEFILE_H);
        next = -1;

    }else{

        frame = animation->getFrames()->getElementById(frame_id);

        this->applyAnimation(texture, x, y, frame->getImage_x(), frame->getImage_y(), frame->getImage_w(), frame->getImage_h());

        if(frame->getNext() == nullptr){
            next = animation->getInit();

        }else{
            next = frame->getNext()->getId();

        }

   }

    return next;

}


//---------------------------------------------------------------------------

void AGE::moveImage(int id, int x, int y, double angle, SDL_Point* center, SDL_RendererFlip flip){

    SDL_Texture* texture;
    bool available = false;
    int w;
    int h;

    texture = this->texture_index->getTexture(id);
    available = this->texture_index->getAvailable(id);

    if ((texture == nullptr) || (available == true)){
        this->applyImage(this->missing_image, x, y, API_IMAGES_MISSINGIMAGEFILE_W, API_IMAGES_MISSINGIMAGEFILE_H);

    }else{
        w = this->texture_index->getTextureW(id);
        h = this->texture_index->getTextureH(id);

        if((angle == 0.0) && (center == NULL) && (flip == AGE_FLIPN)){
            this->applyImage(texture, x, y, w, h);

        }else{
            this->applyImage(texture, x, y, w, h, angle, center, flip);

        }

        this->texture_index->setPosition(id, x, y);

    }

}


//---------------------------------------------------------------------------

void AGE::applyImage(SDL_Texture* texture, int x, int y, int w, int h){

    SDL_Rect image_rect;
    image_rect.x = 0;
    image_rect.y = 0;
    image_rect.h = h;
    image_rect.w = w;

    SDL_Rect destination_rect;
    destination_rect.x = x;
    destination_rect.y = y;
    destination_rect.h = h;
    destination_rect.w = w;

    SDL_RenderCopy(this->renderer, texture, &image_rect, &destination_rect);

}


//---------------------------------------------------------------------------

void AGE::applyImage(SDL_Texture* texture, int x, int y, int w, int h, double angle, SDL_Point* center, SDL_RendererFlip flip){

    SDL_Rect image_rect;
    image_rect.x = 0;
    image_rect.y = 0;
    image_rect.h = h;
    image_rect.w = w;

    SDL_Rect destination_rect;
    destination_rect.x = x;
    destination_rect.y = y;
    destination_rect.h = h;
    destination_rect.w = w;

    SDL_RenderCopyEx(this->renderer, texture, &image_rect, &destination_rect, angle, center, flip);

}


//---------------------------------------------------------------------------

void AGE::applyAnimation(SDL_Texture* texture, int x, int y, int cut_x, int cut_y, int cut_w, int cut_h){

    SDL_Rect image_rect;
    image_rect.x = cut_x;
    image_rect.y = cut_y;
    image_rect.h = cut_h;
    image_rect.w = cut_w;

    SDL_Rect destination_rect;
    destination_rect.x = x;
    destination_rect.y = y;
    destination_rect.h = cut_h;
    destination_rect.w = cut_w;

    SDL_RenderCopy(this->renderer, texture, &image_rect, &destination_rect);

}


//---------------------------------------------------------------------------

void AGE::loadAPI(){

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //start SDL_image
    IMG_Init( IMG_INIT_PNG | IMG_INIT_PNG );

    //Set up window
    this->window = SDL_CreateWindow(this->window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->screen_x, this->screen_y, this->window_mode);
    this->wsurface = SDL_GetWindowSurface(this->window);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface* temp_surface = IMG_Load(API_IMAGES_MISSINGIMAGEFILE_SRC.c_str());
    this->missing_image = SDL_CreateTextureFromSurface(this->renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

}


//---------------------------------------------------------------------------

void AGE::pause(int miliseconds){

    SDL_Delay(miliseconds);

}


//---------------------------------------------------------------------------

void AGE::terminate()
{

    this->animation_index->freeList();
    this->area_index->freeList();
    this->texture_index->freeList();

    SDL_DestroyWindow(this->window);
    SDL_Quit();

}


//---------------------------------------------------------------------------

void AGE::refresh(){

    SDL_RenderPresent(this->renderer);

}


//---------------------------------------------------------------------------

AGETextureListIndex* AGE::getTextureIndex(){

    return this->texture_index;

}


//---------------------------------------------------------------------------

bool AGE::checkFile(string src){

    bool result = false;

    if( access( src.c_str(), F_OK ) != -1 ) {
        result = true;
    }

    return result;

}


//---------------------------------------------------------------------------

void AGE::clearScreen(){

    this->clearScreen(0x00, 0x00, 0x00);

}


//---------------------------------------------------------------------------

void AGE::clearScreen(Uint8 color1, Uint8 color2, Uint8 color3){

    SDL_SetRenderDrawColor(this->renderer, color1, color2, color3, 255);
    SDL_RenderClear(this->renderer);

}


//---------------------------------------------------------------------------

void AGE::freeImage(int id){

    this->texture_index->setAvailable(id, true);

}

//---------------------------------------------------------------------------

void AGE::deleteImage(int id){

    this->texture_index->setAvailable(id, true);
    SDL_DestroyTexture(this->texture_index->getTexture(id));
    this->texture_index->setTexture(id, nullptr);

}


//---------------------------------------------------------------------------

void AGE::drawSquare(int x1, int y1, int x2, int y2, int color1, int color2, int color3){

    this->drawSquare(x1, y1, x2, y2, color1, color2, color3, 0xFF);

}


//---------------------------------------------------------------------------

void AGE::drawSquare(int x1, int y1, int x2, int y2, int color1, int color2, int color3, int alpha){

    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
    SDL_Rect fillRect = { x1, y1, x2, y2};
    SDL_SetRenderDrawColor( this->renderer, color1, color2, color3, alpha);
    SDL_RenderFillRect( this->renderer, &fillRect );
    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_NONE);

}


//---------------------------------------------------------------------------

void AGE::drawLine(int x1, int y1, int x2, int y2, int color1, int color2, int color3){

    SDL_SetRenderDrawColor( this->renderer, color1, color2, color3, 255);
    SDL_RenderDrawLine(this->renderer, x1, y1, x2, y2);

}


//---------------------------------------------------------------------------

void AGE::fadeScreen(int alpha){

    this->drawSquare(0, 0, this->screen_x, this->screen_y, 0, 0, 0, alpha);

}


//---------------------------------------------------------------------------

SDL_Event* AGE::getEventHandler(){

    return &this->event_handler;

}

//---------------------------------------------------------------------------

bool AGE::checkAreaCollision(int area_id1, int texture_id, int area_id2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->area_index->getArea(area_id1);
    area2 = this->texture_index->getElementById(texture_id)->getAreaIndex()->getArea(area_id2);

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkAreaCollision(int area_id1, int texture_id, int x, int y, int area_id2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->area_index->getArea(area_id1);
    area2 = this->texture_index->getElementById(texture_id)->getAreaIndex()->getArea(area_id2);

    area2.x = x + area2.x;
    area2.y = y + area2.y;

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTextureBindedAreaCollision(int texture_id1, int texture_id2, int area_id){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(texture_id1);
    area2 = this->texture_index->getElementById(texture_id2)->getAreaIndex()->getArea(area_id);

    area2.x = area2.x + this->texture_index->getElementById(texture_id2)->getPositionX();
    area2.y = area2.x + this->texture_index->getElementById(texture_id2)->getPositionY();

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTextureBindedAreaCollision(int texture_id1, int x1, int y1, int texture_id2, int area_id){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(texture_id1);
    area2 = this->texture_index->getElementById(texture_id2)->getAreaIndex()->getArea(area_id);

    area1.x = x1;
    area1.y = y1;
    area2.x = area2.x + this->texture_index->getElementById(texture_id2)->getPositionX();
    area2.y = area2.y + this->texture_index->getElementById(texture_id2)->getPositionY();

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTextureBindedAreaCollision(int texture_id1, int x1, int y1, int texture_id2, int x2, int y2, int area_id){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(texture_id1);
    area2 = this->texture_index->getElementById(texture_id2)->getAreaIndex()->getArea(area_id);

    area1.x = x1;
    area1.y = y1;
    area2.x = x2 + area2.x + this->texture_index->getElementById(texture_id2)->getPositionX();
    area2.y = y2 + area2.y + this->texture_index->getElementById(texture_id2)->getPositionY();

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTexturesCollision(int id1, int id2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(id1);
    area2 = this->texture_index->getCollisionRect(id2);

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTexturesCollision(int id1, int id2, int x2, int y2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(id1);
    area2 = this->texture_index->getCollisionRect(id2);

    area2.x = x2;
    area2.y = y2;

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTexturesCollision(int id1, int x1, int y1, int id2, int x2, int y2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(id1);
    area2 = this->texture_index->getCollisionRect(id2);

    area1.x = x1;
    area1.y = y1;
    area2.x = x2;
    area2.y = y2;

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkTextureAreaCollision(int id_texture, int id_area){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getCollisionRect(id_texture);
    area2 = this->area_index->getArea(id_area);

    result = this->checkCollision(area1, area2);

    return result;

}

//---------------------------------------------------------------------------

bool AGE::checkAreaBindAreaCollision(int area_id1, int texture_id, int area_id2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->area_index->getArea(area_id1);
    area2 = this->texture_index->getElementById(texture_id)->getAreaIndex()->getArea(area_id2);
    area2.x = area2.x + this->texture_index->getElementById(texture_id)->getPositionX();
    area2.y = area2.y + this->texture_index->getElementById(texture_id)->getPositionY();

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkAreasCollision(int area_id1, int area_id2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->area_index->getArea(area_id1);
    area2 = this->area_index->getArea(area_id2);

    result = this->checkCollision(area1, area2);

    return result;

}

//---------------------------------------------------------------------------

bool AGE::checkBindAreasCollision(int texture_id1, int area_id1, int texture_id2, int area_id2){

    bool result = false;
    SDL_Rect area1;
    SDL_Rect area2;

    area1 = this->texture_index->getElementById(texture_id1)->getAreaIndex()->getArea(area_id1);
    area2 = this->texture_index->getElementById(texture_id2)->getAreaIndex()->getArea(area_id2);
    area1.x = area1.x + this->texture_index->getElementById(texture_id1)->getPositionX();
    area1.y = area1.y + this->texture_index->getElementById(texture_id1)->getPositionY();
    area2.x = area2.x + this->texture_index->getElementById(texture_id2)->getPositionX();
    area2.y = area2.y + this->texture_index->getElementById(texture_id2)->getPositionY();

    result = this->checkCollision(area1, area2);

    return result;

}


//---------------------------------------------------------------------------

bool AGE::checkCollision(SDL_Rect area1, SDL_Rect area2){

    bool result = false;
    int diff_x;
    int diff_y;

    diff_x = area1.x - area2.x;
    diff_y = area1.y - area2.y;

    if(((diff_x >= -area1.w) && (diff_x <= area2.w)) && ((diff_y >= -area1.h) && (diff_y <= area2.h))){
        result = true;

    }

    return result;


}


//---------------------------------------------------------------------------

int AGE::linkCollisionAreaToTexture(int id, string tag, int x, int y, int w, int h){

    int result = -1;
    int color1 = (rand() % 160) + 50;
    int color2 = (rand() % 160) + 50;
    int color3 = (rand() % 160) + 50;

    result = this->linkCollisionAreaToTexture(id, tag, x, y, w, h, color1, color2, color3);

    return result;

}


//---------------------------------------------------------------------------

int AGE::linkCollisionAreaToTexture(int id, string tag, int x, int y, int w, int h, int color1, int color2, int color3){

    int result = -1;
    SDL_Rect area;

    area.x = x;
    area.y = y;
    area.w = w;
    area.h = h;

    result = this->texture_index->linkCollisionArea(id, area, tag, color1, color2, color3);

    return result;

}

//---------------------------------------------------------------------------

int AGE::linkCollisionAreaToScreen(string tag, int x, int y, int w, int h){

    int result = -1;
    int color1 = (rand() % 160) + 50;
    int color2 = (rand() % 160) + 50;
    int color3 = (rand() % 160) + 50;

    result = this->linkCollisionAreaToScreen(tag, x, y, w, h, color1, color2, color3);

    return result;

}


//---------------------------------------------------------------------------

int AGE::linkCollisionAreaToScreen(string tag, int x, int y, int w, int h, int color1, int color2, int color3){

    int result = -1;
    SDL_Rect area;

    area.x = x;
    area.y = y;
    area.w = w;
    area.h = h;

    result = this->area_index->createRegister(tag);
    this->area_index->setArea(result, area);
    this->area_index->setColor1(result, color1);
    this->area_index->setColor2(result, color2);
    this->area_index->setColor3(result, color3);

    return result;

}


//---------------------------------------------------------------------------

void AGE::drawCollisionArea(int id_texture, int id_area){

    AGETextureListElement* texture;
    AGECollisionAreaElement* area;

    if ((id_texture >= 0) && (id_texture >= 0)){

        texture = this->texture_index->getElementById(id_texture);
        if (texture != nullptr){

            area = texture->getAreaIndex()->getElementById(id_area);

            if (area != nullptr){

                this->drawCollisionArea(area, texture->getPositionX(), texture->getPositionY());

            }

        }

    }

}


//---------------------------------------------------------------------------


void AGE::drawCollisionArea(int id){

    AGECollisionAreaElement* area;

    if (id >= 0){

        area = this->area_index->getElementById(id);

        if (area != nullptr){

            this->drawCollisionArea(area, 0, 0);

        }

    }

}


//---------------------------------------------------------------------------

void AGE::drawCollisionArea(AGECollisionAreaElement* area, int mod_x, int mod_y){


            this->drawSquare(mod_x + area->getArea().x,
                             mod_y + area->getArea().y,
                             area->getArea().w,
                             area->getArea().h,
                             area->getColor1(),
                             area->getColor2(),
                             area->getColor3(),
                             110
                             );

            this->drawLine(mod_x + area->getArea().x,
                           mod_y + area->getArea().y,
                           mod_x + area->getArea().x + area->getArea().w,
                           mod_y + area->getArea().y,
                           area->getColor1(),
                           area->getColor2(),
                           area->getColor3()
                           );

            this->drawLine(mod_x + area->getArea().x,
                           mod_y + area->getArea().y + area->getArea().h,
                           mod_x + area->getArea().x + area->getArea().w,
                           mod_y + area->getArea().y + area->getArea().h,
                           area->getColor1(),
                           area->getColor2(),
                           area->getColor3()
                           );

            this->drawLine(mod_x + area->getArea().x,
                           mod_y + area->getArea().y,
                           mod_x + area->getArea().x,
                           mod_y + area->getArea().y + area->getArea().h,
                           area->getColor1(),
                           area->getColor2(),
                           area->getColor3()
                           );

            this->drawLine(mod_x + area->getArea().x + area->getArea().w,
                           mod_y + area->getArea().y,
                           mod_x + area->getArea().x + area->getArea().w,
                           mod_y + area->getArea().y + area->getArea().h,
                           area->getColor1(),
                           area->getColor2(),
                           area->getColor3()
                           );

}


//---------------------------------------------------------------------------

string AGE::itos(int number){

    stringstream ss;
    ss << number;

    return ss.str();

}


//---------------------------------------------------------------------------
