#include "Coordinate.h"

point::point() :point("(300,300)") {}

point::point(std::string s_)//将字符串形式的坐标转换成两个int类型并存储在成员变量中
{
	convert(s_);
}

void point::convert(std::string s_)
{
	int n = s_.find_first_of(",");
	this -> x = std::stoi(s_.substr(1, n - 1));
	int n2 = s_.find_last_of(")");
	this -> y = std::stoi(s_.substr(n + 1, n2 - n - 1));
}

int point::getx()//getter
{
	return x;
}

void point::setpoint(std::string s_)//setter
{
	convert(s_);
}

int point::gety()//getter
{
	return y;
}
