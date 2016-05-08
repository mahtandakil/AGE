/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 08/05/16
* Autogen: 1.1.2c
****************************************************************************/


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_LABEL_H
#define AGE_LABEL_H


class AGE_Label
{
	public:
		AGE_Label();
		virtual ~AGE_Label();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		AGE_Label* getNext();
		string getContent();
		SDL_Texture* getTexture();
		int getFont();
		int getFont_color_r();
		int getFont_color_g();
		int getFont_color_b();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(AGE_Label* next);
		int setContent(string content);
		int setTexture(SDL_Texture* texture);
		int setFont(int font);
		int setFont_color_r(int font_color_r);
		int setFont_color_g(int font_color_g);
		int setFont_color_b(int font_color_b);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		AGE_Label* next;
		string content;
		SDL_Texture* texture;
		int font;
		int font_color_r;
		int font_color_g;
		int font_color_b;

};


#endif // AGE_LABEL_H



