/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 24/08/2015
* Last change: 24/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGETextureListIndex.h"


#include <iostream>
#include <SDL.h>


using namespace std;


#ifndef AGEANIMATIONELEMENT_H
#define AGEANIMATIONELEMENT_H


class AGEAnimationElement
{
	public:
		AGEAnimationElement();
		virtual ~AGEAnimationElement();

		int getId();
		string getTag();
		bool getAvailable();
		AGEAnimationElement* getNext();
		Uint8 getElements();
		Uint8 getInit();
		AGETextureListIndex* getTexture_index();
		void setId(int id);
		void setTag(string tag);
		void setAvailable(bool available);
		void setNext(AGEAnimationElement* next);
		void setElements(Uint8 elements);
		void setInit(Uint8 init);
		void setTexture_index(AGETextureListIndex* texture_index);


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGEAnimationElement* next;
		Uint8 elements;
		Uint8 init;
		AGETextureListIndex* texture_index;

};


#endif // AGEANIMATIONELEMENT_H


