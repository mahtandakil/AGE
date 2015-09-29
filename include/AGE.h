/****************************************************************************
* Created for: ArcadeBox C
* Dev line: AGE v1
* Creation day: 11/02/2014
* Last change: 29/09/2015
****************************************************************************/


#include "AGEAnimationIndex.h"
#include "AGECollisionAreaIndex.h"
#include "AGEFontIndex.h"
#include "AGELabelTTFIndex.h"
#include "AGEPrefixedValues.h"
#include "AGEStringsIndex.h"
#include "AGETextureListIndex.h"


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>


using namespace std;


#ifndef AGE_H
#define AGE_H

struct AGE_Color{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};


/****************************************************************************/

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
        void clearScreen(Uint8 color1, Uint8 color2, Uint8 color3); /**< All the screen shows only one color . */
        bool createFile(string file_src, string content="");
        void deleteImage(int id); /**< Deletes a loaded image and sets its register as usable. */
        void drawCollisionArea(int id); /**< Make visible the specified collision area. */
        void drawCollisionArea(int id_texture, int id_area); /**< Make visible the specified binded collision area. */
        void drawLine(int x1, int y1, int x2, int y2, int color1, int color2, int color3); /**< Draws a simple line with a size of 1 pixel. */
        void drawSquare(int x, int y, int w, int h, int color1, int color2, int color3); /**< Draws a square. */
        void drawSquare(int x, int y, int w, int h, int color1, int color2, int color3, int alpha); /**< Draws a square. This function allows to specify the value of the alpha channel. */
        void drawSquareBorder(int x, int y, int w, int h, int color1, int color2, int color3); /**< Draws only the border of a square. */
        int deployAnimation(string src); /**< This functions loads an animation and all its related images. */
        int deployAnimation(string src, int x, int y); /**< This functions loads an animation and all its related images and shows the first image on the screen */
        int deployFont(string src, int font_size, string mod); /**< This function loads a font file. */
        int deployImage(string src); /**< This functions loads a image. */
        int deployImage(string src, int x, int y); /**< This functions loads a image and shows it on the screen */
        int deployLabel(string value, int font_id, Uint8 render, Uint8 color1, Uint8 color2, Uint8 color3, bool background=false, Uint8 bg_margin=0, Uint8 bg_color1=0, Uint8 bg_color2=0, Uint8 bg_color3=0, bool border=false, Uint8 border_margin=0, Uint8 border_color1=0, Uint8 border_color2=0, Uint8 border_color3=0); /**< This functions creates a label. */
        int deployString(string value1=AGE_NO_STRING_SET, string value2=AGE_NO_STRING_SET, string value3=AGE_NO_STRING_SET);
        void fadeScreen(int alpha); /**< Sets black the screen with a specific alpha channel value. */
        void freeImage(int id); /**< Sets specific image as usable. It means, that if you want to load this image after the delete, it will be restored from the memory. If other image is loaded, the original register could be used to store the new image, and the old image will be definitely removed from memory. */
        SDL_Event* getEventHandler(); /**< Return the SDL event handler for the app. */
        SDL_Rect getImageSize(int image_id);
        SDL_Rect getLabelSize(int label_id);
        AGE_Color getPixelColor(int texture_id, int x, int y);
        string getString(int register_id, int string_id);
        AGETextureListIndex* getTextureIndex(); /**< Return the texture index of the main process */
        int getRandom(int limit);
        int getRandom(int limit1, int limit2);
        SDL_Rect getWindowSize();
        string itos(int number);
        int linkCollisionAreaToScreen(string tag, int x, int y, int w, int h); /**< Defines an collision area with random color. */
        int linkCollisionAreaToScreen(string tag, int x, int y, int w, int h, int color1, int colo2, int color3); /**< Defines an collision area with specific color. */
        int linkCollisionAreaToTexture(int id, string tag, int x, int y, int w, int h); /**< Defines an collision area for an image with random color. */
        int linkCollisionAreaToTexture(int id, string tag, int x, int y, int w, int h, int color1, int color2, int color3); /**< Defines an collision area for an image with specific color. */
        void loadAPI(); /**< This function loads and initializes the different libraries used by AGE, load the default images and creates the different index. */
        int modifyString(int string_id, string value1=AGE_NO_STRING_SET, string value2=AGE_NO_STRING_SET, string value3=AGE_NO_STRING_SET);
        int moveAnimation(int animation_id, int frame_id, int x, int y, double angle=0.0, SDL_Point* center=NULL, SDL_RendererFlip flip=AGE_FLIPN); /**< Changes the position of an animation image, and returns the id of the next frame. This function don't cares about the delay specified in the GAN file. */
        void moveBindCollisionArea(int texture_id, int area_id, int x, int y); /**< Changes the position of an binded area. */
        void moveCollisionArea(int id, int x, int y); /**< Changes the position of an area. */
        void moveImage(int id, int x, int y, double size_mod=1.0, double angle=0.0, SDL_Point* center=NULL, SDL_RendererFlip flip=AGE_FLIPN); /**< Changes the position of an image. */
        void moveLabel(int label_id, int x, int y, double angle=0.0, SDL_Point* center=NULL, SDL_RendererFlip flip=AGE_FLIPN); /**< Changes the position of a label. */
        void pause(int miliseconds); /**< Pauses the execution of the engine for a time. */
        void refresh(); /**< Presents all the images on the screen. */
        void removeString(int string_id);
        int searchString(string value, int position);
        int setLabelBg(int label_id, bool active=false, Uint8 margin=0, Uint8 color1=0, Uint8 color2=0, Uint8 color3=0); /**< Changes the color and the status of the string background*/
        int setLabelBorder(int label_id, bool active=false, Uint8 margin=0, Uint8 color1=0, Uint8 color2=0, Uint8 color3=0); /**< Changes the color and the status of the string border */
        int setLabelColor(int label_id, Uint8 color1=0, Uint8 color2=0, Uint8 color3=0); /**< Changes the color of the string */
        int setLabelValue(int label_id, string value); /**< Changes the string showed in the label */
        void terminate(); /**< Unloads all the libraries & the index. */


    protected:

    private:
        AGEAnimationIndex* animation_index;
        AGECollisionAreaIndex* area_index;
        void drawCollisionArea(AGECollisionAreaElement* area, int mod_x, int mod_y);
        SDL_Event event_handler;
        AGEFontIndex* font_index;
        TTF_Font* missing_font;
        SDL_Texture* missing_image;
        AGELabelTTFIndex* labelttf_index;
        SDL_Renderer* renderer;
        int screen_x;
        int screen_y;
        AGEStringsIndex* string_index;
        AGETextureListIndex* texture_index;
        SDL_Surface* wsurface;
        SDL_Window* window;
        int window_mode;
        string window_title;

        void applyAnimation(SDL_Texture* texture, int x, int y, int cut_x, int cut_y, int cut_w, int cut_h);
        void applyAnimation(SDL_Texture* texture, int x, int y, int cut_x, int cut_y, int cut_w, int cut_h, double angle, SDL_Point* center, SDL_RendererFlip flip);
        void applyImage(SDL_Texture* texture, int x, int y, int w, int h);
        void applyImage(SDL_Texture* texture, int x, int y, int w, int h, double size_mod, double angle, SDL_Point* center, SDL_RendererFlip flip);
        bool checkCollision(SDL_Rect area1, SDL_Rect area2);
        SDL_Texture* renderTTF(TTF_Font* font, string value, SDL_Color label_color, SDL_Color bg_color, int mode);

};

#endif // AGE_H
