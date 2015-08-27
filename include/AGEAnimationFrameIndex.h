/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 27/08/2015
* Last change: 27/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEAnimationFrameElement.h"


#include <iostream>


using namespace std;


#ifndef AGEANIMATIONFRAMEINDEX_H
#define AGEANIMATIONFRAMEINDEX_H


class AGEAnimationFrameIndex
{
	public:
		AGEAnimationFrameIndex();
		virtual ~AGEAnimationFrameIndex();

		int createRegister(string tag);
		int freeList();
		int getId(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGEAnimationFrameElement* getNext(int id);
		AGEAnimationFrameElement* getElementById(int id);
		int getImage_x(int id);
		int getImage_y(int id);
		int getImage_w(int id);
		int getImage_h(int id);
		int getImage_d(int id);
		int searchById(int id);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGEAnimationFrameElement* next);
		int searchByImage_x(int image_x);
		int searchByImage_y(int image_y);
		int searchByImage_w(int image_w);
		int searchByImage_h(int image_h);
		int searchByImage_d(int image_d);
		int setElementData(int id, string tag, int image_x, int image_y, int image_w, int image_h, int image_d);
		int setElementData(int id, int image_x, int image_y, int image_w, int image_h, int image_d);
		int setTag(int id, string tag);
		int setAvailable(int id, bool available);
		int setNext(int id, AGEAnimationFrameElement* next);
		int setImage_x(int id, int image_x);
		int setImage_y(int id, int image_y);
		int setImage_w(int id, int image_w);
		int setImage_h(int id, int image_h);
		int setImage_d(int id, int image_d);


	protected:



	private:
		int counter;
		AGEAnimationFrameElement* first;
		AGEAnimationFrameElement* last;

		int searchAvailable();

};


#endif // AGEANIMATIONFRAMEINDEX_H


