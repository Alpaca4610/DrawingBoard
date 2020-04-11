#pragma once
#include "Coordinate.h"
#include "color.h"

class shape {
private:
	Color color{ Color::W };
	Color fcolor{ Color::Default };
	bool filled{ false };
public:
	shape() = default;
	shape(Color, bool);
	Color getColor();
	Color getfcolor();
	bool isfilled();
	void setColor(Color);
	void setfilled(bool);
};

class circle :public shape{
private:
	point p;
	double radius;
public:
	circle();
	circle(point, double, Color, bool);
	double getx();
	double gety();
};

class rectangle :public shape{
private:
	point p1,p2;
public:
	rectangle();
	rectangle(point, point, Color, bool);
};

class line:public shape {
private:
	point p1, p2;
public:
	line();
	line(point, point,Color,bool);
};

class triangle:public shape {
private:
	point p1, p2, p3;
public:
	triangle();
	triangle(point, point,point,Color,bool);
};