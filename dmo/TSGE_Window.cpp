/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Window.h"


//---------------------------------------------------------------------------

TSGE_Window::TSGE_Window()
{

	this->ident = -1;
	this->tag = "";
	this->available = false;
	this->next = nullptr;
	this->window = nullptr;
	this->render = nullptr;

}

TSGE_Window::~TSGE_Window()
{
	//dtor
}


//---------------------------------------------------------------------------

int TSGE_Window::printNode(){

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

int TSGE_Window::setIdent(int ident){

	this->ident = ident;
	
	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Window::getIdent(){

	return this->ident;

}


//---------------------------------------------------------------------------

int TSGE_Window::setTag(string tag){

	this->tag = tag;
	
	return this->ident;

}


//---------------------------------------------------------------------------

string TSGE_Window::getTag(){

	return this->tag;

}


//---------------------------------------------------------------------------

int TSGE_Window::setAvailable(bool available){

	this->available = available;
	
	return this->ident;

}


//---------------------------------------------------------------------------

bool TSGE_Window::getAvailable(){

	return this->available;

}


//---------------------------------------------------------------------------

int TSGE_Window::setNext(TSGE_Window* next){

	this->next = next;
	
	return this->ident;

}


//---------------------------------------------------------------------------

TSGE_Window* TSGE_Window::getNext(){

	return this->next;

}


//---------------------------------------------------------------------------

int TSGE_Window::setWindow(SDL_Window* window){

	this->window = window;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Window* TSGE_Window::getWindow(){

	return this->window;

}


//---------------------------------------------------------------------------

int TSGE_Window::setRender(SDL_Renderer* render){

	this->render = render;
	
	return this->ident;

}


//---------------------------------------------------------------------------

SDL_Renderer* TSGE_Window::getRender(){

	return this->render;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
