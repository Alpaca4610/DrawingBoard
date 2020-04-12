#pragma once
#include <ege.h>
#include <graphics.h>
#include <string>

class Color
{private:
	color_t color{ LIGHTGRAY };
public:
	Color() { color = LIGHTGRAY; }
	Color(std::string s) {
		setColor(s);
	}
	color_t getcolor() {
		return color;
	}

	void setColor(std::string s) {
		switch (s[0]) {
		case(82):
			color = RED;
			break;
		case(71):
			color = GREEN;
			break;
		case(66):
			color = BLUE;
			break;
		case(87):
			color = LIGHTGRAY;
			break;
		}
	}
};
