/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 22/08/2015
****************************************************************************/


/*!
\mainpage The mainpage documentation

AGE is a wrapper for SDL and other libraries to make a simple game engine.

For build the project, you will the the following libraries:
    - SDL2
    - SDLI_image2
*/


#include <iostream>
#include <SDL.h>


using namespace std;


#ifndef AGEPREFIXEDVALUES_H_INCLUDED
#define AGEPREFIXEDVALUES_H_INCLUDED


const int API_FPS = 16;
const string API_IMAGES_IMAGEFILE_SRC = "AGE.bmp";
const string API_IMAGES_MISSINGIMAGEFILE_SRC = "AGE_missing.bmp";
const int API_IMAGES_MISSINGIMAGEFILE_W = 146;
const int API_IMAGES_MISSINGIMAGEFILE_H = 60;
const string API_VERSION = "0.4.2a";
const string SDLLIB_VERSION = "2.0.3fix1";
const string SDLLIB_IMAGE_VERSION = "2.0.0";


#endif // AGEPREFIXEDVALUES_H_INCLUDED
