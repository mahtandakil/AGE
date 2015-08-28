/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 28/08/2015
****************************************************************************/


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
const string API_VERSION = "0.5.5";
const string SDLLIB_VERSION = "2.0.3fix1";
const string SDLLIB_IMAGE_VERSION = "2.0.0";
const SDL_RendererFlip AGE_FLIPH = SDL_FLIP_HORIZONTAL;
const SDL_RendererFlip AGE_FLIPV = SDL_FLIP_VERTICAL;
const SDL_RendererFlip AGE_FLIPHV = (SDL_RendererFlip)3;
const SDL_RendererFlip AGE_FLIPN = SDL_FLIP_NONE;

#endif // AGEPREFIXEDVALUES_H_INCLUDED
