/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_Event.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_EVENTINDEX_H
#define TSGE_EVENTINDEX_H


class TSGE_EventIndex
{
	public:
		TSGE_EventIndex();
		virtual ~TSGE_EventIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		TSGE_Event* getFirst();
		TSGE_Event* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, Uint32 event, Uint32 device, int window, Uint32 timestamp, Uint32 state, int x, int y, int w, int h, Uint8 count, Uint16 mod);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		TSGE_Event* getNext(int id);
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
		int setNext(int ident, TSGE_Event* next);
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
		int searchByNext(TSGE_Event* next);
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
		TSGE_Event* first;
		TSGE_Event* last;


};


#endif // TSGE_EVENTINDEX_H

