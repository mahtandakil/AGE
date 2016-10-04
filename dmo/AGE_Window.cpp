/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 26/09/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_Window.h"


//---------------------------------------------------------------------------

AGE_Window::AGE_Window()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->window = nullptr;
	this->render = nullptr;

}

AGE_Window::~AGE_Window()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGE_Window::printNode(){

	cout << "ID: " << this->ident << endl;
	cout << "POINTER: " << this << endl;
	cout << "TAG: " << this->tag << endl;
	cout << "AVAILABLE: " << this->available << endl;
	cout << "NEXT: " << this->next << endl;
	cout << "WINDOW: " << this->window << endl;
	cout << "RENDER: " << this->render << endl;
	cout << endl;
	
	return this->ident;
	
}


//---------------------------------------------------------------------------

int AGE_Window::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Window::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int AGE_Window::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string AGE_Window::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int AGE_Window::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool AGE_Window::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int AGE_Window::setNext(AGE_Window* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

AGE_Window* AGE_Window::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int AGE_Window::setWindow(SDL_Window* window){

	this->window = window;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Window* AGE_Window::getWindow(){

	return this->window;

}


//---------------------------------------------------------------------------

int AGE_Window::setRender(SDL_Renderer* render){

	this->render = render;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Renderer* AGE_Window::getRender(){

	return this->render;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
