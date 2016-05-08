/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 08/05/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_Font.h"


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_FONTINDEX_H
#define AGE_FONTINDEX_H


class AGE_FontIndex
{
	public:
		AGE_FontIndex();
		virtual ~AGE_FontIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		AGE_Font* getFirst();
		AGE_Font* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, string src, TTF_Font* font);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGE_Font* getNext(int id);
		string getSrc(int id);
		TTF_Font* getFont(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, AGE_Font* next);
		int setSrc(int ident, string src);
		int setFont(int ident, TTF_Font* font);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGE_Font* next);
		int searchBySrc(string src);
		int searchByFont(TTF_Font* font);


	protected:



	private:
		int nodes;
		int next_ident;
		AGE_Font* first;
		AGE_Font* last;


};


#endif // AGE_FONTINDEX_H

