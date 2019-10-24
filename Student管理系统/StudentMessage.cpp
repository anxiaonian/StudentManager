#include"StudentMessage.h"
#include<iostream>
using namespace std;

StudentMessage::StudentMessage() {
	head = new Student;
	head->next= new Student;
	rear=head->next;
	/*head->next = NULL;
	rear = head;*/

	in.open("Data.txt");			//打开文件
	if (!in)
		cout << "此文件为空，无数据信息，请先输入..." << endl;
	else {
		while (!in.eof()) {
			rear->Readfile(in);
			if (rear->name[0] == '\0')break;
			rear->next = new Student;
			rear = rear->next;
		}
		in.close();					//关闭文件
		cout << "\t\t读取信息成功...";
		cout << endl;
	}
}
StudentMessage::~StudentMessage() {
	//Save();
	for (Student *p ;head->next != rear;)
	{
		p = head->next;
		head->next  = head->next->next ;
		delete p;
	}
	delete head, rear;
}
//菜单
void StudentMessage::ShowMenu() {
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t*		学生成绩管理系统		 *" << endl;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t*		1、添加学生成绩信息		 *" << endl;
	cout << "\t\t*		2、输出学生成绩信息		 *" << endl;
	cout << "\t\t*		3、查找学生成绩信息		 *" << endl;
	cout << "\t\t*		4、排序学生成绩信息		 *" << endl;
	cout << "\t\t*		5、修改学生成绩信息		 *" << endl;
	cout << "\t\t*		6、删除学生成绩信息		 *" << endl;
	cout << "\t\t*		0、安全退出			 *" << endl;
	cout << "\t\t**************************************************" << endl;
}

//添加加学生信息
void StudentMessage::AddItem()
{
	char ID[20];
	rear->next = new Student;
	while (!Check(ID)) {
		Check(ID);
	}
	strcpy_s(rear->ID,ID);
	rear->InputData();
	rear = rear->next;
	cout << "\t\t学生信息添加成功" << endl;
	cout << "请按任意字符继续....";
	_getch();
}

//输出学生信息
void StudentMessage::Display()
{
	Save();
	for (Student *p = head->next; p != rear; p = p->next)
	{
		p->ShowData();
	}
	
	cout << "请按任意字符继续....";
	_getch();
}

//查找
void StudentMessage::Find() {
	Student *s1 = NULL;
	char m_name[20], m_ID[20];
	int i = 0;
	cout << "请选择查询方式：" << endl;
	cout << "1、按名字查找。" << endl<< "2、按学号查找。" << endl;
	cin >> i;
	switch (i)
	{
	case 1: {
	cout << "请输入名字：" << endl;
		cin >> m_name;
		if (s1 = FindItem(m_name)) {
		s1->next->ShowData();
		cout << "请按任意字符继续....";
		_getch();
		}
		else {
			cout << "没有找到...." << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
		}break;
	case 2: {
	cout << "请输入学号：" << endl;
		cin >> m_ID;
		if (s1 = FindID(m_ID)) {
			s1->next->ShowData();
			cout << "请按任意字符继续....";
			_getch();
		}
		else {
			cout << "没有找到...." << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
	}break;
	}		
}

//保存
void StudentMessage::Save() {
	out.open("Data.txt");
	for (Student*p = head->next; p != rear; p=p->next) {
		out << p->name << '\t' << p->ID << '\t' << p->CNum << '\t' << p->MathNum << '\t' 
			<< p->EnglishNum << '\t' << p->Sum << '\t';
	}
	out.close();
}

//修改
void StudentMessage::CorrectItem() {
	Student *s1 = NULL, *s2 = new Student;
	char m_name[20], m_ID[20];
	int i = 0;
	cout << "请选择修改方式：" << endl;
	cout << "\t\t1、按名字修改。" << endl << "\t\t2、按学号修改。" << endl;
	cin >> i;
	switch (i)
	{
	case 1: {
		cout << "请输入名字：" << endl;
		cin >> m_name;
		cout << "请重新输入：" << endl;
			s2->InputData();
		if (s1 =FindItem(m_name)) {
			strcpy_s(s1->next->name, s2->name);		
			strcpy_s(s1->next->ID, s2->ID);
			s1->next->CNum = s2->CNum;
			s1->next->EnglishNum = s2->EnglishNum;
			s1->next->MathNum = s2->MathNum;
			s1->next->Sum = s2->Sum;
			cout << "\t\t修改成功！" << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
		else {
			cout << "没有找到...." << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
	}break;
	case 2: {
		cout << "请输入学号：" << endl;
		cin >> m_ID;
		cout << "请重新输入：" << endl;
			s2->InputData();
		if (s1 = FindID(m_ID)) {
			strcpy_s(s1->next->name, s2->name);		
			strcpy_s(s1->next->ID, s2->ID);
			s1->next->CNum = s2->CNum;
			s1->next->EnglishNum = s2->EnglishNum;
			s1->next->MathNum = s2->MathNum;
			s1->next->Sum = s2->Sum;
			cout << "\t\t修改成功！"<<endl;
			cout << "请按任意字符继续....";
			_getch();
		}
		else {
			cout << "没有找到...." << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
	}break;
	}
}

//删除
void StudentMessage::RemoveItem() {
	Student *s1 = NULL, *q = NULL, *s2 = new Student;
	char m_name[20], m_ID[20];
	int x = 0;
	cout << "请选择删除方式：" << endl;
	 cout<< "\t\t1、按名字删除" << endl;
	cout<< "\t\t2、按学号删除：" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		cout << "请输入要删除的学生名字：" << endl;
		cin >> m_name;
		if (s1 = FindItem(m_name)) {
			q=s1->next;
			strcpy_s(s2->name, q->name);		//s2暂存被删节点
			strcpy_s(s2->ID, q->ID);
			s2->CNum = q->CNum;
			s2->EnglishNum = q->EnglishNum;
			s2->MathNum = q->MathNum;
			s2->Sum = q->Sum;
			
			s1->next = q->next;		//修改指针
			delete q ;
			cout << "\t\t删除成功！" << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
		else {
			cout << "\t\t没有找到...." << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
	}	break;
	case 2: {
		cout << "请输入要删除的学生学号：" << endl;
		cin >> m_ID; 
		
		if (s1 = FindID(m_ID)) {
			q = s1->next;
			//strcpy_s(s2->name, q->name);		//s2暂存被删节点
			//strcpy_s(s2->ID, q->ID);
			//s2->CNum = q->CNum;
			//s2->EnglishNum = q->EnglishNum;
			//s2->MathNum = q->MathNum;
			//s2->Sum = q->Sum;
			
			s1->next = q->next;		//修改指针
			delete q;
			cout << "\t\t删除成功！" << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
		else {
			cout << "\t\t没有找到...." << endl;
			cout << "请按任意字符继续....";
			_getch();
		}
	}break;
	}
}

//交换
void StudentMessage::Swap(Student*s1, Student*s2) {
	Student*temp = new Student;
	strcpy_s(temp->name, s1->name);
	strcpy_s(temp->ID, s1->ID);
	temp->CNum = s1->CNum;
	temp->EnglishNum = s1->EnglishNum;
	temp->MathNum = s1->MathNum;
	temp->Sum = s1->Sum;

	strcpy_s(s1->name, s2->name);
	strcpy_s(s1->ID, s2->ID);
	s1->CNum = s2->CNum;
	s1->EnglishNum = s2->EnglishNum;
	s1->MathNum = s2->MathNum;
	s1->Sum = s2->Sum;

	strcpy_s(s2->name, temp->name);
	strcpy_s(s2->ID, temp->ID);
	s2->CNum = temp->CNum;
	s2->EnglishNum = temp->EnglishNum;
	s2->MathNum = temp->MathNum;
	s2->Sum = temp->Sum;

}

//排序
void StudentMessage::Sort() {
	Student *s1 = NULL, *s2 = NULL;
	int n = StudentMessage::ListCount();
	if (n < 2)return;
	for (s1 = head->next; s1 != rear; s1 = s1->next)
	{
		for (s2 = s1->next; s2 != rear; s2 = s2->next) {

		if (s1->Sum < s2->Sum)
			Swap(s1,s2);
		}
	}	
	cout << "排序成功..."<< endl;
	cout << "请按任意字符继续....";
	_getch();
}

//学生录入总数
int StudentMessage::ListCount() {
	if (!head) return 0;
	else {
	int Count=0;
	for (Student *p = head->next; p != rear; p = p->next) 
	{
		Count++;
	}
	return Count;
		}
}

bool StudentMessage::Check(char *ID) {
	cout << "\t\t请输入学生学号：";
	cin >> ID;
	for (Student *p = head; p != rear; p = p->next) {
		if (!strcmp(p->next->ID, ID)) {
			cout << "此学号已存在，请重新输入..." << endl;
			cout << "按任意键继续..." << endl;
			_getch();
			return false;
		}
	

	}	cout << "此学号可以录入..." << endl;return true;
}
	