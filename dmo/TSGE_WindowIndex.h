/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Window.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_WINDOWINDEX_H
#define TSGE_WINDOWINDEX_H


class TSGE_WindowIndex
{
	public:
		TSGE_WindowIndex();
		virtual ~TSGE_WindowIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		TSGE_Window* getFirst();
		TSGE_Window* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, SDL_Window* window, SDL_Renderer* render);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		TSGE_Window* getNext(int id);
		SDL_Window* getWindow(int id);
		SDL_Renderer* getRender(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, TSGE_Window* next);
		int setWindow(int ident, SDL_Window* window);
		int setRender(int ident, SDL_Renderer* render);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(TSGE_Window* next);
		int searchByWindow(SDL_Window* window);
		int searchByRender(SDL_Renderer* render);


	protected:



	private:
		int nodes;
		int next_ident;
		TSGE_Window* first;
		TSGE_Window* last;


};


#endif // TSGE_WINDOWINDEX_H

