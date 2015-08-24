/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 24/08/2015
* Last change: 24/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGEAnimationElement.h"


#include <iostream>


using namespace std;


#ifndef AGEANIMATIONINDEX_H
#define AGEANIMATIONINDEX_H


class AGEAnimationIndex
{
	public:
		AGEAnimationIndex();
		virtual ~AGEAnimationIndex();

		int createRegister(string tag);
		int freeList();
		int getId(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGEAnimationElement* getNext(int id);
		Uint8 getElements(int id);
		Uint8 getInit(int id);
		AGETextureListIndex* getTexture_index(int id);
		int searchById(int id);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGEAnimationElement* next);
		int searchByElements(Uint8 elements);
		int searchByInit(Uint8 init);
		int searchByTexture_index(AGETextureListIndex* texture_index);
		int setElementData(int id, string tag, Uint8 elements, Uint8 init, AGETextureListIndex* texture_index);
		int setElementData(int id, Uint8 elements, Uint8 init, AGETextureListIndex* texture_index);
		int setTag(int id, string tag);
		int setAvailable(int id, bool available);
		int setNext(int id, AGEAnimationElement* next);
		int setElements(int id, Uint8 elements);
		int setInit(int id, Uint8 init);
		int setTexture_index(int id, AGETextureListIndex* texture_index);


	protected:



	private:
		int counter;
		AGEAnimationElement* first;
		AGEAnimationElement* last;

		AGEAnimationElement* getElementById(int id);
		int searchAvailable();

};


#endif // AGEANIMATIONINDEX_H


