/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 29/08/2015
* Last change: 29/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEFontIndex.h"


//---------------------------------------------------------------------------

AGEFontIndex::AGEFontIndex()
{

	this->counter = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGEFontIndex::~AGEFontIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int AGEFontIndex::createRegister(string tag){

	AGEFontElement* pointer = new AGEFontElement();
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

int AGEFontIndex::freeList(){

	AGEFontElement* pointer;
	AGEFontElement* next;
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

int AGEFontIndex::getId(int id){

	int result = 0;
	AGEFontElement* pointer;

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

string AGEFontIndex::getTag(int id){

	string result = "";
	AGEFontElement* pointer;

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

bool AGEFontIndex::getAvailable(int id){

	bool result = false;
	AGEFontElement* pointer;

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

AGEFontElement* AGEFontIndex::getNext(int id){

	AGEFontElement* result = nullptr;
	AGEFontElement* pointer;

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

string AGEFontIndex::getSrc(int id){

	string result = "";
	AGEFontElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getSrc();

	}

	return result;

}


//---------------------------------------------------------------------------

TTF_Font* AGEFontIndex::getFont(int id){

	TTF_Font* result = nullptr;
	AGEFontElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;
;

	}else{
		result = pointer->getFont();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::searchById(int id){

	int result = -1;
	bool found = false;
	AGEFontElement* pointer;

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

int AGEFontIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGEFontElement* pointer;

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

int AGEFontIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGEFontElement* pointer;

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

int AGEFontIndex::searchByNext(AGEFontElement* next){

	int result = -1;
	bool found = false;
	AGEFontElement* pointer;

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

int AGEFontIndex::searchBySrc(string src){

	int result = -1;
	bool found = false;
	AGEFontElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (src == pointer->getSrc()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEFontIndex::searchByFont(TTF_Font* font){

	int result = -1;
	bool found = false;
	AGEFontElement* pointer;

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

int AGEFontIndex::setElementData(int id, string tag, string src, TTF_Font* font){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setSrc(src);
		pointer->setFont(font);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::setElementData(int id, string src, TTF_Font* font){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setSrc(src);
		pointer->setFont(font);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::setTag(int id, string tag){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::setAvailable(int id, bool available){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::setNext(int id, AGEFontElement* next){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::setSrc(int id, string src){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setSrc(src);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEFontIndex::setFont(int id, TTF_Font* font){

	AGEFontElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFont(font);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

AGEFontElement* AGEFontIndex::getElementById(int id){
	AGEFontElement* result;
	AGEFontElement* pointer;

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

int AGEFontIndex::searchAvailable(){

	int result = -1;
	int counter = 0;
	bool found = false;
	AGEFontElement* pointer;

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


