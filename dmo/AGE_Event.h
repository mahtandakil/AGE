/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 12/04/16
* Autogen: 1.1.2b
****************************************************************************/


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_EVENT_H
#define AGE_EVENT_H


class AGE_Event
{
	public:
		AGE_Event();
		virtual ~AGE_Event();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		AGE_Event* getNext();
		Uint32 getEvent();
		Uint32 getDevice();
		int getWindow();
		Uint32 getTimestamp();
		Uint32 getState();
		int getX();
		int getY();
		int getW();
		int getH();
		Uint8 getCount();
		Uint16 getMod();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(AGE_Event* next);
		int setEvent(Uint32 event);
		int setDevice(Uint32 device);
		int setWindow(int window);
		int setTimestamp(Uint32 timestamp);
		int setState(Uint32 state);
		int setX(int x);
		int setY(int y);
		int setW(int w);
		int setH(int h);
		int setCount(Uint8 count);
		int setMod(Uint16 mod);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		AGE_Event* next;
		Uint32 event;
		Uint32 device;
		int window;
		Uint32 timestamp;
		Uint32 state;
		int x;
		int y;
		int w;
		int h;
		Uint8 count;
		Uint16 mod;

};


#endif // AGE_EVENT_H



