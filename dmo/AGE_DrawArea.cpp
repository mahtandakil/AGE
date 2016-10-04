/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 26/09/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_DrawArea.h"


//---------------------------------------------------------------------------

AGE_DrawArea::AGE_DrawArea()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->x = -1;
	this->y = -1;
	this->w = -1;
	this->h = -1;
	this->solid = false;
	this->window_id = -1;

}

AGE_DrawArea::~AGE_DrawArea()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGE_DrawArea::printNode(){

	cout << "ID: " << this->ident << endl;
	cout << "POINTER: " << this << endl;
	cout << "TAG: " << this->tag << endl;
	cout << "AVAILABLE: " << this->available << endl;
	cout << "NEXT: " << this->next << endl;
	cout << "X: " << this->x << endl;
	cout << "Y: " << this->y << endl;
	cout << "W: " << this->w << endl;
	cout << "H: " << this->h << endl;
	cout << "SOLID: " << this->solid << endl;
	cout << "WINDOW_ID: " << this->window_id << endl;
	cout << endl;
	
	return this->ident;
	
}


//---------------------------------------------------------------------------

int AGE_DrawArea::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_DrawArea::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool AGE_DrawArea::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setNext(AGE_DrawArea* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

AGE_DrawArea* AGE_DrawArea::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setX(int x){

	this->x = x;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::getX(){

	return this->x;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setY(int y){

	this->y = y;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::getY(){

	return this->y;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setW(int w){

	this->w = w;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::getW(){

	return this->w;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setH(int h){

	this->h = h;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::getH(){

	return this->h;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setSolid(bool solid){

	this->solid = solid;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool AGE_DrawArea::getSolid(){

	return this->solid;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::setWindow_id(int window_id){

	this->window_id = window_id;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_DrawArea::getWindow_id(){

	return this->window_id;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
