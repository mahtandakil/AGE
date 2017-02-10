/****************************************************************************
* Created for: AGE v1
* Dev line: TSGE v2
* Creation day: 17/07/2015
* Last change: 09/02/2017
****************************************************************************/


#include "TSGE_definitions.h"
#include "TSGE_util.h"
#include "dmo/DMOM.h"


#include <iostream>


using namespace std;


#ifndef TSGE_H_INCLUDED
#define TSGE_H_INCLUDED

//---------------------------------------------------------------------------

class TSGE {

public:
	TSGE();
	virtual ~TSGE();
	bool tsge_collision_check(TSGE_Cartesian area1, TSGE_Cartesian area2);
	bool tsge_core_load_libs();
	DMOM* tsge_dmom_get();
	int tsge_draw_area_create(TSGE_Cartesian coords, bool solid, int window_id = 0);
	TSGE_Event_Status tsge_event_get_status();
	int tsge_event_process();
	int tsge_font_delete(int font_id);
	int tsge_font_deploy(string src, int font_size);
	int tsge_font_free(int font_id);
	int tsge_image_delete(int image_id);
	int tsge_image_deploy(string src, int window_id = 0);
	int tsge_image_deploy(string src, int x, int y, int window_id = 0);
	int tsge_image_free(int image_id);
	int tsge_image_move(int image_id, int x, int y, int window_id = 0);
	int tsge_image_move_to_draw_area(int image_id, int draw_area_id, int x, int y);
	TSGE_Cartesian tsge_image_size_get(int image_id);
	int tsge_image_tag_set(int image_id, string tag);
	int tsge_label_compose(string text, int font_id, TSGE_Color color, Uint8 mode = TSGE_LABELMODEFLAG_SOLID, TSGE_Color bg_color = {0,0,0,0});
    int tsge_line_draw(TSGE_Cartesian point1, TSGE_Cartesian point2, TSGE_Color color, SDL_BlendMode blend_mode = TSGE_BLENDINGFLAG_BLEND, int window_id = 0);
	void tsge_pause(int miliseconds);
	int tsge_square_draw(TSGE_Cartesian square, TSGE_Color color, SDL_BlendMode blend_mode = TSGE_BLENDINGFLAG_BLEND, int window_id = 0);
	TSGE_Cartesian tsge_window_cartesian_get(int window_id = 0);
	int tsge_window_cartesian_set(TSGE_Cartesian cartesian, int window_id = 0);
	int tsge_window_clear(int window_id = 0, TSGE_Color color = {0,0,0,255});
	int tsge_window_create(string title, TSGE_Cartesian coords, Uint32 wflags = 0, Uint32 rflags = 0);
	int tsge_window_fading(Uint8 alpha, int window_id = 0, TSGE_Color color = {0,0,0,255});
	int tsge_window_position_set(TSGE_Cartesian position, int window_id = 0);
	int tsge_window_refresh();
	int tsge_window_refresh(int window_id);
	int tsge_window_remove(int window_id);
	int tsge_window_set_focus(int window_id);
	int tsge_window_set_visible(int window_id, bool visible);
    int tsge_window_size_set(TSGE_Cartesian size, int window_id = 0);

private:
	DMOM* dmom;
	TSGE_DrawAreaIndex* draw_area_index;
	TSGE_EventIndex* event_index;
    TSGE_FontIndex* font_index;
	TSGE_ImageIndex* image_index;
	SDL_Event sdl_event_handler;
	TSGE_WindowIndex* window_index;

    int tsge_font_unload(int font_id);
    int tsge_image_unload(int image_id);
    SDL_Surface* tsge_sdlttf_create_surface(string text, TTF_Font* font, TSGE_Color color, Uint8 mode, TSGE_Color bg_color);
    SDL_Texture* tsge_sdlttf_create_texture(SDL_Surface* temp_surface, SDL_Renderer* render = nullptr);
	bool tsge_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int x, int y, int w, int h);
	bool tsge_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int img_x, int img_y, int img_w, int img_h, int dst_x, int dst_y, int dst_w, int dst_h);

};


//---------------------------------------------------------------------------


#endif // TSGE_H_INCLUDED

