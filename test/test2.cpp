/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 15/02/2016
* Last change: 15/02/2016
****************************************************************************/


#include "test2.h"


//---------------------------------------------------------------------------

Test2::Test2(){

	this->age = nullptr;
	this->keep = true;
	this->change = true;
	this->step = -1;
	this->dmom = nullptr;
	this->window_index = nullptr;

}


Test2::~Test2() {

}


//---------------------------------------------------------------------------

void Test2::modifyTags(){

	cout << endl << endl << "Modifying window 1" << endl;
	this->window_index->getNode(1)->setTag("NEW TAG FOR WINDOW 1");
	cout << "Modifying window 3" << endl;
	this->window_index->getNode(3)->setTag("NEW TAG FOR WINDOW 3");
	cout << "Modifying window 5" << endl;
	this->window_index->getNode(5)->setTag("NEW TAG FOR WINDOW 5");

	this->window_index->printNodes();

	cout << "Now the tags are different" << endl;
}


//---------------------------------------------------------------------------

void Test2::create(){

	this->dmom = this->age->age_dmom_get();
	cout << "The DMOM object have been provided by AGE :" << this->dmom << endl;
	cout << "Be careful, now we are working with the same instance than the engine. As you can see, no more index can be used here, only pointers. Easy work is over." << endl;
	this->window_index = this->dmom->dmom_windowIndex_get();
	cout << "But now we can work directly with the AGE objets. We have use the DMOM to get the windowIndex (" << this->window_index << ")" << endl;
	cout << "Click to get a list of the window registers" << endl;

}


//---------------------------------------------------------------------------

void Test2::createWindows(){

	cout << "This test shows how to use the DMOM class. AGE is designed to be able to do any action only with integer id numbers, no pointers or arrays are needed to work with it. But if you want to work directly with the AGE_(*) objects, you can call the DMOM functions to obtain the index object. This is higly not recommended but can be useful to debugging or get low level info." << endl;
	cout << endl;
	cout << "Now 6 windows are going to be created. Click on one window to continue..." << endl << endl;

	this->age->age_window_create("1", { 20, 40, 180, 180 });
	this->age->age_window_create("2", { 300, 40, 180, 180 });
	this->age->age_window_create("3", { 600, 40, 180, 180 });
	this->age->age_window_create("4", { 20, 300, 180, 180 });
	this->age->age_window_create("5", { 300, 300, 180, 180 });
	this->age->age_window_create("6", { 600, 300, 180, 180 });


}


//---------------------------------------------------------------------------

void Test2::fail(){

	cout << endl << endl;
	cout << "Remember, when you use the DMOM it's easy to break something. We are goint to change the tag for window 7 (it doesn't exist), what do you think that is going to happen? Exactly, nothing good." << endl;

	this->window_index->getNode(7)->setTag("NEW TAG FOR WINDOW 7 - This is going to be bad :)");

}


//---------------------------------------------------------------------------

void Test2::manageEvents(){

	AGE_Event_Status event_status;

	this->age->age_event_process();
	event_status = this->age->age_event_get_status();
	
	while(event_status.event != AGE_EVENT_NOEVENTS){
	
		if(event_status.event == AGE_EVENT_MOUSE_LEFT){
			this->change = true;

		}
	
		event_status = this->age->age_event_get_status();

	}

}


//---------------------------------------------------------------------------

void Test2::list(){

	this->window_index->printNodes();
	cout << "Take a look to the list data. In the next step we are going to delete windows 1, 3 and 5 and look again to the list." << endl;

}


//---------------------------------------------------------------------------

void Test2::list2(){

	this->age->age_window_remove(0); 
	this->age->age_window_remove(2); 
	this->age->age_window_remove(4); 

	this->window_index->printNodes();

	cout << "Three registers have disappeared. With windows it's easy to check it by yourself, but with more complex objects it can be very useful." << endl;
	cout << "If you have access to the objects, you can modify it totally. We are going to change the tag of the reamin windows" << endl;

}


//---------------------------------------------------------------------------

void Test2::start() {

	this->age = new AGE();

	cout << endl << "API version: " << AGE_VERSION << endl << endl;
	cout << "Test 2 - START" << endl;
	cout << endl;

	while(keep){
	
		this->manageEvents();
		this->testSteps();

		this->age->age_window_refresh();
		this->age->age_pause(AGE_30FPS);

	}

}


//---------------------------------------------------------------------------

void Test2::testSteps(){

	if(this->change){

		this->change = false;
		this->step++;

		switch(this->step) {

		case 0:
			this->createWindows();
		break;

		case 1:
			this->create();
		break;

		case 2:
			this->list();
		break;

		case 3:
			this->list2();
		break;

		case 4:
			this->modifyTags();
		break;

		case 5:
			this->fail();
		break;

		default:
			this->keep = false;

		}
	
	}

}


//---------------------------------------------------------------------------
