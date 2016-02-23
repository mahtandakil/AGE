/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 17/07/2015
* Last change: 23/02/2016
****************************************************************************/


#include "test/test.h"


#include <SDL2/SDL.h>


#include <iostream>
#include <string>
#include <cstring>


using namespace std;


//---------------------------------------------------------------------------

void usage() {

	cout << endl;
	cout << "TOOLS:" << endl;
	//cout << "   ADC: age ADC <image_file> <gan_file>" << endl;

	cout << endl;
	cout << "TESTS:" << endl;
	cout << "   Usage: age test <test_number>" << endl;
	cout << "   1: Windows creation and deletion" << endl;
	cout << "   2: DMOM usage" << endl;
	//cout << "   1: Six files are loaded and one is a missing file" << endl;
	//cout << "   2: Memory manage & dynamic load system form images" << endl;
	//cout << "   3: Fade screen & drawsquare function" << endl;
	//cout << "   4: Moving an image to check collisions" << endl;
	//cout << "   5: Area collision system example" << endl;
	//cout << "   6: Animation system example" << endl;
	//cout << "   7: Label system example" << endl;
	//cout << "   8: Collision point system example" << endl;
	cout << endl;

}


//---------------------------------------------------------------------------

int main(int argc, char* args[]) {

	bool help = false;
	int value = 0;

	if(argc < 3){
	
		usage();

	}else {

		if(strcmp(args[1], "test") == 0){

			Test* testm = new Test();
			help = testm->launchTest(atoi(args[2]));
			
		}

	}

	if(help){
		usage();

	}

	return value;

}


//---------------------------------------------------------------------------


