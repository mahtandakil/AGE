/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation date: 08/02/2016
* Last change: 08/05/16
* Autogen: 1.1.2c
****************************************************************************/


#include "AGE_LabelIndex.h"


//---------------------------------------------------------------------------

AGE_LabelIndex::AGE_LabelIndex()
{

	this->nodes = 0;
	this->next_ident = 0;
	this->first = nullptr;
	this->last = nullptr;

}

AGE_LabelIndex::~AGE_LabelIndex()
{

	this->freeList();

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::createNode(string tag){

	AGE_Label* pointer = new AGE_Label();
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

int AGE_LabelIndex::freeNode(int ident){

	AGE_Label* pointer = nullptr;
	int result= -1;

	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
		
		pointer->setAvailable(true);
		result = pointer->getIdent();
		
	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::getPrevious(int ident){

	AGE_Label* pointer = nullptr;
	AGE_Label* next = nullptr;
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

int AGE_LabelIndex::freeList(){

	AGE_Label* pointer = nullptr;
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

int AGE_LabelIndex::deleteNode(int ident){

	AGE_Label* pointer = nullptr;
	AGE_Label* next = nullptr;
	AGE_Label* previous = nullptr;
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

int AGE_LabelIndex::deleteList(){

	AGE_Label* pointer = nullptr;
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

int AGE_LabelIndex::purge(){

	AGE_Label* pointer = nullptr;
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

int AGE_LabelIndex::searchAvailable(int limit){

	AGE_Label* pointer = nullptr;
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

AGE_Label* AGE_LabelIndex::getFirst(){

	return this->first;

}


//---------------------------------------------------------------------------

AGE_Label* AGE_LabelIndex::getNode(int ident){

	AGE_Label* result = nullptr;
	AGE_Label* pointer = nullptr;
	
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

int AGE_LabelIndex::setValues(int ident, string content, SDL_Texture* texture, int font, int font_color_r, int font_color_g, int font_color_b){

	AGE_Label* pointer;
	int result = -1;
	
	pointer = this->getNode(ident);
	
	if(pointer != nullptr){
	
		pointer->setContent(content);
		pointer->setTexture(texture);
		pointer->setFont(font);
		pointer->setFont_color_r(font_color_r);
		pointer->setFont_color_g(font_color_g);
		pointer->setFont_color_b(font_color_b);
		result = pointer->getIdent();
	
	}
	
	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::printNodes(){

	AGE_Label* pointer;
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

int AGE_LabelIndex::getIdent(int ident){

	int result = -1;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGE_LabelIndex::getTag(int ident){

	string result = "";
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getTag();

	}

	return result;

}


//---------------------------------------------------------------------------

bool AGE_LabelIndex::getAvailable(int ident){

	bool result = false;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = false;


	}else{
		result = pointer->getAvailable();

	}

	return result;

}


//---------------------------------------------------------------------------

AGE_Label* AGE_LabelIndex::getNext(int ident){

	AGE_Label* result = nullptr;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getNext();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGE_LabelIndex::getContent(int ident){

	string result = "";
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = "";


	}else{
		result = pointer->getContent();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Texture* AGE_LabelIndex::getTexture(int ident){

	SDL_Texture* result = nullptr;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = nullptr;


	}else{
		result = pointer->getTexture();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::getFont(int ident){

	int result = -1;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getFont();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::getFont_color_r(int ident){

	int result = -1;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getFont_color_r();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::getFont_color_g(int ident){

	int result = -1;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getFont_color_g();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::getFont_color_b(int ident){

	int result = -1;
	AGE_Label* pointer;

	pointer = this->getNode(ident);

	if ((pointer == nullptr) || (ident < 0)){
		result = -1;


	}else{
		result = pointer->getFont_color_b();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::searchByIdent(int ident){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

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

int AGE_LabelIndex::searchByTag(string tag){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

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

int AGE_LabelIndex::searchByAvailable(bool available){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

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

int AGE_LabelIndex::searchByNext(AGE_Label* next){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

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

int AGE_LabelIndex::searchByContent(string content){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (content == pointer->getContent()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::searchByTexture(SDL_Texture* texture){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

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

int AGE_LabelIndex::searchByFont(int font){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

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

int AGE_LabelIndex::searchByFont_color_r(int font_color_r){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (font_color_r == pointer->getFont_color_r()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::searchByFont_color_g(int font_color_g){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (font_color_g == pointer->getFont_color_g()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::searchByFont_color_b(int font_color_b){

	int result = -1;
	bool found = false;
	AGE_Label* pointer;

	if (this->nodes == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (! ((pointer == nullptr) || (found))){

			if (font_color_b == pointer->getFont_color_b()){

				result = pointer->getIdent();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setTag(int ident, string tag){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTag(tag);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setAvailable(int ident, bool available){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setAvailable(available);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setNext(int ident, AGE_Label* next){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setNext(next);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setContent(int ident, string content){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setContent(content);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setTexture(int ident, SDL_Texture* texture){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setTexture(texture);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setFont(int ident, int font){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setFont(font);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setFont_color_r(int ident, int font_color_r){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setFont_color_r(font_color_r);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setFont_color_g(int ident, int font_color_g){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setFont_color_g(font_color_g);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGE_LabelIndex::setFont_color_b(int ident, int font_color_b){

	AGE_Label* pointer;
	int result = -1;

	pointer = this->getNode(ident);

	if (pointer != nullptr){

		pointer->setFont_color_b(font_color_b);
		result = pointer->getIdent();

	}

	return result;

}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

