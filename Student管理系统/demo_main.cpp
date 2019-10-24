/***********************************************************************
项目名称：学生管理系统
程序文件：demo_main.cpp
开发工具：VS2015		(数据结构算法分析与设计，链表、排序)
项目功能：学生管理系统，输入、删除、查询、修改、输出、排序等
**********************************************************************/

#include"StudentMessage.h"
#include<string.h>		//处理字符
#include<fstream>		//处理文件
#include<conio.h>		//getch()
#include<iostream>
using namespace std;

int main()
{
	int x, i = 0;
	bool quit = false;
	StudentMessage score;
	cout << "请按任意键继续..."<< endl;
	_getch();
	while(!quit){
		system("CLS");
		score.ShowMenu();
		cout << "请选择：" << endl;
		cin >> x;
		switch (x)
		{
		case 0:quit = true; break;
		case 1:score.AddItem(); break;
		case 2:score.Display(); break;
		case 3:score.Find(); break;
		case 4: score.Sort(); break;
		case 5:score.CorrectItem(); break;
		case 6:score.RemoveItem();break;	
	/*	default:
			break;*/
		}
	}

	system("pause");
	return 0;
}