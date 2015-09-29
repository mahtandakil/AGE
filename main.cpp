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
* Last change: 29/09/2015
*
*
* REFERENCES
* http://lazyfoo.net
* http://www.sdltutorials.com/
* http://www.spriters-resource.com
* http://spritedatabase.net
* http://downloads.khinsider.com/
* https://bintray.com/
* https://github.com/
* http://xerces.apache.org/xerces-c/apiDocs-3/index.html
* http://dbus.freedesktop.org/doc/api/html/index.html
*
*
* MILLESTONE
* 0.5.7 - ADC - Animation definition creator
* 0.5.8 - ACC - Animation collision creator
* 0.5.9 - LSC - Label from sprites creator
* 0.5.10 - Allow size modification for labels
* 0.5.11 - Label object system from sprites
* 0.5.12 - Check animation system & area collision system
* 0.5.13 - Create collision points system
* 0.6.0 - Create an human walk simulation
* 0.6.1 - Create a single collision function for users (AGE_TYPE)
* 0.7.0 - Create SDLApiButton list system
* 0.7.1 - Develop regular button
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
* 0.10.10 - Check deploy functions to verify the previous objects are unloaded properly
* 0.10.11 - Images & other objs must use tag value as main identifier (allows one file to be loaded several times)
* 1.0.0 - TQ1: HD
* 1.0.1 - Sound loading
* 1.1.0 - Sound play
* 1.2.0 - Create AGE_Color to manage color options instead, color1,2,3
* 1.2.1 - Draw circles
* 1.3.0 - Circular area collision system
*
*
* DEV NOTES
* Clean code and send to github
* test 6 -> AGE::moveAnimation flip modes
*
*
*
****************************************************************************/


#include <iostream>


#include "test.h"
#include "tools/ADC/ADC.h"


using namespace std;


//---------------------------------------------------------------------------

void launchADC(string image_src, string gan_src){

    ADC* tool;

    tool = new ADC();
    tool->init(image_src, gan_src);
    tool->start();


}

//---------------------------------------------------------------------------


int main(int argc, char* args[]){

    string tool;
    int opt;
    string opts1;
    string opts2;

    if (argc == 3){
        tool = args[1];
        opt = atoi(args[2]);

        if (tool == "test"){
            new test(opt);

        }else{
            new test(-1);

        }

    }else if (argc == 4){

        tool = args[1];

        if(tool == "ADC"){

            opts1 = args[2];
            opts2 = args[3];

            launchADC(opts1, opts2);

        }

    }else{
        new test(0);
        //new test(6);
        //launchADC("test/an02.png", "test/test_adc.gan");
    }



    return 0;
}

//---------------------------------------------------------------------------

