/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 15/02/2016
****************************************************************************/


#include "AGE_EventIndex.h"
#include "AGE_WindowIndex.h"


#ifndef DMOM_H
#define DMOM_H

//---------------------------------------------------------------------------

class DMOM{

public:
	DMOM();
	~DMOM();

	AGE_EventIndex* dmom_eventIndex_get();
	bool dmom_eventIndex_set(AGE_EventIndex* pointer);
	AGE_WindowIndex* dmom_windowIndex_get();
	bool dmom_windowIndex_set(AGE_WindowIndex* pointer);


private:

	AGE_EventIndex* event_index;
	AGE_WindowIndex* window_index;

};


//---------------------------------------------------------------------------

#endif // DMOM_H


