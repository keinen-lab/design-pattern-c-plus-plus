// decoratorPattern.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// component
class Widget 
{
public:
	virtual void draw() = 0;
	virtual ~Widget()	{	}
};

// concrete component
class TextField : public Widget {
private:
	int width, height;
public:
	TextField(int w, int h) {
		width = w;
		height = h;
	}

	void draw() {
		cout << "TextField: " << width << ", " << height << "\n";
	}
};

// Decorateor
class Decorator : public Widget 
{
private:
	Widget * wid;		//referenct to Widget
public:
	Decorator(Widget* w) 
	{
		wid = w;
	}

	~Decorator()
	{
		delete wid;
	}

	void draw() 
	{
		wid->draw();
	}
};

// concrete decorator A
class BorderDecorator : public Decorator 
{
public:
	BorderDecorator(Widget* w) : Decorator(w) {}
	void draw()
	{
		Decorator::draw();
		cout << "   BorderDecorator" << "\n";
	}
};

// concrete decorator B
class ScrollDecorator : public Decorator 
{
public:
	ScrollDecorator(Widget* w) : Decorator(w) {}
	void draw()
	{
		Decorator::draw();
		cout << "   ScrollDecorator" << "\n";
	}
};

int main()
{
	Widget* aWidget = new BorderDecorator(new ScrollDecorator(new TextField(80, 24)));
	aWidget->draw();

	char input;
	cin >> input;

    return 0;
}

