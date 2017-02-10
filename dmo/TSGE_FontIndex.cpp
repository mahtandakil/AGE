/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_FontIndex.h"


//---------------------------------------------------------------------------

TSGE_FontIndex::TSGE_FontIndex()
{

	this->nodes = 0;
	this->next_ident = 0;
	this->first = nullptr;
	this->last = nullptr;

}

TSGE_FontIndex::~TSGE_FontIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::createNode(string tag){

	TSGE_Font* pointer = new TSGE_Font();
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

int TSGE_FontIndex::freeNode(int ident){

	TSGE_Font* pointer = nullptr;
	int result= -1;

	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
		
		pointer->setAvailable(true);
		result = pointer->getIdent();
		
	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::getPrevious(int ident){

	TSGE_Font* pointer = nullptr;
	TSGE_Font* next = nullptr;
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

int TSGE_FontIndex::freeList(){

	TSGE_Font* pointer = nullptr;
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

int TSGE_FontIndex::deleteNode(int ident){

	TSGE_Font* pointer = nullptr;
	TSGE_Font* next = nullptr;
	TSGE_Font* previous = nullptr;
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

int TSGE_FontIndex::deleteList(){

	TSGE_Font* pointer = nullptr;
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

int TSGE_FontIndex::purge(){

	TSGE_Font* pointer = nullptr;
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

int TSGE_FontIndex::searchAvailable(int limit){

	TSGE_Font* pointer = nullptr;
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

TSGE_Font* TSGE_FontIndex::getFirst(){

	return this->first;

}


//---------------------------------------------------------------------------

TSGE_Font* TSGE_FontIndex::getNode(int ident){

	TSGE_Font* result = nullptr;
	TSGE_Font* pointer = nullptr;
	
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

int TSGE_FontIndex::setValues(int ident, TTF_Font* font, string src, int size){

	TSGE_Font* pointer;
	int result = -1;
	
	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
	
		pointer->setFont(font);
		pointer->setSrc(src);
		pointer->setSize(size);
		result = pointer->getIdent();
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::printNodes(){

	TSGE_Font* pointer;
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

int TSGE_FontIndex::getIdent(int ident){

	int result = -1;
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

string TSGE_FontIndex::getTag(int ident){

	string result = "";
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getTag();

	}

	return result;

}


//---------------------------------------------------------------------------

bool TSGE_FontIndex::getAvailable(int ident){

	bool result = false;
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = false;


	}else{
		result = pointer->getAvailable();

	}

	return result;

}


//---------------------------------------------------------------------------

TSGE_Font* TSGE_FontIndex::getNext(int ident){

	TSGE_Font* result = nullptr;
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getNext();

	}

	return result;

}


//---------------------------------------------------------------------------

TTF_Font* TSGE_FontIndex::getFont(int ident){

	TTF_Font* result = nullptr;
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getFont();

	}

	return result;

}


//---------------------------------------------------------------------------

string TSGE_FontIndex::getSrc(int ident){

	string result = "";
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getSrc();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::getSize(int ident){

	int result = -1;
	TSGE_Font* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getSize();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::searchByIdent(int ident){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

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

int TSGE_FontIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

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

int TSGE_FontIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

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

int TSGE_FontIndex::searchByNext(TSGE_Font* next){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

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

int TSGE_FontIndex::searchByFont(TTF_Font* font){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (font == pointer->getFont()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::searchBySrc(string src){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (src == pointer->getSrc()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::searchBySize(int size){

	int result = -1;
	bool found = false;
	TSGE_Font* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (size == pointer->getSize()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::setTag(int ident, string tag){

	TSGE_Font* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::setAvailable(int ident, bool available){

	TSGE_Font* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::setNext(int ident, TSGE_Font* next){

	TSGE_Font* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::setFont(int ident, TTF_Font* font){

	TSGE_Font* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setFont(font);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::setSrc(int ident, string src){

	TSGE_Font* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setSrc(src);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_FontIndex::setSize(int ident, int size){

	TSGE_Font* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setSize(size);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

