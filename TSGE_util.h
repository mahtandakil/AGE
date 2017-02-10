/****************************************************************************
* Created for: AGE v1
* Dev line: TSGE v2
* Creation day: 24/07/2015
* Last change: 12/12/2016
****************************************************************************/


#include <iostream>
#include <sstream>
#include <sys/stat.h>


using namespace std;


#ifndef TSGE_UTIL_H_INCLUDED
#define TSGE_UTIL_H_INCLUDED


string tsge_util_actos(TSGE_Color color);
SDL_Color tsge_util_actsc(TSGE_Color color);
bool tsge_util_file_check(string src);
string tsge_util_itos(int number);


#endif // TSGE_H_INCLUDED
