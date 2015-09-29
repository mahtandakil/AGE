/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 27/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGELabelTTFIndex.h"


//---------------------------------------------------------------------------

AGELabelTTFIndex::AGELabelTTFIndex()
{

	this->counter = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGELabelTTFIndex::~AGELabelTTFIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::createRegister(string tag){

	AGELabelTTFElement* pointer = new AGELabelTTFElement();
	pointer->setTag(tag);

	if (this->counter == 0){

		this->counter = 1;
		pointer->setId(0);
		this->first = pointer;
		this->last = pointer;

	}else{

		this->counter++;
		pointer->setId(this->counter-1);
		this->last->setNext(pointer);
		this->last = pointer;

	}

	return pointer->getId();

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::freeList(){

	AGELabelTTFElement* pointer;
	AGELabelTTFElement* next;
	int result= 0;

    if(this->first != nullptr){

        pointer = this->first;

        while(pointer != nullptr){

            next = pointer->getNext();
            counter++;
            delete pointer;
            pointer = next;

        }

    }

    return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::getId(int id){

	int result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGELabelTTFIndex::getTag(int id){

	string result = "";
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getTag();

	}

	return result;

}


//---------------------------------------------------------------------------

bool AGELabelTTFIndex::getAvailable(int id){

	bool result = false;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = false;
;

	}else{
		result = pointer->getAvailable();

	}

	return result;

}


//---------------------------------------------------------------------------

AGELabelTTFElement* AGELabelTTFIndex::getNext(int id){

	AGELabelTTFElement* result = nullptr;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;
;

	}else{
		result = pointer->getNext();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGELabelTTFIndex::getContent(int id){

	string result = "";
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getContent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::getFont(int id){

	int result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;

	}else{
		result = pointer->getFont();

	}

	return result;

}


//---------------------------------------------------------------------------

bool AGELabelTTFIndex::getBorder(int id){

	bool result = false;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = false;
;

	}else{
		result = pointer->getBorder();

	}

	return result;

}


//---------------------------------------------------------------------------

bool AGELabelTTFIndex::getBg(int id){

	bool result = false;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = false;
;

	}else{
		result = pointer->getBg();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getFont_color1(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getFont_color1();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getFont_color2(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getFont_color2();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getFont_color3(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getFont_color3();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBorder_margin(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBorder_margin();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBg_margin(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBg_margin();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBorder_color1(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBorder_color1();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBorder_color2(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBorder_color2();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBorder_color3(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBorder_color3();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBg_color1(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBg_color1();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBg_color2(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBg_color2();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getBg_color3(int id){

	Uint8 result = 0;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBg_color3();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Texture* AGELabelTTFIndex::getTexture(int id){

	SDL_Texture* result = nullptr;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;


	}else{
		result = pointer->getTexture();

	}

	return result;

}


//---------------------------------------------------------------------------

bool AGELabelTTFIndex::getModified(int id){

	bool result = false;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = false;


	}else{
		result = pointer->getModified();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGELabelTTFIndex::getRender(int id){

	Uint8 result = AGE_RENDER_N;
	AGELabelTTFElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = AGE_RENDER_N;


	}else{
		result = pointer->getRender();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchById(int id){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (id == pointer->getId()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (tag == pointer->getTag()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (available == pointer->getAvailable()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByNext(AGELabelTTFElement* next){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (next == pointer->getNext()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByContent(string content){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (content == pointer->getContent()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByFont(int font){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (font == pointer->getFont()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBorder(bool border){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (border == pointer->getBorder()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBg(bool bg){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bg == pointer->getBg()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByFont_color1(Uint8 font_color1){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (font_color1 == pointer->getFont_color1()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByFont_color2(Uint8 font_color2){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (font_color2 == pointer->getFont_color2()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByFont_color3(Uint8 font_color3){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (font_color3 == pointer->getFont_color3()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBorder_color1(Uint8 border_color1){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (border_color1 == pointer->getBorder_color1()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBorder_color2(Uint8 border_color2){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (border_color2 == pointer->getBorder_color2()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBorder_color3(Uint8 border_color3){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (border_color3 == pointer->getBorder_color3()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBg_color1(Uint8 bg_color1){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bg_color1 == pointer->getBg_color1()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBg_color2(Uint8 bg_color2){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bg_color2 == pointer->getBg_color2()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchByBg_color3(Uint8 bg_color3){

	int result = -1;
	bool found = false;
	AGELabelTTFElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bg_color3 == pointer->getBg_color3()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGELabelTTFIndex::setElementData(int id, string tag, string content, int font, bool border, bool bg, Uint8 font_color1, Uint8 font_color2, Uint8 font_color3, Uint8 border_color1, Uint8 border_color2, Uint8 border_color3, Uint8 bg_color1, Uint8 bg_color2, Uint8 bg_color3){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setContent(content);
		pointer->setFont(font);
		pointer->setBorder(border);
		pointer->setBg(bg);
		pointer->setFont_color1(font_color1);
		pointer->setFont_color2(font_color2);
		pointer->setFont_color3(font_color3);
		pointer->setBorder_color1(border_color1);
		pointer->setBorder_color2(border_color2);
		pointer->setBorder_color3(border_color3);
		pointer->setBg_color1(bg_color1);
		pointer->setBg_color2(bg_color2);
		pointer->setBg_color3(bg_color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setElementData(int id, string content, int font, bool border, bool bg, Uint8 font_color1, Uint8 font_color2, Uint8 font_color3, Uint8 border_color1, Uint8 border_color2, Uint8 border_color3, Uint8 bg_color1, Uint8 bg_color2, Uint8 bg_color3){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setContent(content);
		pointer->setFont(font);
		pointer->setBorder(border);
		pointer->setBg(bg);
		pointer->setFont_color1(font_color1);
		pointer->setFont_color2(font_color2);
		pointer->setFont_color3(font_color3);
		pointer->setBorder_color1(border_color1);
		pointer->setBorder_color2(border_color2);
		pointer->setBorder_color3(border_color3);
		pointer->setBg_color1(bg_color1);
		pointer->setBg_color2(bg_color2);
		pointer->setBg_color3(bg_color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setTag(int id, string tag){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setAvailable(int id, bool available){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setNext(int id, AGELabelTTFElement* next){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setContent(int id, string content){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setContent(content);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setFont(int id, int font){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFont(font);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBorder(int id, bool border){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBorder(border);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBg(int id, bool bg){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBg(bg);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setFont_color1(int id, Uint8 font_color1){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFont_color1(font_color1);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setFont_color2(int id, Uint8 font_color2){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFont_color2(font_color2);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setFont_color3(int id, Uint8 font_color3){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFont_color3(font_color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setTexture(int id, SDL_Texture* texture){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTexture(texture);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setModified(int id, bool modified){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setModified(modified);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setRender(int id, Uint8 render){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setRender(render);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBorder_margin(int id, Uint8 border_margin){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBorder_margin(border_margin);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBg_margin(int id, Uint8 bg_margin){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBg_margin(bg_margin);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBorder_color1(int id, Uint8 border_color1){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBorder_color1(border_color1);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBorder_color2(int id, Uint8 border_color2){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBorder_color2(border_color2);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBorder_color3(int id, Uint8 border_color3){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBorder_color3(border_color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBg_color1(int id, Uint8 bg_color1){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBg_color1(bg_color1);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBg_color2(int id, Uint8 bg_color2){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBg_color2(bg_color2);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::setBg_color3(int id, Uint8 bg_color3){

	AGELabelTTFElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBg_color3(bg_color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

AGELabelTTFElement* AGELabelTTFIndex::getElementById(int id){

	AGELabelTTFElement* result = nullptr;
	AGELabelTTFElement* pointer = nullptr;

	if (this->counter == 0){
		result = nullptr;

	}else{

		pointer = this->first;

		while (pointer != nullptr){
			if (id == pointer->getId()){
				result = pointer;

			}

		pointer = pointer->getNext();
		}
	}

	return result;

}


//---------------------------------------------------------------------------

int AGELabelTTFIndex::searchAvailable(){

	int result = -1;
	int counter = 0;
	bool found = false;
	AGELabelTTFElement* pointer;

	while((counter < this->counter) && (found == false)){

		pointer = this->getElementById(counter);
		if (pointer->getAvailable() == true){

			result = pointer->getId();
			found = true;

		}

		counter++;

	}

	return result;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


