/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 29/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEFontElement.h"


#include <iostream>


using namespace std;


#ifndef AGEFONTINDEX_H
#define AGEFONTINDEX_H


class AGEFontIndex
{
	public:
		AGEFontIndex();
		virtual ~AGEFontIndex();

		int createRegister(string tag);
		int freeList();
		int getId(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGEFontElement* getNext(int id);
		string getSrc(int id);
		TTF_Font* getFont(int id);
		int searchById(int id);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGEFontElement* next);
		int searchBySrc(string src);
		int searchByFont(TTF_Font* font);
		int setElementData(int id, string tag, string src, TTF_Font* font);
		int setElementData(int id, string src, TTF_Font* font);
		int setTag(int id, string tag);
		int setAvailable(int id, bool available);
		int setNext(int id, AGEFontElement* next);
		int setSrc(int id, string src);
		int setFont(int id, TTF_Font* font);


	protected:



	private:
		int counter;
		AGEFontElement* first;
		AGEFontElement* last;

		AGEFontElement* getElementById(int id);
		int searchAvailable();

};


#endif // AGEFONTINDEX_H


