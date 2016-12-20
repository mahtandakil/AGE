/****************************************************************************
* Created for: AGE v1
* Dev line: AGE v2
* Creation day: 24/07/2015
* Last change: 12/12/2016
****************************************************************************/


#include <iostream>
#include <sstream>
#include <sys/stat.h>


using namespace std;


#ifndef AGE_UTIL_H_INCLUDED
#define AGE_UTIL_H_INCLUDED


string age_util_actos(AGE_Color color);
SDL_Color age_util_actsc(AGE_Color color);
bool age_util_file_check(string src);
string age_util_itos(int number);


#endif // AGE_H_INCLUDED
