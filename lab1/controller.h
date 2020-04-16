#pragma once
#include <ege.h>
#include "Coordinate.h"
#include <graphics.h>
#include <string>

class controller {
private:
	point p1;
	PIMAGE pimg;
public:
	controller();
	controller(std::string);
	point getpoint();
	void close();
};
