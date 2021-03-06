// designpattern.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// https://ko.wikipedia.org/wiki/%EB%B9%8C%EB%8D%94_%ED%8C%A8%ED%84%B4
// Product
class Pizza
{
private:
	string dough;
	string sauce;
	string topping;

public:
	Pizza() {}
	~Pizza() {}

	void SetDough(const string& d) { dough = d; };
	void SetSauce(const string& s) { sauce = s; };
	void SetTopping(const string& t) { topping = t; };

	void ShowPizza()
	{
		cout << " Yummy !!!" << endl
			<< "Pizza with Dough as " << dough
			<< ". Sauce as " << sauce
			<< " and Topping as " << topping
			<< " !! " << endl;
	}
};

// Abstract Builder
class PizzaBuilder
{
protected:
	auto_ptr<Pizza> pizza;

public:
	PizzaBuilder() {}
	virtual ~PizzaBuilder() {}

	auto_ptr<Pizza> GetPizza()
	{
		return pizza;
	}

	void createdNewPizzaProduct()
	{
		pizza.reset(new Pizza);
	}

	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
};

// Concrete Builder
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
	HawaiianPizzaBuilder() : PizzaBuilder() {}
	~HawaiianPizzaBuilder() {}

	void buildDough()
	{
		pizza->SetDough("cross");
	}
	void buildSauce()
	{
		pizza->SetSauce("mild");
	}
	void buildTopping()
	{
		pizza->SetTopping("ham and pineapple");
	}
};

// Concrete Builder
class SpicyPizzaBuilder : public PizzaBuilder
{
public:
	SpicyPizzaBuilder() : PizzaBuilder() {}
	~SpicyPizzaBuilder() {}

	void buildDough()
	{
		pizza->SetDough("Pan baked");
	}
	void buildSauce()
	{
		pizza->SetSauce("hot");
	}
	void buildTopping()
	{
		pizza->SetTopping("pepperoni and salami");
	}
};

// Director
class Waiter
{
private:
	PizzaBuilder * pizzaBuilder;
public:
	Waiter() : pizzaBuilder(NULL) {}
	~Waiter() {}

	void SetPizzaBuilder(PizzaBuilder* b)
	{
		pizzaBuilder = b;
	}

	auto_ptr<Pizza> GetPizza()
	{
		return pizzaBuilder->GetPizza();
	}

	void ConstructPiza()
	{
		pizzaBuilder->createdNewPizzaProduct();
		pizzaBuilder->buildDough();
		pizzaBuilder->buildSauce();
		pizzaBuilder->buildTopping();
	}
};

int main()
{
	Waiter waiter;

	HawaiianPizzaBuilder hawaiianPizzaBuilder;
	waiter.SetPizzaBuilder(&hawaiianPizzaBuilder);
	waiter.ConstructPiza();
	auto_ptr<Pizza> pizza = waiter.GetPizza();
	pizza->ShowPizza();

	SpicyPizzaBuilder spicyPizzaBuilder;
	waiter.SetPizzaBuilder(&spicyPizzaBuilder);
	waiter.ConstructPiza();
	pizza = waiter.GetPizza();
	pizza->ShowPizza();

	char input;
	cin >> input;

	return 0;
}

