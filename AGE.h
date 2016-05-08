/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 17/07/2015
* Last change: 08/05/2016
****************************************************************************/


#include "AGE_definitions.h"
#include "AGE_util.h"
#include "dmo/DMOM.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "libs/sdl_gfx/SDL2_gfxPrimitives.h"


#include <iostream>


using namespace std;


//---------------------------------------------------------------------------

#ifndef AGE_H_INCLUDED
#define AGE_H_INCLUDED


class AGE {

public:
	AGE();
	virtual ~AGE();
	int age_circle_draw(AGE_Cartesian cartesian, AGE_Color color, bool filled = false, int window_id = 0);
	bool age_core_load_libs();
	DMOM* age_dmom_get();
	AGE_Event_Status age_event_get_status();
	int age_event_process();
	int age_font_deploy(string src, int font_size, string mod);
	int age_image_delete(int image_id);
	int age_image_deploy(string src, int window_id = 0);
	int age_image_deploy(string src, int x, int y, int window_id = 0);
	int age_image_free(int image_id);
	int age_image_move(int image_id, int x, int y, int window_id = 0);
	int age_label_deploy(string value, int font_id, AGE_Color color, int window_id = 0);
	int age_label_move(int label_id, int x, int y, int window_id = 0);
	int age_line_draw(AGE_Cartesian point1, AGE_Cartesian point2, AGE_Color color, int window_id = 0);
	void age_pause(int miliseconds);
	int age_square_draw(AGE_Cartesian square, AGE_Color color, int window_id = 0);
	AGE_Cartesian age_window_cartesian_get(int window_id = 0);
	int age_window_clear(int window_id = 0);
	int age_window_create(string title, AGE_Cartesian coords, Uint32 wflags = 0, Uint32 rflags = 0);
	int age_window_set_visible(int window_id, bool visible);
	int age_window_refresh();
	int age_window_refresh(int window_id);
	int age_window_remove(int window_id);
	int age_window_set_focus(int window_id);

private:
	DMOM* dmom;
	AGE_EventIndex* event_index;
	AGE_FontIndex* font_index;
	AGE_ImageIndex* image_index;
	AGE_LabelIndex* label_index;
	SDL_Event sdl_event_handler;
	AGE_WindowIndex* window_index;

    int age_image_unload(int image_id);
	bool age_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int x, int y, int w, int h);
    SDL_Texture* age_ttf_render(TTF_Font* font, string value, AGE_Color color, int window_id = 0);

};


//---------------------------------------------------------------------------


#endif // AGE_H_INCLUDED

