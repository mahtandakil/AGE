/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 14/02/2016
****************************************************************************/


#include "DMOM.h"


//---------------------------------------------------------------------------

DMOM::DMOM(){

	this->window_index = nullptr;
	this->event_index = nullptr;

}

DMOM::~DMOM(){
}


//---------------------------------------------------------------------------

AGE_EventIndex* DMOM::dmom_eventIndex_get()
{
	return this->event_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_eventIndex_set(AGE_EventIndex* pointer)
{
	this->event_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

AGE_WindowIndex * DMOM::dmom_windowIndex_get()
{
	return this->window_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_windowIndex_set(AGE_WindowIndex* pointer)
{
	this->window_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

