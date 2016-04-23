/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 12/04/16
* Autogen: 1.1.2b
****************************************************************************/


#include "AGE_Image.h"


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_IMAGEINDEX_H
#define AGE_IMAGEINDEX_H


class AGE_ImageIndex
{
	public:
		AGE_ImageIndex();
		virtual ~AGE_ImageIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		AGE_Image* getFirst();
		AGE_Image* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, string src, SDL_Surface* surface, SDL_Texture* texture, int texture_h, int texture_w);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGE_Image* getNext(int id);
		string getSrc(int id);
		SDL_Surface* getSurface(int id);
		SDL_Texture* getTexture(int id);
		int getTexture_h(int id);
		int getTexture_w(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, AGE_Image* next);
		int setSrc(int ident, string src);
		int setSurface(int ident, SDL_Surface* surface);
		int setTexture(int ident, SDL_Texture* texture);
		int setTexture_h(int ident, int texture_h);
		int setTexture_w(int ident, int texture_w);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGE_Image* next);
		int searchBySrc(string src);
		int searchBySurface(SDL_Surface* surface);
		int searchByTexture(SDL_Texture* texture);
		int searchByTexture_h(int texture_h);
		int searchByTexture_w(int texture_w);


	protected:



	private:
		int nodes;
		int next_ident;
		AGE_Image* first;
		AGE_Image* last;


};


#endif // AGE_IMAGEINDEX_H

