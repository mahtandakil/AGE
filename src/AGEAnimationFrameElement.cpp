/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 27/08/2015
* Last change: 27/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEAnimationFrameElement.h"


//---------------------------------------------------------------------------

AGEAnimationFrameElement::AGEAnimationFrameElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->image_x = 0;
	this->image_y = 0;
	this->image_w = 0;
	this->image_h = 0;
	this->image_d = 0;

}

AGEAnimationFrameElement::~AGEAnimationFrameElement()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGEAnimationFrameElement::getId(){

	return this->id;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setId(int id){

	this->id = id;

}


//---------------------------------------------------------------------------

string AGEAnimationFrameElement::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setTag(string tag){

	this->tag = tag;

}


//---------------------------------------------------------------------------

bool AGEAnimationFrameElement::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setAvailable(bool available){

	this->available = available;

}


//---------------------------------------------------------------------------

AGEAnimationFrameElement* AGEAnimationFrameElement::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setNext(AGEAnimationFrameElement* next){

	this->next = next;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameElement::getImage_x(){

	return this->image_x;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setImage_x(int image_x){

	this->image_x = image_x;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameElement::getImage_y(){

	return this->image_y;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setImage_y(int image_y){

	this->image_y = image_y;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameElement::getImage_w(){

	return this->image_w;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setImage_w(int image_w){

	this->image_w = image_w;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameElement::getImage_h(){

	return this->image_h;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setImage_h(int image_h){

	this->image_h = image_h;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameElement::getImage_d(){

	return this->image_d;

}


//---------------------------------------------------------------------------

void AGEAnimationFrameElement::setImage_d(int image_d){

	this->image_d = image_d;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
