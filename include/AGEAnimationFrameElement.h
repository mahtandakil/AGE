/****************************************************************************
* Created for: AGE
* Dev line: AGE v1
* Creation day: 27/08/2015
* Last change: 27/08/2015
* Autogen: CListGen 1.0.8
****************************************************************************/


#include <iostream>


using namespace std;


#ifndef AGEANIMATIONFRAMEELEMENT_H
#define AGEANIMATIONFRAMEELEMENT_H


class AGEAnimationFrameElement
{
	public:
		AGEAnimationFrameElement();
		virtual ~AGEAnimationFrameElement();

		int getId();
		string getTag();
		bool getAvailable();
		AGEAnimationFrameElement* getNext();
		int getImage_x();
		int getImage_y();
		int getImage_w();
		int getImage_h();
		int getImage_d();
		void setId(int id);
		void setTag(string tag);
		void setAvailable(bool available);
		void setNext(AGEAnimationFrameElement* next);
		void setImage_x(int image_x);
		void setImage_y(int image_y);
		void setImage_w(int image_w);
		void setImage_h(int image_h);
		void setImage_d(int image_d);


	protected:


	private:
		int id;
		string tag;
		bool available;
		AGEAnimationFrameElement* next;
		int image_x;
		int image_y;
		int image_w;
		int image_h;
		int image_d;

};


#endif // AGEANIMATIONFRAMEELEMENT_H


