#include <iostream>
#include <graphics.h>
#include "default.h"

int main() {
	initgraph(640, 800);
	color_t R;
	setcolor(RED);
	ege::circle(200, 200, 100);
	getch();
	return 0;
}