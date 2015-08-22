/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 22/08/2015
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
* 0.4.3 - Better implementation of test examples
* 0.5.0 - Check the hard delete functions for all the list systems & call it from terminate
* 0.5.1 - Deploy animation list system
* 0.5.2 - Load animation files
* 0.5.3 - Get individual animation textures
* 0.5.4 - Check animation system & area collision system
* 0.6.0 - Create an human walk simulation
* 0.6.1 - Label system from TTF
* 0.7.0 - Label system from sprites
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
        new test(5);

    }

    return 0;
}
