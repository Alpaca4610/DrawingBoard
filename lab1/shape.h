#pragma once
#include "Coordinate.h"
#include "color.h"
using std::string;

class shape {
private:
	Color color{};
	Color fcolor{};
	bool filled{ false };
public:
	void convertBool(string);
	shape() = default;
	shape(string, string);
	bool isfilled();
	void setfilled(bool);
	Color getcolor();
	Color getbgcolor();
};

class Circle :public shape{
private:
	point p;
	double radius;
public:
	Circle();
	Circle(point, double, string, string);
	double getx();
	double gety();
};

class RectangleC :public shape{
private:
	point p1,p2;
public:
	RectangleC();
	RectangleC(point, point, string, string);
	point getp1();
	point getp2();
};

class Line {
private:
	point p1, p2;
	Color color;
public:
	Line();
	Line(point, point,string);
	Color getcolor();
	point getp1();
	point getp2();
};

class triangle:public shape {
private:
	point p1, p2, p3;
public:
	triangle();
	triangle(point, point,point,string,string);
	point getp1();
	point getp2();
	point getp3();
};