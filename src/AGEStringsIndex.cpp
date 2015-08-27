/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 27/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGEStringsIndex.h"


//---------------------------------------------------------------------------

AGEStringsIndex::AGEStringsIndex()
{

	this->counter = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGEStringsIndex::~AGEStringsIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int AGEStringsIndex::createRegister(string tag){

	AGEStringsElement* pointer = new AGEStringsElement();
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

int AGEStringsIndex::freeList(){

	AGEStringsElement* pointer;
	AGEStringsElement* next;
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

int AGEStringsIndex::getId(int id){

	int result = 0;
	AGEStringsElement* pointer;

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

string AGEStringsIndex::getTag(int id){

	string result = "";
	AGEStringsElement* pointer;

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

bool AGEStringsIndex::getAvailable(int id){

	bool result = false;
	AGEStringsElement* pointer;

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

AGEStringsElement* AGEStringsIndex::getNext(int id){

	AGEStringsElement* result = nullptr;
	AGEStringsElement* pointer;

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

string AGEStringsIndex::getEntry1(int id){

	string result = "";
	AGEStringsElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getEntry1();

	}

	return result;

}

//---------------------------------------------------------------------------

string AGEStringsIndex::getEntry2By1(string entry1){

    string result = "";
	int index;

    index = this->searchByEntry1(entry1);
    if (index != -1){
        result = this->getEntry2(index);

    }

    return result;

}


//---------------------------------------------------------------------------

string AGEStringsIndex::getEntry2(int id){

	string result = "";
	AGEStringsElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";


	}else{
		result = pointer->getEntry2();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGEStringsIndex::getEntry3(int id){

	string result = "";
	AGEStringsElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getEntry3();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::searchById(int id){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

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

int AGEStringsIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

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

int AGEStringsIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

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

int AGEStringsIndex::searchByNext(AGEStringsElement* next){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

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

int AGEStringsIndex::searchByEntry1(string entry1){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (entry1 == pointer->getEntry1()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEStringsIndex::searchByEntry2(string entry2){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (entry2 == pointer->getEntry2()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEStringsIndex::searchByEntry3(string entry3){

	int result = -1;
	bool found = false;
	AGEStringsElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (entry3 == pointer->getEntry3()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEStringsIndex::setElementData(int id, string tag, string entry1, string entry2, string entry3){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setEntry1(entry1);
		pointer->setEntry2(entry2);
		pointer->setEntry3(entry3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setElementData(int id, string entry1, string entry2, string entry3){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setEntry1(entry1);
		pointer->setEntry2(entry2);
		pointer->setEntry3(entry3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setTag(int id, string tag){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setAvailable(int id, bool available){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setNext(int id, AGEStringsElement* next){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setEntry1(int id, string entry1){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setEntry1(entry1);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setEntry2(int id, string entry2){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setEntry2(entry2);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEStringsIndex::setEntry3(int id, string entry3){

	AGEStringsElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setEntry3(entry3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

AGEStringsElement* AGEStringsIndex::getElementById(int id){
	AGEStringsElement* result;
	AGEStringsElement* pointer;

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

int AGEStringsIndex::searchAvailable(){

	int result = -1;
	int counter = 0;
	bool found = false;
	AGEStringsElement* pointer;

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


