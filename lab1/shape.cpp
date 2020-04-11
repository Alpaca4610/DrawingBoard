#include "shape.h"
#include <iostream>
#include <string>

shape::shape(Color color_, bool filled_)
{
	color = color_;
	filled = filled_;
/*	if (filled) {
		std::cout << "请输入需要填充的颜色！" << std::endl;
		std::string s;
	//	std::cin >> s;
//		static_cast<Color>(s) >> fcolor;
	}*/
}

Color shape::getColor()
{
	return color;
}

Color shape::getfcolor()
{
	return fcolor;
}

bool shape::isfilled()
{
	return filled;
}

void shape::setColor(Color color_)
{
	color = color_;
}

void shape::setfilled(bool filled_)
{
	filled = filled_;
}

circle::circle():circle(point(),5.0,Color::W,false){}

circle::circle(point p_, double r_, Color c_, bool filled_):shape { c_, filled_ }
{
	p = p_;
	radius = r_;
}

double circle::getx()
{
	return p.getx();
}

double circle::gety()
{
	return p.gety();
}

rectangle::rectangle():rectangle(point(100,100),point(200,200),Color::Default,false){}

rectangle::rectangle(point p1_, point p2_, Color c_, bool filled_):shape{c_,filled_}
{
	p1 = p1_;
	p2 = p2_;
}

triangle::triangle():triangle(point(100,100),point(200,200),point(300,300),Color::Default,false){}

triangle::triangle(point p1_, point p2_, point p3_,Color c_,bool filled_):shape(c_,filled_)
{
	p1 = p1_;
	p2 = p2_;
	p3 = p3_;
}

line::line():line(point(100,100),point(200,200),Color::Default,false){}

line::line(point p1_, point p2_,Color c_,bool filled_):shape(c_,filled_)
{
	p1 = p1_;
	p2 = p2_;
}
