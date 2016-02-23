/****************************************************************************
* Created for: AGE v2
* Dev line: AGE v2
* Creation day: 08/02/2016
* Last change: 15/02/2016
****************************************************************************/


#include "test.h"
#include "test1.h"
#include "test2.h"


//---------------------------------------------------------------------------

Test::Test()
{
}


Test::~Test()
{
}


//---------------------------------------------------------------------------

bool Test::launchTest(int test){
	
	Test1* test1m = nullptr;
	Test2* test2m = nullptr;
	bool fail = false;

	switch(test){

		case 1:
			test1m = new Test1();
			test1m->start();
		break;

		case 2:
			test2m = new Test2();
			test2m->start();
		break;

		default:
			fail = true;
	
	}

	return fail;

}


//---------------------------------------------------------------------------
