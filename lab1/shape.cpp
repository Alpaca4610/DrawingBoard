#include "shape.h"
#include <graphics.h>
#include "ege.h"
#include <string>
#include "controller.h"
#include <filesystem>
#include <fstream>
#pragma warning(disable:4996) //启用ege库被禁用的函数
namespace fs = std::filesystem;

void shape::convertBool(string filled_)//将字符串转换为bool类型的变量
{
	if ('Y' == filled_[0]) {
		filled = true;
	}
	else if ('N' == filled_[0]) {
		filled = false;
	}
}

shape::shape(string color_, string filled_, string size_)//将字符串转换成color_t类型的变量
{
	size = size_;
	color = new Color(color_);
	convertBool(filled_);
	char fc[2];
	if (filled) {//判断如果填充，则要求用户输入填充图形的颜色
		inputbox_getline("请输入需要填充图形的颜色", "请输入需要填充图形的颜色（R代表红色，G代表绿色，B代表蓝色）：（回车确认）", fc, 2);
		fcolor = new Color{ fc };
	}
	else {
		fcolor = new Color{ "NULL" };
	}
	numOfObjects++;
}

bool shape::isfilled()//getter
{
	return filled;
}

void shape::setfilled(bool filled_)//setter
{
	filled = filled_;
}

Color* shape::getcolor()//getter
{
	return color;
}

Color* shape::getbgcolor()//getter
{
	return fcolor;
}

string shape::getsize()
{
	return size;
}

string* shape::getAOfsize()
{
	return &size;
}

int shape::getnumberObjects()
{
	return numOfObjects;
}

int* shape::getAOnumberObjects()
{
	return &numOfObjects;
}

shape::~shape()
{
	delete color;
	delete fcolor;
	numOfObjects--;
}

Circle::Circle(Circle& c)//拷贝构造函数
{
	p = c.p;
	radius = c.radius;
	*(this->getcolor()) = *(c.getcolor());//深拷贝
	*(this->getbgcolor()) = *(c.getbgcolor());//深拷贝
	*(this->getAOfsize()) = c.getsize();
}

Circle::Circle(point p_, int r_, string s_, string filled_, string size_) :shape{ s_, filled_ ,size_ }//利用接收的字符串构造类
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

int Circle::getRadius()
{
	return radius;
}

void Circle::draw()
{
	controller screen1(this->getsize());//创建画板屏幕对象让用户自定义大小
	setcolor((*(this->getcolor())).getcolor());//设置圆边界的颜色
	circle(static_cast<int>(this->getx()), this->gety(), radius);//画圆函数
	if (this->isfilled()) {
		setfillcolor(((*this->getbgcolor())).getcolor());
		floodfill(this->getx(), this->gety(), (*(this->getcolor())).getcolor());
	}//判断图形是否填充，若填充，使用圆心作为floodfill的一个参数进行填充
}

void Circle::writefile()
{
	fs::path p{ "figure.txt" };
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);
	out << "1" << std::endl
		<< this->getx() << " " << this->gety() << " " << radius << std::endl
		<< (*(this->getcolor())).getString() << " " << this->isfilled() << std::endl;
	out.close();
}

Circle::~Circle()
{
}

RectangleC::RectangleC(RectangleC& r)
{
	p1 = r.p1;
	p2 = r.p2;
	*(this->getcolor()) = *(r.getcolor());//深拷贝
	*(this->getbgcolor()) = *(r.getbgcolor());//深拷贝
	*(this->getAOfsize()) = r.getsize();
}

RectangleC::RectangleC(point p1_, point p2_, string s_, string filled_, string size_) :shape{ s_,filled_,size_ }
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

void RectangleC::draw()
{
	controller screen1(this->getsize());
	setcolor((*(this->getcolor())).getcolor());
	rectangle(this->getp1().getx(), this->getp1().gety(), this->getp2().getx(), this->getp2().gety());
	if (this->isfilled()) {
		setfillcolor((*(this->getbgcolor())).getcolor());
		floodfill((this->getp1().getx()) + 1, (this->getp1().gety()) - 2, (*(this->getcolor())).getcolor());
	}//将矩形左上角的坐标做变换处理后作为floodfill的一个参数进行填充
}

void RectangleC::writefile()
{
	fs::path p{ "figure.txt" };
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);
	out << "3" << std::endl
		<< this->getp1().getx() << " " << this->getp1().gety() << " " << this->getp2().getx() << " " << this->getp2().gety() << " " << std::endl
		<< (*(this->getcolor())).getString() << " " << this->isfilled() << std::endl;
	out.close();
}

RectangleC::~RectangleC()
{
}

triangle::triangle(triangle& t1)
{
	p1 = t1.p1;
	p2 = t1.p2;
	p3 = t1.p3;
	*(this->getcolor()) = *(this->getcolor());
	*(this->getbgcolor()) = *(this->getbgcolor());
	*(this->getAOfsize()) = t1.getsize();
}

triangle::triangle(point p1_, point p2_, point p3_, string c_, string filled_, string size_) :shape(c_, filled_, size_)
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

void triangle::draw()
{
	controller screen1(this->getsize());
	int pt[] = { this->getp1().getx(),this->getp1().gety(), this->getp2().getx(), this->getp2().gety(), this->getp3().getx(), this->getp3().gety() };//利用接收到的点坐标数据创建一个数组
	setcolor((*(this->getcolor())).getcolor());
	if (this->isfilled()) {
		setfillstyle(SOLID_FILL, (*(this->getbgcolor())).getcolor());//与fillploy一起使用的填充函数
	}
	fillpoly(3, pt);//创建一个三条边，顶点坐标为数组中元素值的三角形对象
}

void triangle::writefile()
{
	fs::path p{ "figure.txt" };
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);
	out << "2" << std::endl
		<< this->getp1().getx() << " " << this->getp1().gety() << " " << this->getp2().getx() << " " << this->getp2().gety() << " " << this->getp3().getx() << " " << this->getp3().gety() << " " << std::endl
		<< (*(this->getcolor())).getString() << " " << this->isfilled() << std::endl;
	out.close();
}

triangle::~triangle()
{
}

Line::Line(Line& l)
{
	p1 = l.p1;
	p2 = l.p2;
	*color = *(l.color);//深拷贝
	size = l.size;
	(*(shape::getAOnumberObjects()))++;
}

Line::Line(point p1_, point p2_, string c_, string size_)
{
	p1 = p1_;
	p2 = p2_;
	color = new Color(c_);
	size = size_;
	(*(shape::getAOnumberObjects()))++;
}

Color* Line::getcolor()
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

string Line::getsize()
{
	return size;
}

void Line::draw()
{
	controller screen1(size);
	setcolor((*(this->getcolor())).getcolor());
	line(this->getp1().getx(), this->getp1().gety(), this->getp2().getx(), this->getp2().gety());//画线
}

Line::~Line()
{
	delete color;
	(*(shape::getAOnumberObjects()))--;
}

ploygon::ploygon(ploygon& p1)
{
	p = std::vector<int>(p1.p);
	n = p1.n;
	*(this->getcolor()) = *(p1.getcolor());//深拷贝
	*(this->getbgcolor()) = *(p1.getbgcolor());//深拷贝
	*(this->getAOfsize()) = p1.getsize();
}

ploygon::ploygon(string n_, string color_, string filled_, string size_) :shape(color_, filled_, size_)
{
	n = std::stoi(n_);
	for (int i = 0; i < n; i++) {//根据用户输入的顶点数创建vector存储顶点坐标
		char p_temp[15];
		inputbox_getline("请输入顶点坐标", "请输入顶点坐标(如(233,233))（回车确认）", p_temp, 15);
		point p_{ p_temp };
		p.push_back(p_.getx());
		p.push_back(p_.gety());
	}
}

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

void ploygon::draw()
{
	controller screen1(this->getsize());
	setfillcolor((*(this->getcolor())).getcolor());
	if (this->isfilled()) {
		setfillstyle(SOLID_FILL, (*(this->getcolor())).getcolor());
	}
	fillpoly(this->getn(), this->getp());
}

void ploygon::writefile()
{
}

ploygon::~ploygon()
{
	delete[]this->getp();
}