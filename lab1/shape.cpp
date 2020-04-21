#include "shape.h"
#include <graphics.h>
#include "ege.h"
#include <string>
#include "controller.h"
#pragma warning(disable:4996) //����ege�ⱻ���õĺ���

void shape::convertBool(string filled_)//���ַ���ת��Ϊbool���͵ı���
{
	if ('Y' == filled_[0]) {
		filled = true;
	}	
	else if ('N' == filled_[0]) {
		filled = false;
	}
}

shape::shape(string color_, string filled_,string size_)//���ַ���ת����color_t���͵ı���
{
	size = size_;
	color = new Color(color_);
	convertBool(filled_);
	char fc[2];
	if (filled) {//�ж������䣬��Ҫ���û��������ͼ�ε���ɫ
		inputbox_getline("��������Ҫ���ͼ�ε���ɫ", "��������Ҫ���ͼ�ε���ɫ��R�����ɫ��G������ɫ��B������ɫ�������س�ȷ�ϣ�", fc, 2);
		fcolor = new Color{ fc };
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

shape::~shape()
{
	delete color;
	delete fcolor;
}

Circle::Circle(Circle& c)//�������캯��
{
	p = c.p;
	radius = c.radius;
	*(this->getcolor()) = *(c.getcolor());//���
	*(this->getbgcolor()) = *(c.getbgcolor());//���
	*(this->getAOfsize()) = c.getsize();
}

Circle::Circle(point p_, int r_, string s_, string filled_, string size_) :shape{ s_, filled_ ,size_ }//���ý��յ��ַ���������
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

void Circle::draw()
{
	controller screen1(this -> getsize());//����������Ļ�������û��Զ����С
	setcolor((*(this -> getcolor())).getcolor());//����Բ�߽����ɫ
	circle(static_cast<int>(this->getx()), this -> gety(), radius);//��Բ����
	if (this -> isfilled()) {
		setfillcolor(((*this -> getbgcolor())).getcolor());
		floodfill(this -> getx(), this -> gety(), (*(this -> getcolor())).getcolor());
	}//�ж�ͼ���Ƿ���䣬����䣬ʹ��Բ����Ϊfloodfill��һ�������������
}

Circle::~Circle()
{
}


RectangleC::RectangleC(RectangleC& r)
{
	p1 = r.p1;
	p2 = r.p2;
	*(this->getcolor()) = *(r.getcolor());//���
	*(this->getbgcolor()) = *(r.getbgcolor());//���
	*(this->getAOfsize()) = r.getsize();
}

RectangleC::RectangleC(point p1_, point p2_, string s_, string filled_,string size_):shape{s_,filled_,size_}
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
	controller screen1(this -> getsize());
	setcolor((*(this -> getcolor())).getcolor());
	rectangle(this -> getp1().getx(), this -> getp1().gety(), this -> getp2().getx(), this -> getp2().gety());
	if (this -> isfilled()) {
		setfillcolor((*(this -> getbgcolor())).getcolor());
		floodfill((this -> getp1().getx()) + 1, (this -> getp1().gety()) - 2, (*(this -> getcolor())).getcolor());
	}//���������Ͻǵ��������任�������Ϊfloodfill��һ�������������
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

triangle::triangle(point p1_, point p2_, point p3_,string c_,string filled_,string size_):shape(c_,filled_,size_)
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
	controller screen1(this -> getsize());
	int pt[] = { this -> getp1().getx(),this -> getp1().gety(), this -> getp2().getx(), this -> getp2().gety(), this -> getp3().getx(), this -> getp3().gety() };//���ý��յ��ĵ��������ݴ���һ������
	setcolor((*(this -> getcolor())).getcolor());
	if (this -> isfilled()) {
		setfillstyle(SOLID_FILL, (*(this -> getbgcolor())).getcolor());//��fillployһ��ʹ�õ���亯��
	}
	fillpoly(3, pt);//����һ�������ߣ���������Ϊ������Ԫ��ֵ�������ζ���
}

triangle::~triangle()
{
}


Line::Line(Line& l)
{
	p1 = l.p1;
	p2 = l.p2;
	*color = *(l.color);//���
	size = l.size;
}

Line::Line(point p1_, point p2_,string c_,string size_)
{
	p1 = p1_;
	p2 = p2_;
	color = new Color(c_);
	size = size_;
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

void Line::draw()
{
	controller screen1(size);
	setcolor((*(this -> getcolor())).getcolor());
	line(this -> getp1().getx(), this -> getp1().gety(), this -> getp2().getx(), this -> getp2().gety());//����
}

Line::~Line()
{
	delete color;
}

ploygon::ploygon(ploygon& p1)
{
	p = std::vector<int>(p1.p);
	n = p1.n;
	*(this->getcolor()) = *(p1.getcolor());//���
	*(this->getbgcolor()) = *(p1.getbgcolor());//���
	*(this->getAOfsize()) = p1.getsize();
}

ploygon::ploygon(string n_,string color_,string filled_,string size_):shape(color_,filled_,size_)
{
	n = std::stoi(n_);
	for (int i = 0; i < n; i++) {//�����û�����Ķ���������vector�洢��������
		char p_temp[15];
		inputbox_getline("�����붥������", "�����붥������(��(233,233))���س�ȷ�ϣ�",p_temp ,15);
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
	controller screen1(this -> getsize());
	setfillcolor((*(this -> getcolor())).getcolor());
	if (this -> isfilled()) {
		setfillstyle(SOLID_FILL, (*(this -> getcolor())).getcolor());
	}
	fillpoly(this -> getn(), this -> getp());
}

ploygon::~ploygon()
{
	delete[]this -> getp();
}
