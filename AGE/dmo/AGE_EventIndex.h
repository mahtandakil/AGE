/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 16/02/16
* Autogen: 1.1.2b
****************************************************************************/


#include "AGE_Event.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_EVENTINDEX_H
#define AGE_EVENTINDEX_H


class AGE_EventIndex
{
	public:
		AGE_EventIndex();
		virtual ~AGE_EventIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		AGE_Event* getFirst();
		AGE_Event* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, Uint32 event, Uint32 device, int window, Uint32 timestamp, Uint32 state, int x, int y, int w, int h, Uint8 count, Uint16 mod);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGE_Event* getNext(int id);
		Uint32 getEvent(int id);
		Uint32 getDevice(int id);
		int getWindow(int id);
		Uint32 getTimestamp(int id);
		Uint32 getState(int id);
		int getX(int id);
		int getY(int id);
		int getW(int id);
		int getH(int id);
		Uint8 getCount(int id);
		Uint16 getMod(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, AGE_Event* next);
		int setEvent(int ident, Uint32 event);
		int setDevice(int ident, Uint32 device);
		int setWindow(int ident, int window);
		int setTimestamp(int ident, Uint32 timestamp);
		int setState(int ident, Uint32 state);
		int setX(int ident, int x);
		int setY(int ident, int y);
		int setW(int ident, int w);
		int setH(int ident, int h);
		int setCount(int ident, Uint8 count);
		int setMod(int ident, Uint16 mod);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGE_Event* next);
		int searchByEvent(Uint32 event);
		int searchByDevice(Uint32 device);
		int searchByWindow(int window);
		int searchByTimestamp(Uint32 timestamp);
		int searchByState(Uint32 state);
		int searchByX(int x);
		int searchByY(int y);
		int searchByW(int w);
		int searchByH(int h);
		int searchByCount(Uint8 count);
		int searchByMod(Uint16 mod);


	protected:



	private:
		int nodes;
		int next_ident;
		AGE_Event* first;
		AGE_Event* last;


};


#endif // AGE_EVENTINDEX_H

