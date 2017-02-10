/****************************************************************************
* Created for: AGE v1
* Dev line: TSGE v2
* Creation day: 17/07/2015
* Last change: 09/02/2017
****************************************************************************/


#include "TSGE.h"


//---------------------------------------------------------------------------

TSGE::TSGE(){

    //Initializing the object containers
	this->dmom = new DMOM();

	this->draw_area_index = new TSGE_DrawAreaIndex();
	this->dmom->dmom_drawareaIndex_set(this->draw_area_index);

	this->event_index = new TSGE_EventIndex();
	this->dmom->dmom_eventIndex_set(this->event_index);

	this->font_index = new TSGE_FontIndex();
	this->dmom->dmom_fontIndex_set(this->font_index);

	this->image_index = new TSGE_ImageIndex();
	this->dmom->dmom_imageIndex_set(this->image_index);

	this->window_index = new TSGE_WindowIndex();
	this->dmom->dmom_windowIndex_set(this->window_index);

}


//---------------------------------------------------------------------------

TSGE::~TSGE(){
    //dtor
}


//---------------------------------------------------------------------------

//This function returns the window size & position values
TSGE_Cartesian TSGE::tsge_window_cartesian_get(int window_id){

	TSGE_Cartesian result = { -1, -1, -1, -1 };
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
int TSGE::tsge_window_position_set(TSGE_Cartesian position, int window_id){

	SDL_Window* window;
	int result = TSGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

		SDL_SetWindowPosition(window, position.x, position.y);
        result = window_id;

    //The index does not contains any node with that id
	}else{
        result = TSGE_ERRORFLAG_NOWINDOW;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function sets the window size value
int TSGE::tsge_window_size_set(TSGE_Cartesian size, int window_id){

	SDL_Window* window;
	int result = TSGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

		SDL_SetWindowSize(window, size.w, size.h);
        result = window_id;

    //The index does not contains any node with that id
	}else{
        result = TSGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function sets the window position & size values
int TSGE::tsge_window_cartesian_set(TSGE_Cartesian cartesian, int window_id){

	SDL_Window* window;
	int result = TSGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	window = this->window_index->getWindow(window_id);
	if(window != nullptr){

        SDL_SetWindowPosition(window, cartesian.x, cartesian.y);
		SDL_SetWindowSize(window, cartesian.w, cartesian.h);
        result = window_id;

    //The index does not contains any node with that id
	}else{
        result = TSGE_ERRORFLAG_NOWINDOW;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function overwrites the full window canvas
int TSGE::tsge_window_clear(int window_id, TSGE_Color color){

	TSGE_Cartesian window_values;
	int result = TSGE_ERRORFLAG_GENERIC;

    //We retrieve the window values and correct the 'x' and 'y' values to apply the square in the full screen
	window_values = this->tsge_window_cartesian_get(window_id);
    window_values.x = 0;
    window_values.y = 0;

    //If the square will be draw only if the window has an adequate size,
	if(window_values.h != -1 && window_values.w != -1){

		this->tsge_square_draw(window_values, color, TSGE_BLENDINGFLAG_BLEND, window_id);
		result = window_id;

    //The window values were incorrect
	}else{
        result = TSGE_ERRORFLAG_SIZE;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function applies the image using the SDL2 lib and allows to modify the size and the inner image
bool TSGE::tsge_sdltexture_apply(SDL_Texture* texture, SDL_Renderer* render, int img_x, int img_y, int img_w, int img_h, int dst_x, int dst_y, int dst_w, int dst_h){

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
bool TSGE::tsge_sdltexture_apply(SDL_Texture * texture, SDL_Renderer* render, int x, int y, int w, int h){

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
int TSGE::tsge_square_draw(TSGE_Cartesian square, TSGE_Color color, SDL_BlendMode blend_mode, int window_id){

	SDL_Renderer* render = nullptr;
	int result = TSGE_ERRORFLAG_GENERIC;

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
            SDL_SetRenderDrawBlendMode(render, TSGE_BLENDINGFLAG_NONE);
        }

        result = window_id;

	}

	return result;

}


//---------------------------------------------------------------------------

//This image allow to draw a image inside of a previously defined draw area
int TSGE::tsge_image_move_to_draw_area(int image_id, int draw_area_id, int x, int y){

    bool op_result = false;
    TSGE_Image* image_node = nullptr;
    TSGE_DrawArea* da_node = nullptr;
    SDL_Renderer* render = nullptr;
    SDL_Texture* texture = nullptr;
	int window_id = -1;
	TSGE_Cartesian img_cart = {0,0,0,0};
	TSGE_Cartesian dst_cart = {0,0,0,0};
	int result = TSGE_ERRORFLAG_GENERIC;

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

            op_result = this->tsge_sdltexture_apply(texture, render, img_cart.x, img_cart.y, img_cart.w, img_cart.h, dst_cart.x, dst_cart.y, dst_cart.w, dst_cart.h);
            result = image_id;

        //Draw area is not solid
        }else{
            op_result = this->tsge_sdltexture_apply(texture, render, dst_cart.x, dst_cart.y, dst_cart.w, dst_cart.h);
            result = image_id;

        }

		if(!op_result){
			result = TSGE_ERRORFLAG_RENDERPROCESS;
		}

    //Result is TSGE_ERRORFLAG_GENERIC if something went wrong
	}else{

		result = TSGE_ERRORFLAG_GENERIC;

	}

	return result;

}


//---------------------------------------------------------------------------

//With this function, the tag node linked to the image can be modified
int TSGE::tsge_image_tag_set(int image_id, string tag){

    int result = TSGE_ERRORFLAG_GENERIC;
    TSGE_Image* image_node = nullptr;

    image_node = this->image_index->getNode(image_id);

    //Looking for a image in the index
    if(image_node != nullptr){

        image_node->setTag(tag);
        result = image_id;

    //The index does not contains any node with that id
    }else{
        result = TSGE_ERRORFLAG_NOREGISTER;

    }

    return result;

}


//---------------------------------------------------------------------------

//This function is used to draw an image inside of a window
int TSGE::tsge_image_move(int image_id, int x, int y, int window_id){

	bool op_result = false;
	TSGE_Image* image_node = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Renderer* render = nullptr;
	int w = 0;
	int h = 0;
	int result = TSGE_ERRORFLAG_GENERIC;

	image_node = this->image_index->getNode(image_id);
	render = this->window_index->getRender(window_id);

    //The function only works if all the object information is retrieved previously
	if(image_node != nullptr && render != nullptr){

		image_node->setAvailable(false);

		texture = image_node->getTexture();
		w = image_node->getTexture_w();
		h = image_node->getTexture_h();

        //The proper SDL controller function is called
		op_result = this->tsge_sdltexture_apply(texture, render, x, y, w, h);
		if(!op_result){
			result = TSGE_ERRORFLAG_IMAGEDRAW;

		}

    //There was a problem trying to recover the action data
	}else{
		result = TSGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function marks an image as 'available', but the image is still in the memory program
int TSGE::tsge_image_free(int image_id){

    int result = TSGE_ERRORFLAG_GENERIC;
    TSGE_Image* image_node = nullptr;

    image_node = this->image_index->getNode(image_id);

    //Looking for a image in the index
    if(image_node != nullptr){

        image_node->setAvailable(true);
        result = image_id;

    //The index does not contains any node with that id
    }else{
		result = TSGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function unloads an image from the memory program
int TSGE::tsge_image_unload(int image_id){

	TSGE_Image* image_node = nullptr;
	SDL_Texture* image_texture = nullptr;
	SDL_Surface* image_surface = nullptr;
	int result = TSGE_ERRORFLAG_GENERIC;

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
		result = TSGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function unloads an image from the memory program and deletes the proper DMOM node
int TSGE::tsge_image_delete(int image_id){

    image_id = this->tsge_image_unload(image_id);
    image_id = this->image_index->deleteNode(image_id);

	return image_id;

}


//---------------------------------------------------------------------------

//This function creates a new window
int TSGE::tsge_window_create(string title, TSGE_Cartesian coords, Uint32 wflags, Uint32 rflags){

	SDL_Window* window = nullptr;
	SDL_Renderer* render = nullptr;
	SDL_DisplayMode display_mode;
	int window_id = -1;
	int result = TSGE_ERRORFLAG_GENERIC;


	SDL_GetCurrentDisplayMode(0, &display_mode);

    //The coordinate values area changed if the user sends an TSGE_WINDOWFLAG
	if (coords.x == TSGE_WINDOWFLAG_XCENTERED) {
		coords.x = (display_mode.w / 2) - (coords.w / 2);
	}

	if (coords.y == TSGE_WINDOWFLAG_YCENTERED) {
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
            result = TSGE_ERRORFLAG_NORENDER;

		}

    //.. to send the creating error flag
	}else{
	    result = TSGE_ERRORFLAG_NOWINDOW;

	}

	return result;

}

//---------------------------------------------------------------------------

//This function can be used to create a fading effect.
int TSGE::tsge_window_fading(Uint8 alpha, int window_id, TSGE_Color color){

    TSGE_Cartesian window_size = {-1, -1, -1, -1};
    int result = TSGE_ERRORFLAG_GENERIC;

    window_size = this->tsge_window_cartesian_get(window_id);

    result = this->tsge_square_draw({0, 0, window_size.w, window_size.h}, {color.r, color.g, color.b, alpha}, TSGE_BLENDINGFLAG_BLEND, window_id);

    return result;

}


//---------------------------------------------------------------------------

//This function allows to hide or show a window
int TSGE::tsge_window_set_visible(int window_id, bool visible){

	TSGE_Window* mwindow = nullptr;
	int result = TSGE_ERRORFLAG_GENERIC;

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
        result = TSGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function deletes a window
int TSGE::tsge_window_remove(int window_id){

	int result = TSGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	if (this->window_index->searchByIdent(window_id) == window_id) {

		SDL_DestroyRenderer(this->window_index->getRender(window_id));
		SDL_DestroyWindow(this->window_index->getWindow(window_id));
		result = this->window_index->getIdent(window_id);
		this->window_index->deleteNode(window_id);

    //The index does not contains any node with that id
	}else{
	    result = TSGE_ERRORFLAG_NOREGISTER;

    }

	return result;

}


//---------------------------------------------------------------------------

//This function allows to change the window focus
int TSGE::tsge_window_set_focus(int window_id){

	TSGE_Window* mwindow = nullptr;
	int result = TSGE_ERRORFLAG_GENERIC;

	//Looking for a window in the index
	mwindow = this->window_index->getNode(window_id);
	if (mwindow != nullptr) {

		SDL_RaiseWindow(mwindow->getWindow());
		result = mwindow->getIdent();

    //The index does not contains any node with that id
	}else{
        result = TSGE_ERRORFLAG_NOREGISTER;
	}

	return result;

}


//---------------------------------------------------------------------------

//This function loads and initializes the needed libraries
bool TSGE::tsge_core_load_libs(){

	bool load_status = true;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	return load_status;

}


//---------------------------------------------------------------------------

//This function returns the main DMOM object used
DMOM * TSGE::tsge_dmom_get(){

	return this->dmom;

}


//---------------------------------------------------------------------------

//This function creates a label and stores it in memory as an image
int TSGE::tsge_label_compose(string text, int font_id, TSGE_Color color, Uint8 mode, TSGE_Color bg_color){

    SDL_Color label_color;
    TTF_Font* font = nullptr;
    TSGE_Font* font_node = nullptr;
    int image_id = -1;
	int image_w = -1;
	int image_h = -1;
    int result = TSGE_ERRORFLAG_GENERIC;
    string tag = "";
    SDL_Surface* temp_surface = nullptr;
    SDL_Texture* temp_texture = nullptr;

    font_node = this->font_index->getNode(font_id);

    //Font id is not valid
    if(font_node == nullptr){
        result = TSGE_ERRORFLAG_FONTID;

    }else{

        //The font object is recovered
        font = font_node->getFont();

        //Searching for a previously similar composed label
        tag = "TSGELABEL|" + text + "|" + font_node->getSrc() + "|" + tsge_util_itos(font_node->getSize()) + "|" + tsge_util_actos(color);
        image_id = this->image_index->searchByTag(tag);

        //There are no similar labels
        if(image_id == -1){

            label_color = tsge_util_actsc(color);
            image_id = this->image_index->searchAvailable();

            //There area available registers
            if(image_id == -1){

			    image_id = this->image_index->createNode(tag);
			    this->image_index->setSrc(image_id, tag);

            //There is an available register
            }else{

                this->tsge_image_unload(image_id);
                this->image_index->setTag(image_id, tag);
                this->image_index->setSrc(image_id, tag);

            }

            //The image is created and the node values are updated
            temp_surface = this->tsge_sdlttf_create_surface(text, font, color, mode, bg_color);
            temp_texture = this->tsge_sdlttf_create_texture(temp_surface);

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
SDL_Surface* TSGE::tsge_sdlttf_create_surface(string text, TTF_Font* font, TSGE_Color color, Uint8 mode, TSGE_Color bg_color){

    SDL_Surface* temp_surface = nullptr;

    if(mode == TSGE_LABELMODEFLAG_BLENDED){
        temp_surface = TTF_RenderUTF8_Blended(font, text.c_str(), tsge_util_actsc(color));

    }else if(mode == TSGE_LABELMODEFLAG_SOLID){
        temp_surface = TTF_RenderUTF8_Solid( font, text.c_str(), tsge_util_actsc(color));

    }else if(mode == TSGE_LABELMODEFLAG_SHADED){
        temp_surface = TTF_RenderUTF8_Shaded( font, text.c_str(), tsge_util_actsc(color), tsge_util_actsc(bg_color));

    }else{
        temp_surface = TTF_RenderUTF8_Solid( font, text.c_str(), tsge_util_actsc(color));

    }

    return temp_surface;

}


//---------------------------------------------------------------------------

//This functions loads an image as a SDL_Texture
SDL_Texture* TSGE::tsge_sdlttf_create_texture(SDL_Surface* temp_surface, SDL_Renderer* render){

    SDL_Texture* temp_texture = nullptr;
    TSGE_Window* window = nullptr;

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
int TSGE::tsge_image_deploy(string src, int window_id) {

	SDL_Texture* temp_texture = nullptr;
	SDL_Surface* temp_surface = nullptr;
	SDL_Renderer* render = nullptr;
	int image_w = -1;
	int image_h = -1;
	int image_id = -1;
	int result = TSGE_ERRORFLAG_GENERIC;
	string tag = "";

    //Here, we check if the image was previously loaded
    tag = src;
	image_id = this->image_index->searchByTag(tag);

    //If the images was not loaded
	if (image_id == -1){

        //The function looks for an available node
        image_id = this->image_index->searchByAvailable(true);

        //Here we check if the image file really exists
        if(tsge_util_file_check(src)){

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

                this->tsge_image_unload(image_id);
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
            result = TSGE_ERRORFLAG_FILEACCESS;

        }

    //If the image was previously loaded, no image is loaded, but the function returns the other image id
	}else{

        this->image_index->setAvailable(image_id, false);
        result = image_id;

	}

	return result;

}

//This function calls the other version of 'tsge_image_deploy' and draws the image in the window
int TSGE::tsge_image_deploy(string src, int x, int y, int window_id){

    int result = TSGE_ERRORFLAG_GENERIC;
	int image_id = -1;

	image_id = this->tsge_image_deploy(src, window_id);
	result = this->tsge_image_move(image_id, x, y, window_id);

	return result;

}


//---------------------------------------------------------------------------

//This function unloads a font from the memory program
int TSGE::tsge_font_unload(int font_id){

	int result = TSGE_ERRORFLAG_GENERIC;
	TSGE_Font* font_node = nullptr;
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
		result = TSGE_ERRORFLAG_NOREGISTER;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function marks an font as 'available', but the font is still in the memory program
int TSGE::tsge_font_free(int font_id){

    TSGE_Font* font_node = nullptr;
    int result = TSGE_ERRORFLAG_GENERIC;

    //Looking for a font in the index
    font_node = this->font_index->getNode(font_id);
    if(font_node != nullptr){

        font_node->setAvailable(true);
        result = font_id;

    //The index does not contains any node with that id
    }else{
        result = TSGE_ERRORFLAG_FONTID;

	}

	return result;

}


//---------------------------------------------------------------------------

//This function unloads an font from the memory program and deletes the proper DMOM node
int TSGE::tsge_font_delete(int font_id){

    int result = TSGE_ERRORFLAG_GENERIC;

    font_id = this->tsge_font_unload(font_id);
    result = this->image_index->deleteNode(font_id);

	return result;

}


//---------------------------------------------------------------------------

//This function load an specified file as a font
int TSGE::tsge_font_deploy(string src, int font_size){

    TTF_Font *temp_font = nullptr;
    int result = TSGE_ERRORFLAG_GENERIC;
    int font_id = -1;
    string tag = "";

    tag = src + "|" + tsge_util_itos(font_size);
    font_id = this->font_index->searchByTag(tag);

    //Font is not registered, this block loads the font and creates the register
     if (font_id == -1){

        //We search for an available register
        font_id = this->font_index->searchByAvailable(true);

        if (tsge_util_file_check(src)){

            temp_font =  TTF_OpenFont(src.c_str(), font_size);

            //There was a problem loading the font file
            if (temp_font == nullptr){
                result = TSGE_ERRORFLAG_FONTLOAD;

            }else{

                //If we need to create a new register (there are not available registers)
                if(font_id == -1){
                    font_id = this->font_index->createNode(tag);

                //if we have found an available register for the new font
                }else{
                    font_id = this->tsge_font_unload(font_id);

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
            result = TSGE_ERRORFLAG_FILEACCESS;

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
TSGE_Cartesian TSGE::tsge_image_size_get(int image_id){

    TSGE_Cartesian result = {0,0,0,0};

    result.h = this->image_index->getTexture_h(image_id);
    result.w = this->image_index->getTexture_w(image_id);

    return result;

}


//---------------------------------------------------------------------------

//This functions stops the execution temporarily
void TSGE::tsge_pause(int miliseconds){

	SDL_Delay(miliseconds);

}


//---------------------------------------------------------------------------

//All the window content is updated
int TSGE::tsge_window_refresh(){

	TSGE_Window* mwindow = nullptr;
	SDL_Renderer* mrender = nullptr;
	int updated_windows = 0;
	int result = TSGE_ERRORFLAG_GENERIC;

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
int TSGE::tsge_window_refresh(int window_id){

	TSGE_Window* mwindow = nullptr;
	SDL_Renderer* mrender = nullptr;
	int result = TSGE_ERRORFLAG_GENERIC;

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
int TSGE::tsge_draw_area_create(TSGE_Cartesian coords, bool solid, int window_id){

    int da_id = TSGE_ERRORFLAG_GENERIC;

    da_id = this->draw_area_index->createNode();
    this->draw_area_index->setValues(da_id, coords.x, coords.y, coords.w, coords.h, solid, window_id);

    return da_id;

}


//---------------------------------------------------------------------------

//This functions draws a line in the specified window
int TSGE::tsge_line_draw(TSGE_Cartesian point1, TSGE_Cartesian point2, TSGE_Color color, SDL_BlendMode blend_mode, int window_id){

    SDL_Renderer* render = nullptr;
    int result = TSGE_ERRORFLAG_GENERIC;

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
            SDL_SetRenderDrawBlendMode(render, TSGE_BLENDINGFLAG_NONE);
        }

        result = window_id;

    }

    return result;

}


//---------------------------------------------------------------------------

//This functions checks if two areas are in a collision status
bool TSGE::tsge_collision_check(TSGE_Cartesian area1, TSGE_Cartesian area2){

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
