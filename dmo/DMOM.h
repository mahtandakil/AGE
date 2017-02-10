/****************************************************************************
* Created for: AGE v2
* Dev line: TSGE v2
* Creation day: 08/02/2016
* Last change: 09/02/2017
****************************************************************************/


#include "TSGE_DrawAreaIndex.h"
#include "TSGE_EventIndex.h"
#include "TSGE_FontIndex.h"
#include "TSGE_ImageIndex.h"
#include "TSGE_WindowIndex.h"


#ifndef DMOM_H
#define DMOM_H


//---------------------------------------------------------------------------

class DMOM{

public:
	DMOM();
	~DMOM();

	TSGE_DrawAreaIndex* dmom_drawareaIndex_get();
	bool dmom_drawareaIndex_set(TSGE_DrawAreaIndex* pointer);
	TSGE_FontIndex* dmom_fontIndex_get();
	bool dmom_fontIndex_set(TSGE_FontIndex* pointer);
	TSGE_EventIndex* dmom_eventIndex_get();
	bool dmom_eventIndex_set(TSGE_EventIndex* pointer);
	TSGE_ImageIndex* dmom_imageIndex_get();
	bool dmom_imageIndex_set(TSGE_ImageIndex* pointer);
	TSGE_WindowIndex* dmom_windowIndex_get();
	bool dmom_windowIndex_set(TSGE_WindowIndex* pointer);


private:

	TSGE_DrawAreaIndex* draw_area_index;
	TSGE_EventIndex* event_index;
	TSGE_FontIndex* font_index;
	TSGE_ImageIndex* image_index;
	TSGE_WindowIndex* window_index;

};


//---------------------------------------------------------------------------

#endif // DMOM_H


