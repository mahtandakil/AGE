/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 08/05/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_Label.h"


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_LABELINDEX_H
#define AGE_LABELINDEX_H


class AGE_LabelIndex
{
	public:
		AGE_LabelIndex();
		virtual ~AGE_LabelIndex();

		int createNode(string tag="");
		int freeNode(int ident);
		int freeList();
		int deleteNode(int ident);
		int deleteList();
		AGE_Label* getFirst();
		AGE_Label* getNode(int id);
		int getPrevious(int ident);
		int printNodes();
		int purge();
		int searchAvailable(int limit=0);
		int setValues(int ident, string content, SDL_Texture* texture, int font, int font_color_r, int font_color_g, int font_color_b);
		int getIdent(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGE_Label* getNext(int id);
		string getContent(int id);
		SDL_Texture* getTexture(int id);
		int getFont(int id);
		int getFont_color_r(int id);
		int getFont_color_g(int id);
		int getFont_color_b(int id);
		int setTag(int ident, string tag);
		int setAvailable(int ident, bool available);
		int setNext(int ident, AGE_Label* next);
		int setContent(int ident, string content);
		int setTexture(int ident, SDL_Texture* texture);
		int setFont(int ident, int font);
		int setFont_color_r(int ident, int font_color_r);
		int setFont_color_g(int ident, int font_color_g);
		int setFont_color_b(int ident, int font_color_b);
		int searchByIdent(int ident);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGE_Label* next);
		int searchByContent(string content);
		int searchByTexture(SDL_Texture* texture);
		int searchByFont(int font);
		int searchByFont_color_r(int font_color_r);
		int searchByFont_color_g(int font_color_g);
		int searchByFont_color_b(int font_color_b);


	protected:



	private:
		int nodes;
		int next_ident;
		AGE_Label* first;
		AGE_Label* last;


};


#endif // AGE_LABELINDEX_H

