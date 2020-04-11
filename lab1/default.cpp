#include "default.h"
#include <graphics.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

controller::controller():controller(640,480){}

controller::controller(int a,int b)
{
		initgraph(a, b);
		getch();
}

void controller::close()
{
	closegraph();
}
