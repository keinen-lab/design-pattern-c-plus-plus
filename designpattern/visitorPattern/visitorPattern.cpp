// visitorPattern.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// 1. Add an accept(visitor) method to the "element" hierachy
class Element
{
public:
	virtual void accept(class Visitor &v) = 0;
};

class This : public Element
{
public:
	void accept(Visitor &v);
	string tHis()
	{
		return "This";
	}
};

class That : public Element
{
public:
	void accept(Visitor &v);
	string that()
	{
		return "That";
	}
};

class TheOther : public Element
{
public:
	void accept(Visitor &v);
	string theOther()
	{
		return "TheOther";
	}
};

class Visitor
{
public:
	virtual void visit(This *e) = 0;
	virtual void visit(That *e) = 0;
	virtual void visit(TheOther *e) = 0;
};

void This::accept(Visitor &v)
{
	v.visit(this);
}

void That::accept(Visitor &v)
{
	v.visit(this);
}
	
void TheOther::accept(Visitor &v)
{
	v.visit(this);
}

class UpVisitor : public Visitor
{
	void visit(This *e)
	{
		cout << "do Up on " + e->tHis() << "\n";
	}

	void visit(That *e)
	{
		cout << "do Up on " + e->that() << "\n";
	}

	void visit(TheOther *e)
	{
		cout << "do Up on " + e->theOther() << "\n";
	}
};

class DownVisitor : public Visitor
{
	void visit(This *e)
	{
		cout << "do Down on " + e->tHis() << "\n";
	}

	void visit(That *e)
	{
		cout << "do Down on " + e->that() << "\n";
	}

	void visit(TheOther *e)
	{
		cout << "do Down on " + e->theOther() << "\n";
	}
};

int main()
{
	Element* list[] =
	{
		new This(), new That(), new TheOther()
	};

	UpVisitor up;
	DownVisitor down;

	for (int i = 0; i < 3; i++)
	{
		list[i]->accept(up);
	}

	for (int i = 0; i < 3; i++)
	{
		list[i]->accept(down);
	}

	char input;
	cin >> input;

    return 0;
}

