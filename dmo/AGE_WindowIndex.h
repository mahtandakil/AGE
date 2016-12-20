/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 12/12/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_Window.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_WINDOWINDEX_H
#define AGE_WINDOWINDEX_H


class AGE_WindowIndex
{
	public:
		AGE_WindowIndex();
		virtual ~AGE_WindowIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		AGE_Window* getFirst();
		AGE_Window* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, SDL_Window* window, SDL_Renderer* render);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGE_Window* getNext(int id);
		SDL_Window* getWindow(int id);
		SDL_Renderer* getRender(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, AGE_Window* next);
		int setWindow(int ident, SDL_Window* window);
		int setRender(int ident, SDL_Renderer* render);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGE_Window* next);
		int searchByWindow(SDL_Window* window);
		int searchByRender(SDL_Renderer* render);


	protected:



	private:
		int nodes;
		int next_ident;
		AGE_Window* first;
		AGE_Window* last;


};


#endif // AGE_WINDOWINDEX_H

