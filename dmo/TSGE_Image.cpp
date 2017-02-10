/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Image.h"


//---------------------------------------------------------------------------

TSGE_Image::TSGE_Image()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->src = "";
	this->surface = nullptr;
	this->texture = nullptr;
	this->texture_h = -1;
	this->texture_w = -1;

}

TSGE_Image::~TSGE_Image()
{
	//dtor
}


//---------------------------------------------------------------------------

int TSGE_Image::printNode(){

	cout << "ID: " << this->ident << endl;
	cout << "POINTER: " << this << endl;
	cout << "TAG: " << this->tag << endl;
	cout << "AVAILABLE: " << this->available << endl;
	cout << "NEXT: " << this->next << endl;
	cout << "SRC: " << this->src << endl;
	cout << "SURFACE: " << this->surface << endl;
	cout << "TEXTURE: " << this->texture << endl;
	cout << "TEXTURE_H: " << this->texture_h << endl;
	cout << "TEXTURE_W: " << this->texture_w << endl;
	cout << endl;
	
	return this->ident;
	
}


//---------------------------------------------------------------------------

int TSGE_Image::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Image::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Image::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_Image::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int TSGE_Image::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool TSGE_Image::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int TSGE_Image::setNext(TSGE_Image* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TSGE_Image* TSGE_Image::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int TSGE_Image::setSrc(string src){

	this->src = src;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_Image::getSrc(){

	return this->src;

}


//---------------------------------------------------------------------------

int TSGE_Image::setSurface(SDL_Surface* surface){

	this->surface = surface;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Surface* TSGE_Image::getSurface(){

	return this->surface;

}


//---------------------------------------------------------------------------

int TSGE_Image::setTexture(SDL_Texture* texture){

	this->texture = texture;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Texture* TSGE_Image::getTexture(){

	return this->texture;

}


//---------------------------------------------------------------------------

int TSGE_Image::setTexture_h(int texture_h){

	this->texture_h = texture_h;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Image::getTexture_h(){

	return this->texture_h;

}


//---------------------------------------------------------------------------

int TSGE_Image::setTexture_w(int texture_w){

	this->texture_w = texture_w;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Image::getTexture_w(){

	return this->texture_w;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
