#include <stdio.h>
#include <graphics.h>
#include "color.h"

int main()
{
    initgraph(640, 480);

    setfont(18, 0, "宋体");

    int k = 0;
    for (; k != key_esc; ) // key_esc是ege定义的按键常数
    {
        outtextxy(0, 0, "欢迎使用Drawing Board！");
        outtextxy(0, 25, "1.画一个圆");
        outtextxy(0, 50, "2.画一个矩形");
        outtextxy(0, 75, "3.画一条线");
        outtextxy(0, 100, "4.画一个三角形");
        outtextxy(0, 125, "5.退出");
        k = getch();
        switch (k) {
        case 49:
            cleardevice();
            outtextxy(0, 0, "请输入圆心的坐标：");
            char str[100];
            inputbox_getline("请输入", "你爱输入什么就输入什么（回车确认）", str, 100);
            setcolor(EGERGB(0xFC, 0xFC, 0xFC));
            circle(200, 200, 100);
            getch();
            cleardevice();
        }
    }
    closegraph();
    return 0;
}
