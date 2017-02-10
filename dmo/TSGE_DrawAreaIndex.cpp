/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_DrawAreaIndex.h"


//---------------------------------------------------------------------------

TSGE_DrawAreaIndex::TSGE_DrawAreaIndex()
{

	this->nodes = 0;
	this->next_ident = 0;
	this->first = nullptr;
	this->last = nullptr;

}

TSGE_DrawAreaIndex::~TSGE_DrawAreaIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::createNode(string tag){

	TSGE_DrawArea* pointer = new TSGE_DrawArea();
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

int TSGE_DrawAreaIndex::freeNode(int ident){

	TSGE_DrawArea* pointer = nullptr;
	int result= -1;

	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
		
		pointer->setAvailable(true);
		result = pointer->getIdent();
		
	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::getPrevious(int ident){

	TSGE_DrawArea* pointer = nullptr;
	TSGE_DrawArea* next = nullptr;
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

int TSGE_DrawAreaIndex::freeList(){

	TSGE_DrawArea* pointer = nullptr;
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

int TSGE_DrawAreaIndex::deleteNode(int ident){

	TSGE_DrawArea* pointer = nullptr;
	TSGE_DrawArea* next = nullptr;
	TSGE_DrawArea* previous = nullptr;
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

int TSGE_DrawAreaIndex::deleteList(){

	TSGE_DrawArea* pointer = nullptr;
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

int TSGE_DrawAreaIndex::purge(){

	TSGE_DrawArea* pointer = nullptr;
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

int TSGE_DrawAreaIndex::searchAvailable(int limit){

	TSGE_DrawArea* pointer = nullptr;
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

TSGE_DrawArea* TSGE_DrawAreaIndex::getFirst(){

	return this->first;

}


//---------------------------------------------------------------------------

TSGE_DrawArea* TSGE_DrawAreaIndex::getNode(int ident){

	TSGE_DrawArea* result = nullptr;
	TSGE_DrawArea* pointer = nullptr;
	
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

int TSGE_DrawAreaIndex::setValues(int ident, int x, int y, int w, int h, bool solid, int window_id){

	TSGE_DrawArea* pointer;
	int result = -1;
	
	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
	
		pointer->setX(x);
		pointer->setY(y);
		pointer->setW(w);
		pointer->setH(h);
		pointer->setSolid(solid);
		pointer->setWindow_id(window_id);
		result = pointer->getIdent();
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::printNodes(){

	TSGE_DrawArea* pointer;
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

int TSGE_DrawAreaIndex::getIdent(int ident){

	int result = -1;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

string TSGE_DrawAreaIndex::getTag(int ident){

	string result = "";
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getTag();

	}

	return result;

}


//---------------------------------------------------------------------------

bool TSGE_DrawAreaIndex::getAvailable(int ident){

	bool result = false;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = false;


	}else{
		result = pointer->getAvailable();

	}

	return result;

}


//---------------------------------------------------------------------------

TSGE_DrawArea* TSGE_DrawAreaIndex::getNext(int ident){

	TSGE_DrawArea* result = nullptr;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getNext();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::getX(int ident){

	int result = -1;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getX();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::getY(int ident){

	int result = -1;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getY();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::getW(int ident){

	int result = -1;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getW();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::getH(int ident){

	int result = -1;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getH();

	}

	return result;

}


//---------------------------------------------------------------------------

bool TSGE_DrawAreaIndex::getSolid(int ident){

	bool result = false;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = false;


	}else{
		result = pointer->getSolid();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::getWindow_id(int ident){

	int result = -1;
	TSGE_DrawArea* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getWindow_id();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::searchByIdent(int ident){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByNext(TSGE_DrawArea* next){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByX(int x){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByY(int y){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByW(int w){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchByH(int h){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

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

int TSGE_DrawAreaIndex::searchBySolid(bool solid){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (solid == pointer->getSolid()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::searchByWindow_id(int window_id){

	int result = -1;
	bool found = false;
	TSGE_DrawArea* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (window_id == pointer->getWindow_id()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setTag(int ident, string tag){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setAvailable(int ident, bool available){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setNext(int ident, TSGE_DrawArea* next){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setX(int ident, int x){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setX(x);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setY(int ident, int y){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setY(y);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setW(int ident, int w){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setW(w);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setH(int ident, int h){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setH(h);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setSolid(int ident, bool solid){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setSolid(solid);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_DrawAreaIndex::setWindow_id(int ident, int window_id){

	TSGE_DrawArea* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setWindow_id(window_id);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

