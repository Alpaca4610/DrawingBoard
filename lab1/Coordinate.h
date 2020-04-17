#pragma once
#include <string>

class point {
private:
	std::string s;
	double x, y;
public:
	point();
	point(std::string);
	double getx();
	void setpoint(double, double);
	double gety();
};
