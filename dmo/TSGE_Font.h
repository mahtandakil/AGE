/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include <SDL2/SDL_ttf.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_FONT_H
#define TSGE_FONT_H


class TSGE_Font
{
	public:
		TSGE_Font();
		virtual ~TSGE_Font();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		TSGE_Font* getNext();
		TTF_Font* getFont();
		string getSrc();
		int getSize();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(TSGE_Font* next);
		int setFont(TTF_Font* font);
		int setSrc(string src);
		int setSize(int size);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		TSGE_Font* next;
		TTF_Font* font;
		string src;
		int size;

};


#endif // TSGE_FONT_H



