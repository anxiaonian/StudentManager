#ifndef StudentMessage_H
#define StudentMessage_H

#include<fstream>		//处理文件
#include<conio.h>		//_getch()
#include<iostream>
using namespace std;


//定义学生类
class Student {
public:
	
	char name[20];		//姓名
	char ID[20];		//学号
	int CNum;			//语文分数
	int MathNum;		//数学分数
	int EnglishNum;		//英语分数
	int Sum;			//学生总分数

	Student *next;


void InputData() {
	
	cout << "\t\t请输入学生姓名：";		cin >> name;
//	cout << "\t\t请输入学生学号：";		cin >> ID;
	cout << "\t\t请输入学生语文分数：";	cin >> CNum;
	cout << "\t\t请输入学生数学分数：";	cin >> MathNum;
	cout << "\t\t请输入学生英语分数：";	cin >> EnglishNum;
	Sum = CNum + MathNum + EnglishNum;
	cout << "\t\t总分为" << Sum << endl;
}
//读取文件
void Readfile(istream &in) {
	in >> name >> ID >> CNum >> MathNum >> EnglishNum >> Sum;
}

//输出数据
void ShowData() {
	cout << "\t姓名：" << name << " " << "\t学号：" << ID <<  " " 
		<< "\t语文分数：" << CNum << " " << "\t数学分数：" << MathNum<< " "
		<< "\t英语分数：" << EnglishNum <<  " "  << "\t总分：" << Sum << endl;
	cout << endl;
				}
};
class StudentMessage {
public:
	StudentMessage();
	~StudentMessage();
	void ShowMenu();				//显示菜单
	void AddItem();					//增加
	void Display();					//输出
	void Find();					//查找
	void Save();					//保存
	void CorrectItem();				//修改
	void RemoveItem();				//删除
	void Swap(Student*, Student*);	//交换
	void Sort();					//排序
	int ListCount();				//学生录入总数
	bool Check(char *ID);			//检查学号是否重复

private:
	Student *head, *rear;
	ifstream in;
	ofstream out;
	
	Student *FindItem(char *name)//按名字查找
	{
		for (Student *p = head; p ->next!= NULL; p = p->next)
		{
			if (!strcmp(p->next->name,name))//
				return p;
		}
		return NULL;
	}
	Student *FindID(char *ID)//按学号查找
	{

		for (Student *p = head; p->next != NULL;p = p->next)
		{
			
			if (!strcmp(p->next->ID, ID))//
				return p;
		}
		return NULL;
	}

};
#endif // !StudentMessage_H
