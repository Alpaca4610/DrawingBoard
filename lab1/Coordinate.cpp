#include "Coordinate.h"

point::point() :point(300.0, 300.0) {}

point::point(double x_, double y_)
{
	x = x_;
	y = y_;
}

double point::getx()
{
	return x;
}

void point::setpoint(double x_, double y_)
{
	x = x_;
	y = y_;
}

double point::gety()
{
	return y;
}
