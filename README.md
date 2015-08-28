//***************************************************************************
/*!
\mainpage The mainpage documentation

AGE is a wrapper for SDL and other libraries to make a simple game engine.

For build the project, you will the the following libraries:
    - SDL2
    - SDLI_image2
*/
/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 28/08/2015
*
*
* REFERENCES
* http://lazyfoo.net
* http://www.spriters-resource.com
* https://bintray.com/
* https://github.com/
* http://xerces.apache.org/xerces-c/apiDocs-3/index.html
* http://dbus.freedesktop.org/doc/api/html/index.html
*
*
* MILLESTONE
* 0.5.5 - Reverse animations
* 0.5.6 - Check animation system & area collision system
* 0.5.7 - Create an human walk simulation
* 0.6.0 - Create collision points system
* 0.6.1 - Create a single collision function for users (AGE_TYPE)
* 0.6.2 - Label object system from TTF
* 0.7.0 - Label object system from sprites
* 0.7.1 - Create SDLApiButton list system
* 0.7.2 - Develop regular button
* 0.8.0 - Create hold button
* 0.9.0 - Sounds
* 0.10.0 - Linux test & fixing
* 0.10.1 - [Consider to remove event list system for SDL events]
* 0.10.2 - Check unused variables
* 0.10.3 - Use proper int -> Uint changes
* 0.10.4 - Dynamic load of the missing image
* 0.10.5 - Texture resize function
* 0.10.6 - Proper use of the destructor instructions
* 0.10.7 - Recode the test examples to fit the new processes
* 0.10.8 - Rename references to API or SDL from prefixed values filesfit the new processes
* 1.0.0 - TQ1: HD
* 1.0.1 - Draw circles
* 1.0.2 - Circular area collision system
*
*
* DEV NOTES
*
*
*
****************************************************************************/


#include <iostream>


#include "test.h"


using namespace std;


int main(int argc, char* args[]){

    if (argc == 2){
        int opt = atoi(args[1]);
        new test(opt);

    }else{
        new test(6);

    }

    return 0;
}
