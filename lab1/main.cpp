#include <stdio.h>
#include <graphics.h>
#include "color.h"
#include "Coordinate.h"
#include <string>
#include "shape.h"
#include "controller.h"
#pragma warning(disable:4996) //启用ege库被禁用的函数

int main()
{
    initgraph(640, 480);
    setfont(18, 0, "宋体");
    int k = 0;
    for (; k != key_esc; ) // key_esc是ege定义的按键常数
    {
        outtextxy(100, 0, "欢迎使用NMSL Drawing Board Ver1.1！");
        outtextxy(170, 25, "1.创建一个圆对象");
        outtextxy(170, 50, "2.创建一个矩形对象");
        outtextxy(170, 75, "3.创建一个三角形对象");
        outtextxy(170, 100, "4.创建一条线对象");
        outtextxy(170, 125, "5.初始化画板大小");
        outtextxy(170, 150, "6.退出");
        k = getch();
        switch (k) {
        case 49: {
            cleardevice();
            char str[15], r[15], c[3], filled[2],size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：（例：（640，480））：（回车确认）", size, 15);
            inputbox_getline("请输入圆心的坐标：", "请输入圆心的坐标（例：（233，233））：（回车确认）", str, 15);
            inputbox_getline("请输入圆的半径：", "请输入圆心的半径：（回车确认）", r, 10);
            inputbox_getline("请输入圆的颜色：", "请输入圆的颜色（R代表红色，G代表绿色，B代表蓝色））：（回车确认）", c, 3);
            inputbox_getline("该圆是否填充？：", "该圆是否填充？（填充请输入Y，不填充请输入N）：（回车确认）", filled, 2);
            controller screen1(size);
            Circle c1{ point{str},std::stod(r),c, filled };
            setcolor(c1.getcolor().getcolor());
            circle(static_cast<int>(c1.getx()), static_cast<int>(c1.gety()), std::stod(r));
            if (c1.isfilled()) {
                setfillcolor(c1.getbgcolor().getcolor());
                floodfill(c1.getx(), c1.gety(), c1.getcolor().getcolor());
            }
            getch();
            cleardevice();
            break; }
        case 50: {
            cleardevice();
            char p1[15],p2[15], c[3], filled[2], size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：（例：（640，480））：（回车确认）", size, 15);
            inputbox_getline("请输入矩形左上角顶点的坐标：", "请输入矩形左上角顶点的坐标（例：（233，233））：（回车确认）", p1, 15);
            inputbox_getline("请输入矩形右上角顶点的坐标：", "请输入矩形右下角顶点的坐标（例：（333，133））：（回车确认）", p2, 15);
            inputbox_getline("请输入矩形的颜色：", "请输入矩形的颜色（R代表红色，G代表绿色，B代表蓝色））：（回车确认）", c, 3);
            inputbox_getline("该矩形是否填充？：", "该矩形是否填充？（填充请输入Y，不填充请输入N）：（回车确认）", filled, 2);
            controller screen1(size);
            RectangleC g1{point(p1),point(p2),c,filled};
            setcolor(g1.getcolor().getcolor());
            rectangle(static_cast<int>(g1.getp1().getx()), static_cast<int>(g1.getp1().gety()), static_cast<int>(g1.getp2().getx()), static_cast<int>(g1.getp2().gety()));
            if (g1.isfilled()) {
                setfillcolor(g1.getbgcolor().getcolor());
                floodfill((g1.getp1().getx())+1, (g1.getp1().gety())-2, g1.getcolor().getcolor());
            }
            getch();
            cleardevice();
            break;
        }        
        case 51: {
            cleardevice();
            char p1[15],p2[15], p3[15],c[3], filled[2],size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：（例：（640，480））：（回车确认）", size, 15);
            inputbox_getline("请输入三角形第一个顶点的坐标：", "请输入三角形第一个顶点的坐标（例：（233，233））：（回车确认）", p1, 15);
            inputbox_getline("请输入三角形第二个顶点的坐标：", "请输入三角形第二个顶点的坐标（例：（333，400））：（回车确认）", p2, 15);
            inputbox_getline("请输入三角形第三个顶点的坐标：", "请输入三角形第三个顶点的坐标（例：（300，300））：（回车确认）", p3, 15);
            inputbox_getline("请输入三角形的颜色：", "请输入三角形的颜色（R代表红色，G代表绿色，B代表蓝色））：（回车确认）", c, 3);
            inputbox_getline("该三角形是否填充？：", "该三角形是否填充？（填充请输入Y，不填充请输入N）：（回车确认）", filled, 2);
            controller screen1(size);
            triangle t1{point(p1),point(p2),point(p3),c,filled};
            int pt[] = {t1.getp1().getx(),t1.getp1().gety(), t1.getp2().getx(), t1.getp2().gety(), t1.getp3().getx(), t1.getp3().gety() };
            setcolor(t1.getcolor().getcolor());        
           if (t1.isfilled()) {
                setfillstyle(SOLID_FILL, BLUE);
            }
            fillpoly(3, pt);
            getch();
            cleardevice();
            break;
        }
        case 52: {
            cleardevice();
            char p1[15], p2[15], c[3],size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：（例：（640，480））：（回车确认）", size, 15);
            inputbox_getline("请输入线段第一个顶点的坐标：", "请输入线段第一个顶点的坐标（例：（233，233））：（回车确认）", p1, 15);
            inputbox_getline("请输入线段第二个顶点的坐标：", "请输入线段第二个顶点的坐标（例：（433，433））：（回车确认）", p2, 15);
            inputbox_getline("请输入线段的颜色：", "请输入线段的颜色（R代表红色，G代表绿色，B代表蓝色））：（回车确认）", c, 3);
            controller screen1(size);
            Line l1(point(p1), point(p2), c);
            setcolor(l1.getcolor().getcolor());
            line(l1.getp1().getx(), l1.getp1().gety(), l1.getp2().getx(), l1.getp2().gety());
            getch();
            cleardevice();
            break;
        }
        case 53: {
            initgraph(640, 480);
            setcolor(LIGHTGRAY);
            outtextxy(320, 240, "初始化完成！");
            break;
        }
        case 54:
            exit(0);
            break;

        }
    }
    closegraph();
    return 0;
}
