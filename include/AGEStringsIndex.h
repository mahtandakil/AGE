/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 25/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include "AGEStringsElement.h"


#include <iostream>


using namespace std;


#ifndef AGESTRINGSINDEX_H
#define AGESTRINGSINDEX_H


class AGEStringsIndex
{
	public:
		AGEStringsIndex();
		virtual ~AGEStringsIndex();

		int createRegister(string tag);
		int freeList();
		int getId(int id);
		string getTag(int id);
		bool getAvailable(int id);
		AGEStringsElement* getNext(int id);
		string getEntry1(int id);
		string getEntry2(int id);
		string getEntry2By1(string entry1);
		string getEntry3(int id);
		int searchById(int id);
		int searchByTag(string tag);
		int searchByAvailable(bool available);
		int searchByNext(AGEStringsElement* next);
		int searchByEntry1(string entry1);
		int searchByEntry2(string entry2);
		int searchByEntry3(string entry3);
		int setElementData(int id, string tag, string entry1, string entry2, string entry3);
		int setElementData(int id, string entry1, string entry2, string entry3);
		int setTag(int id, string tag);
		int setAvailable(int id, bool available);
		int setNext(int id, AGEStringsElement* next);
		int setEntry1(int id, string entry1);
		int setEntry2(int id, string entry2);
		int setEntry3(int id, string entry3);


	protected:



	private:
		int counter;
		AGEStringsElement* first;
		AGEStringsElement* last;

		AGEStringsElement* getElementById(int id);
		int searchAvailable();

};


#endif // AGESTRINGSINDEX_H


