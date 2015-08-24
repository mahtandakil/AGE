/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 24/08/2015
* Last change: 24/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGEAnimationIndex.h"


//---------------------------------------------------------------------------

AGEAnimationIndex::AGEAnimationIndex()
{

	this->counter = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGEAnimationIndex::~AGEAnimationIndex()
{
	//dtor
}


//---------------------------------------------------------------------------

int AGEAnimationIndex::createRegister(string tag){

	AGEAnimationElement* pointer = new AGEAnimationElement();
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

int AGEAnimationIndex::freeList(){

	AGEAnimationElement* pointer;
	AGEAnimationElement* next;
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

int AGEAnimationIndex::getId(int id){

	int result = 0;
	AGEAnimationElement* pointer;

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

string AGEAnimationIndex::getTag(int id){

	string result = "";
	AGEAnimationElement* pointer;

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

bool AGEAnimationIndex::getAvailable(int id){

	bool result = false;
	AGEAnimationElement* pointer;

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

AGEAnimationElement* AGEAnimationIndex::getNext(int id){

	AGEAnimationElement* result = nullptr;
	AGEAnimationElement* pointer;

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

Uint8 AGEAnimationIndex::getElements(int id){

	Uint8 result = 0;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getElements();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGEAnimationIndex::getInit(int id){

	Uint8 result = 0;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getInit();

	}

	return result;

}


//---------------------------------------------------------------------------

AGETextureListIndex* AGEAnimationIndex::getTexture_index(int id){

	AGETextureListIndex* result = nullptr;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;
;

	}else{
		result = pointer->getTexture_index();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::searchById(int id){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

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

int AGEAnimationIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

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

int AGEAnimationIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

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

int AGEAnimationIndex::searchByNext(AGEAnimationElement* next){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

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

int AGEAnimationIndex::searchByElements(Uint8 elements){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (elements == pointer->getElements()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByInit(Uint8 init){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (init == pointer->getInit()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByTexture_index(AGETextureListIndex* texture_index){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (texture_index == pointer->getTexture_index()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::setElementData(int id, string tag, Uint8 elements, Uint8 init, AGETextureListIndex* texture_index){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setElements(elements);
		pointer->setInit(init);
		pointer->setTexture_index(texture_index);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setElementData(int id, Uint8 elements, Uint8 init, AGETextureListIndex* texture_index){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setElements(elements);
		pointer->setInit(init);
		pointer->setTexture_index(texture_index);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setTag(int id, string tag){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setAvailable(int id, bool available){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setNext(int id, AGEAnimationElement* next){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setElements(int id, Uint8 elements){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setElements(elements);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setInit(int id, Uint8 init){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setInit(init);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setTexture_index(int id, AGETextureListIndex* texture_index){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTexture_index(texture_index);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

AGEAnimationElement* AGEAnimationIndex::getElementById(int id){
	AGEAnimationElement* result;
	AGEAnimationElement* pointer;

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

int AGEAnimationIndex::searchAvailable(){

	int result = -1;
	int counter = 0;
	bool found = false;
	AGEAnimationElement* pointer;

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


