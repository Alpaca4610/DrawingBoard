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

public:
	rectangle();
	rectangle(point, double, Color, bool);
	double getx();
	double gety();
	Color getcolor();
	Color getfcolor();
	bool is_fill();
};

class line {
private:

public:
	line();
	line(point, point, Color);
	double getx();
	double gety();
	Color getcolor();
};

class triangle:public shape {
private:

public:
	triangle();
	triangle(point, double, Color, bool);
	double getx();
	double gety();
	Color getcolor();
	Color getfcolor();
	bool is_fill();
};