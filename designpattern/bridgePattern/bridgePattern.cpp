// bridgePattern.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// implementor
class DrawingAPI {
public:
	virtual void drawCircle(double x, double y, double radius) = 0;
	virtual ~DrawingAPI() {};
};

// concrete implementor A
class DrawingAPI1 : DrawingAPI 
{
public:
	void drawCircle(double x, double y, double radius)
	{
		cout << "API1. circle at " << x << ":" << y << " " << radius << endl;
	}
};

// concrete implementor B
class DrawingAPI2 : DrawingAPI
{
public:
	void drawCircle(double x, double y, double radius)
	{
		cout << "API2. circle at " << x << ":" << y << " " << radius << endl;
	}
};

// Abstraction
class Shape
{
public:
	virtual ~Shape() {	};
	virtual void draw() = 0;
	virtual void resizeByPercentage(double pct) = 0;
};

// Refined Abstraction
class CircleShape : public Shape
{
private:
	double m_x, m_y, m_radius;
	DrawingAPI* m_drawingAPI;
public:
	CircleShape(double x, double y, double radius, DrawingAPI *drawingAPI)
	{
		m_x = x;
		m_y = y; 
		m_radius = radius;
		m_drawingAPI = drawingAPI;
	}

	void draw()
	{
		m_drawingAPI->drawCircle(m_x, m_y, m_radius);
	}

	void resizeByPercentage(double pct)
	{
		m_radius *= pct;
	}
};


int main()
{
	DrawingAPI1 dap1;
	DrawingAPI2 dap2;

	CircleShape circle1(1, 2, 3, (DrawingAPI*)&dap1);
	CircleShape circle2(5, 7, 11, (DrawingAPI*)&dap2);

	circle1.resizeByPercentage(2.5);
	circle2.resizeByPercentage(2.5);

	circle1.draw();
	circle2.draw();

	char input;
	cin >> input;

    return 0;
}

