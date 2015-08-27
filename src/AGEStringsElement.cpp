/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 25/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGEStringsElement.h"


//---------------------------------------------------------------------------

AGEStringsElement::AGEStringsElement()
{

	this->id = 0;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->entry1 = "";
	this->entry2 = "";
	this->entry3 = "";

}

AGEStringsElement::~AGEStringsElement()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGEStringsElement::getId(){

	return this->id;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setId(int id){

	this->id = id;

}


//---------------------------------------------------------------------------

string AGEStringsElement::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setTag(string tag){

	this->tag = tag;

}


//---------------------------------------------------------------------------

bool AGEStringsElement::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setAvailable(bool available){

	this->available = available;

}


//---------------------------------------------------------------------------

AGEStringsElement* AGEStringsElement::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setNext(AGEStringsElement* next){

	this->next = next;

}


//---------------------------------------------------------------------------

string AGEStringsElement::getEntry1(){

	return this->entry1;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setEntry1(string entry1){

	this->entry1 = entry1;

}


//---------------------------------------------------------------------------

string AGEStringsElement::getEntry2(){

	return this->entry2;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setEntry2(string entry2){

	this->entry2 = entry2;

}


//---------------------------------------------------------------------------

string AGEStringsElement::getEntry3(){

	return this->entry3;

}


//---------------------------------------------------------------------------

void AGEStringsElement::setEntry3(string entry3){

	this->entry3 = entry3;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
