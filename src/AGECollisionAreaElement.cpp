/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 13/08/2015
* Last change: 21/08/2015
* Autogen: CListGen 1.0.3
****************************************************************************/


#include "AGECollisionAreaElement.h"


//---------------------------------------------------------------------------

AGECollisionAreaElement::AGECollisionAreaElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->type = 0;
	this->area.x = 0;
	this->area.y = 0;
	this->area.h = 0;
	this->area.w = 0;
	this->color1 = 0;
	this->color2 = 0;
	this->color3 = 0;

}

AGECollisionAreaElement::~AGECollisionAreaElement()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGECollisionAreaElement::getId(){

	return this->id;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setId(int id){

	this->id = id;

}


//---------------------------------------------------------------------------

string AGECollisionAreaElement::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setTag(string tag){

	this->tag = tag;

}


//---------------------------------------------------------------------------

bool AGECollisionAreaElement::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setAvailable(bool available){

	this->available = available;

}


//---------------------------------------------------------------------------

AGECollisionAreaElement* AGECollisionAreaElement::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setNext(AGECollisionAreaElement* next){

	this->next = next;

}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaElement::getType(){

	return this->type;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setType(Uint8 type){

	this->type = type;

}


//---------------------------------------------------------------------------

SDL_Rect AGECollisionAreaElement::getArea(){

	return this->area;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setArea(SDL_Rect area){

    this->area = area;


}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaElement::getColor1(){

	return this->color1;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setColor1(Uint8 color1){

	this->color1 = color1;

}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaElement::getColor2(){

	return this->color2;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setColor2(Uint8 color2){

	this->color2 = color2;

}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaElement::getColor3(){

	return this->color3;

}


//---------------------------------------------------------------------------

void AGECollisionAreaElement::setColor3(Uint8 color3){

	this->color3 = color3;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
