/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 27/09/2015
* Autogen: CListGen 1.0.8
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

	this->freeList();

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

AGEAnimationFrameIndex* AGEAnimationIndex::getFrames(int id){

	AGEAnimationFrameIndex* result = nullptr;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;
;

	}else{
		result = pointer->getFrames();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGEAnimationIndex::getFile(int id){

	string result = "";
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getFile();

	}

	return result;

}


//---------------------------------------------------------------------------

string AGEAnimationIndex::getDescription(int id){

	string result = "";
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = "";
;

	}else{
		result = pointer->getDescription();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::getBgcolor1(int id){

	int result = 0;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBgcolor1();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::getBgcolor2(int id){

	int result = 0;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBgcolor2();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::getBgcolor3(int id){

	int result = 0;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getBgcolor3();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::getImages(int id){

	int result = 0;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = 0;
;

	}else{
		result = pointer->getImages();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::getInit(int id){

	int result = 0;
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

int AGEAnimationIndex::searchByFrames(AGEAnimationFrameIndex* frames){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (frames == pointer->getFrames()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByFile(string file){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (file == pointer->getFile()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByDescription(string description){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (description == pointer->getDescription()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByBgcolor1(int bgcolor1){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bgcolor1 == pointer->getBgcolor1()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByBgcolor2(int bgcolor2){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bgcolor2 == pointer->getBgcolor2()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByBgcolor3(int bgcolor3){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (bgcolor3 == pointer->getBgcolor3()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByImages(int images){

	int result = -1;
	bool found = false;
	AGEAnimationElement* pointer;

	if (this->counter == 0){
		result = -1;

	}else{

		pointer = this->first;

		while (not ((pointer == nullptr) or (found))){

			if (images == pointer->getImages()){

				result = pointer->getId();
				found = true;

			}

			pointer = pointer->getNext();

		}

	}

	return result;

}



//---------------------------------------------------------------------------

int AGEAnimationIndex::searchByInit(int init){

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

int AGEAnimationIndex::setElementData(int id, string tag, AGEAnimationFrameIndex* frames, string file, string description, int bgcolor1, int bgcolor2, int bgcolor3, int images, int init){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTag(tag);
		pointer->setFrames(frames);
		pointer->setFile(file);
		pointer->setDescription(description);
		pointer->setBgcolor1(bgcolor1);
		pointer->setBgcolor2(bgcolor2);
		pointer->setBgcolor3(bgcolor3);
		pointer->setImages(images);
		pointer->setInit(init);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setElementData(int id, AGEAnimationFrameIndex* frames, string file, string description, int bgcolor1, int bgcolor2, int bgcolor3, int images, int init){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFrames(frames);
		pointer->setFile(file);
		pointer->setDescription(description);
		pointer->setBgcolor1(bgcolor1);
		pointer->setBgcolor2(bgcolor2);
		pointer->setBgcolor3(bgcolor3);
		pointer->setImages(images);
		pointer->setInit(init);
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

int AGEAnimationIndex::setFrames(int id, AGEAnimationFrameIndex* frames){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFrames(frames);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setFile(int id, string file){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setFile(file);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setDescription(int id, string description){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setDescription(description);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setBgcolor1(int id, int bgcolor1){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBgcolor1(bgcolor1);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setBgcolor2(int id, int bgcolor2){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBgcolor2(bgcolor2);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setBgcolor3(int id, int bgcolor3){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setBgcolor3(bgcolor3);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setImages(int id, int images){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setImages(images);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setInit(int id, int init){

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

AGEAnimationElement* AGEAnimationIndex::getElementById(int id){

	AGEAnimationElement* result = nullptr;
	AGEAnimationElement* pointer = nullptr;

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

int AGEAnimationIndex::setTexture(int id, SDL_Texture* texture){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTexture(texture);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setSurface(int id, SDL_Surface* surface){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setSurface(surface);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setTexture_h(int id, int texture_h){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTexture_h(texture_h);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

int AGEAnimationIndex::setTexture_w(int id, int texture_w){

	AGEAnimationElement* pointer;
	int result = -1;

	pointer = this->getElementById(id);

	if (pointer != nullptr){

		pointer->setTexture_w(texture_w);
		result = pointer->getId();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Texture*  AGEAnimationIndex::getTexture(int id){

	SDL_Texture* result = nullptr;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;


	}else{
		result = pointer->getTexture();

	}

	return result;

}


//---------------------------------------------------------------------------

SDL_Surface*  AGEAnimationIndex::getSurface(int id){

	SDL_Surface* result = nullptr;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = nullptr;


	}else{
		result = pointer->getSurface();

	}

	return result;

}


//---------------------------------------------------------------------------

int  AGEAnimationIndex::getTexture_w(int id){

	int result = -1;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = -1;


	}else{
		result = pointer->getTexture_w();

	}

	return result;

}


//---------------------------------------------------------------------------

int  AGEAnimationIndex::getTexture_h(int id){

	int result = -1;
	AGEAnimationElement* pointer;

	pointer = this->getElementById(id);

	if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
		result = -1;


	}else{
		result = pointer->getTexture_h();

	}

	return result;

}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


