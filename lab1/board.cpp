#include <stdio.h>
#include <graphics.h>
#include "color.h"
#include "Coordinate.h"
#include <string>
#include "shape.h"
#include "controller.h"
#include "ege.h"
#include <filesystem>
#include <fstream>
int shape::numOfObjects{ 0 };

int main()
{
	setcaption("Alpaca Drawing Board");
	initgraph(640, 480);
	setfont(18, 0, "宋体"); //设置字体
	int k{ 0 };
	std::vector<Circle*> cStore;
	std::vector<RectangleC*> rStore;
	std::vector<triangle*> tStore;
	std::vector<Line*> LStore;
	std::vector<ploygon*> pStore;

	for (; k != key_esc; ) // key_esc是ege定义的按键常数
	{
		setcolor(LIGHTGRAY);
		cleardevice();
		outtextxy(125, 0, "欢迎使用Alpaca Drawing Board Ver4.3！");
		outtextxy(170, 25, "1.圆形绘图菜单");
		outtextxy(170, 50, "2.矩形绘图菜单");
		outtextxy(170, 75, "3.三角形绘图菜单");
		outtextxy(170, 100, "4.线段绘图菜单");
		outtextxy(170, 125, "5.多边形绘图菜单");
		outtextxy(170, 150, "6.导出图形对象参数保存至文件");
		outtextxy(170, 175, "7.从文件中导入图形对象参数");
		outtextxy(170, 200, "8.查看当前所有图形对象个数");
		outtextxy(170, 225, "9.自由绘图");
		outtextxy(170, 250, "0.退出");
		k = getch();
		switch (k) {
		case 49: {
			cleardevice(); //清空之前输出的菜单信息，便于接下来的绘图
			int cmenu1{ 0 };
			for (; cmenu1 != 53; )
			{
				setcolor(LIGHTGRAY);
				outtextxy(170, 0, "1.创建一个圆对象");
				outtextxy(170, 25, "2.查看当前已创建圆对象的参数");
				outtextxy(170, 50, "3.绘制存储的圆对象");
				outtextxy(170, 75, "4.删除某个圆对象");
				outtextxy(170, 100, "5.返回主菜单");
				cmenu1 = getch();
				switch (cmenu1) {
				case 49: {
					char str[15], r[15], c[3], filled[2], size[15];//创建用于接收inputbox的字符串
					inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))：(回车确认)", size, 15);
					inputbox_getline("请输入圆心的坐标：", "请输入圆心的坐标(例：(233，233)，符号为英文！)：(回车确认)", str, 15);
					inputbox_getline("请输入圆的半径：", "请输入圆心的半径：(回车确认)", r, 10);
					inputbox_getline("请输入圆的颜色：", "请输入圆的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
					inputbox_getline("该圆是否填充？：", "该圆是否填充？(填充请输入Y，不填充请输入N)：(回车确认)", filled, 2);
					cStore.push_back(new Circle{ point{str}, std::stoi(r), c, filled, size });//利用接收的数据创建圆对象;
					cleardevice();
					outtextxy(100, 0, "创建成功！");
					getch();
					cleardevice();
					break;
				}
				case 50: {
					cleardevice();
					if (cStore.size() == 0) {
						outtextxy(100, 0, "对象列表为空！");
						getch();
						cleardevice();
						break;
					}
					initgraph(1200, 1200);
					int j = 0;
					char temp[300] = { "" };
					for (auto i : cStore) {
						sprintf_s(temp, "编号：%d  半径：%d   坐标：(%d,%d)  边框颜色：%s   是否填充：%d   填充颜色：%s   画板大小：%s", j, (*i).getRadius(), (*i).getx(), (*i).gety(), (*i).getcolor()->getString().c_str(), (*i).isfilled(), (*i).getbgcolor()->getString().c_str(), (*i).getsize().c_str());
						outtextxy(0, 25 * j, temp);
						j++;
					}
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 51: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入需要绘制的圆的编号：", "请输入需要绘制的圆的编号：(回车确认)", id, 2);
					if ((std::stoi(id) > cStore.size()) || cStore.size() == 0) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					cStore[std::stoi(id)]->draw();
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 52: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入删除的圆编号：", "请输入需要删除的圆编号：(回车确认)", id, 2);
					if (std::stoi(id) > cStore.size()) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					delete cStore[std::stoi(id)];
					cStore.erase(cStore.begin() + std::stoi(id));
					outtextxy(100, 0, "清除成功！");
					char temp[100];
					sprintf_s(temp, "目前有%d个圆形对象", cStore.size());
					outtextxy(100, 50, temp);
					getch();
					cleardevice();
				}
				}
			}
			cleardevice();//清屏
			break; }
		case 50: {
			cleardevice(); //清空之前输出的菜单信息，便于接下来的绘图
			int cmenu2{ 0 };
			for (; cmenu2 != 53; )
			{
				setcolor(LIGHTGRAY);
				outtextxy(170, 0, "1.创建一个矩形对象");
				outtextxy(170, 25, "2.查看当前已创建矩形对象的参数");
				outtextxy(170, 50, "3.绘制存储的矩形对象");
				outtextxy(170, 75, "4.删除某个矩形对象");
				outtextxy(170, 100, "5.返回主菜单");
				cmenu2 = getch();
				switch (cmenu2) {
				case 49: {
					cleardevice();
					char p1[15], p2[15], c[3], filled[2], size[15];
					inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480)符号为英文！)：(回车确认)", size, 15);
					inputbox_getline("请输入矩形左上角顶点的坐标：", "请输入矩形左上角顶点的坐标(例：(233，233)符号为英文！)：(回车确认)", p1, 15);
					inputbox_getline("请输入矩形右下角顶点的坐标：", "请输入矩形右下角顶点的坐标(例：(333，133)符号为英文！)：(回车确认)", p2, 15);
					inputbox_getline("请输入矩形的颜色：", "请输入矩形的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
					inputbox_getline("该矩形是否填充？：", "该矩形是否填充？(填充请输入Y，不填充请输入N)：(回车确认)", filled, 2);
					rStore.push_back(new RectangleC{ point(p1),point(p2),c,filled,size });//利用point类创建矩形对象
					cleardevice();
					outtextxy(100, 0, "创建成功！");
					getch();
					cleardevice();
					break;
				}
				case 50: {
					cleardevice();
					if (rStore.size() == 0) {
						outtextxy(100, 0, "对象列表为空！");
						getch();
						cleardevice();
						break;
					}
					initgraph(1200, 1200);
					int j = 0;
					char temp[200];
					for (auto i : rStore) {
						sprintf_s(temp, "编号：%d   左上角坐标：%s  右上角坐标：%s  边框颜色：%s   是否填充：%d   填充颜色：%s   画板大小：%s", j, i->getp1().getpS().c_str(), i->getp2().getpS().c_str(), (*i).getcolor()->getString().c_str(), (*i).isfilled(), (*i).getbgcolor()->getString().c_str(), (*i).getsize().c_str());
						outtextxy(0, 25 * j, temp);
						j++;
					}
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 51: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入需要绘制的矩形的编号：", "请输入需要绘制的矩形的编号：(回车确认)", id, 2);
					if ((std::stoi(id) > rStore.size()) || rStore.size() == 0) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					rStore[std::stoi(id)]->draw();
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 52: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入删除的矩形编号：", "请输入需要删除的矩形编号：(回车确认)", id, 2);
					if (std::stoi(id) > rStore.size()) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					delete rStore[std::stoi(id)];
					rStore.erase(rStore.begin() + std::stoi(id));
					outtextxy(100, 0, "清除成功！");
					char temp[100];
					sprintf_s(temp, "目前有%d个矩形对象", rStore.size());
					outtextxy(100, 50, temp);
					getch();
					cleardevice();
				}
				}
			}
			cleardevice();//清屏
			break; }

		case 51: {
			cleardevice();
			int cmenu3{ 0 };
			for (; cmenu3 != 53; )
			{
				setcolor(LIGHTGRAY);
				outtextxy(170, 0, "1.创建一个三角形对象");
				outtextxy(170, 25, "2.查看当前已创建三角形对象的参数");
				outtextxy(170, 50, "3.绘制存储的三角形对象");
				outtextxy(170, 75, "4.删除某个三角形对象");
				outtextxy(170, 100, "5.返回主菜单");
				cmenu3 = getch();
				switch (cmenu3) {
				case 49: {
					cleardevice();
					char p1[15], p2[15], p3[15], c[3], filled[2], size[15];
					inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))符号为英文！：(回车确认)", size, 15);
					inputbox_getline("请输入三角形第一个顶点的坐标：", "请输入三角形第一个顶点的坐标(例：(233，233))符号为英文！：(回车确认)", p1, 15);
					inputbox_getline("请输入三角形第二个顶点的坐标：", "请输入三角形第二个顶点的坐标(例：(333，400))符号为英文！：(回车确认)", p2, 15);
					inputbox_getline("请输入三角形第三个顶点的坐标：", "请输入三角形第三个顶点的坐标(例：(300，300))符号为英文！：(回车确认)", p3, 15);
					inputbox_getline("请输入三角形的颜色：", "请输入三角形的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
					inputbox_getline("该三角形是否填充？：", "该三角形是否填充？(填充请输入Y，不填充请输入N)：(回车确认)", filled, 2);
					tStore.push_back(new triangle{ point(p1),point(p2),point(p3),c,filled,size });//创建一个三角形对象
					cleardevice();
					outtextxy(100, 0, "创建成功！");
					getch();
					cleardevice();
					break;
				}
				case 50: {
					cleardevice();
					if (tStore.size() == 0) {
						outtextxy(100, 0, "对象列表为空！");
						getch();
						cleardevice();
						break;
					}
					initgraph(1200, 1200);
					int j = 0;
					char temp[200];
					for (auto i : tStore) {
						sprintf_s(temp, "编号：%d   坐标1：%s  坐标2：%s  坐标3：%s  边框颜色：%s   是否填充：%d   填充颜色：%s   画板大小：%s", j, i->getp1().getpS().c_str(), i->getp2().getpS().c_str(), i->getp3().getpS().c_str(), (*i).getcolor()->getString().c_str(), (*i).isfilled(), (*i).getbgcolor()->getString().c_str(), (*i).getsize().c_str());
						outtextxy(0, 25 * j, temp);
						j++;
					}
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 51: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入需要绘制的三角形的编号：", "请输入需要绘制的三角形的编号：(回车确认)", id, 2);
					if ((std::stoi(id) > tStore.size()) || tStore.size() == 0) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					tStore[std::stoi(id)]->draw();
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 52: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入删除的三角形编号：", "请输入需要删除的三角形编号：(回车确认)", id, 2);
					if (std::stoi(id) > tStore.size()) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					delete tStore[std::stoi(id)];
					tStore.erase(tStore.begin() + std::stoi(id));
					outtextxy(100, 0, "清除成功！");
					char temp[100];
					sprintf_s(temp, "目前有%d个三角形对象", tStore.size());
					outtextxy(100, 50, temp);
					getch();
					cleardevice();
				}
				}
			}
			break;
		}

		case 52: {
			cleardevice();
			int cmenu4{ 0 };
			for (; cmenu4 != 53; )
			{
				setcolor(LIGHTGRAY);
				outtextxy(170, 0, "1.创建一个线段对象");
				outtextxy(170, 25, "2.查看当前已创建线段对象的参数");
				outtextxy(170, 50, "3.绘制存储的线段对象");
				outtextxy(170, 75, "4.删除某个线段对象");
				outtextxy(170, 100, "5.返回主菜单");
				cmenu4 = getch();
				switch (cmenu4) {
				case 49: {
					cleardevice();
					char p1[15], p2[15], c[3], size[15];
					inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480)符号为英文！)：(回车确认)", size, 15);
					inputbox_getline("请输入线段第一个顶点的坐标：", "请输入线段第一个顶点的坐标(例：(233，233)符号为英文！)：(回车确认)", p1, 15);
					inputbox_getline("请输入线段第二个顶点的坐标：", "请输入线段第二个顶点的坐标(例：(433，433)符号为英文！)：(回车确认)", p2, 15);
					inputbox_getline("请输入线段的颜色：", "请输入线段的颜色(R代表红色，G代表绿色，B代表蓝色))：(回车确认)", c, 3);
					LStore.push_back(new Line(point(p1), point(p2), c, size));//创建线对象
					cleardevice();
					outtextxy(100, 0, "创建成功！");
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 50: {
					cleardevice();
					if (LStore.size() == 0) {
						outtextxy(100, 0, "对象列表为空！");
						getch();
						cleardevice();
						break;
					}
					initgraph(1200, 1200);
					int j = 0;
					char temp[200];
					for (auto i : LStore) {
						sprintf_s(temp, "编号：%d   坐标1：%s  坐标2：%s   边框颜色：%s   画板大小：%s", j, i->getp1().getpS().c_str(), i->getp2().getpS().c_str(), (*i).getcolor()->getString().c_str(), (*i).getsize().c_str());
						outtextxy(0, 25 * j, temp);
						j++;
					}
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 51: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入需要绘制的线段的编号：", "请输入需要绘制的线段的编号：(回车确认)", id, 2);
					if ((std::stoi(id) > LStore.size()) || LStore.size() == 0) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					LStore[std::stoi(id)]->draw();
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 52: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入删除的线段编号：", "请输入需要删除的线段编号：(回车确认)", id, 2);
					if (std::stoi(id) > LStore.size()) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					delete LStore[std::stoi(id)];
					LStore.erase(LStore.begin() + std::stoi(id));
					outtextxy(100, 0, "清除成功！");
					char temp[100];
					sprintf_s(temp, "目前有%d个线段对象", LStore.size());
					outtextxy(100, 50, temp);
					getch();
					cleardevice();
				}
				}
			}
			break;
		}

		case 53: {
			cleardevice();
			int cmenu5{ 0 };
			for (; cmenu5 != 53; )
			{
				setcolor(LIGHTGRAY);
				outtextxy(170, 0, "1.创建一个多边形对象");
				outtextxy(170, 25, "2.查看当前已创建多边形对象的参数");
				outtextxy(170, 50, "3.绘制存储的多边形对象");
				outtextxy(170, 75, "4.删除某个多边形对象");
				outtextxy(170, 100, "5.返回主菜单");
				cmenu5 = getch();
				switch (cmenu5) {
				case 49: {
					cleardevice();
					char color_[2], filled_[2], ns[2], size[15];
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
					ploygon* pg1 = new ploygon(ns, color_, filled_, size);//创建多边形对象
					cleardevice();
					outtextxy(100, 0, "创建成功！");
					getch();
					cleardevice();
					break;
				}
				case 50: {
					cleardevice();
					if (pStore.size() == 0) {
						outtextxy(100, 0, "对象列表为空！");
						getch();
						cleardevice();
						break;
					}
					initgraph(1200, 1200);
					int j = 0;
					char temp[200];
					for (auto i : pStore) {
						sprintf_s(temp, "编号：%d   边数：%d   边框颜色：%s   是否填充：%d   填充颜色：%s   画板大小：%s", j, i->getn(), (*i).getcolor()->getString().c_str(), (*i).isfilled(), (*i).getbgcolor()->getString().c_str(), (*i).getsize().c_str());
						outtextxy(0, 25 * j, temp);
						j++;
					}
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 51: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入需要绘制的多边形的编号：", "请输入需要绘制的多边形的编号：(回车确认)", id, 2);
					if (std::stoi(id) > pStore.size()) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					pStore[std::stoi(id)]->draw();
					getch();
					cleardevice();
					initgraph(640, 480);
					break;
				}
				case 52: {
					cleardevice();
					char id[2];
					inputbox_getline("请输入删除的多边形编号：", "请输入需要删除的多边形编号：(回车确认)", id, 2);
					if ((std::stoi(id) > pStore.size()) || pStore.size() == 0) {
						outtextxy(100, 0, "请输入正确的编号！");
						getch();
						cleardevice();
						break;
					}
					delete pStore[std::stoi(id)];
					pStore.erase(pStore.begin() + std::stoi(id));
					outtextxy(100, 0, "清除成功！");
					char temp[100];
					sprintf_s(temp, "目前有%d个多边形对象", pStore.size());
					outtextxy(100, 50, temp);
					getch();
					cleardevice();
				}
				}
			}
			break;
		}

		case 54: {
			cleardevice();
			outtextxy(100, 0, "开始将数据保存成文件......");
			outtextxy(75, 25, "支持圆、三角形、矩形、线段对象参数的导出");
			int num = 0;
			for (auto i : cStore) {
				(*i).writefile();
				num++;
			}
			for (auto i : tStore) {
				(*i).writefile();
				num++;
			}
			for (auto i : rStore) {
				(*i).writefile();
				num++;
			}
			for (auto i : LStore) {
				(*i).writefile();
				num++;
			}
			char notice[100];
			sprintf_s(notice, "已导出%d个对象！按下任意键返回主菜单！", num);
			outtextxy(100, 50, notice);

			getch();
			cleardevice();
			break;
		}
		case 55: {
			cleardevice();
			outtextxy(100, 25, "现在开始从文件读入数据......");
			std::ifstream in;
			in.open("figure.txt");
			int temp;
			int num = 0;
			while (in.peek() != EOF) {//判断是否到达参数列表的尾部，若未到达，则循环存取数据
				num++;//计数
				in >> temp;//读取图形ID
				in.get();//游标进入下一行
				switch (temp) {//不同的图形ID执行不同的存取操作
				case 1: {
					int px, py, radius;
					string color_, filled{ "N" }, bgcolor, size_;
					bool isfilled;
					char point_[15], temp_[1];
					in >> px >> py >> radius;//存取图形的特征信息
					in.get();//进入下一行
					in >> color_ >> isfilled;//读取图形的填充状态信息
					if (isfilled) {//判断图形是否填充，若填充，则接着读取填充颜色信息
						filled = "Y";
						in >> bgcolor;
						if (bgcolor != "R" && bgcolor != "G" && bgcolor != "B") {
							inputbox_getline("发生错误！", "读取一个对象的颜色时发生错误！使用默认颜色:红色 在输入框中回车退出", temp_, 1);
							bgcolor = "R";
						}
					}
					in.get();//进入下一行
					if (color_ != "R" && color_ != "G" && color_ != "B") {//判断图形颜色数据是否合法
						inputbox_getline("发生错误！", "读取一个对象的边框颜色时发生错误！使用默认颜色:红色 在输入框中回车退出", temp_, 1);//使用输入框的形式提醒用户
						color_ = "R";//使用默认颜色：红色
					}
					in >> size_;//读取画板大小信息
					in.get();
					sprintf_s(point_, "(%d,%d)", px, py);
					if (isfilled) {//使用从文件读取的信息，利用构造函数创建对象
						cStore.push_back(new Circle{ point{point_}, radius, color_, filled, size_,bgcolor });
					}
					else {
						cStore.push_back(new Circle{ point{point_}, radius, color_, filled, size_ });
					}
					break;
				}
				case 2: {
					char p1[10], p2[10], p3[10], temp_[1];
					string color_, filled{ "N" }, bgcolor, size_;
					bool isfilled;
					int p1x, p1y, p2x, p2y, p3x, p3y;
					in >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
					in.get();
					in >> color_ >> isfilled;
					if (isfilled) {
						filled = "Y";
						in >> bgcolor;
						if (bgcolor != "R" && bgcolor != "G" && bgcolor != "B") {
							inputbox_getline("发生错误！", "读取一个对象的颜色时发生错误！使用默认颜色:红色 在输入框中回车退出", temp_, 1);
							bgcolor = { "R" };
						}
					}
					in.get();
					if (color_ != "R" && color_ != "G" && color_ != "B") {
						inputbox_getline("发生错误！", "读取一个对象的颜色时发生错误！使用默认颜色：红色 在输入框中回车退出", temp_, 1);
						color_ = { "R" };
					}
					in >> size_;
					in.get();
					sprintf_s(p1, "(%d,%d)", p1x, p1y);
					sprintf_s(p2, "(%d,%d)", p2x, p2y);
					sprintf_s(p3, "(%d,%d)", p3x, p3y);
					if (isfilled) {
						filled = "Y";
						tStore.push_back(new triangle{ point(p1),point(p2),point(p3),color_,filled,size_ ,bgcolor });
					}
					else {
						tStore.push_back(new triangle{ point(p1),point(p2),point(p3),color_,filled,size_ });
					}
					break;
				}
				case 3: {
					int p1x, p1y, p2x, p2y;
					string color_, filled{ "N" }, bgcolor, size_;
					bool isfilled;
					char p1[10], p2[10], temp_[1];
					in >> p1x >> p1y >> p2x >> p2y;
					in.get();
					in >> color_ >> isfilled;
					if (isfilled) {
						filled = "Y";
						in >> bgcolor;
						if (bgcolor != "R" && bgcolor != "G" && bgcolor != "B") {
							inputbox_getline("发生错误！", "读取一个对象的颜色时发生错误！使用默认颜色:红色 在输入框中回车退出", temp_, 1);
							bgcolor = { "R" };
						}
					}
					in.get();
					if (color_ != "R" && color_ != "G" && color_ != "B") {
						inputbox_getline("发生错误！", "读取一个对象的颜色时发生错误！使用默认颜色：红色 在输入框中回车退出", temp_, 1);
						color_ = { "R" };
					}
					in >> size_;
					in.get();
					sprintf_s(p1, "(%d,%d)", p1x, p1y);
					sprintf_s(p2, "(%d,%d)", p2x, p2y);
					if (isfilled) {
						rStore.push_back(new RectangleC{ point(p1),point(p2),color_,filled,size_ ,bgcolor });
					}
					else {
						rStore.push_back(new RectangleC{ point(p1),point(p2),color_,filled,size_ });
					}
					break;
				}
				case 4: {
					int p1x, p1y, p2x, p2y;
					string color_, size_;
					char p1[10], p2[10], temp_[1];
					in >> p1x >> p1y >> p2x >> p2y;
					in.get();
					in >> color_;
					in.get();
					if (color_ != "R" && color_ != "G" && color_ != "B") {
						inputbox_getline("发生错误！", "读取一个对象的颜色时发生错误！使用默认颜色：红色 在输入框中回车退出", temp_, 1);
						color_ = { "R" };
					}
					in >> size_;
					in.get();
					sprintf_s(p1, "(%d,%d)", p1x, p1y);
					sprintf_s(p2, "(%d,%d)", p2x, p2y);
					LStore.push_back(new Line(point(p1), point(p2), color_, size_));
					break;
				}
				}
			}
			char notice[100];
			sprintf_s(notice, "已导入%d个对象！按下任意键返回主菜单！", num);
			outtextxy(100, 50, notice);
			getch();
			cleardevice();
			in.close();
			break;
		}

			   /*
					   case 55: {
						   cleardevice();
						   int x{ 0 }, y{ 0 };
						   char size[15];
						   inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))：(回车确认)", size, 15);
						   controller screen1(size);
						   randomize();
						   inputbox_getline("按下回车键开始绘图，若要结束绘图，再按任意键", "按下回车键开始绘图，若要结束绘图，再按任意键", size, 3);//给用户缓冲时间
						   for (; !kbmsg(); delay_fps(300)) {
							   x = (x + 1) % (static_cast<int>(screen1.getpoint().getx()));
							   y = (y + 1) % (static_cast<int>(screen1.getpoint().gety()));
							   cleardevice();
							   setfillcolor(EGERGB(random(255), random(255), random(255)));
							   fillellipse(x + 100, y + 100, 100, 100);
						   }
						   cleardevice();
						   break;
					   }
			   */

		case 56: {
			cleardevice();
			char temp[50];
			sprintf_s(temp, "当前一共有%d个对象", shape::getnumberObjects());
			outtextxy(100, 0, temp);
			getch();
			cleardevice();
			break;
		}

		case 57: {
			cleardevice();
			char size[15], col[3];
			int x, y;
			inputbox_getline("请输入需要创建的画板大小：", "请输入需要创建的画板大小：(例：(640，480))：(回车确认)", size, 15);
			controller screen1(size);
			inputbox_getline("请输入绘图的颜色：", "请输入绘图的颜色(R代表红色，G代表绿色，B代表蓝色，W代表白色))：(回车确认)", col, 3);
			inputbox_getline("按下回车键开始绘图，若要结束绘图，再按任意键", "按下回车键开始绘图，若要结束绘图，再按任意键", size, 3);//给用户缓冲时间
			Color c(col);
			for (; !kbmsg(); delay_fps(300)) {
				mousepos(&x, &y);//获取当前鼠标位置
				putpixel(x, y, c.getcolor());//在鼠标当前位置打点
			}
			cleardevice();
			initgraph(640, 480);
			break;
		}

		case 48: {
			exit(0);
			break; }
		}
	}
	ege::closegraph();
	return 0;
}