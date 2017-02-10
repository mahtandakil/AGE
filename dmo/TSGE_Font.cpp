/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Font.h"


//---------------------------------------------------------------------------

TSGE_Font::TSGE_Font()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->font = nullptr;
	this->src = "";
	this->size = -1;

}

TSGE_Font::~TSGE_Font()
{
	//dtor
}


//---------------------------------------------------------------------------

int TSGE_Font::printNode(){

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

int TSGE_Font::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Font::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Font::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_Font::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int TSGE_Font::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool TSGE_Font::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int TSGE_Font::setNext(TSGE_Font* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TSGE_Font* TSGE_Font::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int TSGE_Font::setFont(TTF_Font* font){

	this->font = font;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TTF_Font* TSGE_Font::getFont(){

	return this->font;

}


//---------------------------------------------------------------------------

int TSGE_Font::setSrc(string src){

	this->src = src;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_Font::getSrc(){

	return this->src;

}


//---------------------------------------------------------------------------

int TSGE_Font::setSize(int size){

	this->size = size;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Font::getSize(){

	return this->size;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
