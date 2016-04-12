/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 16/02/16
* Autogen: 1.1.2b
****************************************************************************/


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_WINDOW_H
#define AGE_WINDOW_H


class AGE_Window
{
	public:
		AGE_Window();
		virtual ~AGE_Window();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		AGE_Window* getNext();
		SDL_Window* getWindow();
		SDL_Renderer* getRender();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(AGE_Window* next);
		int setWindow(SDL_Window* window);
		int setRender(SDL_Renderer* render);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		AGE_Window* next;
		SDL_Window* window;
		SDL_Renderer* render;

};


#endif // AGE_WINDOW_H



