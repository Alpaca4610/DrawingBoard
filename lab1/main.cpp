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
    setcaption("Alpaca Drawing Board");
    initgraph(640, 480);
    setfont(18, 0, "宋体"); //设置字体
    int k{0};
    for (; k != key_esc; ) // key_esc是ege定义的按键常数
    {
        outtextxy(100, 0, "欢迎使用Alpaca Drawing Board Ver2.1！");
        outtextxy(170, 25, "1.创建一个圆对象");
        outtextxy(170, 50, "2.创建一个矩形对象");
        outtextxy(170, 75, "3.创建一个三角形对象");
        outtextxy(170, 100, "4.创建一条线对象");
        outtextxy(170, 125, "5.创建一个多边形对象");
        outtextxy(170, 150, "6.自由绘图");
        outtextxy(170, 175, "7.创建一个移动且颜色不断变化的圆");
        outtextxy(170, 200, "8.初始化画板大小");
        outtextxy(170, 225, "9.退出");
        k = getch();
        switch (k) {
        case 49: {
            cleardevice(); //清空之前输出的菜单信息，便于接下来的绘图
            char str[15], r[15], c[3], filled[2],size[15];//创建用于接收inputbox的字符串
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))：(回车确认)", size, 15);
            inputbox_getline("请输入圆心的坐标：", "请输入圆心的坐标(例：(233，233)，符号为英文！)：(回车确认)", str, 15);
            inputbox_getline("请输入圆的半径：", "请输入圆心的半径：(回车确认)", r, 10);
            inputbox_getline("请输入圆的颜色：", "请输入圆的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
            inputbox_getline("该圆是否填充？：", "该圆是否填充？(填充请输入Y，不填充请输入N)：(回车确认)", filled, 2);
            Circle c1{ point{str},std::stoi(r),c, filled };//利用接收的数据创建圆对象
            controller screen1(size);//创建画板屏幕对象让用户自定义大小
            setcolor(c1.getcolor().getcolor());//设置圆边界的颜色
            circle(static_cast<int>(c1.getx()), c1.gety(), std::stoi(r));//画圆函数
            if (c1.isfilled()) {
                setfillcolor(c1.getbgcolor().getcolor());
                floodfill(c1.getx(), c1.gety(), c1.getcolor().getcolor());
            }//判断图形是否填充，若填充，使用圆心作为floodfill的一个参数进行填充
            getch();
            cleardevice();//清屏
            break; }
        case 50: {
            cleardevice();
            char p1[15],p2[15], c[3], filled[2], size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480)符号为英文！)：(回车确认)", size, 15);
            inputbox_getline("请输入矩形左上角顶点的坐标：", "请输入矩形左上角顶点的坐标(例：(233，233)符号为英文！)：(回车确认)", p1, 15);
            inputbox_getline("请输入矩形右上角顶点的坐标：", "请输入矩形右下角顶点的坐标(例：(333，133)符号为英文！)：(回车确认)", p2, 15);
            inputbox_getline("请输入矩形的颜色：", "请输入矩形的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
            inputbox_getline("该矩形是否填充？：", "该矩形是否填充？(填充请输入Y，不填充请输入N)：(回车确认)", filled, 2);
            controller screen1(size);
            RectangleC g1{point(p1),point(p2),c,filled};//利用point类创建矩形对象
            setcolor(g1.getcolor().getcolor());
            rectangle(static_cast<int>(g1.getp1().getx()), static_cast<int>(g1.getp1().gety()), static_cast<int>(g1.getp2().getx()), static_cast<int>(g1.getp2().gety()));
            if (g1.isfilled()) {
                setfillcolor(g1.getbgcolor().getcolor());
                floodfill((g1.getp1().getx())+1, (g1.getp1().gety())-2, g1.getcolor().getcolor());
            }//将矩形左上角的坐标做变换处理后作为floodfill的一个参数进行填充
            getch();
            cleardevice();
            break;
        }        
        case 51: {
            cleardevice();
            char p1[15],p2[15], p3[15],c[3], filled[2],size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))符号为英文！：(回车确认)", size, 15);
            inputbox_getline("请输入三角形第一个顶点的坐标：", "请输入三角形第一个顶点的坐标(例：(233，233))符号为英文！：(回车确认)", p1, 15);
            inputbox_getline("请输入三角形第二个顶点的坐标：", "请输入三角形第二个顶点的坐标(例：(333，400))符号为英文！：(回车确认)", p2, 15);
            inputbox_getline("请输入三角形第三个顶点的坐标：", "请输入三角形第三个顶点的坐标(例：(300，300))符号为英文！：(回车确认)", p3, 15);
            inputbox_getline("请输入三角形的颜色：", "请输入三角形的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
            inputbox_getline("该三角形是否填充？：", "该三角形是否填充？(填充请输入Y，不填充请输入N)：(回车确认)", filled, 2);
            triangle t1{point(p1),point(p2),point(p3),c,filled};//创建一个三角形对象
            controller screen1(size);
            int pt[] = {t1.getp1().getx(),t1.getp1().gety(), t1.getp2().getx(), t1.getp2().gety(), t1.getp3().getx(), t1.getp3().gety() };//利用接收到的点坐标数据创建一个数组
            setcolor(t1.getcolor().getcolor());        
           if (t1.isfilled()) {
                setfillstyle(SOLID_FILL, t1.getbgcolor().getcolor());//与fillploy一起使用的填充函数
            }
            fillpoly(3, pt);//创建一个三条边，顶点坐标为数组中元素值的三角形对象
            getch();
            cleardevice();
            break;
        }
        case 52: {
            cleardevice();
            char p1[15], p2[15], c[3],size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480)符号为英文！)：(回车确认)", size, 15);
            inputbox_getline("请输入线段第一个顶点的坐标：", "请输入线段第一个顶点的坐标(例：(233，233)符号为英文！)：(回车确认)", p1, 15);
            inputbox_getline("请输入线段第二个顶点的坐标：", "请输入线段第二个顶点的坐标(例：(433，433)符号为英文！)：(回车确认)", p2, 15);
            inputbox_getline("请输入线段的颜色：", "请输入线段的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
            controller screen1(size);
            Line l1(point(p1), point(p2), c);//创建线对象
            setcolor(l1.getcolor().getcolor());
            line(l1.getp1().getx(), l1.getp1().gety(), l1.getp2().getx(), l1.getp2().gety());//画线
            getch();
            cleardevice();
            break;
        }
        case 53: {
            cleardevice();
            char color_[2], filled_[2],ns[2],size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480)符号为英文！)：(回车确认)", size, 15);
            inputbox_getline("请输入多边形的边数", "请输入多边形的边数", ns, 2);
            if (std::stoi(ns) <= 2) {//判断用户输入的数据是否合法
                outtext("请输入正确的顶点个数！（n >= 3）");
                getch();
                cleardevice();
                break;
            }
            inputbox_getline("请输入边框的颜色", "请输入边框的颜色(R代表红色，G代表绿色，B代表蓝色))(回车确认)", color_, 2);
            inputbox_getline("该多边形是否填充？：", "该多边形是否填充？(填充请输入Y，不填充请输入N)", filled_, 2);
            ploygon pg1(ns, color_, filled_);//创建多边形对象
            controller screen1(size);
            setfillcolor(pg1.getcolor().getcolor());
            if (pg1.isfilled()) {
                setfillstyle(SOLID_FILL, pg1.getcolor().getcolor());
            }
            fillpoly(pg1.getn(), pg1.getp());
            getch();
            delete[]pg1.getp();
            cleardevice();
            break;
        }        
        case 54: {
            cleardevice();
            char size[15],col[3];
            int x, y;
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))：(回车确认)", size, 15);
            controller screen1(size);
            inputbox_getline("请输入绘图的颜色：", "请输入绘图的颜色(R代表红色，G代表绿色，B代表蓝色，W代表白色))：(回车确认)", col, 3);
            inputbox_getline("按下回车键开始绘图，若要结束绘图，再按任意键", "按下回车键开始绘图，若要结束绘图，再按任意键", size, 3);//给用户缓冲时间
            Color c(col);
            for (; !kbmsg(); delay_fps(300)) {
                mousepos(&x,&y);//获取当前鼠标位置
                putpixel(x, y, c.getcolor());//在鼠标当前位置打点
            }
            cleardevice();
            break;
        }
        case 55: {
            cleardevice();
            int x{ 0 }, y{0};
            char size[15];
            inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))：(回车确认)", size, 15);
            controller screen1(size);
            randomize();
            inputbox_getline("按下回车键开始绘图，若要结束绘图，再按任意键", "按下回车键开始绘图，若要结束绘图，再按任意键", size, 3);//给用户缓冲时间
            for (; !kbmsg(); delay_fps(300)) {
                x = (x + 1) % (static_cast<int>(screen1.getpoint().getx()));
                y = (y + 1) % (static_cast<int>(screen1.getpoint().gety()));
                cleardevice();
                setfillcolor(EGERGB(random(255), random(255),random(255)));
                fillellipse(x + 100, y+100, 100, 100);
            }
            cleardevice();
            break;
        }
        case 56: {
            initgraph(640, 480);//将画板设置成初始大小
            setcolor(LIGHTGRAY);//将绘图颜色设置成默认颜色
            outtextxy(320, 240, "初始化完成！");
            break;
        }
        case 57:
            exit(0);
            break;

        }
    }
    closegraph();
    return 0;
}
