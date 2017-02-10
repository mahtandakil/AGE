/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Font.h"


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_FONTINDEX_H
#define TSGE_FONTINDEX_H


class TSGE_FontIndex
{
	public:
		TSGE_FontIndex();
		virtual ~TSGE_FontIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		TSGE_Font* getFirst();
		TSGE_Font* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, TTF_Font* font, string src, int size);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		TSGE_Font* getNext(int id);
		TTF_Font* getFont(int id);
		string getSrc(int id);
		int getSize(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, TSGE_Font* next);
		int setFont(int ident, TTF_Font* font);
		int setSrc(int ident, string src);
		int setSize(int ident, int size);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(TSGE_Font* next);
		int searchByFont(TTF_Font* font);
		int searchBySrc(string src);
		int searchBySize(int size);


	protected:



	private:
		int nodes;
		int next_ident;
		TSGE_Font* first;
		TSGE_Font* last;


};


#endif // TSGE_FONTINDEX_H

