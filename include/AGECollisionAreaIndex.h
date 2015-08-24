/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 13/08/2015
* Last change: 24/08/2015
* Autogen: CListGen 1.0.3
****************************************************************************/


#include "AGECollisionAreaElement.h"


#include <iostream>
#include <SDL.h>


using namespace std;


#ifndef AGECOLLISIONAREAINDEX_H
#define AGECOLLISIONAREAINDEX_H


class AGECollisionAreaIndex
{
	public:
		AGECollisionAreaIndex();
		virtual ~AGECollisionAreaIndex();

		int createRegister(string tag); /**< Dynamically creates a register to store the area and its information. */
		int freeList(); /**< Unloads all the registers stored in the list */
		int getId(int id); /**< Returns the 'id' value for a specific register. . It's a little useless, but can be used to check if an specific id are stored in the list. */
		string getTag(int id); /**< Returns the 'tag' value for a specific register. */
		bool getAvailable(int id); /**< Check if a register is available for use*/
		AGECollisionAreaElement* getNext(int id); /**< Returns the 'next' value for a specific register. */
		Uint8 getType(int id); /**< Returns the type of collision area that is defined. NOTE: for the moment only squared areas are supported (type=0) */
		SDL_Rect getArea(int id); /**< Returns the 'area' value for a specific register. */
		Uint8 getColor1(int id);/**< Returns the 'color1' value for a specific register. */
		Uint8 getColor2(int id);/**< Returns the 'color2' value for a specific register. */
		Uint8 getColor3(int id); /**< Returns the 'color3' value for a specific register. */
		int searchById(int id); /**< This is function created automatically by CListGen. It's a little useless, but can be used to check if an specific id are stored in the list. */
		int searchByTag(string tag); /**< Return the first register with a specific 'tag' value */
		int searchByAvailable(bool available); /**< Return the first register with a specific 'available' value */
		int searchByNext(AGECollisionAreaElement* next); /**< Return the first register with a specific 'next' value */
		int searchByType(Uint8 type); /**< Return the first register with a specific 'type' value */
		int searchByColor1(Uint8 color1); /**< Return the first register with a specific 'color1' value */
		int searchByColor2(Uint8 color2); /**< Return the first register with a specific 'color2' value */
		int searchByColor3(Uint8 color3); /**< Return the first register with a specific 'color3' value */
		AGECollisionAreaElement* getElementById(int id); /**< Search a register using its id, and returns the full register. */
		int setElementData(int id, string tag, Uint8 type, SDL_Rect area, Uint8 color1, Uint8 color2, Uint8 color3); /**< This function allows to modify the information of a specific register and the 'tag' basic string.*/
		int setElementData(int id, Uint8 type, SDL_Rect area, Uint8 color1, Uint8 color2, Uint8 color3); /**< This function allows to modify the information of a specific register. */
		int setTag(int id, string tag); /**< Modifies the 'tag' value for a specific register. This is a basic element for the dynamic linked lists */
		int setArea(int id, SDL_Rect area); /**< Modifies the 'area' value for a specific register. */
		int setAvailable(int id, bool available); /**< Modifies the 'available' value for a specific register. This is a basic element for the dynamic linked lists */
		int setNext(int id, AGECollisionAreaElement* next);  /**< Modifies the 'next' value for a specific register. This is a basic element for the dynamic linked lists */
		int setType(int id, Uint8 type); /**< Modifies the 'type' value for a specific register. NOTE: for the moment only squared areas are supported (type=0) */
		int setPosition(int id, int x, int y); /**< Modifies the 'x' & 'y' values for a specific register. This values are used to establish the exactly position of the image on the screen. */
		int setColor(int id, Uint8 color1, Uint8 color2, Uint8 color3); /**< Modifies the color for a specific register in RGB format */
		int setColor1(int id, Uint8 color1); /**< Modifies the 'color1' red value for a specific register */
		int setColor2(int id, Uint8 color2); /**< Modifies the 'color1' green value for a specific register */
		int setColor3(int id, Uint8 color3); /**< Modifies the 'color1' blue value for a specific register */


	protected:



	private:
		int counter;
		AGECollisionAreaElement* first;
		AGECollisionAreaElement* last;

		int searchAvailable();

};


#endif // AGECOLLISIONAREAINDEX_H


