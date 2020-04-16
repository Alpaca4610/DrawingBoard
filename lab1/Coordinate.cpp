#include "Coordinate.h"

point::point() :point("(300,300)") {}

point::point(std::string s_)//将字符串形式的坐标转换成两个int类型并存储在成员变量中
{
	s = s_;
	int n = s.find_first_of(",");
	x = std::stod(s.substr(1, n - 1));
	int n2 = s.find_last_of(")");
	y = std::stod(s.substr(n + 1, n2 -  n- 1));
}

double point::getx()//getter
{
	return x;
}

void point::setpoint(double x_, double y_)//setter
{
	x = x_;
	y = y_;
}

double point::gety()//getter
{
	return y;
}
