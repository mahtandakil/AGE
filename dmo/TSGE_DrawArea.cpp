/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_DrawArea.h"


//---------------------------------------------------------------------------

TSGE_DrawArea::TSGE_DrawArea()
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

TSGE_DrawArea::~TSGE_DrawArea()
{
	//dtor
}


//---------------------------------------------------------------------------

int TSGE_DrawArea::printNode(){

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

int TSGE_DrawArea::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_DrawArea::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool TSGE_DrawArea::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setNext(TSGE_DrawArea* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TSGE_DrawArea* TSGE_DrawArea::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setX(int x){

	this->x = x;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::getX(){

	return this->x;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setY(int y){

	this->y = y;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::getY(){

	return this->y;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setW(int w){

	this->w = w;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::getW(){

	return this->w;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setH(int h){

	this->h = h;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::getH(){

	return this->h;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setSolid(bool solid){

	this->solid = solid;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool TSGE_DrawArea::getSolid(){

	return this->solid;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::setWindow_id(int window_id){

	this->window_id = window_id;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_DrawArea::getWindow_id(){

	return this->window_id;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
