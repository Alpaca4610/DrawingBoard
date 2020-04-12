#include "shape.h"
#include <iostream>
#include <string>

void shape::convertBool(string filled_)
{
	if ('Y' == filled_[0]) {
		filled = true;
	}	
	else if ('N' == filled_[0]) {
		filled = false;
	}
}

shape::shape(string color_, string filled_)
{
	color = Color(color_);
	convertBool(filled_);
	char fc[2];
	if (filled) {
		inputbox_getline("请输入需要填充图形的颜色", "请输入需要填充图形的颜色（R代表红色，G代表绿色，B代表蓝色）：（回车确认）", fc, 2);
		fcolor = Color{ fc };
	}
}


bool shape::isfilled()
{
	return filled;
}

void shape::setfilled(bool filled_)
{
	filled = filled_;
}

Color shape::getcolor()
{
	return color;
}

Color shape::getbgcolor()
{
	return fcolor;
}

Circle::Circle():Circle(point("100,100"),5.0,"W","N"){}

Circle::Circle(point p_, double r_, string s_, string filled_):shape { s_, filled_ }
{
	p = p_;
	radius = r_;
}

double Circle::getx()
{
	return p.getx();
}

double Circle::gety()
{
	return p.gety();
}

RectangleC::RectangleC():RectangleC(point("100,100"),point("200,200"),"W", "N"){}

RectangleC::RectangleC(point p1_, point p2_, string s_, string filled_):shape{s_,filled_}
{
	p1 = p1_;
	p2 = p2_;
}

point RectangleC::getp1()
{
	return p1;
}

point RectangleC::getp2()
{
	return p2;
}

triangle::triangle():triangle(point("100,100"),point("200,200"),point("300,300"),"W", "N"){}

triangle::triangle(point p1_, point p2_, point p3_,string c_,string filled_):shape(c_,filled_)
{
	p1 = p1_;
	p2 = p2_;
	p3 = p3_;
}

point triangle::getp1()
{
	return p1;
}

point triangle::getp2()
{
	return p2;
}

point triangle::getp3()
{
	return p3;
}

Line::Line():Line(point("100,100"),point("200,200"),"W"){}

Line::Line(point p1_, point p2_,string c_)
{
	p1 = p1_;
	p2 = p2_;
	color = Color(c_);
}

Color Line::getcolor()
{
	return color;
}

point Line::getp1()
{
	return p1;
}
point Line::getp2()
{
	return p2;
}
