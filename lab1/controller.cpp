#include "controller.h"

controller::controller() :controller("(640,480)") {}

controller::controller(std::string size_)//�����ַ��������point���ͣ�������point�е�getter������ȡ����
{
	p1 = point(size_);
	initgraph(p1.getx(), p1.gety());
}

point controller::getpoint()
{
	return p1;
}

void controller::close()
{
	closegraph();
}