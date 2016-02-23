/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 16/02/16
* Autogen: 1.1.2b
****************************************************************************/


#include "AGE_EventIndex.h"


//---------------------------------------------------------------------------

AGE_EventIndex::AGE_EventIndex()
{

	this->nodes = 0;
	this->next_ident = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGE_EventIndex::~AGE_EventIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int AGE_EventIndex::createNode(string tag){

	AGE_Event* pointer = new AGE_Event();
	pointer->setTag(tag);

	if (this->nodes == 0){
	
		this->nodes = 1;
		pointer->setIdent(0);
		this->next_ident = 1;
		this->first = pointer;
		this->last = pointer;
	
	}else{
	
		this->nodes++;
		pointer->setIdent(this->next_ident);
		this->next_ident++;
		this->last->setNext(pointer);
		this->last = pointer;
		
	}

	return pointer->getIdent();

}


//---------------------------------------------------------------------------

int AGE_EventIndex::freeNode(int ident){

	AGE_Event* pointer = nullptr;
	int result= -1;

	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
		
		pointer->setAvailable(true);
		result = pointer->getIdent();
		
	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getPrevious(int ident){

	AGE_Event* pointer = nullptr;
	AGE_Event* next = nullptr;
	bool keep = true;
	int result = -1;

    if(this->nodes > 0){

        pointer = this->first;

        while(keep){

            if(pointer->getNext() == nullptr){

                keep = false;

            }else{

                next = pointer->getNext();

                if(ident == next->getIdent()){

                    keep = false;
                    result = pointer->getIdent();

                }else{

                    pointer = next;

                }

            }

        }

    }
	
	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::freeList(){

	AGE_Event* pointer = nullptr;
	int result= 0;

	pointer = this->first;

	while(pointer != nullptr){
	
		this->freeNode(pointer->getIdent());
		result++;
		pointer = pointer->getNext();
	
	}

    return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::deleteNode(int ident){

	AGE_Event* pointer = nullptr;
	AGE_Event* next = nullptr;
	AGE_Event* previous = nullptr;
	int previous_id = -1;
	int result = -1;

	pointer = this->getNode(ident);

	if(pointer != nullptr){

        if(ident == this->first->getIdent()){

            this->first = pointer->getNext();

        }else{

            previous_id = this->getPrevious(pointer->getIdent());
            previous = this->getNode(previous_id);
            next = pointer->getNext();

            if(ident == this->last->getIdent()){

                this->last = this->getNode(this->getPrevious(this->last->getIdent()));

            }

            previous->setNext(next);

        }

        result = pointer->getIdent();
        delete(pointer);
        this->nodes--;

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::deleteList(){

	AGE_Event* pointer = nullptr;
	int result = 0;

	pointer = this->first;

	while(pointer != nullptr){
	
		this->deleteNode(pointer->getIdent());
		pointer = this->first;
		result++;
		
	}

	this->nodes = 0;
	this->next_ident = 0;
	this->first = nullptr;
	this->last = nullptr;

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::purge(){

	AGE_Event* pointer = nullptr;
	int available_ident = -1;
	int result = -1;

	available_ident = this->searchAvailable();
	pointer = this->getNode(available_ident);
	
	while(pointer != nullptr){

		this->deleteNode(pointer->getIdent());

		available_ident = this->searchAvailable();
		pointer = this->getNode(available_ident);		
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchAvailable(int limit){

	AGE_Event* pointer = nullptr;
	bool found = false;
	int result = -1;
	
	pointer = this->first;
	while(pointer != nullptr && found == false){
	
		if(pointer->getAvailable() && pointer->getIdent() >= limit){
		
			found = true;
			result = pointer->getIdent();
		
		}else{
		
			pointer = pointer->getNext();
		
		}
	
	}
	
	return result;
	
}


//---------------------------------------------------------------------------

AGE_Event* AGE_EventIndex::getFirst(){

	return this->first;

}


//---------------------------------------------------------------------------

AGE_Event* AGE_EventIndex::getNode(int ident){

	AGE_Event* result = nullptr;
	AGE_Event* pointer = nullptr;
	
	if (this->nodes > 0){
	
		pointer = this->first;
		
		while (pointer != nullptr){
			if (ident == pointer->getIdent()){
				result = pointer;
		
			}
		
		pointer = pointer->getNext();
		
		}
		
	}
	
	return result;
	
}


//---------------------------------------------------------------------------

int AGE_EventIndex::setValues(int ident, Uint32 event, Uint32 device, int window, Uint32 timestamp, Uint32 state, int x, int y, int w, int h, Uint8 count, Uint16 mod){

	AGE_Event* pointer;
	int result = -1;
	
	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
	
		pointer->setEvent(event);
		pointer->setDevice(device);
		pointer->setWindow(window);
		pointer->setTimestamp(timestamp);
		pointer->setState(state);
		pointer->setX(x);
		pointer->setY(y);
		pointer->setW(w);
		pointer->setH(h);
		pointer->setCount(count);
		pointer->setMod(mod);
		result = pointer->getIdent();
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::printNodes(){

	AGE_Event* pointer;
	int result = 0;
	
	pointer = this->first;
	
	cout << "LIST NODES: " << this->nodes << endl;
	cout << "NEXT IDENT: " << this->next_ident << endl;
	cout << "FIRST: " << this->first << endl;
	cout << "LAST: " << this->last << endl;
	cout << endl;
	
	while(pointer != nullptr){
	
		pointer->printNode();
		pointer = pointer->getNext();
		result++;
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getIdent(int ident){

	int result = -1;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGE_EventIndex::getTag(int ident){

	string result = "";
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getTag();

	}

	return result;

}


//---------------------------------------------------------------------------

bool AGE_EventIndex::getAvailable(int ident){

	bool result = false;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = false;


	}else{
		result = pointer->getAvailable();

	}

	return result;

}


//---------------------------------------------------------------------------

AGE_Event* AGE_EventIndex::getNext(int ident){

	AGE_Event* result = nullptr;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getNext();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint32 AGE_EventIndex::getEvent(int ident){

	Uint32 result = 0;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = 0;


	}else{
		result = pointer->getEvent();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint32 AGE_EventIndex::getDevice(int ident){

	Uint32 result = 0;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = 0;


	}else{
		result = pointer->getDevice();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getWindow(int ident){

	int result = -1;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getWindow();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint32 AGE_EventIndex::getTimestamp(int ident){

	Uint32 result = 0;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = 0;


	}else{
		result = pointer->getTimestamp();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint32 AGE_EventIndex::getState(int ident){

	Uint32 result = 0;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = 0;


	}else{
		result = pointer->getState();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getX(int ident){

	int result = -1;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getX();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getY(int ident){

	int result = -1;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getY();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getW(int ident){

	int result = -1;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getW();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::getH(int ident){

	int result = -1;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getH();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint8 AGE_EventIndex::getCount(int ident){

	Uint8 result = 0;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = 0;


	}else{
		result = pointer->getCount();

	}

	return result;

}


//---------------------------------------------------------------------------

Uint16 AGE_EventIndex::getMod(int ident){

	Uint16 result = 0;
	AGE_Event* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = 0;


	}else{
		result = pointer->getMod();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByIdent(int ident){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (ident == pointer->getIdent()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (tag == pointer->getTag()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (available == pointer->getAvailable()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByNext(AGE_Event* next){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (next == pointer->getNext()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByEvent(Uint32 event){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (event == pointer->getEvent()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByDevice(Uint32 device){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (device == pointer->getDevice()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByWindow(int window){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (window == pointer->getWindow()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByTimestamp(Uint32 timestamp){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (timestamp == pointer->getTimestamp()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByState(Uint32 state){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (state == pointer->getState()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByX(int x){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (x == pointer->getX()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByY(int y){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (y == pointer->getY()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByW(int w){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (w == pointer->getW()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByH(int h){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (h == pointer->getH()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByCount(Uint8 count){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (count == pointer->getCount()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::searchByMod(Uint16 mod){

	int result = -1;
	bool found = false;
	AGE_Event* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (mod == pointer->getMod()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setTag(int ident, string tag){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setAvailable(int ident, bool available){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setNext(int ident, AGE_Event* next){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setEvent(int ident, Uint32 event){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setEvent(event);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setDevice(int ident, Uint32 device){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setDevice(device);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setWindow(int ident, int window){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setWindow(window);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setTimestamp(int ident, Uint32 timestamp){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTimestamp(timestamp);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setState(int ident, Uint32 state){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setState(state);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setX(int ident, int x){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setX(x);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setY(int ident, int y){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setY(y);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setW(int ident, int w){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setW(w);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setH(int ident, int h){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setH(h);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setCount(int ident, Uint8 count){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setCount(count);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_EventIndex::setMod(int ident, Uint16 mod){

	AGE_Event* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setMod(mod);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

