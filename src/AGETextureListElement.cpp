/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v1
* Creation day: 02/08/2015
* Last change: 06/09/2015
****************************************************************************/


#include "AGETextureListElement.h"


//---------------------------------------------------------------------------

AGETextureListElement::AGETextureListElement()
{

    this->available = true;
    this->next = nullptr;
    this->src = "NOT_SOURCE_FIXED";
    this->texture = nullptr;
    this->texture_id = -1;
    this->texture_h = -1;
    this->texture_w = -1;
    this->position_x = -1;
    this->position_y = -1;
    this->surface = nullptr;

    this->area_index = new AGECollisionAreaIndex();

}

AGETextureListElement::~AGETextureListElement()
{
    //dtor
}


//---------------------------------------------------------------------------

void AGETextureListElement::setSrc(string src){

    this->src = src;

}


//---------------------------------------------------------------------------

void AGETextureListElement::setAvailable(bool available){

    this->available = available;

}


//---------------------------------------------------------------------------

string AGETextureListElement::getSrc(){

    return this->src;

}


//---------------------------------------------------------------------------

int AGETextureListElement::getId(){

    return this->texture_id;

}


//---------------------------------------------------------------------------

bool AGETextureListElement::getAvailable(){

    return this->available;

}


//---------------------------------------------------------------------------

AGETextureListElement* AGETextureListElement::getNext(){

    return this->next;

}


//---------------------------------------------------------------------------

void AGETextureListElement::setNext(AGETextureListElement* next){

    this->next = next;

}


//---------------------------------------------------------------------------

void AGETextureListElement::setId(int texture_id){

    this->texture_id = texture_id;

}


//---------------------------------------------------------------------------

void AGETextureListElement::setTexture(SDL_Texture* texture){

    if ((texture != nullptr) && (this->available)){
        this->texture = texture;
        SDL_QueryTexture(texture, nullptr, nullptr, &this->texture_w, &this->texture_h);
        this->available = false;
    }

}


//---------------------------------------------------------------------------

SDL_Texture* AGETextureListElement::getTexture(){

    return this->texture;

}


//---------------------------------------------------------------------------

int AGETextureListElement::getTextureH(){

    return this->texture_h;

}


//---------------------------------------------------------------------------

int AGETextureListElement::getTextureW(){

    return this->texture_w;

}


//---------------------------------------------------------------------------

void AGETextureListElement::setPosition(int x, int y){

    this->position_x = x;
    this->position_y = y;

}


//---------------------------------------------------------------------------

int AGETextureListElement::getPositionX(){

    return this->position_x;

}


//---------------------------------------------------------------------------

int AGETextureListElement::getPositionY(){

    return this->position_y;

}


//---------------------------------------------------------------------------

AGECollisionAreaIndex* AGETextureListElement::getAreaIndex(){

    return this->area_index;

}


//---------------------------------------------------------------------------

AGECollisionAreaIndex* AGETextureListElement::initAreaIndex(){

    this->area_index = new AGECollisionAreaIndex();

    return this->area_index;

}


//---------------------------------------------------------------------------

SDL_Surface* AGETextureListElement::getSurface(){

    return this->surface;

}


//---------------------------------------------------------------------------

void AGETextureListElement::setSurface(SDL_Surface* surface){

    this->surface = surface;

}


//---------------------------------------------------------------------------
