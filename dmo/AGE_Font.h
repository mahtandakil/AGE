/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 08/05/16
* Autogen: 1.1.2c
****************************************************************************/


#include <SDL2/SDL_ttf.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_FONT_H
#define AGE_FONT_H


class AGE_Font
{
	public:
		AGE_Font();
		virtual ~AGE_Font();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		AGE_Font* getNext();
		string getSrc();
		TTF_Font* getFont();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(AGE_Font* next);
		int setSrc(string src);
		int setFont(TTF_Font* font);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		AGE_Font* next;
		string src;
		TTF_Font* font;

};


#endif // AGE_FONT_H



