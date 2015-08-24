/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 24/08/2015
* Last change: 24/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGEAnimationElement.h"


//---------------------------------------------------------------------------

AGEAnimationElement::AGEAnimationElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->elements = 0;
	this->init = 0;
	this->texture_index = nullptr;

}

AGEAnimationElement::~AGEAnimationElement()
{
	//dtor
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

Uint8 AGEAnimationElement::getElements(){

	return this->elements;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setElements(Uint8 elements){

	this->elements = elements;

}


//---------------------------------------------------------------------------

Uint8 AGEAnimationElement::getInit(){

	return this->init;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setInit(Uint8 init){

	this->init = init;

}


//---------------------------------------------------------------------------

AGETextureListIndex* AGEAnimationElement::getTexture_index(){

	return this->texture_index;

}


//---------------------------------------------------------------------------

void AGEAnimationElement::setTexture_index(AGETextureListIndex* texture_index){

	this->texture_index = texture_index;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
