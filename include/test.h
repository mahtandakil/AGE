/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 17/07/2015
* Last change: 22/08/2015
****************************************************************************/


#include "AGE.h"


#include <iostream>


using namespace std;


#ifndef TEST_H
#define TEST_H


class test
{
    public:
        test(int id); /**< The main function for test requests. The integer defines what test will be launched.*/
        virtual ~test();

    protected:
    private:

        AGE* api;
        void test1();
        void test2();
        void test3();
        void test4();
        void test5();
        void test6();
        void test7();
        void test8();
        void test9();

};

#endif // TEST_H
