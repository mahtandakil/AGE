/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 22/02/2016
****************************************************************************/


#include "test1.h"


//---------------------------------------------------------------------------

Test1::Test1(){

	this->age = nullptr;
	this->change = true;
	this->exit = false;
	this->keep = true;
	this->step = 0;
	this->events = nullptr;

}


Test1::~Test1(){
}


//---------------------------------------------------------------------------

void Test1::start() {

	this->age = new AGE();

	cout << endl << "API version: " << AGE_VERSION << endl << endl;
	cout << "Test 1 - START" << endl;
	cout << endl;
	cout << "Press <ENTER> or <CLICK> in the screen to continue with the test." << endl;
	cout << "Press <ESC> to exit." << endl << endl;

	this->age->age_core_load_libs();
	
	while (this->keep) {

		this->manageChanges();
		this->manageEvents();

		this->age->age_window_refresh();
		this->age->age_pause(AGE_30FPS);

	}

}


//---------------------------------------------------------------------------

void Test1::createWindow1(){
	
	int window_id;

	AGE_Cartesian coords = {40, 40, 400, 400};

	cout << "A reagular window is going to be created" << endl;
	window_id = this->age->age_window_create("First window", coords);
	cout << "Window ID: " << window_id << endl << endl;

}


//---------------------------------------------------------------------------

void Test1::createWindow2(){

	int window_id;

	AGE_Cartesian coords = {70, 70, 300, 300 };

	cout << "Another window. Same options but different position & size" << endl;
	window_id = this->age->age_window_create("Second window", coords);
	cout << "Window ID: " << window_id << endl << endl;

}


//---------------------------------------------------------------------------

void Test1::createWindow3(){

	int window_id;

	AGE_Cartesian coords = { 100, 100, 400, 400 };

	cout << "This one is going to be borderless, so you need to use the propper flag (AGE_WINDOWFLAG_NOBORDER)." << endl;
	window_id = this->age->age_window_create("Third window", coords, AGE_WINDOWFLAG_NOBORDER);
	cout << "Window ID: " << window_id << endl << endl;

}


//---------------------------------------------------------------------------

void Test1::createWindow4(){

	int window_id;

	AGE_Cartesian coords = { 130, 130, 400, 400 };

	cout << "By default, the windows cannot be resized, but you can allow it using AGE_WINDOWFLAG_RESIZABLE. Don't worry, the click advance for the test have been disabled in this step." << endl;
	window_id = this->age->age_window_create("Fourth window", coords, AGE_WINDOWFLAG_RESIZABLE);
	cout << "Window ID: " << window_id << endl << endl;

}


//---------------------------------------------------------------------------

void Test1::createWindow5(){

	int window_id;

	AGE_Cartesian coords = { 200, 200, 400, 400 };

	cout << "The window number 5 have been created, but it's hidden." << endl;
	window_id = this->age->age_window_create("Fifth window", coords, AGE_WINDOWFLAG_NOVISIBLE);
	cout << "Window ID: " << window_id << endl << endl;


}


//---------------------------------------------------------------------------

void Test1::createWindow6(){

	int window_id;

	AGE_Cartesian coords = { AGE_WINDOWFLAG_XCENTERED, AGE_WINDOWFLAG_YCENTERED, 400, 145 };

	cout << "All the previous windows had a specific position values, but probably want some of your windows to be centered." << endl;
	window_id = this->age->age_window_create("Sixth window", coords);
	cout << "Window ID: " << window_id << endl << endl;

}


//---------------------------------------------------------------------------

void Test1::manageEvents(){

	AGE_Event_Status event_stat;

	this->age->age_event_process();
	event_stat = this->age->age_event_get_status();

	while(event_stat.event != AGE_EVENT_NOEVENTS){

		switch(event_stat.event){

			case AGE_EVENT_WINDOW_CLOSE:
				this->exit = true;
			break;

			case AGE_EVENT_KEY_RETURN:
				this->change = true;
			break;

			case AGE_EVENT_MOUSE_LEFT:
				if(this->step != 4){
					this->change = true;
				}
			break;

		}

		event_stat = this->age->age_event_get_status();

	}

}


//---------------------------------------------------------------------------

void Test1::updateWindow5(){

	this->age->age_window_set_visible(4, true);

}


//---------------------------------------------------------------------------

void Test1::deleteAllWindows(){

	AGE_Cartesian coords = { 0, 0, 0, 0 };
	int window_id = -1;

	cout << "Finally we are going to create a full screen window. But first we are going to delete all the previous windows. Please, wai while the windows are deleted." << endl;
	
	cout << "Deleting window 6; function returns: " << this->age->age_window_remove(5) << endl;
	this->age->age_pause(300);

	cout << "Deleting window 5; function returns: " << this->age->age_window_remove(4) << endl;
	this->age->age_pause(300);

	cout << "Deleting window 4; function returns: " << this->age->age_window_remove(3) << endl;
	this->age->age_pause(300);

	cout << "Deleting window 3; function returns: " << this->age->age_window_remove(2) << endl;
	this->age->age_pause(300);

	cout << "Deleting window 2; function returns: " << this->age->age_window_remove(1) << endl;
	this->age->age_pause(300);

	cout << "Deleting window 1; function returns: " << this->age->age_window_remove(0) << endl;
	cout << "Here comes the full screen window" << endl;
	this->age->age_pause(1500);

	window_id = this->age->age_window_create("Fullscreen window", coords, AGE_WINDOWFLAG_FULLDESKTOP);
	cout << "Window ID: " << window_id << endl << endl;

}


//---------------------------------------------------------------------------

void Test1::finalStep(){

	cout << "With this step the test is over." << endl;

}


//---------------------------------------------------------------------------

void Test1::focusOnWindows2(){

	cout << "Do you remember the second window? We know its id number (1) and we are going to use it set it as the active window." << endl;
	this->age->age_window_set_focus(1);

}


//---------------------------------------------------------------------------

void Test1::manageChanges(){

	if(this->exit){
		this->keep = false;
	}

	if(this->change){

		this->step++;
		this->change = false;

		switch(this->step){

			case 1:
				this->createWindow1();
			break;

			case 2:
				this->createWindow2();
			break;

			case 3:
				this->createWindow3();
			break;

			case 4:
				this->createWindow4();
			break;

			case 5:
				this->createWindow5();
			break;

			case 6:
				this->updateWindow5();
			break;

			case 7:
				this->focusOnWindows2();
			break;

			case 8:
				this->createWindow6();
			break;

			case 9:
				this->deleteAllWindows();
			break;
	
			case 10:
				this->finalStep();
			break; 
			
			default:
				this->exit = true;
			break;
		
		}

	}

}

//---------------------------------------------------------------------------
