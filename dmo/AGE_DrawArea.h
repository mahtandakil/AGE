/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 12/12/16
* Autogen: 1.1.2c
****************************************************************************/


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_DRAWAREA_H
#define AGE_DRAWAREA_H


class AGE_DrawArea
{
	public:
		AGE_DrawArea();
		virtual ~AGE_DrawArea();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		AGE_DrawArea* getNext();
		int getX();
		int getY();
		int getW();
		int getH();
		bool getSolid();
		int getWindow_id();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(AGE_DrawArea* next);
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
		AGE_DrawArea* next;
		int x;
		int y;
		int w;
		int h;
		bool solid;
		int window_id;

};


#endif // AGE_DRAWAREA_H



