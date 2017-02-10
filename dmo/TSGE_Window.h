/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_WINDOW_H
#define TSGE_WINDOW_H


class TSGE_Window
{
	public:
		TSGE_Window();
		virtual ~TSGE_Window();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		TSGE_Window* getNext();
		SDL_Window* getWindow();
		SDL_Renderer* getRender();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(TSGE_Window* next);
		int setWindow(SDL_Window* window);
		int setRender(SDL_Renderer* render);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		TSGE_Window* next;
		SDL_Window* window;
		SDL_Renderer* render;

};


#endif // TSGE_WINDOW_H



