/****************************************************************************
* Created for: ArcadeBox C
* Dev line: AGE v1
* Creation day: 11/02/2014
* Last change: 22/08/2015
****************************************************************************/


#include "AGECollisionAreaIndex.h"
#include "AGEPrefixedValues.h"
#include "AGETextureListIndex.h"


#include <SDL.h>
#include <SDL_image.h>


#include <iostream>
#include <unistd.h>


using namespace std;


#ifndef AGE_H
#define AGE_H

/*! AGE class */

class AGE
{
    public:
        AGE();
        virtual ~AGE();

        void configure(int x, int y, string window_mode, string wtitle); /**< This function configures the window mode & size. */
        bool checkFile(string src); /**< Checks if the provided file exists and it's readable. */
        bool checkAreaCollision(int area_id, int texture_id); /**< Checks if there is a collision between an area and a texture. */
        bool checkAreaCollision(int area_id1, int texture_id, int area_id2); /**< Checks if there is a collision between an area and a binded area. */
        bool checkAreaCollision(int area_id1, int texture_id, int x, int y, int area_id2); /**< Checks if there is a collision between an area and a binded area. The x & y values are needed if the image has been draw several times in the same screen. */
        bool checkAreaBindAreaCollision(int area_id1, int texture_id, int area_id2); /**< Checks if there is a collision between an area and a binded area. */
        bool checkAreasCollision(int area_id1, int area_id2); /**< Checks if there is a collision between two areas. */
        bool checkBindAreasCollision(int texture_id1, int area_id1, int texture_id2, int area_id2); /**< Checks if there is a collision between two binded areas. */
        bool checkTextureAreaCollision(int id_texture, int id_area); /**< Checks if there is a collision between an image and an area. */
        bool checkTextureBindedAreaCollision(int texture_id1, int texture_id2, int area_id); /**< Checks if there is a collision between an image and a binded area. */
        bool checkTextureBindedAreaCollision(int texture_id1, int x1, int y1, int texture_id2, int area_id); /**< Checks if there is a collision between an area and a binded area. The x & y values are needed if the image has been draw several times in the same screen. */
        bool checkTextureBindedAreaCollision(int texture_id1, int x1, int y1, int texture_id2, int x2, int y2, int area_id); /**< Checks if there is a collision between an area and a binded area. The x & y values are needed if the image has been draw several times in the same screen. */
        bool checkTexturesCollision(int id1, int id2); /**< Checks if there is a collision between two textures. */
        bool checkTexturesCollision(int id1, int id2, int x2, int y2); /**< Checks if there is a collision between two textures. The x & y values are needed if the image has been draw several times in the same screen. */
        bool checkTexturesCollision(int id1, int x1, int y1, int id2, int x2, int y2); /**< Checks if there is a collision between two textures. The x & y values are needed if the image has been draw several times in the same screen. */
        void clearScreen(); /**< All the screen shows only black. */
        void deleteImage(int id); /**< Deletes a loaded image and sets its register as usable. */
        void drawCollisionArea(int id); /**< Make visible the specified collision area. */
        void drawCollisionArea(int id_texture, int id_area); /**< Make visible the specified binded collision area. */
        void drawLine(int x1, int y1, int x2, int y2, int color1, int color2, int color3); /**< Draws a simple line with a size of 1 pixel. */
        void drawSquare(int x1, int y1, int x2, int y2, int color1, int color2, int color3); /**< Draws a square. */
        void drawSquare(int x1, int y1, int x2, int y2, int color1, int color2, int color3, int alpha); /**< Draws a square. This function allows to specify the value of the alpha channel. */
        int deployImage(string src); /**< This functions loads a image. */
        int deployImage(string src, int x, int y); /**< This functions loads a image and shows it on the screen */
        void fadeScreen(int alpha); /**< Sets black the screen with a specific alpha channel value. */
        void freeImage(int id); /**< Sets specific image as usable. It means, that if you want to load this image after the delete, it will be restored from the memory. If other image is loaded, the original register could be used to store the new image, and the old image will be definitely removed from memory. */
        SDL_Event* getEventHandler(); /**< Return the SDL event handler for the app. */
        AGETextureListIndex* getTextureIndex(); /**< Return the texture index of the main process */
        int linkCollisionAreaToScreen(string tag, int x, int y, int w, int h); /**< Defines an collision area with random color. */
        int linkCollisionAreaToScreen(string tag, int x, int y, int w, int h, int color1, int colo2, int color3); /**< Defines an collision area with specific color. */
        int linkCollisionAreaToTexture(int id, string tag, int x, int y, int w, int h); /**< Defines an collision area for an image with random color. */
        int linkCollisionAreaToTexture(int id, string tag, int x, int y, int w, int h, int color1, int color2, int color3); /**< Defines an collision area for an image with specific color. */
        void loadAPI(); /**< This function loads and initializes the different libraries used by AGE, load the default images and creates the different index. */
        void moveBindCollisionArea(int texture_id, int area_id, int x, int y); /**< Changes the position of an binded area. */
        void moveCollisionArea(int id, int x, int y); /**< Changes the position of an area. */
        void moveImage(int id, int x, int y); /**< Changes the position of an image. */
        void pause(int miliseconds); /**< Pauses the execution of the engine for a time. */
        void refresh(); /**< Presents all the images on the screen. */
        void terminate(); /**< Unloads all the libraries & the index. */


    protected:

    private:
        AGECollisionAreaIndex* area_index;
        void drawCollisionArea(AGECollisionAreaElement* area, int mod_x, int mod_y);
        SDL_Event event_handler;
        SDL_Texture* missing_image;
        SDL_Renderer* renderer;
        int screen_x;
        int screen_y;
        AGETextureListIndex* texture_index;
        SDL_Surface* wsurface;
        SDL_Window* window;
        int window_mode;
        string window_title;

        void applyImage(SDL_Texture* texture, int x, int y, int w, int h);
        bool checkCollision(SDL_Rect area1, SDL_Rect area2);

};

#endif // AGE_H
