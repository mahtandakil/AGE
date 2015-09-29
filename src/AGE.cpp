/****************************************************************************
* Created for: ArcadeBox C
* Dev line: AGE v1
* Creation day: 11/02/2014
* Last change: 28/09/2015
****************************************************************************/


#include "AGE.h"


//---------------------------------------------------------------------------

AGE::AGE(){

    //this->event_handler;

    this->missing_font = nullptr;
    this->missing_image = nullptr;
    this->screen_x = 0;
    this->screen_y = 0;
    this->window = nullptr;
    this->window_mode = 0;
    this->window_title = "";
    this->wsurface = nullptr;

    this->animation_index = new AGEAnimationIndex();
    this->area_index = new AGECollisionAreaIndex();
    this->font_index = new AGEFontIndex();
    this->labelttf_index = new AGELabelTTFIndex();
    this->string_index = new AGEStringsIndex();
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

    }else if(window_mode == "maximized"){
        this->window_mode = SDL_WINDOW_MAXIMIZED;

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


int AGE::deployAnimation(string src){

    int animation_id = -1;
    string opt;
    int counter;
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

            temp_surface = IMG_Load(strings_index->getEntry2By1("FILE").c_str());

            if(temp_surface != nullptr){

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

                SDL_SetColorKey(temp_surface, SDL_TRUE, SDL_MapRGB(temp_surface->format, this->animation_index->getBgcolor1(animation_id), this->animation_index->getBgcolor2(animation_id), this->animation_index->getBgcolor3(animation_id)));
                temp_texture = SDL_CreateTextureFromSurface(this->renderer, temp_surface);
                SDL_QueryTexture(temp_texture, nullptr, nullptr, &texture_w, &texture_h);
                this->animation_index->setTexture(animation_id, temp_texture);
                this->animation_index->setTexture_w(animation_id, texture_w);
                this->animation_index->setTexture_h(animation_id, texture_h);
                this->animation_index->setSurface(animation_id, temp_surface);

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

            //If we need to create a new register (there are not available registers)
            if(image_id == -1){
                image_id = this->texture_index->createRegister(src);

            //if we have found an available register for the new image
            }else{
                SDL_DestroyTexture(this->texture_index->getTexture(image_id));
                SDL_FreeSurface(this->texture_index->getSurface(image_id));
                this->texture_index->setSrc(image_id, src);
            }

            this->texture_index->setTexture(image_id, temp_texture);
            this->texture_index->setSurface(image_id, temp_surface);

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

int AGE::deployLabel(string value, int font_id, Uint8 render, Uint8 color1, Uint8 color2, Uint8 color3, bool background, Uint8 bg_margin, Uint8 bg_color1, Uint8 bg_color2, Uint8 bg_color3, bool border, Uint8 border_margin, Uint8 border_color1, Uint8 border_color2, Uint8 border_color3){

    SDL_Texture* temp_texture = nullptr;
    int label_id = -1;
    string tag = "";
    TTF_Font* font = nullptr;
    SDL_Color label_color;
    SDL_Color bg_color;

    tag = value + "-" + this->font_index->getTag(font_id);
    label_id = this->labelttf_index->searchByTag(tag);

    //Label is not registered, this block loads the image and creates the register
    if (label_id == -1){

        //We get the font, if it don't exists, the default font will be used
        font = this->font_index->getFont(font_id);
        if(font == nullptr){
            font = this->missing_font;

        }

        label_color.r = color1;
        label_color.g = color2;
        label_color.b = color3;
        label_color.a = 255;
        bg_color.r = bg_color1;
        bg_color.g = bg_color2;
        bg_color.b = bg_color3;
        bg_color.a = 255;

        //We search for an available register
        label_id = this->labelttf_index->searchByAvailable(true);

        temp_texture = this->renderTTF(font, value, label_color, bg_color, render);

        //If we need to create a new register (there are not available registers)
        if(label_id == -1){
            label_id = this->labelttf_index->createRegister(tag);

        //if we have found an available register for the new image
        }else{
            SDL_DestroyTexture(this->labelttf_index->getTexture(label_id));

        }

        this->labelttf_index->setTexture(label_id, temp_texture);
        this->labelttf_index->setFont_color1(label_id, color1);
        this->labelttf_index->setFont_color1(label_id, color2);
        this->labelttf_index->setFont_color1(label_id, color3);
        this->labelttf_index->setBg(label_id, background);
        this->labelttf_index->setBg_margin(label_id, bg_margin);
        this->labelttf_index->setBg_color1(label_id, bg_color1);
        this->labelttf_index->setBg_color2(label_id, bg_color2);
        this->labelttf_index->setBg_color3(label_id, bg_color3);
        this->labelttf_index->setBorder(label_id, border);
        this->labelttf_index->setBorder_margin(label_id, border_margin);
        this->labelttf_index->setBorder_color1(label_id, border_color1);
        this->labelttf_index->setBorder_color2(label_id, border_color2);
        this->labelttf_index->setBorder_color3(label_id, border_color3);
        this->labelttf_index->setModified(label_id, false);
        this->labelttf_index->setFont(label_id, font_id);
        this->labelttf_index->setRender(label_id, render);
        this->labelttf_index->setContent(label_id, value);


    //Label was created previously, so the available flag is set to 'false' to avoid label unload
    }else{
        this->labelttf_index->setAvailable(label_id, false);

    }

    return label_id;

}


//---------------------------------------------------------------------------

int AGE::deployFont(string src, int font_size, string mod){

    TTF_Font *temp_font = nullptr;
    int font_id = -1;
    string tag = "";

    tag = src + " - " + this->itos(font_size) + " - " + mod;
    font_id = this->font_index->searchByTag(tag);

    //Font is not registered, this block loads the font and creates the register
    if (font_id == -1){

        //We search for an available register
        font_id = this->font_index->searchByAvailable(true);

        if (this->checkFile(src)){

            temp_font =  TTF_OpenFont(src.c_str(), font_size);

            //If we need to create a new register (there are not available registers)
            if(font_id == -1){
                font_id = this->font_index->createRegister(src);

            //if we have found an available register for the new image
            }else{
                TTF_CloseFont(this->font_index->getFont(font_id));

            }

            this->font_index->setSrc(font_id, src);
            this->font_index->setTag(font_id, tag);
            this->font_index->setFont(font_id, temp_font);

        //If the file is not valid, we return an invalid id
        }else{
            font_id = -1;

        }



    //font was loaded previously, so the available flag is set to 'false' to avoid image unload
    }else{
        this->font_index->setAvailable(font_id, false);

    }

    return font_id;

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

int AGE::moveAnimation(int animation_id, int frame_id, int x, int y, double angle, SDL_Point* center, SDL_RendererFlip flip){

    AGEAnimationElement* animation;
    AGEAnimationFrameElement* frame;
    SDL_Texture* texture;
    bool available = false;
    int next = -1;

    animation = this->animation_index->getElementById(animation_id);
    available = this->animation_index->getAvailable(animation_id);
    texture = animation->getTexture();

    if ((texture == nullptr) || (animation == nullptr) || (available == true)){

        this->applyImage(this->missing_image, x, y, API_IMAGES_MISSINGIMAGEFILE_W, API_IMAGES_MISSINGIMAGEFILE_H);
        next = -1;

    }else{

        frame = animation->getFrames()->getElementById(frame_id);

        if((angle == 0.0) && (center == NULL) && (flip == AGE_FLIPN)){
            this->applyAnimation(texture, x, y, frame->getImage_x(), frame->getImage_y(), frame->getImage_w(), frame->getImage_h());

        }else{
            this->applyAnimation(texture, x, y, frame->getImage_x(), frame->getImage_y(), frame->getImage_w(), frame->getImage_h(), angle, center, flip);

        }

        if(frame->getNext() == nullptr){
            next = animation->getInit();

        }else{
            next = frame->getNext()->getId();

        }

   }

    return next;

}


//---------------------------------------------------------------------------

void AGE::moveImage(int id, int x, int y, double size_mod, double angle, SDL_Point* center, SDL_RendererFlip flip){

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

        if((angle == 0.0) && (size_mod == 0.0) && (center == NULL) && (flip == AGE_FLIPN)){
            this->applyImage(texture, x, y, w, h);

        }else{
            this->applyImage(texture, x, y, w, h, size_mod, angle, center, flip);

        }

        this->texture_index->setPosition(id, x, y);

    }

}


//---------------------------------------------------------------------------

void AGE::moveLabel(int label_id, int x, int y,  double angle, SDL_Point* center, SDL_RendererFlip flip){

    SDL_Texture* texture = nullptr;
    SDL_Color label_color;
    SDL_Color bg_color;
    bool available = false;
    int w;
    int h;
    int margin = 0;

    texture = this->labelttf_index->getTexture(label_id);
    available = this->labelttf_index->getAvailable(label_id);

    if ((texture == nullptr) || (available == true)){
        this->applyImage(this->missing_image, x, y, API_IMAGES_MISSINGIMAGEFILE_W, API_IMAGES_MISSINGIMAGEFILE_H);

    }else{

        if(this->labelttf_index->getModified(label_id)){

            label_color.r = this->labelttf_index->getFont_color1(label_id);
            label_color.g = this->labelttf_index->getFont_color2(label_id);
            label_color.b = this->labelttf_index->getFont_color3(label_id);
            label_color.a = 255;
            bg_color.r = this->labelttf_index->getBg_color1(label_id);
            bg_color.g = this->labelttf_index->getBg_color2(label_id);
            bg_color.b = this->labelttf_index->getBg_color3(label_id);
            bg_color.a = 255;

            texture = this->labelttf_index->getTexture(label_id);
            SDL_DestroyTexture(texture);
            texture = this->renderTTF(this->font_index->getFont(this->labelttf_index->getFont(label_id)),
                                      this->labelttf_index->getContent(label_id),
                                      label_color,
                                      bg_color,
                                      this->labelttf_index->getRender(label_id)
                                      );
            this->labelttf_index->setTexture(label_id, texture);
            this->labelttf_index->setModified(label_id, false);



        }

        SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

        if(angle == 0.0){

            if (this->labelttf_index->getBg(label_id)){

                margin = this->labelttf_index->getBg_margin(label_id);
                this->drawSquare(x-margin, y-margin, w+(margin*2), h+(margin*2), this->labelttf_index->getBg_color1(label_id), this->labelttf_index->getBg_color2(label_id), this->labelttf_index->getBg_color3(label_id));

            }

            if (this->labelttf_index->getBorder(label_id)){

                margin = this->labelttf_index->getBorder_margin(label_id);
                this->drawSquareBorder(x-margin, y-margin, w+(margin*2), h+(margin*2), this->labelttf_index->getBorder_color1(label_id), this->labelttf_index->getBorder_color2(label_id), this->labelttf_index->getBorder_color3(label_id));

            }

            this->applyImage(texture, x, y, w, h, 1, angle, center, flip);

        }else{
            this->applyImage(texture, x, y, w, h, 1, angle, center, flip);

        }

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

void AGE::applyImage(SDL_Texture* texture, int x, int y, int w, int h, double size_mod, double angle, SDL_Point* center, SDL_RendererFlip flip){

    SDL_Rect image_rect;
    image_rect.x = 0;
    image_rect.y = 0;
    image_rect.h = h;
    image_rect.w = w;

    SDL_Rect destination_rect;
    destination_rect.x = x;
    destination_rect.y = y;
    destination_rect.h = h*size_mod;
    destination_rect.w = w*size_mod;

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

void AGE::applyAnimation(SDL_Texture* texture, int x, int y, int cut_x, int cut_y, int cut_w, int cut_h, double angle, SDL_Point* center, SDL_RendererFlip flip){

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

    SDL_RenderCopyEx(this->renderer, texture, &image_rect, &destination_rect, angle, center, flip);

}


//---------------------------------------------------------------------------

void AGE::loadAPI(){

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );

    //start SDL_image
    IMG_Init( IMG_INIT_PNG | IMG_INIT_PNG );

    //start SDL_ttf
    TTF_Init();

    //Set up window
    this->window = SDL_CreateWindow(this->window_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->screen_x, this->screen_y, this->window_mode);
    this->wsurface = SDL_GetWindowSurface(this->window);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface* temp_surface = IMG_Load(API_IMAGES_MISSINGIMAGEFILE_SRC.c_str());
    this->missing_image = SDL_CreateTextureFromSurface(this->renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    this->missing_font = TTF_OpenFont(AGE_FONT_SRC.c_str(), AGE_FONT_SIZE);

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
    this->font_index->freeList();
    this->string_index->freeList();
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

bool AGE::createFile(string file_src, string content){

    bool result = false;

    ofstream file(file_src);
    file << content;
    file.close();

    result = this->checkFile(file_src);

    return result;

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
    SDL_FreeSurface(this->texture_index->getSurface(id));
    this->texture_index->setTexture(id, nullptr);

}


//---------------------------------------------------------------------------

void AGE::drawSquare(int x, int y, int w, int h, int color1, int color2, int color3){

    this->drawSquare(x, y, w, h, color1, color2, color3, 0xFF);

}


//---------------------------------------------------------------------------

void AGE::drawSquare(int x, int y, int w, int h, int color1, int color2, int color3, int alpha){

    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
    SDL_Rect fillRect = { x, y, w, h};
    SDL_SetRenderDrawColor( this->renderer, color1, color2, color3, alpha);
    SDL_RenderFillRect( this->renderer, &fillRect );
    SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_NONE);

}


//---------------------------------------------------------------------------

void AGE::drawSquareBorder(int x, int y, int w, int h, int color1, int color2, int color3){

            this->drawLine(x, y, x+w, y, color1, color2, color3);
            this->drawLine(x, y, x, y+h, color1, color2, color3);
            this->drawLine(x+w, y+h, x+w, y, color1, color2, color3);
            this->drawLine(x+w, y+h, x, y+h, color1, color2, color3);

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


//------------------- --------------------------------------------------------

int AGE::setLabelValue(int label_id, string value){

    int result = -1;

    if ((this->labelttf_index->getId(label_id) == label_id) and (label_id >= 0)){

        this->labelttf_index->setContent(label_id, value);
        this->labelttf_index->setModified(label_id, true);
        result = this->labelttf_index->getId(label_id);

    }else{
        result = -1;

    }

    return result;

}

//------------------- --------------------------------------------------------

int AGE::setLabelColor(int label_id, Uint8 color1, Uint8 color2, Uint8 color3){

    int result = -1;

    if ((this->labelttf_index->getId(label_id) == label_id) or (label_id >= 0)){

        this->labelttf_index->setFont_color1(label_id, color1);
        this->labelttf_index->setFont_color2(label_id, color2);
        this->labelttf_index->setFont_color3(label_id, color3);
        this->labelttf_index->setModified(label_id, true);
        result = this->labelttf_index->getId(label_id);

    }else{
        result = -1;

    }

    return result;

}


//------------------- --------------------------------------------------------

int AGE::setLabelBg(int label_id, bool active, Uint8 margin, Uint8 color1, Uint8 color2, Uint8 color3){

    int result = -1;

    if ((this->labelttf_index->getId(label_id) == label_id) or (label_id >= 0)){

        this->labelttf_index->setBg(label_id, active);
        this->labelttf_index->setBg_margin(label_id,margin);
        this->labelttf_index->setBg_color1(label_id, color1);
        this->labelttf_index->setBg_color2(label_id, color2);
        this->labelttf_index->setBg_color3(label_id, color3);
        this->labelttf_index->setModified(label_id, true);
        result = this->labelttf_index->getId(label_id);

    }else{
        result = -1;

    }

    return result;

}

//------------------- --------------------------------------------------------

int AGE::setLabelBorder(int label_id, bool active, Uint8 margin, Uint8 color1, Uint8 color2, Uint8 color3){

    int result = -1;

    if ((this->labelttf_index->getId(label_id) == label_id) or (label_id >= 0)){

        this->labelttf_index->setBorder(label_id, active);
        this->labelttf_index->setBorder_margin(label_id,margin);
        this->labelttf_index->setBorder_color1(label_id, color1);
        this->labelttf_index->setBorder_color2(label_id, color2);
        this->labelttf_index->setBorder_color3(label_id, color3);
        this->labelttf_index->setModified(label_id, true);
        result = this->labelttf_index->getId(label_id);

    }else{
        result = -1;

    }

    return result;

}

//------------------- --------------------------------------------------------

SDL_Texture* AGE::renderTTF(TTF_Font* font, string value, SDL_Color label_color, SDL_Color bg_color, int mode){

    SDL_Surface* temp_surface = nullptr;
    SDL_Texture* temp_texture = nullptr;

    if(value == ""){
        value = " ";

    }

    if(mode == AGE_RENDER_B){
        temp_surface = TTF_RenderText_Blended(font, value.c_str(), label_color );

    }else if(mode == AGE_RENDER_N){
        temp_surface = TTF_RenderText_Solid( font, value.c_str(), label_color );

    }else if(mode == AGE_RENDER_S){
        temp_surface = TTF_RenderText_Shaded( font, value.c_str(), label_color, bg_color);

    }

    temp_texture = SDL_CreateTextureFromSurface(this->renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    return temp_texture;

}


//---------------------------------------------------------------------------

SDL_Rect AGE::getWindowSize(){

    SDL_Rect result;

    SDL_GetWindowSize(this->window, &result.w, &result.h);

    return result;

}


//---------------------------------------------------------------------------

SDL_Rect AGE::getLabelSize(int label_id){

    SDL_Rect label_size;
    SDL_Texture* texture = nullptr;

    label_size.w = 0;
    label_size.h = 0;

    if(label_id == this->labelttf_index->getId(label_id)){

        texture = this->labelttf_index->getTexture(label_id);

        if(not (texture == nullptr)){

            SDL_QueryTexture(texture, nullptr, nullptr, &label_size.w, &label_size.h);

        }

    }

    return label_size;

}


//---------------------------------------------------------------------------

SDL_Rect AGE::getImageSize(int image_id){

    SDL_Rect image_size;
    SDL_Texture* texture = nullptr;

    image_size.w = 0;
    image_size.h = 0;

    if(image_id == this->texture_index->getId(image_id)){

        texture = this->texture_index->getTexture(image_id);

        if(not (texture == nullptr)){

            SDL_QueryTexture(texture, nullptr, nullptr, &image_size.w, &image_size.h);

        }

    }

    return image_size;

}


//---------------------------------------------------------------------------

int AGE::getRandom(int limit1){

    return this->getRandom(0, limit1);

}


//---------------------------------------------------------------------------

int AGE::getRandom(int limit1, int limit2){

    int result = -1;

    if (limit1 == limit2){
        result = limit1;

    }else if(limit1 > limit2){
        result = (rand() % (limit2-limit1)+limit1);

    }

    return result;

}


//---------------------------------------------------------------------------

AGE_Color AGE::getPixelColor(int texture_id, int x, int y){

    AGE_Color result = {0,0,0,0};
    Uint32 pixel = 0;
    SDL_Surface* surface;
    int bpp = 0;

    if(x < 0){x = 0;}
    if(y < 0){y = 0;}

    surface = this->texture_index->getSurface(texture_id);

    SDL_LockSurface(this->texture_index->getSurface(texture_id));
    bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    pixel = *(Uint32 *)p;
    SDL_GetRGBA(pixel, this->texture_index->getSurface(texture_id)->format, &result.r, &result.g, &result.b, &result.a);
    SDL_UnlockSurface(this->texture_index->getSurface(texture_id));

    return result;

}


//---------------------------------------------------------------------------

int AGE::deployString(string value1, string value2, string value3){

    int result = -1;

    result = this->string_index->setElementData(this->string_index->createRegister(""), value1, value2, value3);

    return result;

}


//---------------------------------------------------------------------------

int AGE::modifyString(int string_id, string value1, string value2, string value3){

    int result = -1;

    result = this->string_index->searchById(string_id);

    if (value1 != AGE_NO_STRING_SET){this->string_index->setEntry1(result, value1);}
    if (value2 != AGE_NO_STRING_SET){this->string_index->setEntry2(result, value2);}
    if (value3 != AGE_NO_STRING_SET){this->string_index->setEntry3(result, value3);}

    return result;

}


//---------------------------------------------------------------------------

void AGE::removeString(int string_id){

    this->string_index->setAvailable(string_id, true);

}


//---------------------------------------------------------------------------

string AGE::getString(int register_id, int string_id){

    switch(string_id){

        case 0:
            return this->string_index->getEntry1(register_id);
        break;

        case 1:
            return this->string_index->getEntry2(register_id);
        break;

        case 2:
            return this->string_index->getEntry3(register_id);
        break;

        default:
            return AGE_NO_STRING_SET;
        break;

    }

}


//---------------------------------------------------------------------------

int AGE::searchString(string value, int position){


    switch(position){

        case 0:
            return this->string_index->searchByEntry1(value);
        break;

        case 1:
            return this->string_index->searchByEntry2(value);
        break;

        case 2:
            return this->string_index->searchByEntry3(value);
        break;

        default:
            return -1;
        break;

    }

}

//---------------------------------------------------------------------------
