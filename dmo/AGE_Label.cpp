/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 08/05/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_Label.h"


//---------------------------------------------------------------------------

AGE_Label::AGE_Label()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->content = "";
	this->texture = nullptr;
	this->font = -1;
	this->font_color_r = -1;
	this->font_color_g = -1;
	this->font_color_b = -1;

}

AGE_Label::~AGE_Label()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGE_Label::printNode(){

	cout << "ID: " << this->ident << endl;
	cout << "POINTER: " << this << endl;
	cout << "TAG: " << this->tag << endl;
	cout << "AVAILABLE: " << this->available << endl;
	cout << "NEXT: " << this->next << endl;
	cout << "CONTENT: " << this->content << endl;
	cout << "TEXTURE: " << this->texture << endl;
	cout << "FONT: " << this->font << endl;
	cout << "FONT_COLOR_R: " << this->font_color_r << endl;
	cout << "FONT_COLOR_G: " << this->font_color_g << endl;
	cout << "FONT_COLOR_B: " << this->font_color_b << endl;
	cout << endl;
	
	return this->ident;
	
}


//---------------------------------------------------------------------------

int AGE_Label::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Label::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Label::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_Label::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int AGE_Label::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool AGE_Label::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int AGE_Label::setNext(AGE_Label* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

AGE_Label* AGE_Label::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int AGE_Label::setContent(string content){

	this->content = content;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_Label::getContent(){

	return this->content;

}


//---------------------------------------------------------------------------

int AGE_Label::setTexture(SDL_Texture* texture){

	this->texture = texture;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Texture* AGE_Label::getTexture(){

	return this->texture;

}


//---------------------------------------------------------------------------

int AGE_Label::setFont(int font){

	this->font = font;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Label::getFont(){

	return this->font;

}


//---------------------------------------------------------------------------

int AGE_Label::setFont_color_r(int font_color_r){

	this->font_color_r = font_color_r;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Label::getFont_color_r(){

	return this->font_color_r;

}


//---------------------------------------------------------------------------

int AGE_Label::setFont_color_g(int font_color_g){

	this->font_color_g = font_color_g;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Label::getFont_color_g(){

	return this->font_color_g;

}


//---------------------------------------------------------------------------

int AGE_Label::setFont_color_b(int font_color_b){

	this->font_color_b = font_color_b;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Label::getFont_color_b(){

	return this->font_color_b;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
