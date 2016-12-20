/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 17/07/2015
* Last change: 20/12/2016
****************************************************************************/


#include "AGE.h"


//---------------------------------------------------------------------------

AGE::AGE(){

    //Initializing the object containers
	this->dmom = new DMOM();

	this->draw_area_index = new AGE_DrawAreaIndex();
	this->dmom->dmom_drawareaIndex_set(this->draw_area_index);

	this->event_index = new AGE_EventIndex();
	this->dmom->dmom_eventIndex_set(this->event_index);

	this->font_index = new AGE_FontIndex();
	this->dmom->dmom_fontIndex_set(this->font_index);

	this->image_index = new AGE_ImageIndex();
	this->dmom->dmom_imageIndex_set(this->image_index);

	this->window_index = new AGE_WindowIndex();
	this->dmom->dmom_windowIndex_set(this->window_index);

}


//---------------------------------------------------------------------------

AGE::~AGE(){
    //dtor
}


//---------------------------------------------------------------------------

//This function returns the window size & position values
AGE_Cartesian AGE::age_window_cartesian_get(int window_id){

	AGE_Cartesian result = { -1, -1, -1, -1 };
	SDL_Window* window;

	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

		SDL_GetWindowSize(window, &result.w, &result.h);
		SDL_GetWindowPosition(window, &result.x, &result.y);

	}

	return result;

}


//---------------------------------------------------------------------------

//This function sets the window position value
int AGE::age_window_position_set(AGE_Cartesian position, int window_id){

	SDL_Window* window;
	int result = AGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

		SDL_SetWindowPosition(window, position.x, position.y);
        result = window_id;

    //The index does not contains any node with that id
	}else{
        result = AGE_ERRORFLAG_NOWINDOW;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function sets the window size value
int AGE::age_window_size_set(AGE_Cartesian size, int window_id){

	SDL_Window* window;
	int result = AGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

		SDL_SetWindowSize(window, size.w, size.h);
        result = window_id;

    //The index does not contains any node with that id
	}else{
        result = AGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function sets the window position & size values
int AGE::age_window_cartesian_set(AGE_Cartesian cartesian, int window_id){

	SDL_Window* window;
	int result = AGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

        SDL_SetWindowPosition(window, cartesian.x, cartesian.y);
		SDL_SetWindowSize(window, cartesian.w, cartesian.h);
        result = window_id;

    //The index does not contains any node with that id
	}else{
        result = AGE_ERRORFLAG_NOWINDOW;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function overwrites the full window canvas
int AGE::age_window_clear(int window_id, AGE_Color color){

	AGE_Cartesian window_values;
	int result = AGE_ERRORFLAG_GENERIC;

    //We retrieve the window values and correct the 'x' and 'y' values to apply the square in the full screen
	window_values = this->age_window_cartesian_get(window_id);
    window_values.x = 0;
    window_values.y = 0;

    //If the square will be draw only if the window has an adequate size,
	if(window_values.h != -1 && window_values.w != -1){

		this->age_square_draw(window_values, color, AGE_BLENDINGFLAG_BLEND, window_id);
		result = window_id;

    //The window values were incorrect
	}else{
        result = AGE_ERRORFLAG_SIZE;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function applies the image using the SDL2 lib and allows to modify the size and the inner image
bool AGE::age_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int img_x, int img_y, int img_w, int img_h, int dst_x, int dst_y, int dst_w, int dst_h){

	int sdl_result = -1;
	bool result = false;

	SDL_Rect image_rect;
	image_rect.x = img_x;
	image_rect.y = img_y;
	image_rect.h = img_h;
	image_rect.w = img_w;

	SDL_Rect destination_rect;
	destination_rect.x = dst_x;
	destination_rect.y = dst_y;
    destination_rect.h = dst_h;
    destination_rect.w = dst_w;

	sdl_result = SDL_RenderCopy(render, texture, &image_rect, &destination_rect);

	if (sdl_result == 0) {
		result = true;
	}

	return result;

}


//---------------------------------------------------------------------------

//This function applies the image using the SDL2 lib
bool AGE::age_sdltexture_apply(SDL_Texture * texture, SDL_Renderer* render, int x, int y, int w, int h){

	int sdl_result = -1;
	bool result = false;

	SDL_Rect image_rect;
	image_rect.x = 0;
	image_rect.y = 0;
	image_rect.h = h;
	image_rect.w = w;

	SDL_Rect destination_rect;
	destination_rect.x = x;
	destination_rect.y = y;
    destination_rect.h = h;
    destination_rect.w = w;

	sdl_result = SDL_RenderCopy(render, texture, &image_rect, &destination_rect);

	if (sdl_result == 0) {
		result = true;
	}

	return result;

}


//---------------------------------------------------------------------------

//This function draws a square in a window
int AGE::age_square_draw(AGE_Cartesian square, AGE_Color color, SDL_BlendMode blend_mode, int window_id){

	SDL_Renderer* render = nullptr;
	int result = AGE_ERRORFLAG_GENERIC;

	render = this->window_index->getRender(window_id);
	if(render != nullptr){

        //If the square is not going to have a totally solid color, the engine needs to change the render configuration
	    if(color.a != 255){
            SDL_SetRenderDrawBlendMode(render, blend_mode);
        }

		SDL_Rect fillRect = {square.x, square.y, square.w, square.h};
		SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(render, &fillRect);

        //The render configuration is restored
	    if(color.a != 255){
            SDL_SetRenderDrawBlendMode(render, AGE_BLENDINGFLAG_NONE);
        }

        result = window_id;

	}

	return result;

}


//---------------------------------------------------------------------------

//This image allow to draw a image inside of a previously defined draw area
int AGE::age_image_move_to_draw_area(int image_id, int draw_area_id, int x, int y){

    bool op_result = false;
    AGE_Image* image_node = nullptr;
    AGE_DrawArea* da_node = nullptr;
    SDL_Renderer* render = nullptr;
    SDL_Texture* texture = nullptr;
	int window_id = -1;
	AGE_Cartesian img_cart = {0,0,0,0};
	AGE_Cartesian dst_cart = {0,0,0,0};
	int result = AGE_ERRORFLAG_GENERIC;

    //Recovering data
   	image_node = this->image_index->getNode(image_id);
    da_node = this->draw_area_index->getNode(draw_area_id);
    window_id = da_node->getWindow_id();
	render = this->window_index->getRender(window_id);

    //Check that all ids are correct
	if(image_node != nullptr && render != nullptr && da_node != nullptr){

        image_node->setAvailable(false);

        window_id = da_node->getWindow_id();
		texture = image_node->getTexture();
        img_cart.x = 0;
        img_cart.y = 0;
        img_cart.h = image_node->getTexture_h();
        img_cart.w = image_node->getTexture_w();

        dst_cart.x = x + da_node->getX();
        dst_cart.y = y + da_node->getY();
        dst_cart.h = image_node->getTexture_h();
        dst_cart.w = image_node->getTexture_w();


        //Draw area is solid
		if(da_node->getSolid()){

            //This code checks if the image exceeds the limits of the draw area and calculates the new coordinates
            if(x<0){
                img_cart.x = -x;
                dst_cart.w = image_node->getTexture_w() + x;
                dst_cart.x = da_node->getX();
            }

            if(y<0){
                img_cart.y = -y;
                dst_cart.h = image_node->getTexture_h() + y;
                dst_cart.y = da_node->getY();
            }

            if(x+img_cart.w>da_node->getW()){
                img_cart.w = da_node->getW() - x;
                dst_cart.w = da_node->getW() - x;
            }

            if(y+img_cart.h>da_node->getH()){
                img_cart.h = da_node->getH() - y;
                dst_cart.h = da_node->getH() - y;
           }

            op_result = this->age_sdltexture_apply(texture, render, img_cart.x, img_cart.y, img_cart.w, img_cart.h, dst_cart.x, dst_cart.y, dst_cart.w, dst_cart.h);
            result = image_id;

        //Draw area is not solid
        }else{
            op_result = this->age_sdltexture_apply(texture, render, dst_cart.x, dst_cart.y, dst_cart.w, dst_cart.h);
            result = image_id;

        }

		if(!op_result){
			result = AGE_ERRORFLAG_RENDERPROCESS;
		}

    //Result is AGE_ERRORFLAG_GENERIC if something went wrong
	}else{

		result = AGE_ERRORFLAG_GENERIC;

	}

	return result;

}


//---------------------------------------------------------------------------

//With this function, the tag node linked to the image can be modified
int AGE::age_image_tag_set(int image_id, string tag){

    int result = AGE_ERRORFLAG_GENERIC;
    AGE_Image* image_node = nullptr;

    image_node = this->image_index->getNode(image_id);

    //Looking for a image in the index
    if(image_node != nullptr){

        image_node->setTag(tag);
        result = image_id;

    //The index does not contains any node with that id
    }else{
        result = AGE_ERRORFLAG_NOREGISTER;

    }

    return result;

}


//---------------------------------------------------------------------------

//This function is used to draw an image inside of a window
int AGE::age_image_move(int image_id, int x, int y, int window_id){

	bool op_result = false;
	AGE_Image* image_node = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Renderer* render = nullptr;
	int w = 0;
	int h = 0;
	int result = AGE_ERRORFLAG_GENERIC;

	image_node = this->image_index->getNode(image_id);
	render = this->window_index->getRender(window_id);

    //The function only works if all the object information is retrieved previously
	if(image_node != nullptr && render != nullptr){

		image_node->setAvailable(false);

		texture = image_node->getTexture();
		w = image_node->getTexture_w();
		h = image_node->getTexture_h();

        //The proper SDL controller function is called
		op_result = this->age_sdltexture_apply(texture, render, x, y, w, h);
		if(!op_result){
			result = AGE_ERRORFLAG_IMAGEDRAW;

		}

    //There was a problem trying to recover the action data
	}else{
		result = AGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function marks an image as 'available', but the image is still in the memory program
int AGE::age_image_free(int image_id){

    int result = AGE_ERRORFLAG_GENERIC;
    AGE_Image* image_node = nullptr;

    image_node = this->image_index->getNode(image_id);

    //Looking for a image in the index
    if(image_node != nullptr){

        image_node->setAvailable(true);
        result = image_id;

    //The index does not contains any node with that id
    }else{
		result = AGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function unloads an image from the memory program
int AGE::age_image_unload(int image_id){

	AGE_Image* image_node = nullptr;
	SDL_Texture* image_texture = nullptr;
	SDL_Surface* image_surface = nullptr;
	int result = AGE_ERRORFLAG_GENERIC;

	//Looking for a image in the index
	image_node = this->image_index->getNode(image_id);
	if(image_node != nullptr){

        image_texture = image_node->getTexture();
        image_surface = image_node->getSurface();

        //Only if there area a loaded element, the system tries to unload it from memory
        if(image_texture != nullptr){
            SDL_DestroyTexture(image_texture);
        }

        if(image_surface != nullptr){
            SDL_FreeSurface(image_surface);
        }

        result = image_node->getIdent();

    //The index does not contains any node with that id
	}else{
		result = AGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function unloads an image from the memory program and deletes the proper DMOM node
int AGE::age_image_delete(int image_id){

    image_id = this->age_image_unload(image_id);
    image_id = this->image_index->deleteNode(image_id);

	return image_id;

}


//---------------------------------------------------------------------------

//This function creates a new window
int AGE::age_window_create(string title, AGE_Cartesian coords, Uint32 wflags, Uint32 rflags){

	SDL_Window* window = nullptr;
	SDL_Renderer* render = nullptr;
	SDL_DisplayMode display_mode;
	int window_id = -1;
	int result = AGE_ERRORFLAG_GENERIC;


	SDL_GetCurrentDisplayMode(0, &display_mode);

    //The coordinate values area changed if the user sends an AGE_WINDOWFLAG
	if (coords.x == AGE_WINDOWFLAG_XCENTERED) {
		coords.x = (display_mode.w / 2) - (coords.w / 2);
	}

	if (coords.y == AGE_WINDOWFLAG_YCENTERED) {
		coords.y = (display_mode.h / 2) - (coords.h / 2);
	}

	window = SDL_CreateWindow(title.c_str(), coords.x, coords.y, coords.w, coords.h, wflags);

	//Checking if there was a problem creating the window...
	if(window != nullptr){

		render = SDL_CreateRenderer(window, -1, rflags);

		//Also checking if the render creating was correct
		if(render != nullptr){

			window_id = this->window_index->createNode(title);
			this->window_index->setValues(window_id, window, render);

        //
		}else{
            result = AGE_ERRORFLAG_NORENDER;

		}

    //.. to send the creating error flag
	}else{
	    result = AGE_ERRORFLAG_NOWINDOW;

	}

	return result;

}

//---------------------------------------------------------------------------

//This function can be used to create a fading effect.
int AGE::age_window_fading(Uint8 alpha, int window_id, AGE_Color color){

    AGE_Cartesian window_size = {-1, -1, -1, -1};
    int result = AGE_ERRORFLAG_GENERIC;

    window_size = this->age_window_cartesian_get(window_id);

    result = this->age_square_draw({0, 0, window_size.w, window_size.h}, {color.r, color.g, color.b, alpha}, AGE_BLENDINGFLAG_BLEND, window_id);

    return result;

}


//---------------------------------------------------------------------------

//This function allows to hide or show a window
int AGE::age_window_set_visible(int window_id, bool visible){

	AGE_Window* mwindow = nullptr;
	int result = AGE_ERRORFLAG_GENERIC;

    //Looking for a window in the index
	mwindow = this->window_index->getNode(window_id);
	if(mwindow != nullptr) {

		if(visible){
			SDL_ShowWindow(mwindow->getWindow());

		}else {
			SDL_HideWindow(mwindow->getWindow());

		}

		result = mwindow->getIdent();

	//The index does not contains any node with that id
	}else{
        result = AGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function deletes a window
int AGE::age_window_remove(int window_id){

	int result = AGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	if (this->window_index->searchByIdent(window_id) == window_id) {

		SDL_DestroyRenderer(this->window_index->getRender(window_id));
		SDL_DestroyWindow(this->window_index->getWindow(window_id));
		result = this->window_index->getIdent(window_id);
		this->window_index->deleteNode(window_id);

    //The index does not contains any node with that id
	}else{
	    result = AGE_ERRORFLAG_NOREGISTER;

    }

	return result;

}


//---------------------------------------------------------------------------

//This function allows to change the window focus
int AGE::age_window_set_focus(int window_id){

	AGE_Window* mwindow = nullptr;
	int result = AGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	mwindow = this->window_index->getNode(window_id);
	if (mwindow != nullptr) {

		SDL_RaiseWindow(mwindow->getWindow());
		result = mwindow->getIdent();

    //The index does not contains any node with that id
	}else{
        result = AGE_ERRORFLAG_NOREGISTER;
	}

	return result;

}


//---------------------------------------------------------------------------

//This function loads and initializes the needed libraries
bool AGE::age_core_load_libs(){

	bool load_status = true;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	return load_status;

}


//---------------------------------------------------------------------------

//This function returns the main DMOM object used
DMOM * AGE::age_dmom_get(){

	return this->dmom;

}


//---------------------------------------------------------------------------

//This function returns the next event object in the AGE format
AGE_Event_Status AGE::age_event_get_status(){

	AGE_Event_Status status;
	AGE_Event* event_node = nullptr;
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
		status.event = AGE_EVENT_NOEVENTS;

	}

	return status;

}


//---------------------------------------------------------------------------

//This function creates a label and stores it in memory as an image
int AGE::age_label_compose(string text, int font_id, AGE_Color color, Uint8 mode, AGE_Color bg_color){

    SDL_Color label_color;
    TTF_Font* font = nullptr;
    AGE_Font* font_node = nullptr;
    int image_id = -1;
	int image_w = -1;
	int image_h = -1;
    int result = AGE_ERRORFLAG_GENERIC;
    string tag = "";
    SDL_Surface* temp_surface = nullptr;
    SDL_Texture* temp_texture = nullptr;

    font_node = this->font_index->getNode(font_id);

    //Font id is not valid
    if(font_node == nullptr){
        result = AGE_ERRORFLAG_FONTID;

    }else{

        //The font object is recovered
        font = font_node->getFont();

        //Searching for a previously similar composed label
        tag = "AGELABEL|" + text + "|" + font_node->getSrc() + "|" + age_util_itos(font_node->getSize()) + "|" + age_util_actos(color);
        image_id = this->image_index->searchByTag(tag);

        //There are no similar labels
        if(image_id == -1){

            label_color = age_util_actsc(color);
            image_id = this->image_index->searchAvailable();

            //There area available registers
            if(image_id == -1){

			    image_id = this->image_index->createNode(tag);
			    this->image_index->setSrc(image_id, tag);

            //There is an available register
            }else{

                this->age_image_unload(image_id);
                this->image_index->setTag(image_id, tag);
                this->image_index->setSrc(image_id, tag);

            }

            //The image is created and the node values are updated
            temp_surface = this->age_sdlttf_create_surface(text, font, color, mode, bg_color);
            temp_texture = this->age_sdlttf_create_texture(temp_surface);

			this->image_index->setTexture(image_id, temp_texture);
			this->image_index->setSurface(image_id, temp_surface);
			SDL_QueryTexture(temp_texture, nullptr, nullptr, &image_w, &image_h);
			this->image_index->setTexture_h(image_id, image_h);
			this->image_index->setTexture_w(image_id, image_w);

			result = image_id;

        //There are another similar label
        }else{
            result = image_id;

        }

    }


    return result;

}


//---------------------------------------------------------------------------

//This functions loads an image as a SDL_Surface
SDL_Surface* AGE::age_sdlttf_create_surface(string text, TTF_Font* font, AGE_Color color, Uint8 mode, AGE_Color bg_color){

    SDL_Surface* temp_surface = nullptr;

    if(mode == AGE_LABELMODEFLAG_BLENDED){
        temp_surface = TTF_RenderUTF8_Blended(font, text.c_str(), age_util_actsc(color));

    }else if(mode == AGE_LABELMODEFLAG_SOLID){
        temp_surface = TTF_RenderUTF8_Solid( font, text.c_str(), age_util_actsc(color));

    }else if(mode == AGE_LABELMODEFLAG_SHADED){
        temp_surface = TTF_RenderUTF8_Shaded( font, text.c_str(), age_util_actsc(color), age_util_actsc(bg_color));

    }else{
        temp_surface = TTF_RenderUTF8_Solid( font, text.c_str(), age_util_actsc(color));

    }

    return temp_surface;

}


//---------------------------------------------------------------------------

//This functions loads an image as a SDL_Texture
SDL_Texture* AGE::age_sdlttf_create_texture(SDL_Surface* temp_surface, SDL_Renderer* render){

    SDL_Texture* temp_texture = nullptr;
    AGE_Window* window = nullptr;

    if(render == nullptr){

        window = this->window_index->getFirst();

        if(window != nullptr){
            render = window->getRender();

        }else{
            render = nullptr;

        }

    }

    if(render != nullptr){
        temp_texture = SDL_CreateTextureFromSurface(render, temp_surface);

    }

    return temp_texture;

}


//---------------------------------------------------------------------------

//This function loads a new image in the program
int AGE::age_image_deploy(string src, int window_id) {

	SDL_Texture* temp_texture = nullptr;
	SDL_Surface* temp_surface = nullptr;
	SDL_Renderer* render = nullptr;
	int image_w = -1;
	int image_h = -1;
	int image_id = -1;
	int result = AGE_ERRORFLAG_GENERIC;
	string tag = "";

    //Here, we check if the image was previously loaded
    tag = src;
	image_id = this->image_index->searchByTag(tag);

    //If the images was not loaded
	if (image_id == -1){

        //The function looks for an available node
        image_id = this->image_index->searchByAvailable(true);

        //Here we check if the image file really exists
        if(age_util_file_check(src)){

            //The image is loaded
            temp_surface = IMG_Load(src.c_str());
			render = this->window_index->getRender(window_id);
			temp_texture = SDL_CreateTextureFromSurface(render, temp_surface);

            //If there is not any available node, a new one is created...
			if(image_id == -1){

			    image_id = this->image_index->createNode(tag);
			    this->image_index->setSrc(image_id, tag);

            //... else, the image stored in the node is deleted and the node is updated with the new information
			}else{

                this->age_image_unload(image_id);
                this->image_index->setTag(image_id, tag);
                this->image_index->setSrc(image_id, src);
			}

			//The image is finally updated
			this->image_index->setTexture(image_id, temp_texture);
			this->image_index->setSurface(image_id, temp_surface);
			SDL_QueryTexture(temp_texture, nullptr, nullptr, &image_w, &image_h);
			this->image_index->setTexture_h(image_id, image_h);
			this->image_index->setTexture_w(image_id, image_w);
			result = image_id;

        //If the image file is not present, an error value is assigned to the output
        }else{
            result = AGE_ERRORFLAG_FILEACCESS;

        }

    //If the image was previously loaded, no image is loaded, but the function returns the other image id
	}else{

        this->image_index->setAvailable(image_id, false);
        result = image_id;

	}

	return result;

}

//This function calls the other version of 'age_image_deploy' and draws the image in the window
int AGE::age_image_deploy(string src, int x, int y, int window_id){

    int result = AGE_ERRORFLAG_GENERIC;
	int image_id = -1;

	image_id = this->age_image_deploy(src, window_id);
	result = this->age_image_move(image_id, x, y, window_id);

	return result;

}


//---------------------------------------------------------------------------

//This function process the SDL event list and fills the AGE event list with the proper format
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

		event = AGE_EVENT_NOEVENTS;
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
			node = this->event_index->createNode(age_util_itos(event) + "-" + age_util_itos(events));
			this->event_index->setValues(node, event, device, window, timestamp, state, x, y, w, h, count, mod);
		}

	}

	return events;

}


//---------------------------------------------------------------------------

//This function unloads a font from the memory program
int AGE::age_font_unload(int font_id){

	int result = AGE_ERRORFLAG_GENERIC;
	AGE_Font* font_node = nullptr;
	TTF_Font* font_pointer = nullptr;

	//Looking for a font in the index
	font_node = this->font_index->getNode(font_id);
	if(font_node != nullptr){

        font_pointer = font_node->getFont();

        if(font_pointer != nullptr){
            TTF_CloseFont(font_pointer);

        }

        result = font_node->getIdent();

    //The index does not contains any node with that id
	}else{
		result = AGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function marks an font as 'available', but the font is still in the memory program
int AGE::age_font_free(int font_id){

    AGE_Font* font_node = nullptr;
    int result = AGE_ERRORFLAG_GENERIC;

    //Looking for a font in the index
    font_node = this->font_index->getNode(font_id);
    if(font_node != nullptr){

        font_node->setAvailable(true);
        result = font_id;

    //The index does not contains any node with that id
    }else{
        result = AGE_ERRORFLAG_FONTID;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function unloads an font from the memory program and deletes the proper DMOM node
int AGE::age_font_delete(int font_id){

    int result = AGE_ERRORFLAG_GENERIC;

    font_id = this->age_font_unload(font_id);
    result = this->image_index->deleteNode(font_id);

	return result;

}


//---------------------------------------------------------------------------

//This function load an specified file as a font
int AGE::age_font_deploy(string src, int font_size){

    TTF_Font *temp_font = nullptr;
    int result = AGE_ERRORFLAG_GENERIC;
    int font_id = -1;
    string tag = "";

    tag = src + "|" + age_util_itos(font_size);
    font_id = this->font_index->searchByTag(tag);

    //Font is not registered, this block loads the font and creates the register
     if (font_id == -1){

        //We search for an available register
        font_id = this->font_index->searchByAvailable(true);

        if (age_util_file_check(src)){

            temp_font =  TTF_OpenFont(src.c_str(), font_size);

            //There was a problem loading the font file
            if (temp_font == nullptr){
                result = AGE_ERRORFLAG_FONTLOAD;

            }else{

                //If we need to create a new register (there are not available registers)
                if(font_id == -1){
                    font_id = this->font_index->createNode(tag);

                //if we have found an available register for the new font
                }else{
                    font_id = this->age_font_unload(font_id);

                }

                this->font_index->setTag(font_id, tag);
                this->font_index->setAvailable(font_id, false);
                this->font_index->setSrc(font_id, src);
                this->font_index->setFont(font_id, temp_font);
                this->font_index->setSize(font_id, font_size);
                result = font_id;

            }

        //If the file is not accessible, we return an error value
        }else{
            result = AGE_ERRORFLAG_FILEACCESS;

        }

    //font was loaded previously, so the available flag is set to 'false' to avoid image unload
    }else{

        this->font_index->setAvailable(font_id, false);
        result = font_id;

    }

    return result;

}


//---------------------------------------------------------------------------

//This function returns the size values of an image
AGE_Cartesian AGE::age_image_size_get(int image_id){

    AGE_Cartesian result = {0,0,0,0};

    result.h = this->image_index->getTexture_h(image_id);
    result.w = this->image_index->getTexture_w(image_id);

    return result;

}


//---------------------------------------------------------------------------

//This functions stops the execution temporarily
void AGE::age_pause(int miliseconds){

	SDL_Delay(miliseconds);

}


//---------------------------------------------------------------------------

//All the window content is updated
int AGE::age_window_refresh(){

	AGE_Window* mwindow = nullptr;
	SDL_Renderer* mrender = nullptr;
	int updated_windows = 0;
	int result = AGE_ERRORFLAG_GENERIC;

	mwindow = this->window_index->getFirst();
    //All the window nodes are processed
	while(mwindow != nullptr){

		mrender = mwindow->getRender();
		SDL_RenderPresent(mrender);
		updated_windows++;
		mwindow = mwindow->getNext();

	}

	result = updated_windows;

	return result;

}


//---------------------------------------------------------------------------

//The specified window content is updated
int AGE::age_window_refresh(int window_id){

	AGE_Window* mwindow = nullptr;
	SDL_Renderer* mrender = nullptr;
	int result = AGE_ERRORFLAG_GENERIC;

	mwindow = this->window_index->getNode(window_id);
	if (mwindow != nullptr) {

		mrender = mwindow->getRender();
		SDL_RenderPresent(mrender);
		result = mwindow->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

//This functions is called to create draw areas
int AGE::age_draw_area_create(AGE_Cartesian coords, bool solid, int window_id){

    int da_id = AGE_ERRORFLAG_GENERIC;

    da_id = this->draw_area_index->createNode();
    this->draw_area_index->setValues(da_id, coords.x, coords.y, coords.w, coords.h, solid, window_id);

    return da_id;

}


//---------------------------------------------------------------------------

//This functions draws a line in the specified window
int AGE::age_line_draw(AGE_Cartesian point1, AGE_Cartesian point2, AGE_Color color, SDL_BlendMode blend_mode, int window_id){

    SDL_Renderer* render = nullptr;
    int result = AGE_ERRORFLAG_GENERIC;

    render = this->window_index->getRender(window_id);

    if(render != nullptr){

        //If the line is not going to have a totally solid color, the engine needs to change the render configuration
        if(color.a != 255){
            SDL_SetRenderDrawBlendMode(render, blend_mode);
        }

        SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(render, point1.x, point1.y, point2.x, point2.y);

        //The render configuration is restored
        if(color.a != 255){
            SDL_SetRenderDrawBlendMode(render, AGE_BLENDINGFLAG_NONE);
        }

        result = window_id;

    }

    return result;

}


//---------------------------------------------------------------------------

//This functions checks if two areas are in a collision status
bool AGE::age_collision_check(AGE_Cartesian area1, AGE_Cartesian area2){

    bool result = false;
    int diff_x;
    int diff_y;

    diff_x = area1.x - area2.x;
    diff_y = area1.y - area2.y;

    if(((diff_x >= -area1.w) && (diff_x <= area2.w)) && ((diff_y >= -area1.h) && (diff_y <= area2.h))){
        result = true;

    }

    return result;

}


//---------------------------------------------------------------------------
