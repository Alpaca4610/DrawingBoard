#include "default.h"
#include <graphics.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

controller::controller():controller(640,480){}

controller::controller(int a,int b)
{
	if (a > 0 && b > 0) {
		initgraph(a, b);
		getch();
	}
	else {
		cout << "��������ȷ�ĳ������ݣ�" << endl;
	}
}

void controller::close()
{
	closegraph();
}
