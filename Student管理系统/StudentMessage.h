#ifndef StudentMessage_H
#define StudentMessage_H

#include<fstream>		//�����ļ�
#include<conio.h>		//_getch()
#include<iostream>
using namespace std;


//����ѧ����
class Student {
public:
	
	char name[20];		//����
	char ID[20];		//ѧ��
	int CNum;			//���ķ���
	int MathNum;		//��ѧ����
	int EnglishNum;		//Ӣ�����
	int Sum;			//ѧ���ܷ���

	Student *next;


void InputData() {
	
	cout << "\t\t������ѧ��������";		cin >> name;
//	cout << "\t\t������ѧ��ѧ�ţ�";		cin >> ID;
	cout << "\t\t������ѧ�����ķ�����";	cin >> CNum;
	cout << "\t\t������ѧ����ѧ������";	cin >> MathNum;
	cout << "\t\t������ѧ��Ӣ�������";	cin >> EnglishNum;
	Sum = CNum + MathNum + EnglishNum;
	cout << "\t\t�ܷ�Ϊ" << Sum << endl;
}
//��ȡ�ļ�
void Readfile(istream &in) {
	in >> name >> ID >> CNum >> MathNum >> EnglishNum >> Sum;
}

//�������
void ShowData() {
	cout << "\t������" << name << " " << "\tѧ�ţ�" << ID <<  " " 
		<< "\t���ķ�����" << CNum << " " << "\t��ѧ������" << MathNum<< " "
		<< "\tӢ�������" << EnglishNum <<  " "  << "\t�ܷ֣�" << Sum << endl;
	cout << endl;
				}
};
class StudentMessage {
public:
	StudentMessage();
	~StudentMessage();
	void ShowMenu();				//��ʾ�˵�
	void AddItem();					//����
	void Display();					//���
	void Find();					//����
	void Save();					//����
	void CorrectItem();				//�޸�
	void RemoveItem();				//ɾ��
	void Swap(Student*, Student*);	//����
	void Sort();					//����
	int ListCount();				//ѧ��¼������
	bool Check(char *ID);			//���ѧ���Ƿ��ظ�

private:
	Student *head, *rear;
	ifstream in;
	ofstream out;
	
	Student *FindItem(char *name)//�����ֲ���
	{
		for (Student *p = head; p ->next!= NULL; p = p->next)
		{
			if (!strcmp(p->next->name,name))//
				return p;
		}
		return NULL;
	}
	Student *FindID(char *ID)//��ѧ�Ų���
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
