/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 12/12/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_Font.h"


//---------------------------------------------------------------------------

AGE_Font::AGE_Font()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->font = nullptr;
	this->src = "";
	this->size = -1;

}

AGE_Font::~AGE_Font()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGE_Font::printNode(){

	cout << "ID: " << this->ident << endl;
	cout << "POINTER: " << this << endl;
	cout << "TAG: " << this->tag << endl;
	cout << "AVAILABLE: " << this->available << endl;
	cout << "NEXT: " << this->next << endl;
	cout << "FONT: " << this->font << endl;
	cout << "SRC: " << this->src << endl;
	cout << "SIZE: " << this->size << endl;
	cout << endl;
	
	return this->ident;
	
}


//---------------------------------------------------------------------------

int AGE_Font::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Font::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Font::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_Font::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int AGE_Font::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool AGE_Font::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int AGE_Font::setNext(AGE_Font* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

AGE_Font* AGE_Font::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int AGE_Font::setFont(TTF_Font* font){

	this->font = font;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TTF_Font* AGE_Font::getFont(){

	return this->font;

}


//---------------------------------------------------------------------------

int AGE_Font::setSrc(string src){

	this->src = src;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_Font::getSrc(){

	return this->src;

}


//---------------------------------------------------------------------------

int AGE_Font::setSize(int size){

	this->size = size;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Font::getSize(){

	return this->size;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
