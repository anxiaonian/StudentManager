/***********************************************************************
��Ŀ���ƣ�ѧ������ϵͳ
�����ļ���demo_main.cpp
�������ߣ�VS2015		(���ݽṹ�㷨��������ƣ���������)
��Ŀ���ܣ�ѧ������ϵͳ�����롢ɾ������ѯ���޸ġ�����������
**********************************************************************/

#include"StudentMessage.h"
#include<string.h>		//�����ַ�
#include<fstream>		//�����ļ�
#include<conio.h>		//getch()
#include<iostream>
using namespace std;

int main()
{
	int x, i = 0;
	bool quit = false;
	StudentMessage score;
	cout << "�밴���������..."<< endl;
	_getch();
	while(!quit){
		system("CLS");
		score.ShowMenu();
		cout << "��ѡ��" << endl;
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