#include "shape.h"
#include <graphics.h>
#include "ege.h"
#include <string>

void shape::convertBool(string filled_)//将字符串转换为bool类型的变量
{
	if ('Y' == filled_[0]) {
		filled = true;
	}	
	else if ('N' == filled_[0]) {
		filled = false;
	}
}

shape::shape(string color_, string filled_)//将字符串转换成color_t类型的变量
{
	color = Color(color_);
	convertBool(filled_);
	char fc[2];
	if (filled) {//判断如果填充，则要求用户输入填充图形的颜色
		inputbox_getline("请输入需要填充图形的颜色", "请输入需要填充图形的颜色（R代表红色，G代表绿色，B代表蓝色）：（回车确认）", fc, 2);
		fcolor = Color{ fc };
	}
}


bool shape::isfilled()//getter
{
	return filled;
}

void shape::setfilled(bool filled_)//setter
{
	filled = filled_;
}

Color shape::getcolor()//getter
{
	return color;
}

Color shape::getbgcolor()//getter
{
	return fcolor;
}

Circle::Circle():Circle(point("100,100"),5.0,"W","N"){}//default ctor

Circle::Circle(point p_, int r_, string s_, string filled_):shape { s_, filled_ }//利用接收的字符串构造类
{
	p = p_;
	radius = r_;
}

int Circle::getx()//getter
{
	return p.getx();
}

int Circle::gety()//getter
{
	return p.gety();
}

RectangleC::RectangleC():RectangleC(point("100,100"),point("200,200"),"W", "N"){}//default ctor

RectangleC::RectangleC(point p1_, point p2_, string s_, string filled_):shape{s_,filled_}
{
	p1 = p1_;
	p2 = p2_;
}

point RectangleC::getp1()//getter
{
	return p1;
}

point RectangleC::getp2()//getter
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

ploygon::ploygon(string n_,string color_,string filled_):shape(color_,filled_)
{
	n = std::stoi(n_);
	for (int i = 0; i < n; i++) {//根据用户输入的顶点数创建vector存储顶点坐标
		char p_temp[15];
		inputbox_getline("请输入顶点坐标", "请输入顶点坐标(如(233,233))（回车确认）",p_temp ,15);
		point p_{ p_temp };
		p.push_back(p_.getx());
		p.push_back(p_.gety());
	}
}

ploygon::ploygon():ploygon("3","R","N"){}

int ploygon::getn()
{
	return n;
}

int* ploygon::getp()//将vector转换成整数数组并返回
{
	int* po = new int[p.size()];//注意sizeof！！！！！！！
	std::copy(p.begin(), p.end(), po);
	return po;
}

