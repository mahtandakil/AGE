/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 15/02/2016
* Last change: 16/02/2016
****************************************************************************/

#include "../AGE/AGE.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


class Test2 {

public:
	Test2();
	~Test2();

	void create();
	void createWindows();
	void fail();
	void list();
	void list2();
	void manageEvents();
	void modifyTags();
	void start();
	void testSteps();

private:
	AGE* age;
	DMOM* dmom;
	AGE_WindowIndex* window_index;
	bool keep;
	bool change;
	int step;

};

