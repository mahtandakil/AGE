/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 29/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include <SDL_ttf.h>


#include <iostream>


using namespace std;


#ifndef AGEFONTELEMENT_H
#define AGEFONTELEMENT_H


class AGEFontElement
{
	public:
		AGEFontElement();
		virtual ~AGEFontElement();

		int getId();
		string getTag();
		bool getAvailable();
		AGEFontElement* getNext();
		string getSrc();
		TTF_Font* getFont();
		void setId(int id);
		void setTag(string tag);
		void setAvailable(bool available);
		void setNext(AGEFontElement* next);
		void setSrc(string src);
		void setFont(TTF_Font* font);


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGEFontElement* next;
		string src;
		TTF_Font* font;

};


#endif // AGEFONTELEMENT_H


