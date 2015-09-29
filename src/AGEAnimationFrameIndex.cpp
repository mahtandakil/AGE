/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 27/08/2015
* Last change: 27/09/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include "AGEAnimationFrameIndex.h"


//---------------------------------------------------------------------------

AGEAnimationFrameIndex::AGEAnimationFrameIndex()
{

	this->counter = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGEAnimationFrameIndex::~AGEAnimationFrameIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::createRegister(string tag){

	AGEAnimationFrameElement* pointer = new AGEAnimationFrameElement();
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

int AGEAnimationFrameIndex::freeList(){

	AGEAnimationFrameElement* pointer;
	AGEAnimationFrameElement* next;
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

int AGEAnimationFrameIndex::getId(int id){

	int result = 0;
	AGEAnimationFrameElement* pointer;

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

string AGEAnimationFrameIndex::getTag(int id){

	string result = "";
	AGEAnimationFrameElement* pointer;

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

bool AGEAnimationFrameIndex::getAvailable(int id){

	bool result = false;
	AGEAnimationFrameElement* pointer;

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

AGEAnimationFrameElement* AGEAnimationFrameIndex::getNext(int id){

	AGEAnimationFrameElement* result = nullptr;
	AGEAnimationFrameElement* pointer;

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

int AGEAnimationFrameIndex::getImage_x(int id){

	int result = 0;
	AGEAnimationFrameElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getImage_x();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::getImage_y(int id){

	int result = 0;
	AGEAnimationFrameElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getImage_y();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::getImage_w(int id){

	int result = 0;
	AGEAnimationFrameElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getImage_w();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::getImage_h(int id){

	int result = 0;
	AGEAnimationFrameElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getImage_h();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::getImage_d(int id){

	int result = 0;
	AGEAnimationFrameElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getImage_d();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::searchById(int id){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

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

int AGEAnimationFrameIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

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

int AGEAnimationFrameIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

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

int AGEAnimationFrameIndex::searchByNext(AGEAnimationFrameElement* next){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

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

int AGEAnimationFrameIndex::searchByImage_x(int image_x){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (image_x == pointer->getImage_x()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::searchByImage_y(int image_y){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (image_y == pointer->getImage_y()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::searchByImage_w(int image_w){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (image_w == pointer->getImage_w()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::searchByImage_h(int image_h){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (image_h == pointer->getImage_h()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::searchByImage_d(int image_d){

	int result = -1;
	bool found = false;
	AGEAnimationFrameElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (image_d == pointer->getImage_d()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setElementData(int id, string tag, int image_x, int image_y, int image_w, int image_h, int image_d){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setImage_x(image_x);
		pointer->setImage_y(image_y);
		pointer->setImage_w(image_w);
		pointer->setImage_h(image_h);
		pointer->setImage_d(image_d);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setElementData(int id, int image_x, int image_y, int image_w, int image_h, int image_d){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImage_x(image_x);
		pointer->setImage_y(image_y);
		pointer->setImage_w(image_w);
		pointer->setImage_h(image_h);
		pointer->setImage_d(image_d);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setTag(int id, string tag){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setAvailable(int id, bool available){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setNext(int id, AGEAnimationFrameElement* next){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setImage_x(int id, int image_x){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImage_x(image_x);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setImage_y(int id, int image_y){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImage_y(image_y);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setImage_w(int id, int image_w){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImage_w(image_w);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setImage_h(int id, int image_h){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImage_h(image_h);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationFrameIndex::setImage_d(int id, int image_d){

	AGEAnimationFrameElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImage_d(image_d);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

AGEAnimationFrameElement* AGEAnimationFrameIndex::getElementById(int id){

	AGEAnimationFrameElement* result = nullptr;
	AGEAnimationFrameElement* pointer = nullptr;

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

int AGEAnimationFrameIndex::searchAvailable(){

	int result = -1;
	int counter = 0;
	bool found = false;
	AGEAnimationFrameElement* pointer;

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


