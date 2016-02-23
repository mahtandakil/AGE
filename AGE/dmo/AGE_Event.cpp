/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 16/02/16
* Autogen: 1.1.2b
****************************************************************************/


#include "AGE_Event.h"


//---------------------------------------------------------------------------

AGE_Event::AGE_Event()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->event = 0;
	this->device = 0;
	this->window = -1;
	this->timestamp = 0;
	this->state = 0;
	this->x = -1;
	this->y = -1;
	this->w = -1;
	this->h = -1;
	this->count = 0;
	this->mod = 0;

}

AGE_Event::~AGE_Event()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGE_Event::printNode(){

	cout << "ID: " << this->ident << endl;
	cout << "POINTER: " << this << endl;
	cout << "TAG: " << this->tag << endl;
	cout << "AVAILABLE: " << this->available << endl;
	cout << "NEXT: " << this->next << endl;
	cout << "EVENT: " << this->event << endl;
	cout << "DEVICE: " << this->device << endl;
	cout << "WINDOW: " << this->window << endl;
	cout << "TIMESTAMP: " << this->timestamp << endl;
	cout << "STATE: " << this->state << endl;
	cout << "X: " << this->x << endl;
	cout << "Y: " << this->y << endl;
	cout << "W: " << this->w << endl;
	cout << "H: " << this->h << endl;
	cout << "COUNT: " << this->count << endl;
	cout << "MOD: " << this->mod << endl;
	cout << endl;
	
	return this->ident;
	
}


//---------------------------------------------------------------------------

int AGE_Event::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_Event::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int AGE_Event::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool AGE_Event::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int AGE_Event::setNext(AGE_Event* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

AGE_Event* AGE_Event::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int AGE_Event::setEvent(Uint32 event){

	this->event = event;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 AGE_Event::getEvent(){

	return this->event;

}


//---------------------------------------------------------------------------

int AGE_Event::setDevice(Uint32 device){

	this->device = device;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 AGE_Event::getDevice(){

	return this->device;

}


//---------------------------------------------------------------------------

int AGE_Event::setWindow(int window){

	this->window = window;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::getWindow(){

	return this->window;

}


//---------------------------------------------------------------------------

int AGE_Event::setTimestamp(Uint32 timestamp){

	this->timestamp = timestamp;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 AGE_Event::getTimestamp(){

	return this->timestamp;

}


//---------------------------------------------------------------------------

int AGE_Event::setState(Uint32 state){

	this->state = state;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 AGE_Event::getState(){

	return this->state;

}


//---------------------------------------------------------------------------

int AGE_Event::setX(int x){

	this->x = x;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::getX(){

	return this->x;

}


//---------------------------------------------------------------------------

int AGE_Event::setY(int y){

	this->y = y;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::getY(){

	return this->y;

}


//---------------------------------------------------------------------------

int AGE_Event::setW(int w){

	this->w = w;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::getW(){

	return this->w;

}


//---------------------------------------------------------------------------

int AGE_Event::setH(int h){

	this->h = h;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Event::getH(){

	return this->h;

}


//---------------------------------------------------------------------------

int AGE_Event::setCount(Uint8 count){

	this->count = count;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint8 AGE_Event::getCount(){

	return this->count;

}


//---------------------------------------------------------------------------

int AGE_Event::setMod(Uint16 mod){

	this->mod = mod;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint16 AGE_Event::getMod(){

	return this->mod;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
