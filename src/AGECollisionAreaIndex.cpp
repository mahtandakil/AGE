/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 13/08/2015
* Last change: 22/08/2015
* Autogen: CListGen 1.0.3
****************************************************************************/


#include "AGECollisionAreaIndex.h"


//---------------------------------------------------------------------------

AGECollisionAreaIndex::AGECollisionAreaIndex()
{

	this->counter = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGECollisionAreaIndex::~AGECollisionAreaIndex()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::createRegister(string tag){

	AGECollisionAreaElement* pointer = new AGECollisionAreaElement();
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

int AGECollisionAreaIndex::getId(int id){

	int result = 0;
	AGECollisionAreaElement* pointer;

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

string AGECollisionAreaIndex::getTag(int id){

	string result = "";
	AGECollisionAreaElement* pointer;

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

bool AGECollisionAreaIndex::getAvailable(int id){

	bool result = false;
	AGECollisionAreaElement* pointer;

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

AGECollisionAreaElement* AGECollisionAreaIndex::getNext(int id){

	AGECollisionAreaElement* result = nullptr;
	AGECollisionAreaElement* pointer;

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

Uint8 AGECollisionAreaIndex::getType(int id){

	Uint8 result = 0;
	AGECollisionAreaElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getType();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Rect AGECollisionAreaIndex::getArea(int id){

	SDL_Rect result;
	AGECollisionAreaElement* pointer;

    result.x = 0;
    result.y = 0;
    result.h = 0;
    result.w = 0;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){

	    result.x = 0;
        result.y = 0;
        result.h = 0;
        result.w = 0;

	}else{
		result = pointer->getArea();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaIndex::getColor1(int id){

	Uint8 result = 0;
	AGECollisionAreaElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getColor1();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaIndex::getColor2(int id){

	Uint8 result = 0;
	AGECollisionAreaElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getColor2();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGECollisionAreaIndex::getColor3(int id){

	Uint8 result = 0;
	AGECollisionAreaElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getColor3();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::searchById(int id){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

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

int AGECollisionAreaIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

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

int AGECollisionAreaIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

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

int AGECollisionAreaIndex::searchByNext(AGECollisionAreaElement* next){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

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

int AGECollisionAreaIndex::searchByType(Uint8 type){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (type == pointer->getType()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::searchByColor1(Uint8 color1){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (color1 == pointer->getColor1()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::searchByColor2(Uint8 color2){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (color2 == pointer->getColor2()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::searchByColor3(Uint8 color3){

	int result = -1;
	bool found = false;
	AGECollisionAreaElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (color3 == pointer->getColor3()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setElementData(int id, string tag, Uint8 type, SDL_Rect area, Uint8 color1, Uint8 color2, Uint8 color3){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setType(type);
		pointer->setArea(area);
		pointer->setColor1(color1);
		pointer->setColor2(color2);
		pointer->setColor3(color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setElementData(int id, Uint8 type, SDL_Rect area, Uint8 color1, Uint8 color2, Uint8 color3){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setType(type);
		pointer->setArea(area);
		pointer->setColor1(color1);
		pointer->setColor2(color2);
		pointer->setColor3(color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setTag(int id, string tag){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setAvailable(int id, bool available){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setNext(int id, AGECollisionAreaElement* next){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setType(int id, Uint8 type){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setType(type);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setArea(int id, SDL_Rect area){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setArea(area);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setColor(int id, Uint8 color1, Uint8 color2, Uint8 color3){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setColor1(color1);
		pointer->setColor2(color2);
		pointer->setColor3(color3);
		result = pointer->getId();

	}

	return result;

}

//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setColor1(int id, Uint8 color1){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setColor1(color1);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setColor2(int id, Uint8 color2){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setColor2(color2);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGECollisionAreaIndex::setColor3(int id, Uint8 color3){

	AGECollisionAreaElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setColor3(color3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

AGECollisionAreaElement* AGECollisionAreaIndex::getElementById(int id){
	AGECollisionAreaElement* result;
	AGECollisionAreaElement* pointer;

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

int AGECollisionAreaIndex::searchAvailable(){

	int result = -1;
	int counter = 0;
	bool found = false;
	AGECollisionAreaElement* pointer;

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

int AGECollisionAreaIndex::setPosition(int id, int x, int y){

	AGECollisionAreaElement* pointer;
    SDL_Rect area;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

        area = pointer->getArea();
		area.x = x;
		area.y = y;
        pointer->setArea(area);

	}

	return result;

}


//---------------------------------------------------------------------------

