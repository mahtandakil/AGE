/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 17/07/2015
* Last change: 19/12/2016
****************************************************************************/


#include "AGE_definitions.h"
#include "AGE_util.h"
#include "dmo/DMOM.h"


#include <iostream>


using namespace std;


#ifndef AGE_H_INCLUDED
#define AGE_H_INCLUDED

//---------------------------------------------------------------------------

class AGE {

public:
	AGE();
	virtual ~AGE();
	bool age_collision_check(AGE_Cartesian area1, AGE_Cartesian area2);
	bool age_core_load_libs();
	DMOM* age_dmom_get();
	int age_draw_area_create(AGE_Cartesian coords, bool solid, int window_id = 0);
	AGE_Event_Status age_event_get_status();
	int age_event_process();
	int age_font_delete(int font_id);
	int age_font_deploy(string src, int font_size);
	int age_font_free(int font_id);
	int age_image_delete(int image_id);
	int age_image_deploy(string src, int window_id = 0);
	int age_image_deploy(string src, int x, int y, int window_id = 0);
	int age_image_free(int image_id);
	int age_image_move(int image_id, int x, int y, int window_id = 0);
	int age_image_move_to_draw_area(int image_id, int draw_area_id, int x, int y);
	AGE_Cartesian age_image_size_get(int image_id);
	int age_image_tag_set(int image_id, string tag);
	int age_label_compose(string text, int font_id, AGE_Color color, Uint8 mode = AGE_LABELMODEFLAG_SOLID, AGE_Color bg_color = {0,0,0,0});
    int age_line_draw(AGE_Cartesian point1, AGE_Cartesian point2, AGE_Color color, SDL_BlendMode blend_mode = AGE_BLENDINGFLAG_BLEND, int window_id = 0);
	void age_pause(int miliseconds);
	int age_square_draw(AGE_Cartesian square, AGE_Color color, SDL_BlendMode blend_mode = AGE_BLENDINGFLAG_BLEND, int window_id = 0);
	AGE_Cartesian age_window_cartesian_get(int window_id = 0);
	int age_window_cartesian_set(AGE_Cartesian cartesian, int window_id = 0);
	int age_window_clear(int window_id = 0, AGE_Color color = {0,0,0,255});
	int age_window_create(string title, AGE_Cartesian coords, Uint32 wflags = 0, Uint32 rflags = 0);
	int age_window_fading(Uint8 alpha, int window_id = 0, AGE_Color color = {0,0,0,255});
	int age_window_position_set(AGE_Cartesian position, int window_id = 0);
	int age_window_refresh();
	int age_window_refresh(int window_id);
	int age_window_remove(int window_id);
	int age_window_set_focus(int window_id);
	int age_window_set_visible(int window_id, bool visible);
    int age_window_size_set(AGE_Cartesian size, int window_id = 0);

private:
	DMOM* dmom;
	AGE_DrawAreaIndex* draw_area_index;
	AGE_EventIndex* event_index;
    AGE_FontIndex* font_index;
	AGE_ImageIndex* image_index;
	SDL_Event sdl_event_handler;
	AGE_WindowIndex* window_index;

    int age_font_unload(int font_id);
    int age_image_unload(int image_id);
    SDL_Surface* age_sdlttf_create_surface(string text, TTF_Font* font, AGE_Color color, Uint8 mode, AGE_Color bg_color);
    SDL_Texture* age_sdlttf_create_texture(SDL_Surface* temp_surface, SDL_Renderer* render = nullptr);
	bool age_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int x, int y, int w, int h);
	bool age_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int img_x, int img_y, int img_w, int img_h, int dst_x, int dst_y, int dst_w, int dst_h);

};


//---------------------------------------------------------------------------


#endif // AGE_H_INCLUDED

