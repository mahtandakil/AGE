/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation day: 09/02/2017
* Last change: 09/02/2017
****************************************************************************/


#include "TSGE.h"


//---------------------------------------------------------------------------

//This function returns the next event object in the TSGE format
TSGE_Event_Status TSGE::tsge_event_get_status(){

	TSGE_Event_Status status;
	TSGE_Event* event_node = nullptr;
	int event_id = -1;

	event_node = this->event_index->getFirst();

	if(event_node != nullptr){

		event_id = event_node->getIdent();

        //The event values are returned
		status.event = event_node->getEvent();
		status.window = event_node->getWindow();
		status.timestamp = event_node->getTimestamp();
		status.state = event_node->getState();
		status.x = event_node->getX();
		status.y = event_node->getY();
		status.count = event_node->getCount();

        //The event is not longer needed, so is deleted
		this->event_index->deleteNode(event_id);

	}else {

        //This is returned when there are no more events in the list
		this->event_index->deleteList();
		status.event = TSGE_EVENT_NOEVENTS;

	}

	return status;

}


//---------------------------------------------------------------------------

//This function process the SDL event list and fills the TSGE event list with the proper format
int TSGE::tsge_event_process(){

	int events = TSGE_EVENT_NOEVENTS;
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

		event = TSGE_EVENT_NOEVENTS;
		device = 0;
		window = -1;
		timestamp = 0;
		state = 0;
		x = -1;
		y = -1;
		w = -1;
		h = -1;
		count = 0;
		reg = false;

		switch (this->sdl_event_handler.type) {

			case SDL_WINDOWEVENT:
				window = this->sdl_event_handler.window.windowID;
				timestamp = this->sdl_event_handler.window.timestamp;
				switch(this->sdl_event_handler.window.event){
					case SDL_WINDOWEVENT_CLOSE:
						event = TSGE_EVENT_WINDOW_CLOSE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_MOVED:
						event = TSGE_EVENT_WINDOW_MOVE;
						x = this->sdl_event_handler.window.data1;
						y = this->sdl_event_handler.window.data2;
						reg = true;
					break;
					case SDL_WINDOWEVENT_RESIZED:
						event = TSGE_EVENT_WINDOW_RESIZE;
						w = this->sdl_event_handler.window.data1;
						h = this->sdl_event_handler.window.data2;
						reg = true;
					break;
					case SDL_WINDOWEVENT_MINIMIZED:
						event = TSGE_EVENT_WINDOW_MINIMIZE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_MAXIMIZED:
						event = TSGE_EVENT_WINDOW_MAXIMIZE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_SHOWN:
						event = TSGE_EVENT_WINDOW_VISIBLE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_HIDDEN:
						event = TSGE_EVENT_WINDOW_NOVISIBLE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_EXPOSED:
						event = TSGE_EVENT_WINDOW_EXPOSE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						event = TSGE_EVENT_WINDOW_RESIZE;
						w = this->sdl_event_handler.window.data1;
						h = this->sdl_event_handler.window.data2;
						reg = true;
					break;
					case SDL_WINDOWEVENT_RESTORED:
						event = TSGE_EVENT_WINDOW_RESTORE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_ENTER:
						event = TSGE_EVENT_WINDOW_ENTER;
						reg = true;
					break;
					case SDL_WINDOWEVENT_LEAVE:
						event = TSGE_EVENT_WINDOW_LEAVE;
						reg = true;
					break;
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						event = TSGE_EVENT_WINDOW_FOCUS;
						reg = true;
					break;
					case SDL_WINDOWEVENT_FOCUS_LOST:
						event = TSGE_EVENT_WINDOW_NOFOCUS;
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
						event = TSGE_EVENT_KEY_ESC;
						reg = true;
					break;
					case SDLK_F1:
						event = TSGE_EVENT_KEY_F1;
						reg = true;
					break;
					case SDLK_F2:
						event = TSGE_EVENT_KEY_F2;
						reg = true;
					break;
					case SDLK_F3:
						event = TSGE_EVENT_KEY_F3;
						reg = true;
					break;
					case SDLK_F4:
						event = TSGE_EVENT_KEY_F4;
						reg = true;
					break;
					case SDLK_F5:
						event = TSGE_EVENT_KEY_F5;
						reg = true;
					break;
					case SDLK_F6:
						event = TSGE_EVENT_KEY_F6;
						reg = true;
					break;
					case SDLK_F7:
						event = TSGE_EVENT_KEY_F7;
						reg = true;
					break;
					case SDLK_F8:
						event = TSGE_EVENT_KEY_F8;
						reg = true;
					break;
					case SDLK_F9:
						event = TSGE_EVENT_KEY_F9;
						reg = true;
					break;
					case SDLK_F10:
						event = TSGE_EVENT_KEY_F10;
						reg = true;
					break;
					case SDLK_F11:
						event = TSGE_EVENT_KEY_F11;
						reg = true;
					break;
					case SDLK_F12:
						event = TSGE_EVENT_KEY_F12;
						reg = true;
					break;
					case SDLK_PAUSE:
						event = TSGE_EVENT_KEY_PAUSE;
						reg = true;
					break;
					case SDLK_INSERT:
						event = TSGE_EVENT_KEY_INSERT;
						reg = true;
					break;
					case SDLK_DELETE:
						event = TSGE_EVENT_KEY_DELETE;
						reg = true;
					break;
					case SDLK_1:
						event = TSGE_EVENT_KEY_1;
						reg = true;
					break;
					case SDLK_2:
						event = TSGE_EVENT_KEY_2;
						reg = true;
					break;
					case SDLK_3:
						event = TSGE_EVENT_KEY_3;
						reg = true;
					break;
					case SDLK_4:
						event = TSGE_EVENT_KEY_4;
						reg = true;
					break;
					case SDLK_5:
						event = TSGE_EVENT_KEY_5;
						reg = true;
					break;
					case SDLK_6:
						event = TSGE_EVENT_KEY_6;
						reg = true;
					break;
					case SDLK_7:
						event = TSGE_EVENT_KEY_7;
						reg = true;
					break;
					case SDLK_8:
						event = TSGE_EVENT_KEY_8;
						reg = true;
					break;
					case SDLK_9:
						event = TSGE_EVENT_KEY_9;
						reg = true;
					break;
					case SDLK_0:
						event = TSGE_EVENT_KEY_DELETE;
						reg = true;
					break;
					case SDLK_TAB:
						event = TSGE_EVENT_KEY_TAB;
						reg = true;
					break;
					case SDLK_q:
						event = TSGE_EVENT_KEY_Q;
						reg = true;
					break;
					case SDLK_w:
						event = TSGE_EVENT_KEY_W;
						reg = true;
					break;
					case SDLK_e:
						event = TSGE_EVENT_KEY_E;
						reg = true;
					break;
					case SDLK_r:
						event = TSGE_EVENT_KEY_R;
						reg = true;
					break;
					case SDLK_t:
						event = TSGE_EVENT_KEY_T;
						reg = true;
					break;
					case SDLK_y:
						event = TSGE_EVENT_KEY_Y;
						reg = true;
					break;
					case SDLK_u:
						event = TSGE_EVENT_KEY_U;
						reg = true;
					break;
					case SDLK_i:
						event = TSGE_EVENT_KEY_I;
						reg = true;
					break;
					case SDLK_o:
						event = TSGE_EVENT_KEY_O;
						reg = true;
					break;
					case SDLK_p:
						event = TSGE_EVENT_KEY_P;
						reg = true;
					break;
					case SDLK_a:
						event = TSGE_EVENT_KEY_A;
						reg = true;
					break;
					case SDLK_s:
						event = TSGE_EVENT_KEY_S;
						reg = true;
					break;
					case SDLK_d:
						event = TSGE_EVENT_KEY_D;
						reg = true;
					break;
					case SDLK_f:
						event = TSGE_EVENT_KEY_F;
						reg = true;
					break;
					case SDLK_g:
						event = TSGE_EVENT_KEY_G;
						reg = true;
					break;
					case SDLK_h:
						event = TSGE_EVENT_KEY_H;
						reg = true;
					break;
					case SDLK_j:
						event = TSGE_EVENT_KEY_J;
						reg = true;
					break;
					case SDLK_k:
						event = TSGE_EVENT_KEY_K;
						reg = true;
					break;
					case SDLK_l:
						event = TSGE_EVENT_KEY_L;
						reg = true;
					break;
					case SDLK_z:
						event = TSGE_EVENT_KEY_Z;
						reg = true;
					break;
					case SDLK_x:
						event = TSGE_EVENT_KEY_X;
						reg = true;
					break;
					case SDLK_c:
						event = TSGE_EVENT_KEY_C;
						reg = true;
					break;
					case SDLK_v:
						event = TSGE_EVENT_KEY_V;
						reg = true;
					break;
					case SDLK_b:
						event = TSGE_EVENT_KEY_B;
						reg = true;
					break;
					case SDLK_n:
						event = TSGE_EVENT_KEY_N;
						reg = true;
					break;
					case SDLK_m:
						event = TSGE_EVENT_KEY_M;
						reg = true;
					break;
					case SDLK_LSHIFT:
						event = TSGE_EVENT_KEY_LSHIFT;
						reg = true;
					break;
					case SDLK_RSHIFT:
						event = TSGE_EVENT_KEY_RSHIFT;
						reg = true;
					break;
					case SDLK_CAPSLOCK:
						event = TSGE_EVENT_KEY_CAPSLOCK;
						reg = true;
					break;
					case SDLK_LCTRL:
						event = TSGE_EVENT_KEY_LCTRL;
						reg = true;
					break;
					case SDLK_RCTRL:
						event = TSGE_EVENT_KEY_RCTRL;
						reg = true;
					break;
					case SDLK_LALT:
						event = TSGE_EVENT_KEY_LALT;
						reg = true;
					break;
					case SDLK_RALT:
						event = TSGE_EVENT_KEY_RALT;
						reg = true;
					break;
					case SDLK_SPACE:
						event = TSGE_EVENT_KEY_SPACE;
						reg = true;
						break;
					case SDLK_LEFT:
						event = TSGE_EVENT_KEY_LEFT;
						reg = true;
					break;
					case SDLK_UP:
						event = TSGE_EVENT_KEY_UP;
						reg = true;
					break;
					case SDLK_DOWN:
						event = TSGE_EVENT_KEY_DOWN;
						reg = true;
					break;
					case SDLK_RIGHT:
						event = TSGE_EVENT_KEY_RIGHT;
						reg = true;
					break;
					case SDLK_HOME:
						event = TSGE_EVENT_KEY_HOME;
						reg = true;
					break;
					case SDLK_END:
						event = TSGE_EVENT_KEY_END;
						reg = true;
					break;
					case SDLK_PAGEUP:
						event = TSGE_EVENT_KEY_PAGEUP;
						reg = true;
					break;
					case SDLK_PAGEDOWN:
						event = TSGE_EVENT_KEY_PAGEDOWN;
						reg = true;
					break;
					case SDLK_RETURN:
						event = TSGE_EVENT_KEY_RETURN;
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
						event = TSGE_EVENT_MOUSE_LEFT;
						reg = true;
					break;
					case SDL_BUTTON_MIDDLE:
						event = TSGE_EVENT_MOUSE_MIDDLE;
						reg = true;
					break;
					case SDL_BUTTON_RIGHT:
						event = TSGE_EVENT_MOUSE_RIGHT;
						reg = true;
					break;
					case SDL_BUTTON_X1:
						event = TSGE_EVENT_MOUSE_X1;
						reg = true;
					break;
					case SDL_BUTTON_X2:
						event = TSGE_EVENT_MOUSE_X2;
						reg = true;
					break;
				}
			break;

		}

		if(reg){
			node = this->event_index->createNode(tsge_util_itos(event) + "-" + tsge_util_itos(events));
			this->event_index->setValues(node, event, device, window, timestamp, state, x, y, w, h, count, mod);
		}

	}

	return events;

}


//---------------------------------------------------------------------------


