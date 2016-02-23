/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 22/02/2016
****************************************************************************/


#include "AGE_prefixedValues.h"


#include "dmo/DMOM.h"


#ifndef AGE_H
#define AGE_H

//---------------------------------------------------------------------------

struct AGE_Cartesian {
	int x;
	int y;
	int w;
	int h;
};


//---------------------------------------------------------------------------

struct AGE_Color {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};


//---------------------------------------------------------------------------

struct AGE_Event_Status {
	Uint32 event = 0;
	Uint32 device = 0;
	int window = -1;
	Uint32 timestamp = 0;
	Uint32 state = 0;
	int x = -1;
	int y = -1;
	int w = -1;
	int h = -1;
	Uint8 count = 0;
	Uint16 mod = 0;
};


//---------------------------------------------------------------------------

class AGE {

public:
	AGE();
	virtual ~AGE();

	bool age_core_load_libs();
	DMOM* age_dmom_get();
	AGE_Event_Status age_event_get_status();
	int age_event_process();
	void age_pause(int miliseconds);
	int age_window_create(string title, AGE_Cartesian coords, Uint32 wflags = 0, Uint32 rflags = 0);
	int age_window_set_visible(int window_id, bool visible);
	int age_window_refresh();
	int age_window_refresh(int window_id);
	int age_window_remove(int window_id);
	int age_window_set_focus(int window_id);


private:
	AGE_EventIndex* event_index;
	AGE_WindowIndex* window_index;
	DMOM* dmom;
	SDL_Event sdl_event_handler;

};


//---------------------------------------------------------------------------

#endif // AGE_H
