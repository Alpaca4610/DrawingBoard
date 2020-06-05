#include "shape.h"
#include <graphics.h>
#include "ege.h"
#include <string>
#include "controller.h"
#include <filesystem>
#include <fstream>
#pragma warning(disable:4996) //����ege�ⱻ���õĺ���
namespace fs = std::filesystem;

void shape::convertBool(string filled_)//���ַ���ת��Ϊbool���͵ı���
{
	if ('Y' == filled_[0]) {
		filled = true;
	}
	else if ('N' == filled_[0]) {
		filled = false;
	}
}

shape::shape()
{
	color = { new Color{ "NULL" } };
	fcolor = { new Color{ "NULL" } };
	numOfObjects++;
}

shape::shape(string color_, string filled_, string size_, string flag = "D")//���ַ���ת����color_t���͵ı���
{
	size = size_;
	color = new Color(color_);
	convertBool(filled_);
	char fc[2];
	if (flag != "D") {
		fcolor = new Color{ flag.c_str() };
	}
	else {
		if (filled) {//�ж������䣬��Ҫ���û��������ͼ�ε���ɫ
			inputbox_getline("��������Ҫ���ͼ�ε���ɫ", "��������Ҫ���ͼ�ε���ɫ��R�����ɫ��G������ɫ��B������ɫ�������س�ȷ�ϣ�", fc, 2);
			fcolor = new Color{ fc };
		}
		else {
			fcolor = new Color{ "NULL" };
		}
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

bool* shape::getisfilled()
{
	return &filled;
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

/*Circle::Circle(Circle& c)//�������캯��
{
	p = c.p;
	radius = c.radius;
	*(this->getcolor()) = *(c.getcolor());//���
	*(this->getbgcolor()) = *(c.getbgcolor());//���
	*(this->getAOfsize()) = c.getsize();
}*/

Circle::Circle() :shape()
{
}

Circle::Circle(point p_, int r_, string s_, string filled_, string size_, string bgc0lor) : shape{ s_, filled_ ,size_ ,bgc0lor }//���ý��յ��ַ���������
{
	p = p_;
	radius = r_;
}

int Circle::getx() const//getter
{
	return p.getx();
}

int Circle::gety() const//getter
{
	return p.gety();
}

int Circle::getRadius() const
{
	return radius;
}

void Circle::draw()
{
	controller screen1(this->getsize());//����������Ļ�������û��Զ����С
	setcolor((*(this->getcolor())).getcolor());//����Բ�߽����ɫ
	circle(static_cast<int>(this->getx()), this->gety(), radius);//��Բ����
	if (this->isfilled()) {
		setfillcolor(((*this->getbgcolor())).getcolor());
		floodfill(this->getx(), this->gety(), (*(this->getcolor())).getcolor());
	}//�ж�ͼ���Ƿ���䣬����䣬ʹ��Բ����Ϊfloodfill��һ�������������
}

void Circle::writefile()
{
	fs::path p{ "figure.txt" };
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);
	out << "1" << std::endl
		<< this->getx() << " " << this->gety() << " " << radius << std::endl
		<< (*(this->getcolor())).getString() << " " << this->isfilled();
	if (this->isfilled()) {
		out << " " << (*(this->getbgcolor())).getString();
	}
	out << std::endl << this->getsize();
	out << std::endl;
	out.close();
}

bool Circle::operator<(const Circle& c_)
{
	return ((this->radius) < c_.radius);
}

bool Circle::operator>(const Circle& c_)
{
	return ((this->radius) > c_.radius);
}

bool Circle::operator<=(const Circle& c_)
{
	return ((this->radius) <= c_.radius);
}

bool Circle::operator>=(const Circle& c_)
{
	return ((this->radius) >= c_.radius);
}

bool Circle::operator==(const Circle& c_)
{
	return (((this->p) == c_.p) && ((this->radius) == c_.radius));
}

bool Circle::operator!=(const Circle& c_)
{
	return !(((this->p) == c_.p) && ((this->radius) == c_.radius));
}

Circle& Circle::operator=(Circle& c_)
{
	this->radius = c_.radius;
	this->p = c_.p;
	*((*(this->getcolor())).getAOfcolor()) = { (*(c_.getcolor())).getcolor() };
	*(this->getcolor()->getAOfString()) = { c_.getcolor()->getString() };
	*((*(this->getbgcolor())).getAOfcolor()) = { (*(c_.getbgcolor())).getcolor() };
	*(this->getbgcolor()->getAOfString()) = { c_.getbgcolor()->getString() };
	*(this->getAOfsize()) = { (c_.getsize()) };
	*(this->getisfilled()) = { (c_.isfilled()) };
	return *(this);
}

Circle::~Circle()
{
}

/*RectangleC::RectangleC(RectangleC& r)
{
	p1 = r.p1;
	p2 = r.p2;
	*(this->getcolor()) = *(r.getcolor());//���
	*(this->getbgcolor()) = *(r.getbgcolor());//���
	*(this->getAOfsize()) = r.getsize();
}*/

RectangleC::RectangleC() :shape()
{
}

RectangleC::RectangleC(point p1_, point p2_, string s_, string filled_, string size_, string bgc0lor) : shape{ s_,filled_,size_ ,bgc0lor }
{
	p1 = p1_;
	p2 = p2_;
}

point RectangleC::getp1() const//getter
{
	return p1;
}

point RectangleC::getp2() const//getter
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
	}//���������Ͻǵ��������任�������Ϊfloodfill��һ�������������
}

void RectangleC::writefile()
{
	fs::path p{ "figure.txt" };//ʹ��filesystem�е�·���๹�����
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);//ʹ��app��out���ģʽ���ļ�ĩβ�����Ϣ
	out << "3" << std::endl//���ͼ��ID
		<< this->getp1().getx() << " " << this->getp1().gety() << " " << this->getp2().getx() << " " << this->getp2().gety() << " " << std::endl
		<< (*(this->getcolor())).getString() << " " << this->isfilled();//��ͼ�ε�������Ϣ������ļ���
	if (this->isfilled()) {//�ж��Ƿ���Ҫ��������ɫ����
		out << " " << (*(this->getbgcolor())).getString();
	}
	out << std::endl << this->getsize();//��������С��Ϣ
	out << std::endl;
	out.close();
}

int RectangleC::getArea()
{
	return ((abs(p1.getx() - p2.getx())) * (abs(p1.gety() - p2.gety())));
}

bool RectangleC::operator<(RectangleC& r_)
{
	return (this->getArea() < r_.getArea());
}

bool RectangleC::operator>(RectangleC& r_)
{
	return (this->getArea() > r_.getArea());
}

bool RectangleC::operator<=(RectangleC& r_)
{
	return (this->getArea() <= r_.getArea());
}

bool RectangleC::operator>=(RectangleC& r_)
{
	return (this->getArea() >= r_.getArea());
}

bool RectangleC::operator==(RectangleC& r_)
{
	return (this->getArea() == r_.getArea());
}

bool RectangleC::operator!=(RectangleC& r_)
{
	return (this->getArea() != r_.getArea());
}

point RectangleC::operator[](const int& index)
{
	if (index == 0)
		return p1;
	else if (index == 1)
		return p2;
	else
		throw std::exception{ "out of range!" };
}

RectangleC& RectangleC::operator=(RectangleC& r_)
{
	this->p1 = r_.p1;
	this->p2 = r_.p2;
	*((*(this->getcolor())).getAOfcolor()) = { (*(r_.getcolor())).getcolor() };
	*(this->getcolor()->getAOfString()) = { r_.getcolor()->getString() };
	*((*(this->getbgcolor())).getAOfcolor()) = { (*(r_.getbgcolor())).getcolor() };
	*(this->getbgcolor()->getAOfString()) = { r_.getbgcolor()->getString() };
	*(this->getAOfsize()) = { (r_.getsize()) };
	*(this->getisfilled()) = { (r_.isfilled()) };
	return *(this);
}

RectangleC::~RectangleC()
{
}

/*triangle::triangle(triangle& t1)
{
	p1 = t1.p1;
	p2 = t1.p2;
	p3 = t1.p3;
	*(this->getcolor()) = *(this->getcolor());
	*(this->getbgcolor()) = *(this->getbgcolor());
	*(this->getAOfsize()) = t1.getsize();
}*/

triangle::triangle() :shape()
{
}

triangle::triangle(point p1_, point p2_, point p3_, string c_, string filled_, string size_, string bgc0lor) : shape(c_, filled_, size_, bgc0lor)
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
	int pt[] = { this->getp1().getx(),this->getp1().gety(), this->getp2().getx(), this->getp2().gety(), this->getp3().getx(), this->getp3().gety() };//���ý��յ��ĵ��������ݴ���һ������
	setcolor((*(this->getcolor())).getcolor());
	if (this->isfilled()) {
		setfillstyle(SOLID_FILL, (*(this->getbgcolor())).getcolor());//��fillployһ��ʹ�õ���亯��
	}
	fillpoly(3, pt);//����һ�������ߣ���������Ϊ������Ԫ��ֵ�������ζ���
}

void triangle::writefile()
{
	fs::path p{ "figure.txt" };
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);
	out << "2" << std::endl
		<< this->getp1().getx() << " " << this->getp1().gety() << " " << this->getp2().getx() << " " << this->getp2().gety() << " " << this->getp3().getx() << " " << this->getp3().gety() << " " << std::endl
		<< (*(this->getcolor())).getString() << " " << this->isfilled();
	if (this->isfilled()) {
		out << " " << (*(this->getbgcolor())).getString();
	}
	out << std::endl << this->getsize();
	out << std::endl;
	out.close();
}

double triangle::getArea()
{
	double e1, e2, e3, p;
	e1 = pow((pow((p1.getx() - p2.getx()), 2.0) + pow((p1.gety() - p2.gety()), 2.0)), 0.5);
	e2 = pow((pow((p1.getx() - p3.getx()), 2.0) + pow((p1.gety() - p3.gety()), 2.0)), 0.5);
	e3 = pow((pow((p3.getx() - p2.getx()), 2.0) + pow((p3.gety() - p2.gety()), 2.0)), 0.5);
	p = 0.5 * (e1 + e2 + e3);
	return (pow((p * (p - e1) * (p - e2) * (p - e3)), 0.5));
}

bool triangle::operator<(triangle& t)
{
	return (this->getArea() < t.getArea());
}

bool triangle::operator>(triangle& t)
{
	return (this->getArea() > t.getArea());
}

bool triangle::operator<=(triangle& t)
{
	return (this->getArea() <= t.getArea());
}

bool triangle::operator>=(triangle& t)
{
	return (this->getArea() >= t.getArea());
}

bool triangle::operator==(triangle& t)
{
	return (this->getArea() == t.getArea());
}

bool triangle::operator!=(triangle& t)
{
	return (this->getArea() != t.getArea());
}

point triangle::operator[](const int& index)
{
	if (index == 0)
		return p1;
	else if (index == 1)
		return p2;
	else if (index == 3)
		return p3;
	else
		throw std::exception{ "out of range!" };
}

triangle& triangle::operator=(triangle& t)
{
	this->p1 = t.p1;
	this->p2 = t.p2;
	this->p3 = t.p3;
	*((*(this->getcolor())).getAOfcolor()) = { (*(t.getcolor())).getcolor() };
	*(this->getcolor()->getAOfString()) = { t.getcolor()->getString() };
	*((*(this->getbgcolor())).getAOfcolor()) = { (*(t.getbgcolor())).getcolor() };
	*(this->getbgcolor()->getAOfString()) = { t.getbgcolor()->getString() };
	*(this->getAOfsize()) = { (t.getsize()) };
	*(this->getisfilled()) = { (t.isfilled()) };
	return *(this);
}

triangle::~triangle()
{
}

/*Line::Line(Line& l)
{
	p1 = l.p1;
	p2 = l.p2;
	*color = *(l.color);//���
	size = l.size;
	(*(shape::getAOnumberObjects()))++;
}*/

Line::Line()
{
	color = { new Color{ "NULL" } };
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

string* Line::getAOfsize()
{
	return &size;
}

double Line::getLength()
{
	return pow((pow(p1.getx() - p2.getx(), 2) + pow(p1.gety() - p2.gety(), 2)), 0.5);
}

bool Line::operator<(Line& l)
{
	return (this->getLength() < l.getLength());
}

bool Line::operator>(Line& l)
{
	return (this->getLength() < l.getLength());
}

bool Line::operator<=(Line& l)
{
	return (this->getLength() < l.getLength());
}

bool Line::operator>=(Line& l)
{
	return (this->getLength() < l.getLength());
}

bool Line::operator==(Line& l)
{
	return (this->getLength() < l.getLength());
}

bool Line::operator!=(Line& l)
{
	return (this->getLength() < l.getLength());
}

point Line::operator[](const int& index)
{
	if (index == 0)
		return p1;
	else if (index == 1)
		return p2;
	else
		throw std::exception{ "out of range!" };
}

Line& Line::operator=(Line& l)
{
	this->p1 = l.p1;
	this->p2 = l.p2;
	*((*(this->getcolor())).getAOfcolor()) = { (*(l.getcolor())).getcolor() };
	*(this->getcolor()->getAOfString()) = { l.getcolor()->getString() };
	*(this->getAOfsize()) = { (l.getsize()) };
	return *(this);
}

void Line::draw()
{
	controller screen1(size);
	setcolor((*(this->getcolor())).getcolor());
	line(this->getp1().getx(), this->getp1().gety(), this->getp2().getx(), this->getp2().gety());//����
}

void Line::writefile()
{
	fs::path p{ "figure.txt" };
	std::ofstream out;
	out.open(p, std::ios::out | std::ios::app);
	out << "4" << std::endl
		<< this->getp1().getx() << " " << this->getp1().gety() << " " << this->getp2().getx() << " " << this->getp2().gety() << std::endl
		<< (*(this->getcolor())).getString() << std::endl;
	out << this->getsize() << std::endl;
	out.close();
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
	*(this->getcolor()) = *(p1.getcolor());//���
	*(this->getbgcolor()) = *(p1.getbgcolor());//���
	*(this->getAOfsize()) = p1.getsize();
}

ploygon::ploygon(string n_, string color_, string filled_, string size_) :shape(color_, filled_, size_)
{
	n = std::stoi(n_);
	for (int i = 0; i < n; i++) {//�����û�����Ķ���������vector�洢��������
		char p_temp[15];
		inputbox_getline("�����붥������", "�����붥������(��(233,233))���س�ȷ�ϣ�", p_temp, 15);
		point p_{ p_temp };
		p.push_back(p_.getx());
		p.push_back(p_.gety());
	}
}

int ploygon::getn()
{
	return n;
}

int* ploygon::getp()//��vectorת�����������鲢����
{
	int* po = new int[p.size()];//ע��sizeof��������������
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