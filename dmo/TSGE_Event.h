/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_EVENT_H
#define TSGE_EVENT_H


class TSGE_Event
{
	public:
		TSGE_Event();
		virtual ~TSGE_Event();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		TSGE_Event* getNext();
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
		int setNext(TSGE_Event* next);
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
		TSGE_Event* next;
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


#endif // TSGE_EVENT_H



