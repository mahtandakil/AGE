/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 02/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGELabelTTFElement.h"


//---------------------------------------------------------------------------

AGELabelTTFElement::AGELabelTTFElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->content = "";
	this->font = 0;
	this->border = false;
	this->bg = false;
	this->font_color1 = 0;
	this->font_color2 = 0;
	this->font_color3 = 0;
	this->border_margin = 0;
	this->border_color1 = 0;
	this->border_color2 = 0;
	this->border_color3 = 0;
	this->bg_color1 = 0;
	this->bg_color2 = 0;
	this->bg_color3 = 0;
	this->modified = false;
	this->render = AGE_RENDER_N;
	this->texture = nullptr;

}

AGELabelTTFElement::~AGELabelTTFElement()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGELabelTTFElement::getId(){

	return this->id;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setId(int id){

	this->id = id;

}


//---------------------------------------------------------------------------

string AGELabelTTFElement::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setTag(string tag){

	this->tag = tag;

}


//---------------------------------------------------------------------------

bool AGELabelTTFElement::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setAvailable(bool available){

	this->available = available;

}


//---------------------------------------------------------------------------

AGELabelTTFElement* AGELabelTTFElement::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setNext(AGELabelTTFElement* next){

	this->next = next;

}


//---------------------------------------------------------------------------

string AGELabelTTFElement::getContent(){

	return this->content;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setContent(string content){

	this->content = content;

}


//---------------------------------------------------------------------------

int AGELabelTTFElement::getFont(){

	return this->font;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setFont(int font){

	this->font = font;

}


//---------------------------------------------------------------------------

bool AGELabelTTFElement::getBorder(){

	return this->border;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBorder(bool border){

	this->border = border;

}


//---------------------------------------------------------------------------

bool AGELabelTTFElement::getBg(){

	return this->bg;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBg(bool bg){

	this->bg = bg;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getFont_color1(){

	return this->font_color1;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setFont_color1(Uint8 font_color1){

	this->font_color1 = font_color1;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getFont_color2(){

	return this->font_color2;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setFont_color2(Uint8 font_color2){

	this->font_color2 = font_color2;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getFont_color3(){

	return this->font_color3;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setFont_color3(Uint8 font_color3){

	this->font_color3 = font_color3;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBorder_margin(){

	return this->border_margin;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBorder_margin(Uint8 border_margin){

	this->border_margin = border_margin;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBg_margin(){

	return this->bg_margin;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBg_margin(Uint8 bg_margin){

	this->bg_margin = bg_margin;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBorder_color1(){

	return this->border_color1;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBorder_color1(Uint8 border_color1){

	this->border_color1 = border_color1;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBorder_color2(){

	return this->border_color2;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBorder_color2(Uint8 border_color2){

	this->border_color2 = border_color2;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBorder_color3(){

	return this->border_color3;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBorder_color3(Uint8 border_color3){

	this->border_color3 = border_color3;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBg_color1(){

	return this->bg_color1;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBg_color1(Uint8 bg_color1){

	this->bg_color1 = bg_color1;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBg_color2(){

	return this->bg_color2;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBg_color2(Uint8 bg_color2){

	this->bg_color2 = bg_color2;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getBg_color3(){

	return this->bg_color3;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setBg_color3(Uint8 bg_color3){

	this->bg_color3 = bg_color3;

}

//---------------------------------------------------------------------------

SDL_Texture* AGELabelTTFElement::getTexture(){

	return this->texture;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setTexture(SDL_Texture* texture){

	this->texture = texture;

}


//---------------------------------------------------------------------------

bool AGELabelTTFElement::getModified(){

	return this->modified;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setModified(bool modified){

	this->modified = modified;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFElement::getRender(){

	return this->render;

}


//---------------------------------------------------------------------------

void AGELabelTTFElement::setRender(Uint8 render){

	this->render = render;

}


//---------------------------------------------------------------------------
