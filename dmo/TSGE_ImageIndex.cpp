/****************************************************************************
* Created for: TSGE v2
* Dev line: TSGE v2
* Creation date: 08/02/2016
* Last change: 09/02/17
* Autogen: 1.1.2c
****************************************************************************/


#include "TSGE_ImageIndex.h"


//---------------------------------------------------------------------------

TSGE_ImageIndex::TSGE_ImageIndex()
{

	this->nodes = 0;
	this->next_ident = 0;
	this->first = nullptr;
	this->last = nullptr;

}

TSGE_ImageIndex::~TSGE_ImageIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::createNode(string tag){

	TSGE_Image* pointer = new TSGE_Image();
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

int TSGE_ImageIndex::freeNode(int ident){

	TSGE_Image* pointer = nullptr;
	int result= -1;

	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
		
		pointer->setAvailable(true);
		result = pointer->getIdent();
		
	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::getPrevious(int ident){

	TSGE_Image* pointer = nullptr;
	TSGE_Image* next = nullptr;
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

int TSGE_ImageIndex::freeList(){

	TSGE_Image* pointer = nullptr;
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

int TSGE_ImageIndex::deleteNode(int ident){

	TSGE_Image* pointer = nullptr;
	TSGE_Image* next = nullptr;
	TSGE_Image* previous = nullptr;
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

int TSGE_ImageIndex::deleteList(){

	TSGE_Image* pointer = nullptr;
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

int TSGE_ImageIndex::purge(){

	TSGE_Image* pointer = nullptr;
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

int TSGE_ImageIndex::searchAvailable(int limit){

	TSGE_Image* pointer = nullptr;
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

TSGE_Image* TSGE_ImageIndex::getFirst(){

	return this->first;

}


//---------------------------------------------------------------------------

TSGE_Image* TSGE_ImageIndex::getNode(int ident){

	TSGE_Image* result = nullptr;
	TSGE_Image* pointer = nullptr;
	
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

int TSGE_ImageIndex::setValues(int ident, string src, SDL_Surface* surface, SDL_Texture* texture, int texture_h, int texture_w){

	TSGE_Image* pointer;
	int result = -1;
	
	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
	
		pointer->setSrc(src);
		pointer->setSurface(surface);
		pointer->setTexture(texture);
		pointer->setTexture_h(texture_h);
		pointer->setTexture_w(texture_w);
		result = pointer->getIdent();
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::printNodes(){

	TSGE_Image* pointer;
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

int TSGE_ImageIndex::getIdent(int ident){

	int result = -1;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

string TSGE_ImageIndex::getTag(int ident){

	string result = "";
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getTag();

	}

	return result;

}


//---------------------------------------------------------------------------

bool TSGE_ImageIndex::getAvailable(int ident){

	bool result = false;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = false;


	}else{
		result = pointer->getAvailable();

	}

	return result;

}


//---------------------------------------------------------------------------

TSGE_Image* TSGE_ImageIndex::getNext(int ident){

	TSGE_Image* result = nullptr;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getNext();

	}

	return result;

}


//---------------------------------------------------------------------------

string TSGE_ImageIndex::getSrc(int ident){

	string result = "";
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getSrc();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Surface* TSGE_ImageIndex::getSurface(int ident){

	SDL_Surface* result = nullptr;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getSurface();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Texture* TSGE_ImageIndex::getTexture(int ident){

	SDL_Texture* result = nullptr;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getTexture();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::getTexture_h(int ident){

	int result = -1;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getTexture_h();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::getTexture_w(int ident){

	int result = -1;
	TSGE_Image* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getTexture_w();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::searchByIdent(int ident){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

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

int TSGE_ImageIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

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

int TSGE_ImageIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

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

int TSGE_ImageIndex::searchByNext(TSGE_Image* next){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

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

int TSGE_ImageIndex::searchBySrc(string src){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

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

int TSGE_ImageIndex::searchBySurface(SDL_Surface* surface){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (surface == pointer->getSurface()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::searchByTexture(SDL_Texture* texture){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (texture == pointer->getTexture()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::searchByTexture_h(int texture_h){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (texture_h == pointer->getTexture_h()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::searchByTexture_w(int texture_w){

	int result = -1;
	bool found = false;
	TSGE_Image* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (texture_w == pointer->getTexture_w()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setTag(int ident, string tag){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setAvailable(int ident, bool available){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setNext(int ident, TSGE_Image* next){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setSrc(int ident, string src){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setSrc(src);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setSurface(int ident, SDL_Surface* surface){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setSurface(surface);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setTexture(int ident, SDL_Texture* texture){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTexture(texture);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setTexture_h(int ident, int texture_h){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTexture_h(texture_h);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int TSGE_ImageIndex::setTexture_w(int ident, int texture_w){

	TSGE_Image* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTexture_w(texture_w);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

