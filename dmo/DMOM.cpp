/****************************************************************************
* Created for: AGE v2
* Dev line: TSGE v2
* Creation day: 08/02/2016
* Last change: 09/02/2017
****************************************************************************/


#include "DMOM.h"


//---------------------------------------------------------------------------

DMOM::DMOM(){

    this->draw_area_index = nullptr;
	this->event_index = nullptr;
	this->image_index = nullptr;
	this->window_index = nullptr;

}

DMOM::~DMOM(){
}


//---------------------------------------------------------------------------

TSGE_DrawAreaIndex* DMOM::dmom_drawareaIndex_get()
{
	return this->draw_area_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_drawareaIndex_set(TSGE_DrawAreaIndex* pointer)
{
	this->draw_area_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

TSGE_EventIndex* DMOM::dmom_eventIndex_get()
{
	return this->event_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_eventIndex_set(TSGE_EventIndex* pointer)
{
	this->event_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

TSGE_FontIndex* DMOM::dmom_fontIndex_get()
{
	return this->font_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_fontIndex_set(TSGE_FontIndex* pointer)
{
	this->font_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

TSGE_ImageIndex * DMOM::dmom_imageIndex_get()
{
	return this->image_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_imageIndex_set(TSGE_ImageIndex * pointer)
{
	this->image_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

TSGE_WindowIndex * DMOM::dmom_windowIndex_get()
{
	return this->window_index;
}


//---------------------------------------------------------------------------

bool DMOM::dmom_windowIndex_set(TSGE_WindowIndex* pointer)
{
	this->window_index = pointer;
	return true;
}


//---------------------------------------------------------------------------

