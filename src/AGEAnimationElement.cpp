/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 27/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEAnimationElement.h"


//---------------------------------------------------------------------------

AGEAnimationElement::AGEAnimationElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->frames = nullptr;
	this->texture = nullptr;
	this->file = "";
	this->description = "";
	this->bgcolor1 = 0;
	this->bgcolor2 = 0;
	this->bgcolor3 = 0;
	this->images = 0;
	this->init = 0;
	this->texture_h = 0;
	this->texture_w = 0;

}

AGEAnimationElement::~AGEAnimationElement()
{

    if (this->texture == nullptr){
        SDL_DestroyTexture(this->texture);

    }

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getId(){

	return this->id;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setId(int id){

	this->id = id;

}


//---------------------------------------------------------------------------

string AGEAnimationElement::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setTag(string tag){

	this->tag = tag;

}


//---------------------------------------------------------------------------

bool AGEAnimationElement::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setAvailable(bool available){

	this->available = available;

}


//---------------------------------------------------------------------------

AGEAnimationElement* AGEAnimationElement::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setNext(AGEAnimationElement* next){

	this->next = next;

}


//---------------------------------------------------------------------------

AGEAnimationFrameIndex* AGEAnimationElement::getFrames(){

	return this->frames;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setFrames(AGEAnimationFrameIndex* frames){

	this->frames = frames;

}


//---------------------------------------------------------------------------

string AGEAnimationElement::getFile(){

	return this->file;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setFile(string file){

	this->file = file;

}


//---------------------------------------------------------------------------

string AGEAnimationElement::getDescription(){

	return this->description;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setDescription(string description){

	this->description = description;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getBgcolor1(){

	return this->bgcolor1;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setBgcolor1(int bgcolor1){

	this->bgcolor1 = bgcolor1;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getBgcolor2(){

	return this->bgcolor2;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setBgcolor2(int bgcolor2){

	this->bgcolor2 = bgcolor2;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getBgcolor3(){

	return this->bgcolor3;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setBgcolor3(int bgcolor3){

	this->bgcolor3 = bgcolor3;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getImages(){

	return this->images;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setImages(int images){

	this->images = images;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getInit(){

	return this->init;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getTexture_h(){

	return this->texture_h;

}


//---------------------------------------------------------------------------

int AGEAnimationElement::getTexture_w(){

	return this->texture_w;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setInit(int init){

	this->init = init;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setTexture_h(int texture_h){

	this->texture_h = texture_h;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setTexture_w(int texture_w){

	this->texture_w = texture_w;

}


//---------------------------------------------------------------------------

SDL_Texture* AGEAnimationElement::getTexture(){

    return this->texture;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setTexture(SDL_Texture* texture){

    this->texture = texture;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
