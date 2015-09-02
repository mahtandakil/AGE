/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 02/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGELabelTTFElement.h"


#include <iostream>


using namespace std;


#ifndef AGELABELTTFINDEX_H
#define AGELABELTTFINDEX_H


class AGELabelTTFIndex
{
	public:
		AGELabelTTFIndex();
		virtual ~AGELabelTTFIndex();

		int createRegister(string tag);
		int freeList();
		int getId(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGELabelTTFElement* getNext(int id);
		string getContent(int id);
		int getFont(int id);
		bool getBorder(int id);
		bool getBg(int id);
		Uint8 getFont_color1(int id);
		Uint8 getFont_color2(int id);
		Uint8 getFont_color3(int id);
		Uint8 getBorder_margin(int id);
		Uint8 getBorder_color1(int id);
		Uint8 getBorder_color2(int id);
		Uint8 getBorder_color3(int id);
		Uint8 getBg_margin(int id);
		Uint8 getBg_color1(int id);
		Uint8 getBg_color2(int id);
		Uint8 getBg_color3(int id);
		bool getModified(int id);
		Uint8 getRender(int id);
		SDL_Texture* getTexture(int id);
		int searchById(int id);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGELabelTTFElement* next);
		int searchByContent(string content);
		int searchByFont(int font);
		int searchByBorder(bool border);
		int searchByBg(bool bg);
		int searchByFont_color1(Uint8 font_color1);
		int searchByFont_color2(Uint8 font_color2);
		int searchByFont_color3(Uint8 font_color3);
		int searchByBorder_color1(Uint8 border_color1);
		int searchByBorder_color2(Uint8 border_color2);
		int searchByBorder_color3(Uint8 border_color3);
		int searchByBg_color1(Uint8 bg_color1);
		int searchByBg_color2(Uint8 bg_color2);
		int searchByBg_color3(Uint8 bg_color3);
		int setElementData(int id, string tag, string content, int font, bool border, bool bg, Uint8 font_color1, Uint8 font_color2, Uint8 font_color3, Uint8 border_color1, Uint8 border_color2, Uint8 border_color3, Uint8 bg_color1, Uint8 bg_color2, Uint8 bg_color3);
		int setElementData(int id, string content, int font, bool border, bool bg, Uint8 font_color1, Uint8 font_color2, Uint8 font_color3, Uint8 border_color1, Uint8 border_color2, Uint8 border_color3, Uint8 bg_color1, Uint8 bg_color2, Uint8 bg_color3);
		int setTag(int id, string tag);
		int setAvailable(int id, bool available);
		int setNext(int id, AGELabelTTFElement* next);
		int setContent(int id, string content);
		int setFont(int id, int font);
		int setBorder(int id, bool border);
		int setBg(int id, bool bg);
		int setFont_color1(int id, Uint8 font_color1);
		int setFont_color2(int id, Uint8 font_color2);
		int setFont_color3(int id, Uint8 font_color3);
		int setBorder_margin(int id, Uint8 border_margin);
		int setBorder_color1(int id, Uint8 border_color1);
		int setBorder_color2(int id, Uint8 border_color2);
		int setBorder_color3(int id, Uint8 border_color3);
		int setBg_margin(int id, Uint8 border_margin);
		int setBg_color1(int id, Uint8 bg_color1);
		int setBg_color2(int id, Uint8 bg_color2);
		int setBg_color3(int id, Uint8 bg_color3);
		int setModified(int id, bool modified);
		int setRender(int id, Uint8 render);
		int setTexture(int id, SDL_Texture* texture);


	protected:



	private:
		int counter;
		AGELabelTTFElement* first;
		AGELabelTTFElement* last;

		AGELabelTTFElement* getElementById(int id);
		int searchAvailable();

};


#endif // AGELABELTTFINDEX_H


