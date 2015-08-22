/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v1
* Creation day: 02/08/2015
* Last change: 22/08/2015
****************************************************************************/


#include "AGEPrefixedValues.h"
#include "AGECollisionAreaIndex.h"


#ifndef AGETEXTURELISTELEMENT_H
#define AGETEXTURELISTELEMENT_H


class AGETextureListElement
{
    public:
        AGETextureListElement();
        virtual ~AGETextureListElement();

        AGECollisionAreaIndex* getAreaIndex(); /**< This function returns the area index object binded to the image. It's necessary to manage the areas vía the AGETextureListIndex object. */
        bool getAvailable(); /**< Check if a register is available for use*/
        int getId(); /**< Returns the 'id' value for this register. */
        AGETextureListElement* getNext(); /**< Returns the 'next' value for this register. */
        int getPositionX(); /**< Returns the 'position_x' value for this register. */
        int getPositionY(); /**< Returns the 'position_y' value for this register. */
        SDL_Texture* getTexture(); /**< Returns the 'texture' value for this register. */
        int getTextureH(); /**< Returns the 'texture_h' value for this register. */
        int getTextureW(); /**< Returns the 'position_w' value for this register. */
        string getSrc(); /**< Returns the 'src' value for this register. */
        AGECollisionAreaIndex* initAreaIndex(); /**< Creates an AGECollisionAreaIndex object binded to the image. */
        void setAvailable(bool available); /**< Modifies the 'available' value for this register. */
        void setId(int texture_id); /**< Modifies the 'id' value for this register. */
        void setNext(AGETextureListElement* next); /**< Modifies the 'next' value for this register. */
        void setPosition(int x, int y); /**< Sets the x & y values of the position of the image on the screen. This function is required to do a proper collision checking. */
        void setSrc(string src); /**< Modifies the 'src' value for this register. */
        void setTexture(SDL_Texture* texture); /**< Modifies the 'texture' value for this register. */


    protected:


    private:
        AGECollisionAreaIndex* area_index;
        bool available;
        AGETextureListElement* next;
        string src;
        SDL_Texture* texture;
        int texture_id;
        int texture_h;
        int texture_w;
        int position_x;
        int position_y;

};


#endif // AGETEXTURELISTELEMENT_H

