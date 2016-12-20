/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 24/07/2015
* Last change: 12/12/2016
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

string age_util_actos(AGE_Color color){

    string result = "";

    result = result + "r:" + age_util_itos(color.r) + "-";
    result = result + "g:" + age_util_itos(color.g) + "-";
    result = result + "b:" + age_util_itos(color.b) + "-";
    result = result + "a:" + age_util_itos(color.a);

    return result;

}


//---------------------------------------------------------------------------

SDL_Color age_util_actsc(AGE_Color color){

    SDL_Color conv;

    conv.r = color.r;
    conv.g = color.g;
    conv.b = color.b;
    conv.a = color.a;

    return conv;

}


//---------------------------------------------------------------------------



