/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 24/07/2015
* Last change: 14/04/2016
****************************************************************************/


#include "AGE.h"


//---------------------------------------------------------------------------

bool age_util_file_check(string src){

	struct stat buffer;

	return (stat(src.c_str(), &buffer) == 0);

}


//---------------------------------------------------------------------------

string age_util_itos(int number){

    stringstream stream;
    stream << number;

    return stream.str();

}


//---------------------------------------------------------------------------

