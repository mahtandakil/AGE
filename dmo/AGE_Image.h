/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 26/09/16
* Autogen: 1.1.2c
****************************************************************************/


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include <iostream>
#include <string>


using namespace std;


#ifndef AGE_IMAGE_H
#define AGE_IMAGE_H


class AGE_Image
{
	public:
		AGE_Image();
		virtual ~AGE_Image();

		int printNode();
		int getIdent();
		string getTag();
		bool getAvailable();
		AGE_Image* getNext();
		string getSrc();
		SDL_Surface* getSurface();
		SDL_Texture* getTexture();
		int getTexture_h();
		int getTexture_w();
		int setIdent(int ident);
		int setTag(string tag);
		int setAvailable(bool available);
		int setNext(AGE_Image* next);
		int setSrc(string src);
		int setSurface(SDL_Surface* surface);
		int setTexture(SDL_Texture* texture);
		int setTexture_h(int texture_h);
		int setTexture_w(int texture_w);



	protected:


	private:
		int ident;
		string tag;
		bool available;
		AGE_Image* next;
		string src;
		SDL_Surface* surface;
		SDL_Texture* texture;
		int texture_h;
		int texture_w;

};


#endif // AGE_IMAGE_H



