#include "controller.h"

controller::controller():controller("(640,480)"){}

controller::controller(std::string size_)
{
	p1 = point(size_);
	initgraph(p1.getx(), p1.gety());
}

void controller::close()
{
	closegraph();
}
