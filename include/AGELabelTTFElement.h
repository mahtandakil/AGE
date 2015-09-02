/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 02/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEFontElement.h"
#include "AGEPrefixedValues.h"


#include <SDL.h>


#include <iostream>


using namespace std;


#ifndef AGELABELTTFELEMENT_H
#define AGELABELTTFELEMENT_H


class AGELabelTTFElement
{
	public:
		AGELabelTTFElement();
		virtual ~AGELabelTTFElement();

		int getId();
		string getTag();
		bool getAvailable();
		AGELabelTTFElement* getNext();
		string getContent();
		int getFont();
		bool getBorder();
		bool getBg();
		Uint8 getFont_color1();
		Uint8 getFont_color2();
		Uint8 getFont_color3();
		Uint8 getBorder_margin();
		Uint8 getBorder_color1();
		Uint8 getBorder_color2();
		Uint8 getBorder_color3();
		Uint8 getBg_margin();
		Uint8 getBg_color1();
		Uint8 getBg_color2();
		Uint8 getBg_color3();
		bool getModified();
		Uint8 getRender();
		SDL_Texture* getTexture();
		void setId(int id);
		void setTag(string tag);
		void setAvailable(bool available);
		void setNext(AGELabelTTFElement* next);
		void setContent(string content);
		void setFont(int font);
		void setBorder(bool border);
		void setBg(bool bg);
		void setFont_color1(Uint8 font_color1);
		void setFont_color2(Uint8 font_color2);
		void setFont_color3(Uint8 font_color3);
		void setBorder_margin(Uint8 border_margin);
		void setBorder_color1(Uint8 border_color1);
		void setBorder_color2(Uint8 border_color2);
		void setBorder_color3(Uint8 border_color3);
		void setBg_margin(Uint8 bg_margin);
		void setBg_color1(Uint8 bg_color1);
		void setBg_color2(Uint8 bg_color2);
		void setBg_color3(Uint8 bg_color3);
		void setModified(bool modified);
		void setRender(Uint8 render);
		void setTexture(SDL_Texture* texture);


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGELabelTTFElement* next;
		string content;
		int font;
		bool border;
		bool bg;
		Uint8 font_color1;
		Uint8 font_color2;
		Uint8 font_color3;
		Uint8 border_margin;
		Uint8 border_color1;
		Uint8 border_color2;
		Uint8 border_color3;
   		Uint8 bg_margin;
		Uint8 bg_color1;
		Uint8 bg_color2;
		Uint8 bg_color3;
		Uint8 render;
		bool modified;
		SDL_Texture* texture;

};


#endif // AGELABELTTFELEMENT_H


