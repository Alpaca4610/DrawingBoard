#pragma once
#include <ege.h>
#include <graphics.h>
#include <string>

class Color
{private:
	color_t color{ LIGHTGRAY };
public:
	Color();
	Color(std::string);
	color_t getcolor();
	void setColor(std::string);
};
