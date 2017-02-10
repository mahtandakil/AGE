/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_DrawArea.h"


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_DRAWAREAINDEX_H
#define TSGE_DRAWAREAINDEX_H


class TSGE_DrawAreaIndex
{
	public:
		TSGE_DrawAreaIndex();
		virtual ~TSGE_DrawAreaIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		TSGE_DrawArea* getFirst();
		TSGE_DrawArea* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, int x, int y, int w, int h, bool solid, int window_id);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		TSGE_DrawArea* getNext(int id);
		int getX(int id);
		int getY(int id);
		int getW(int id);
		int getH(int id);
		bool getSolid(int id);
		int getWindow_id(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, TSGE_DrawArea* next);
		int setX(int ident, int x);
		int setY(int ident, int y);
		int setW(int ident, int w);
		int setH(int ident, int h);
		int setSolid(int ident, bool solid);
		int setWindow_id(int ident, int window_id);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(TSGE_DrawArea* next);
		int searchByX(int x);
		int searchByY(int y);
		int searchByW(int w);
		int searchByH(int h);
		int searchBySolid(bool solid);
		int searchByWindow_id(int window_id);


	protected:



	private:
		int nodes;
		int next_ident;
		TSGE_DrawArea* first;
		TSGE_DrawArea* last;


};


#endif // TSGE_DRAWAREAINDEX_H

