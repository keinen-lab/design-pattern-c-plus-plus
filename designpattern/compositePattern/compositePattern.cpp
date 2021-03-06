// compositePattern.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component
{
public:
	virtual void list() const = 0;
	virtual ~Component()	{	}
};

class Leaf : public Component
{
private:
	int value;
public:
	explicit Leaf(int val) : value(val) {}
	void list() const
	{
		cout << "  " << value << "\n";
	}
};

class Composite : public Component
{
private:
	vector<Component*> table;
	string id;
public:
	explicit Composite(string id) : id(id) {}
	void add(Component *obj)
	{
		table.push_back(obj);
	}
	void list() const
	{
		cout << id << ":" << "\n";

		for (vector<Component*>::const_iterator it = table.begin(); it != table.end(); ++it)
		{
			(*it)->list();
		}
	}
};


int main()
{
	Leaf num0(0);
	Leaf num1(1);
	Leaf num2(2);
	Leaf num3(3);
	Leaf num4(4);

	Composite container1("Container 1");
	Composite container2("Container 2");

	container1.add(&num0);
	container1.add(&num1);

	container2.add(&num2);
	container2.add(&num3);
	container2.add(&num4);

	container1.add(&container2);
	container1.list();

	char input;
	cin >> input;
	return 0;
}

