/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 13/08/2015
* Last change: 22/08/2015
* Autogen: CListGen 1.0.3
****************************************************************************/


#include <iostream>
#include <SDL.h>


using namespace std;


#ifndef AGECOLLISIONAREAELEMENT_H
#define AGECOLLISIONAREAELEMENT_H


class AGECollisionAreaElement
{
	public:
		AGECollisionAreaElement();
		virtual ~AGECollisionAreaElement();

		int getId(); /**< Returns the 'id' value for this register. */
		string getTag(); /**< Returns the 'tag' value for this register. */
		bool getAvailable(); /**< Returns the 'available' value for this register. */
		AGECollisionAreaElement* getNext(); /**< Returns the 'next' value for this register. */
		Uint8 getType(); /**< Returns the 'type' value for this register. NOTE: for the moment only squared areas are supported (type=0)*/
		SDL_Rect getArea(); /**< Returns the 'area' value for this register. */
		Uint8 getColor1(); /**< Returns the 'color1' value for this register. */
		Uint8 getColor2(); /**< Returns the 'color2' value for this register. */
		Uint8 getColor3(); /**< Returns the 'color3' value for this register. */
		void setId(int id); /**< Modifies the 'id' value for this register. */
		void setTag(string tag); /**< Modifies the 'tag' value for this register. */
		void setAvailable(bool available); /**< Modifies the 'available' value for this register. */
		void setNext(AGECollisionAreaElement* next); /**< Modifies the 'next' value for this register. */
		void setType(Uint8 type); /**< Modifies the 'type' value for this register. */
		void setArea(SDL_Rect area); /**< Modifies the 'area' value for this register. */
		void setColor1(Uint8 color1); /**< Modifies the 'color1' value for this register. */
		void setColor2(Uint8 color2); /**< Modifies the 'color2' value for this register. */
		void setColor3(Uint8 color3); /**< Modifies the 'color3' value for this register. */


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGECollisionAreaElement* next;
		Uint8 type;
		SDL_Rect area;
		Uint8 color1;
		Uint8 color2;
		Uint8 color3;

};


#endif // AGECOLLISIONAREAELEMENT_H


