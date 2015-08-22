/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v1
* Creation day: 02/08/2015
* Last change: 21/08/2015
****************************************************************************/


#include "AGETextureListIndex.h"


//---------------------------------------------------------------------------

AGETextureListIndex::AGETextureListIndex()
{

    this->counter = 0;
    this->first = nullptr;
    this->last = nullptr;

}

AGETextureListIndex::~AGETextureListIndex()
{
    //dtor
}


//---------------------------------------------------------------------------

int AGETextureListIndex::searchBySrc(string src){

    int result = -1;
    AGETextureListElement* pointer;

    if (this->counter == 0){
        result = -1;

    }else{

        pointer = this->first;

        while (not (pointer == nullptr)){

            if (src == pointer->getSrc()){
                result = pointer->getId();

            }

            pointer = pointer->getNext();

        }

    }

    return result;

}

//---------------------------------------------------------------------------

int AGETextureListIndex::searchByAvailable(bool available){

    int result = -1;
    bool found = false;
    AGETextureListElement* pointer;

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

int AGETextureListIndex::getCounter(){

    return this->counter;

}

//---------------------------------------------------------------------------

string AGETextureListIndex::getSrc(int id){

    string result = "";
    AGETextureListElement* pointer;

    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
        result = "";

    }else{
        result = pointer->getSrc();

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::createRegister(string src){

    AGETextureListElement* pointer = new AGETextureListElement();
    pointer->setSrc(src);

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

AGETextureListElement* AGETextureListIndex::getElementById(int id){

    AGETextureListElement* result;
    AGETextureListElement* pointer;

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

int AGETextureListIndex::setTexture(int id, SDL_Texture* texture){

    AGETextureListElement* pointer;
    int result = -1;

    pointer = getElementById(id);

    if (pointer != nullptr){

        pointer->setTexture(texture);
        result = pointer->getId();

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::setAvailable(int id, bool available){

    AGETextureListElement* pointer;
    int result = -1;

    pointer = getElementById(id);

    if (pointer != nullptr){

        pointer->setAvailable(available);
        result = pointer->getId();

    }

    return result;

}

//---------------------------------------------------------------------------

int AGETextureListIndex::setPosition(int id, int x, int y){

    AGETextureListElement* pointer;
    int result = -1;

    pointer = this->getElementById(id);

    if (pointer != nullptr){

        pointer->setPosition(x, y);
        result = pointer->getId();

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::setSrc(int id, string src){

    AGETextureListElement* pointer;
    int result = -1;

    pointer = this->getElementById(id);

    if (pointer != nullptr){

        pointer->setSrc(src);
        result = pointer->getId();

    }

    return result;

}


//---------------------------------------------------------------------------

SDL_Rect AGETextureListIndex::getCollisionRect(int id){

    SDL_Rect result;
    AGETextureListElement* pointer;

    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){

        result.h = -1;
        result.w = -1;
        result.x = -1;
        result.y = -1;

    }else{

        result.h = pointer->getTextureH();
        result.w = pointer->getTextureW();
        result.x = pointer->getPositionX();
        result.y = pointer->getPositionY();

    }

    return result;

}


//---------------------------------------------------------------------------

SDL_Texture* AGETextureListIndex::getTexture(int id){

    SDL_Texture* result = nullptr;
    AGETextureListElement* pointer;

    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
        result = nullptr;

    }else{
        result = pointer->getTexture();

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::getTextureH(int id){

    int result = -1;
    AGETextureListElement* pointer;

    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
        result = -1;

    }else{
        result = pointer->getTextureH();

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::getTextureW(int id){

    int result = -1;
    AGETextureListElement* pointer;

    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
        result = -1;

    }else{
        result = pointer->getTextureW();

    }

    return result;

}


//---------------------------------------------------------------------------

bool AGETextureListIndex::getAvailable(int id){

    bool result = false;
    AGETextureListElement* pointer;

    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
        result = false;

    }else{
        result = pointer->getAvailable();

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::searchAvailable(){

    int result = -1;
    int counter = 0;
    bool found = false;
    AGETextureListElement* pointer;

    while((counter < this->counter) && (found == false)){

        pointer = this->getElementById
        (counter);
        if (pointer->getAvailable() == true){

            result = pointer->getId();
            found = true;

        }

        counter++;

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::linkCollisionArea(int id, SDL_Rect area, string tag){

    int result = -1;
    AGETextureListElement* pointer;
    AGECollisionAreaIndex* area_index;


    pointer = this->getElementById(id);

    if ((pointer == nullptr) or (id < 0) or (id >= this->counter)){
        result = -1;

    }else{

        area_index = pointer->getAreaIndex();
        if (area_index == nullptr){
            area_index = pointer->initAreaIndex();

        }

        result = area_index->createRegister(tag);
        area_index->setArea(result, area);

    }

    return result;

}


//---------------------------------------------------------------------------

int AGETextureListIndex::linkCollisionArea(int id, SDL_Rect area, string tag, int color1, int color2, int color3){

    int result = -1;
    AGECollisionAreaIndex* area_index;

    result = this->linkCollisionArea(id, area, tag);
    if (result > -1){

        area_index = this->getElementById(id)->getAreaIndex();
        area_index->setColor1(result, color1);
        area_index->setColor2(result, color2);
        area_index->setColor3(result, color3);

    }

    return result;

}


//---------------------------------------------------------------------------
