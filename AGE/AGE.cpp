/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 22/02/2016
****************************************************************************/


#include "AGE.h"


//---------------------------------------------------------------------------

AGE::AGE(){

	this->dmom = new DMOM();
	
	this->event_index = new AGE_EventIndex();
	this->dmom->dmom_eventIndex_set(this->event_index);

	this->window_index = new AGE_WindowIndex();
	this->dmom->dmom_windowIndex_set(this->window_index);

}


AGE::~AGE(){
}


//---------------------------------------------------------------------------

int AGE::age_window_create(string title, AGE_Cartesian coords, Uint32 wflags, Uint32 rflags){

	SDL_Window* window;
	SDL_Renderer* render;
	SDL_DisplayMode display_mode;
	int window_id = -1;


	SDL_GetCurrentDisplayMode(0, &display_mode);

	if (coords.x == AGE_WINDOWFLAG_XCENTERED) {
		coords.x = (display_mode.w / 2) - (coords.w / 2);
	}

	if (coords.y == AGE_WINDOWFLAG_YCENTERED) {
		coords.y = (display_mode.h / 2) - (coords.h / 2);
	}

	window = SDL_CreateWindow(title.c_str(), coords.x, coords.y, coords.w, coords.h, wflags);

	if(window != nullptr){
	
		render = SDL_CreateRenderer(window, -1, rflags);

		if(render != nullptr){

			window_id = this->window_index->createNode(title);
			this->window_index->setValues(window_id, window, render);

		}

	}

	return window_id;

}


//---------------------------------------------------------------------------

int AGE::age_window_set_visible(int window_id, bool visible){

	AGE_Window* mwindow = nullptr;
	int updated_window = -1;


	mwindow = this->window_index->getNode(window_id);

	if(mwindow != nullptr) {

		if(visible){
			SDL_ShowWindow(mwindow->getWindow());

		}else {
			SDL_HideWindow(mwindow->getWindow());

		}

		updated_window = mwindow->getIdent();

	}

	return updated_window;

}


//---------------------------------------------------------------------------

int AGE::age_window_remove(int window_id){

	int removed_window = -1;

	if (this->window_index->searchByIdent(window_id) == window_id) {

		SDL_DestroyRenderer(this->window_index->getRender(window_id));
		SDL_DestroyWindow(this->window_index->getWindow(window_id));
		removed_window = this->window_index->getIdent(window_id);
		this->window_index->deleteNode(window_id);

	}

	return removed_window;

}


//---------------------------------------------------------------------------

int AGE::age_window_set_focus(int window_id){
	
	AGE_Window* mwindow = nullptr;
	int updated_window = -1;

	mwindow = this->window_index->getNode(window_id);

	if (mwindow != nullptr) {

		SDL_RaiseWindow(mwindow->getWindow());
		updated_window = mwindow->getIdent();

	}

	return updated_window;

}


//---------------------------------------------------------------------------

bool AGE::age_core_load_libs(){

	bool load_status = true;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	return load_status;

}


//---------------------------------------------------------------------------

DMOM * AGE::age_dmom_get(){

	return this->dmom;

}


//---------------------------------------------------------------------------

AGE_Event_Status AGE::age_event_get_status(){

	AGE_Event_Status status;
	AGE_Event* event_node = nullptr;
	int event_id = -1;

	event_node = this->event_index->getFirst();

	if(event_node != nullptr){

		event_id = event_node->getIdent();

		status.event = event_node->getEvent();
		status.window = event_node->getWindow();
		status.timestamp = event_node->getTimestamp();
		status.state = event_node->getState();
		status.x = event_node->getX();
		status.y = event_node->getY();
		status.count = event_node->getCount();

		this->event_index->deleteNode(event_id);
		
	}
	else {
	
		this->event_index->deleteList();
		status.event = AGE_EVENT_NOEVENTS;
	}


	return status;

}


//---------------------------------------------------------------------------

int AGE::age_event_process(){
	
	int events = AGE_EVENT_NOEVENTS;
	int node = -1;
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
	bool reg = false;

	while (SDL_PollEvent(&this->sdl_event_handler) != 0) {

		Uint32 event = AGE_EVENT_NOEVENTS;
		Uint32 device = 0;
		int window = -1;
		Uint32 timestamp = 0;
		Uint32 state = 0;
		int x = -1;
		int y = -1;
		int w = -1;
		int h = -1;
		Uint8 count = 0;
		bool reg = false;

		switch (this->sdl_event_handler.type) {

			case SDL_WINDOWEVENT:
				window = this->sdl_event_handler.window.windowID;
				timestamp = this->sdl_event_handler.window.timestamp;
				switch(this->sdl_event_handler.window.event){
					case SDL_WINDOWEVENT_CLOSE:
						event = AGE_EVENT_WINDOW_CLOSE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_MOVED:
						event = AGE_EVENT_WINDOW_MOVE;
						x = this->sdl_event_handler.window.data1;
						y = this->sdl_event_handler.window.data2;
						reg = true;
					break;
					case SDL_WINDOWEVENT_RESIZED:
						event = AGE_EVENT_WINDOW_RESIZE;
						w = this->sdl_event_handler.window.data1;
						h = this->sdl_event_handler.window.data2;
						reg = true;
					break;
					case SDL_WINDOWEVENT_MINIMIZED:
						event = AGE_EVENT_WINDOW_MINIMIZE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_MAXIMIZED:
						event = AGE_EVENT_WINDOW_MAXIMIZE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_SHOWN:
						event = AGE_EVENT_WINDOW_VISIBLE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_HIDDEN:
						event = AGE_EVENT_WINDOW_NOVISIBLE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_EXPOSED:
						event = AGE_EVENT_WINDOW_EXPOSE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						event = AGE_EVENT_WINDOW_RESIZE;
						w = this->sdl_event_handler.window.data1;
						h = this->sdl_event_handler.window.data2;
						reg = true;
					break;
					case SDL_WINDOWEVENT_RESTORED:
						event = AGE_EVENT_WINDOW_RESTORE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_ENTER:
						event = AGE_EVENT_WINDOW_ENTER;
						reg = true;
					break;
					case SDL_WINDOWEVENT_LEAVE:
						event = AGE_EVENT_WINDOW_LEAVE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						event = AGE_EVENT_WINDOW_FOCUS;
						reg = true;
					break;
					case SDL_WINDOWEVENT_FOCUS_LOST:
						event = AGE_EVENT_WINDOW_NOFOCUS;
						reg = true;
					break;
				}
			break;

			case SDL_KEYDOWN:
				window = this->sdl_event_handler.key.windowID;
				timestamp = this->sdl_event_handler.key.timestamp;
				count = this->sdl_event_handler.key.repeat;
				switch (this->sdl_event_handler.key.keysym.sym) {
					case SDLK_ESCAPE:
						event = AGE_EVENT_KEY_ESC;
						reg = true;
					break;
					case SDLK_F1:
						event = AGE_EVENT_KEY_F1;
						reg = true;
					break;
					case SDLK_F2:
						event = AGE_EVENT_KEY_F2;
						reg = true;
					break;
					case SDLK_F3:
						event = AGE_EVENT_KEY_F3;
						reg = true;
					break;
					case SDLK_F4:
						event = AGE_EVENT_KEY_F4;
						reg = true;
					break;
					case SDLK_F5:
						event = AGE_EVENT_KEY_F5;
						reg = true;
					break;
					case SDLK_F6:
						event = AGE_EVENT_KEY_F6;
						reg = true;
					break;
					case SDLK_F7:
						event = AGE_EVENT_KEY_F7;
						reg = true;
					break;
					case SDLK_F8:
						event = AGE_EVENT_KEY_F8;
						reg = true;
					break;
					case SDLK_F9:
						event = AGE_EVENT_KEY_F9;
						reg = true;
					break;
					case SDLK_F10:
						event = AGE_EVENT_KEY_F10;
						reg = true;
					break;
					case SDLK_F11:
						event = AGE_EVENT_KEY_F11;
						reg = true;
					break;
					case SDLK_F12:
						event = AGE_EVENT_KEY_F12;
						reg = true;
					break;
					case SDLK_PAUSE:
						event = AGE_EVENT_KEY_PAUSE;
						reg = true;
					break;
					case SDLK_INSERT:
						event = AGE_EVENT_KEY_INSERT;
						reg = true;
					break;
					case SDLK_DELETE:
						event = AGE_EVENT_KEY_DELETE;
						reg = true;
					break;
					case SDLK_1:
						event = AGE_EVENT_KEY_1;
						reg = true;
					break;
					case SDLK_2:
						event = AGE_EVENT_KEY_2;
						reg = true;
					break;
					case SDLK_3:
						event = AGE_EVENT_KEY_3;
						reg = true;
					break;
					case SDLK_4:
						event = AGE_EVENT_KEY_4;
						reg = true;
					break;
					case SDLK_5:
						event = AGE_EVENT_KEY_5;
						reg = true;
					break;
					case SDLK_6:
						event = AGE_EVENT_KEY_6;
						reg = true;
					break;
					case SDLK_7:
						event = AGE_EVENT_KEY_7;
						reg = true;
					break;
					case SDLK_8:
						event = AGE_EVENT_KEY_8;
						reg = true;
					break;
					case SDLK_9:
						event = AGE_EVENT_KEY_9;
						reg = true;
					break;
					case SDLK_0:
						event = AGE_EVENT_KEY_DELETE;
						reg = true;
					break;
					case SDLK_TAB:
						event = AGE_EVENT_KEY_TAB;
						reg = true;
					break;
					case SDLK_q:
						event = AGE_EVENT_KEY_Q;
						reg = true;
					break;
					case SDLK_w:
						event = AGE_EVENT_KEY_W;
						reg = true;
					break;
					case SDLK_e:
						event = AGE_EVENT_KEY_E;
						reg = true;
					break;
					case SDLK_r:
						event = AGE_EVENT_KEY_R;
						reg = true;
					break;
					case SDLK_t:
						event = AGE_EVENT_KEY_T;
						reg = true;
					break;
					case SDLK_y:
						event = AGE_EVENT_KEY_Y;
						reg = true;
					break;
					case SDLK_u:
						event = AGE_EVENT_KEY_U;
						reg = true;
					break;
					case SDLK_i:
						event = AGE_EVENT_KEY_I;
						reg = true;
					break;
					case SDLK_o:
						event = AGE_EVENT_KEY_O;
						reg = true;
					break;
					case SDLK_p:
						event = AGE_EVENT_KEY_P;
						reg = true;
					break;
					case SDLK_a:
						event = AGE_EVENT_KEY_A;
						reg = true;
					break;
					case SDLK_s:
						event = AGE_EVENT_KEY_S;
						reg = true;
					break;
					case SDLK_d:
						event = AGE_EVENT_KEY_D;
						reg = true;
					break;
					case SDLK_f:
						event = AGE_EVENT_KEY_F;
						reg = true;
					break;
					case SDLK_g:
						event = AGE_EVENT_KEY_G;
						reg = true;
					break;
					case SDLK_h:
						event = AGE_EVENT_KEY_H;
						reg = true;
					break;
					case SDLK_j:
						event = AGE_EVENT_KEY_J;
						reg = true;
					break;
					case SDLK_k:
						event = AGE_EVENT_KEY_K;
						reg = true;
					break;
					case SDLK_l:
						event = AGE_EVENT_KEY_L;
						reg = true;
					break;
					case SDLK_z:
						event = AGE_EVENT_KEY_Z;
						reg = true;
					break;
					case SDLK_x:
						event = AGE_EVENT_KEY_X;
						reg = true;
					break;
					case SDLK_c:
						event = AGE_EVENT_KEY_C;
						reg = true;
					break;
					case SDLK_v:
						event = AGE_EVENT_KEY_V;
						reg = true;
					break;
					case SDLK_b:
						event = AGE_EVENT_KEY_B;
						reg = true;
					break;
					case SDLK_n:
						event = AGE_EVENT_KEY_N;
						reg = true;
					break;
					case SDLK_m:
						event = AGE_EVENT_KEY_M;
						reg = true;
					break;
					case SDLK_LSHIFT:
						event = AGE_EVENT_KEY_LSHIFT;
						reg = true;
					break;
					case SDLK_RSHIFT:
						event = AGE_EVENT_KEY_RSHIFT;
						reg = true;
					break;
					case SDLK_CAPSLOCK:
						event = AGE_EVENT_KEY_CAPSLOCK;
						reg = true;
					break;
					case SDLK_LCTRL:
						event = AGE_EVENT_KEY_LCTRL;
						reg = true;
					break;
					case SDLK_RCTRL:
						event = AGE_EVENT_KEY_RCTRL;
						reg = true;
					break;
					case SDLK_LALT:
						event = AGE_EVENT_KEY_LALT;
						reg = true;
					break;
					case SDLK_RALT:
						event = AGE_EVENT_KEY_RALT;
						reg = true;
					break;
					case SDLK_SPACE:
						event = AGE_EVENT_KEY_SPACE;
						reg = true;
						break;
					case SDLK_LEFT:
						event = AGE_EVENT_KEY_LEFT;
						reg = true;
					break;
					case SDLK_UP:
						event = AGE_EVENT_KEY_UP;
						reg = true;
					break;
					case SDLK_DOWN:
						event = AGE_EVENT_KEY_DOWN;
						reg = true;
					break;
					case SDLK_RIGHT:
						event = AGE_EVENT_KEY_RIGHT;
						reg = true;
					break;
					case SDLK_HOME:
						event = AGE_EVENT_KEY_HOME;
						reg = true;
					break;
					case SDLK_END:
						event = AGE_EVENT_KEY_END;
						reg = true;
					break;
					case SDLK_PAGEUP:
						event = AGE_EVENT_KEY_PAGEUP;
						reg = true;
					break;
					case SDLK_PAGEDOWN:
						event = AGE_EVENT_KEY_PAGEDOWN;
						reg = true;
					break;
					case SDLK_RETURN:
						event = AGE_EVENT_KEY_RETURN;
						reg = true;
					break;

				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				timestamp = this->sdl_event_handler.button.timestamp;
				window = this->sdl_event_handler.button.windowID;
				device = this->sdl_event_handler.button.which;
				count = this->sdl_event_handler.button.clicks;
				x = this->sdl_event_handler.button.x;
				y = this->sdl_event_handler.button.y;
				switch (this->sdl_event_handler.button.button) {
					case SDL_BUTTON_LEFT:
						event = AGE_EVENT_MOUSE_LEFT;
						reg = true;
					break;
					case SDL_BUTTON_MIDDLE:
						event = AGE_EVENT_MOUSE_MIDDLE;
						reg = true;
					break;
					case SDL_BUTTON_RIGHT:
						event = AGE_EVENT_MOUSE_RIGHT;
						reg = true;
					break;
					case SDL_BUTTON_X1:
						event = AGE_EVENT_MOUSE_X1;
						reg = true;
					break;
					case SDL_BUTTON_X2:
						event = AGE_EVENT_MOUSE_X2;
						reg = true;
					break;
				}
			break;

		}

		if(reg){
			node = this->event_index->createNode(to_string(event) + "-" + to_string(events));
			this->event_index->setValues(node, event, device, window, timestamp, state, x, y, w, h, count, mod);
		}

	}

	return events;

}


//---------------------------------------------------------------------------

void AGE::age_pause(int miliseconds){
	
	SDL_Delay(miliseconds);

}


//---------------------------------------------------------------------------

int AGE::age_window_refresh(){

	AGE_Window* mwindow = nullptr;
	SDL_Renderer* mrender = nullptr;
	int updated_windows = 0;

	mwindow = this->window_index->getFirst();

	while(mwindow != nullptr){

		mrender = mwindow->getRender();
		SDL_RenderPresent(mrender);
		updated_windows++;
		mwindow = mwindow->getNext();

	}

	return updated_windows;

}


//---------------------------------------------------------------------------

int AGE::age_window_refresh(int window_id){

	AGE_Window* mwindow = nullptr;
	SDL_Renderer* mrender = nullptr;
	int updated_window = -1;

	mwindow = this->window_index->getNode(window_id);
	if (mwindow != nullptr) {

		mrender = mwindow->getRender();
		SDL_RenderPresent(mrender);
		updated_window = mwindow->getIdent();

	}

	return updated_window;

}


//---------------------------------------------------------------------------
