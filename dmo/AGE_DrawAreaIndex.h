/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 12/12/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_DrawArea.h"


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_DRAWAREAINDEX_H
#define AGE_DRAWAREAINDEX_H


class AGE_DrawAreaIndex
{
	public:
		AGE_DrawAreaIndex();
		virtual ~AGE_DrawAreaIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		AGE_DrawArea* getFirst();
		AGE_DrawArea* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, int x, int y, int w, int h, bool solid, int window_id);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGE_DrawArea* getNext(int id);
		int getX(int id);
		int getY(int id);
		int getW(int id);
		int getH(int id);
		bool getSolid(int id);
		int getWindow_id(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, AGE_DrawArea* next);
		int setX(int ident, int x);
		int setY(int ident, int y);
		int setW(int ident, int w);
		int setH(int ident, int h);
		int setSolid(int ident, bool solid);
		int setWindow_id(int ident, int window_id);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGE_DrawArea* next);
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
		AGE_DrawArea* first;
		AGE_DrawArea* last;


};


#endif // AGE_DRAWAREAINDEX_H

