/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include <iostream>
#include <string>


using namespace std;


#ifndef TSGE_DRAWAREA_H
#define TSGE_DRAWAREA_H


class TSGE_DrawArea
{
	public:
		TSGE_DrawArea();
		virtual ~TSGE_DrawArea();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		TSGE_DrawArea* getNext();
		int getX();
		int getY();
		int getW();
		int getH();
		bool getSolid();
		int getWindow_id();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(TSGE_DrawArea* next);
		int setX(int x);
		int setY(int y);
		int setW(int w);
		int setH(int h);
		int setSolid(bool solid);
		int setWindow_id(int window_id);
		


	protected:


	private:
		int ident;
		string tag;
		bool available;
		TSGE_DrawArea* next;
		int x;
		int y;
		int w;
		int h;
		bool solid;
		int window_id;

};


#endif // TSGE_DRAWAREA_H



