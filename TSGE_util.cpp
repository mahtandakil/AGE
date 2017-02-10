/****************************************************************************
* Created for: AGE v1
* Dev line: TSGE v2
* Creation day: 24/07/2015
* Last change: 12/12/2016
****************************************************************************/


#include "TSGE.h"


//---------------------------------------------------------------------------

bool tsge_util_file_check(string src){

	struct stat buffer;

	return (stat(src.c_str(), &buffer) == 0);

}


//---------------------------------------------------------------------------

string tsge_util_itos(int number){

    stringstream stream;
    stream << number;

    return stream.str();

}


//---------------------------------------------------------------------------

string tsge_util_actos(TSGE_Color color){

    string result = "";

    result = result + "r:" + tsge_util_itos(color.r) + "-";
    result = result + "g:" + tsge_util_itos(color.g) + "-";
    result = result + "b:" + tsge_util_itos(color.b) + "-";
    result = result + "a:" + tsge_util_itos(color.a);

    return result;

}


//---------------------------------------------------------------------------

SDL_Color tsge_util_actsc(TSGE_Color color){

    SDL_Color conv;

    conv.r = color.r;
    conv.g = color.g;
    conv.b = color.b;
    conv.a = color.a;

    return conv;

}


//---------------------------------------------------------------------------



