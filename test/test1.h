/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 16/02/2016
****************************************************************************/


#include "../AGE/AGE.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>


using namespace std;


class Test1{

public:
	Test1();
	~Test1();

	void start();

private:
	AGE* age;
	bool change;
	bool keep;
	bool exit;
	int step;
	SDL_Event* events;

	void createWindow1();
	void createWindow2();
	void createWindow3();
	void createWindow4();
	void createWindow5();
	void createWindow6();
	void deleteAllWindows();
	void finalStep();
	void focusOnWindows2();
	void manageChanges();
	void manageEvents();
	void updateWindow5();

};

