#include "Coordinate.h"

point::point() :point("(300,300)") {}

point::point(std::string s_)//���ַ�����ʽ������ת��������int���Ͳ��洢�ڳ�Ա������
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
