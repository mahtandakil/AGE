/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v1
* Creation day: 02/08/2015
* Last change: 27/08/2015
****************************************************************************/



#include "AGEPrefixedValues.h"
#include "AGETextureListElement.h"


#ifndef AGETEXTURELISTINDEX_H
#define AGETEXTURELISTINDEX_H


class AGETextureListIndex
{
    public:
        AGETextureListIndex();
        virtual ~AGETextureListIndex();

        int createRegister(string src); /**< Dynamically creates a register to store the image and its information. */
        int freeList(); /**< Unloads all the registers stored in the list */
        bool getAvailable(int id); /**< Check if a register is available for use*/
        SDL_Rect getCollisionRect(int id); /**< Returns to SDL_Rect information of the image. This is needed for the collision system. */
        int getCounter(); /**< Returns the number of registers that are in usage. */
        AGETextureListElement* getElementById(int id); /**< Search a register using its id, and returns the full register. */
        int getId(int id); /**< This function can be used to check the proper link of the list and if some element exists. */
        string getSrc(int id); /**< Returns the 'src' value for a specific register. */
        SDL_Texture* getTexture(int id); /**< Returns the 'texture' value for a specific register. */
        int getNextId(int id); /**< Returns the 'next' value for a specific register. */
        int getTextureH(int id); /**< Returns the 'texture_h' value for a specific register. */
        int getTextureW(int id); /**< Returns the 'texture_w' value for a specific register. */
        int linkCollisionArea(int id, SDL_Rect area, string tag); /**< Binds dynamically  a collision area to a specific image. The colors of the area will be set randomly.*/
        int linkCollisionArea(int id, SDL_Rect area, string tag, int color1, int color2, int color3); /**< Binds dynamically  a collision area to a specific image. The colors need to be specified in RGB format.*/
        int searchByAvailable(bool available); /**< Return the first register with a specific 'available' value */
        int searchBySrc(string src); /**< Return the first register with a specific 'src' value */
        int setAvailable(int id, bool available); /**< Modifies the 'available' value for a specific register. Establishing this variable to 'true' will allow the system to use the register for a new image and remove the previous image. */
        int setPosition(int id, int x, int y); /**< Modifies the 'x' & 'y' values for a specific register. This values are used to establish the exactly position of the image on the screen. */
        int setSrc(int id, string src); /**< Modifies the 'string' value for a specific register */
        int setTexture(int id, SDL_Texture* texture); /**< Modifies the pointer for the texture recorded in a specific register */

    protected:


    private:
        int counter;
        AGETextureListElement* first;
        AGETextureListElement* last;

        int searchAvailable();

};

#endif // AGETEXTURELISTINDEX_H
