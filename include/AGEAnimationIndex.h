/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 27/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEAnimationElement.h"
#include "AGEAnimationFrameIndex.h"

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
		AGEAnimationFrameIndex* getFrames(int id);
		AGEAnimationElement* getElementById(int id);
        string getFile(int id);
		string getDescription(int id);
		int getBgcolor1(int id);
		int getBgcolor2(int id);
		int getBgcolor3(int id);
		int getImages(int id);
		int getInit(int id);
		SDL_Texture* getTexture(int id);
		int getTexture_h(int id);
		int getTexture_w(int id);
		int searchById(int id);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGEAnimationElement* next);
		int searchByFrames(AGEAnimationFrameIndex* frames);
		int searchByFile(string file);
		int searchByDescription(string description);
		int searchByBgcolor1(int bgcolor1);
		int searchByBgcolor2(int bgcolor2);
		int searchByBgcolor3(int bgcolor3);
		int searchByImages(int images);
		int searchByInit(int init);
		int setElementData(int id, string tag, AGEAnimationFrameIndex* frames, string file, string description, int bgcolor1, int bgcolor2, int bgcolor3, int images, int init);
		int setElementData(int id, AGEAnimationFrameIndex* frames, string file, string description, int bgcolor1, int bgcolor2, int bgcolor3, int images, int init);
		int setTag(int id, string tag);
		int setAvailable(int id, bool available);
		int setNext(int id, AGEAnimationElement* next);
		int setFrames(int id, AGEAnimationFrameIndex* frames);
		int setTexture(int id, SDL_Texture* texture);
		int setTexture_w(int id, int texture_w);
		int setTexture_h(int id, int texture_h);
		int setFile(int id, string file);
		int setDescription(int id, string description);
		int setBgcolor1(int id, int bgcolor1);
		int setBgcolor2(int id, int bgcolor2);
		int setBgcolor3(int id, int bgcolor3);
		int setImages(int id, int images);
		int setInit(int id, int init);


	protected:



	private:
		int counter;
		AGEAnimationElement* first;
		AGEAnimationElement* last;

		int searchAvailable();

};


#endif // AGEANIMATIONINDEX_H


