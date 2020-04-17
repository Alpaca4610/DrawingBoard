#include "color.h"

Color::Color() { color = LIGHTGRAY; }
Color::Color(std::string s) {
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
		break;
	}
}
