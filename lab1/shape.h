#pragma once
#include "Coordinate.h"
#include "color.h"
#include <vector>
using std::string;

class shape {
private:
	Color* color;
	Color* fcolor;
	bool filled{ false };
	string size;
	static int numOfObjects;
public:
	void convertBool(string);
	shape() = default;
	shape(string, string, string);
	bool isfilled();
	void setfilled(bool);
	Color* getcolor();
	Color* getbgcolor();
	virtual void draw() = 0;
	string getsize();
	string* getAOfsize();
	static int getnumberObjects();
	static int* getAOnumberObjects();
	virtual void writefile() = 0;
	~shape();
};

class Circle :public shape {
private:
	point p;
	int radius;
public:
	Circle(Circle&);
	Circle(point, int, string, string, string);
	int getx();
	int gety();
	int getRadius();
	virtual void draw() override;
	virtual void writefile() override;
	~Circle();
};

class RectangleC :public shape {
private:
	point p1, p2;
public:
	RectangleC(RectangleC&);
	RectangleC(point, point, string, string, string);
	point getp1();
	point getp2();
	virtual void draw() override;
	virtual void writefile() override;
	~RectangleC();
};

class Line {
private:
	point p1, p2;
	Color* color;
	string size;
	//static int numOfObjects;
public:
	Line(Line&);
	Line(point, point, string, string);
	Color* getcolor();
	point getp1();
	point getp2();
	string getsize();
	void draw();
	~Line();
};

class triangle :public shape {
private:
	point p1, p2, p3;
public:
	triangle(triangle&);
	triangle(point, point, point, string, string, string);
	point getp1();
	point getp2();
	point getp3();
	virtual void draw() override;
	virtual void writefile() override;
	~triangle();
};

class ploygon :public shape {
private:
	std::vector<int> p;
	int n;
public:
	ploygon(ploygon&);
	ploygon(string, string, string, string);
	int getn();
	int* getp();
	virtual void draw() override;
	virtual void writefile() override;
	~ploygon();
};
