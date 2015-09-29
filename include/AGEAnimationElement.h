/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 06/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEAnimationFrameIndex.h"


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
		AGEAnimationFrameIndex* getFrames();
		string getFile();
		string getDescription();
		int getBgcolor1();
		int getBgcolor2();
		int getBgcolor3();
		int getImages();
		int getInit();
		int getTexture_h();
		int getTexture_w();
		SDL_Texture* getTexture();
		SDL_Surface* getSurface();
		void setId(int id);
		void setTag(string tag);
		void setAvailable(bool available);
		void setNext(AGEAnimationElement* next);
		void setFrames(AGEAnimationFrameIndex* frames);
		void setFile(string file);
		void setDescription(string description);
		void setBgcolor1(int bgcolor1);
		void setBgcolor2(int bgcolor2);
		void setBgcolor3(int bgcolor3);
		void setImages(int images);
		void setInit(int init);
		void setTexture_h(int texture_h);
		void setTexture_w(int texture_w);
		void setTexture(SDL_Texture* texture);
		void setSurface(SDL_Surface* surface);


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGEAnimationElement* next;
		AGEAnimationFrameIndex* frames;
		SDL_Texture* texture;
		SDL_Surface* surface;
		int texture_w;
		int texture_h;
		string file;
		string description;
		int bgcolor1;
		int bgcolor2;
		int bgcolor3;
		int images;
		int init;

};


#endif // AGEANIMATIONELEMENT_H


