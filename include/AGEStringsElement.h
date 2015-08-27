/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 25/08/2015
* Last change: 25/08/2015
* Autogen: CListGen 1.0.7
****************************************************************************/


#include <iostream>


using namespace std;


#ifndef AGESTRINGSELEMENT_H
#define AGESTRINGSELEMENT_H


class AGEStringsElement
{
	public:
		AGEStringsElement();
		virtual ~AGEStringsElement();

		int getId();
		string getTag();
		bool getAvailable();
		AGEStringsElement* getNext();
		string getEntry1();
		string getEntry2();
		string getEntry3();
		void setId(int id);
		void setTag(string tag);
		void setAvailable(bool available);
		void setNext(AGEStringsElement* next);
		void setEntry1(string entry1);
		void setEntry2(string entry2);
		void setEntry3(string entry3);


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGEStringsElement* next;
		string entry1;
		string entry2;
		string entry3;

};


#endif // AGESTRINGSELEMENT_H


