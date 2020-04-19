#pragma once
#include <string>

class point {
private:
	int x, y;
public:
	point();
	point(std::string);
	void convert(std::string);
	int getx();
	int gety();
	void setpoint(std::string);
};
