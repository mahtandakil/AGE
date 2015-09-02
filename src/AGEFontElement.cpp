/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 02/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEFontElement.h"


//---------------------------------------------------------------------------

AGEFontElement::AGEFontElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->src = "";
	this->font = nullptr;

}

AGEFontElement::~AGEFontElement()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGEFontElement::getId(){

	return this->id;

}


//---------------------------------------------------------------------------

void AGEFontElement::setId(int id){

	this->id = id;

}


//---------------------------------------------------------------------------

string AGEFontElement::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

void AGEFontElement::setTag(string tag){

	this->tag = tag;

}


//---------------------------------------------------------------------------

bool AGEFontElement::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

void AGEFontElement::setAvailable(bool available){

	this->available = available;

}


//---------------------------------------------------------------------------

AGEFontElement* AGEFontElement::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

void AGEFontElement::setNext(AGEFontElement* next){

	this->next = next;

}


//---------------------------------------------------------------------------

string AGEFontElement::getSrc(){

	return this->src;

}


//---------------------------------------------------------------------------

void AGEFontElement::setSrc(string src){

	this->src = src;

}


//---------------------------------------------------------------------------

TTF_Font* AGEFontElement::getFont(){

	return this->font;

}


//---------------------------------------------------------------------------

void AGEFontElement::setFont(TTF_Font* font){

	this->font = font;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
