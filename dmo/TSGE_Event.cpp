/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Event.h"


//---------------------------------------------------------------------------

TSGE_Event::TSGE_Event()
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

TSGE_Event::~TSGE_Event()
{
	//dtor
}


//---------------------------------------------------------------------------

int TSGE_Event::printNode(){

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

int TSGE_Event::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_Event::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int TSGE_Event::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool TSGE_Event::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int TSGE_Event::setNext(TSGE_Event* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TSGE_Event* TSGE_Event::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int TSGE_Event::setEvent(Uint32 event){

	this->event = event;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 TSGE_Event::getEvent(){

	return this->event;

}


//---------------------------------------------------------------------------

int TSGE_Event::setDevice(Uint32 device){

	this->device = device;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 TSGE_Event::getDevice(){

	return this->device;

}


//---------------------------------------------------------------------------

int TSGE_Event::setWindow(int window){

	this->window = window;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::getWindow(){

	return this->window;

}


//---------------------------------------------------------------------------

int TSGE_Event::setTimestamp(Uint32 timestamp){

	this->timestamp = timestamp;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 TSGE_Event::getTimestamp(){

	return this->timestamp;

}


//---------------------------------------------------------------------------

int TSGE_Event::setState(Uint32 state){

	this->state = state;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint32 TSGE_Event::getState(){

	return this->state;

}


//---------------------------------------------------------------------------

int TSGE_Event::setX(int x){

	this->x = x;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::getX(){

	return this->x;

}


//---------------------------------------------------------------------------

int TSGE_Event::setY(int y){

	this->y = y;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::getY(){

	return this->y;

}


//---------------------------------------------------------------------------

int TSGE_Event::setW(int w){

	this->w = w;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::getW(){

	return this->w;

}


//---------------------------------------------------------------------------

int TSGE_Event::setH(int h){

	this->h = h;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Event::getH(){

	return this->h;

}


//---------------------------------------------------------------------------

int TSGE_Event::setCount(Uint8 count){

	this->count = count;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint8 TSGE_Event::getCount(){

	return this->count;

}


//---------------------------------------------------------------------------

int TSGE_Event::setMod(Uint16 mod){

	this->mod = mod;
	
	return this->ident;

}


//---------------------------------------------------------------------------

Uint16 TSGE_Event::getMod(){

	return this->mod;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
