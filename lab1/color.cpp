#include "color.h"

Color::Color() :Color("W") {}
Color::Color(std::string s) {
	s_color = s;
	setColor(s);
}
color_t Color::getcolor() {//getter
	return color;
}

void Color::setColor(std::string s) {//setter
	switch (s[0]) {
	case(82):
		color = RED;//使用ege定义的颜色宏
		break;
	case(71):
		color = GREEN;
		break;
	case(66):
		color = BLUE;
		break;
	case(87):
		color = LIGHTGRAY;
	case(78):
		color = BLACK;
		break;
	}
}

std::string Color::getString()
{
	return s_color;
}