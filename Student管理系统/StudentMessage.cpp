#include"StudentMessage.h"
#include<iostream>
using namespace std;

StudentMessage::StudentMessage() {
	head = new Student;
	head->next= new Student;
	rear=head->next;
	/*head->next = NULL;
	rear = head;*/

	in.open("Data.txt");			//���ļ�
	if (!in)
		cout << "���ļ�Ϊ�գ���������Ϣ����������..." << endl;
	else {
		while (!in.eof()) {
			rear->Readfile(in);
			if (rear->name[0] == '\0')break;
			rear->next = new Student;
			rear = rear->next;
		}
		in.close();					//�ر��ļ�
		cout << "\t\t��ȡ��Ϣ�ɹ�...";
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
//�˵�
void StudentMessage::ShowMenu() {
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t*		ѧ���ɼ�����ϵͳ		 *" << endl;
	cout << "\t\t**************************************************" << endl;
	cout << "\t\t*		1�����ѧ���ɼ���Ϣ		 *" << endl;
	cout << "\t\t*		2�����ѧ���ɼ���Ϣ		 *" << endl;
	cout << "\t\t*		3������ѧ���ɼ���Ϣ		 *" << endl;
	cout << "\t\t*		4������ѧ���ɼ���Ϣ		 *" << endl;
	cout << "\t\t*		5���޸�ѧ���ɼ���Ϣ		 *" << endl;
	cout << "\t\t*		6��ɾ��ѧ���ɼ���Ϣ		 *" << endl;
	cout << "\t\t*		0����ȫ�˳�			 *" << endl;
	cout << "\t\t**************************************************" << endl;
}

//��Ӽ�ѧ����Ϣ
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
	cout << "\t\tѧ����Ϣ��ӳɹ�" << endl;
	cout << "�밴�����ַ�����....";
	_getch();
}

//���ѧ����Ϣ
void StudentMessage::Display()
{
	Save();
	for (Student *p = head->next; p != rear; p = p->next)
	{
		p->ShowData();
	}
	
	cout << "�밴�����ַ�����....";
	_getch();
}

//����
void StudentMessage::Find() {
	Student *s1 = NULL;
	char m_name[20], m_ID[20];
	int i = 0;
	cout << "��ѡ���ѯ��ʽ��" << endl;
	cout << "1�������ֲ��ҡ�" << endl<< "2����ѧ�Ų��ҡ�" << endl;
	cin >> i;
	switch (i)
	{
	case 1: {
	cout << "���������֣�" << endl;
		cin >> m_name;
		if (s1 = FindItem(m_name)) {
		s1->next->ShowData();
		cout << "�밴�����ַ�����....";
		_getch();
		}
		else {
			cout << "û���ҵ�...." << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
		}break;
	case 2: {
	cout << "������ѧ�ţ�" << endl;
		cin >> m_ID;
		if (s1 = FindID(m_ID)) {
			s1->next->ShowData();
			cout << "�밴�����ַ�����....";
			_getch();
		}
		else {
			cout << "û���ҵ�...." << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
	}break;
	}		
}

//����
void StudentMessage::Save() {
	out.open("Data.txt");
	for (Student*p = head->next; p != rear; p=p->next) {
		out << p->name << '\t' << p->ID << '\t' << p->CNum << '\t' << p->MathNum << '\t' 
			<< p->EnglishNum << '\t' << p->Sum << '\t';
	}
	out.close();
}

//�޸�
void StudentMessage::CorrectItem() {
	Student *s1 = NULL, *s2 = new Student;
	char m_name[20], m_ID[20];
	int i = 0;
	cout << "��ѡ���޸ķ�ʽ��" << endl;
	cout << "\t\t1���������޸ġ�" << endl << "\t\t2����ѧ���޸ġ�" << endl;
	cin >> i;
	switch (i)
	{
	case 1: {
		cout << "���������֣�" << endl;
		cin >> m_name;
		cout << "���������룺" << endl;
			s2->InputData();
		if (s1 =FindItem(m_name)) {
			strcpy_s(s1->next->name, s2->name);		
			strcpy_s(s1->next->ID, s2->ID);
			s1->next->CNum = s2->CNum;
			s1->next->EnglishNum = s2->EnglishNum;
			s1->next->MathNum = s2->MathNum;
			s1->next->Sum = s2->Sum;
			cout << "\t\t�޸ĳɹ���" << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
		else {
			cout << "û���ҵ�...." << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
	}break;
	case 2: {
		cout << "������ѧ�ţ�" << endl;
		cin >> m_ID;
		cout << "���������룺" << endl;
			s2->InputData();
		if (s1 = FindID(m_ID)) {
			strcpy_s(s1->next->name, s2->name);		
			strcpy_s(s1->next->ID, s2->ID);
			s1->next->CNum = s2->CNum;
			s1->next->EnglishNum = s2->EnglishNum;
			s1->next->MathNum = s2->MathNum;
			s1->next->Sum = s2->Sum;
			cout << "\t\t�޸ĳɹ���"<<endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
		else {
			cout << "û���ҵ�...." << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
	}break;
	}
}

//ɾ��
void StudentMessage::RemoveItem() {
	Student *s1 = NULL, *q = NULL, *s2 = new Student;
	char m_name[20], m_ID[20];
	int x = 0;
	cout << "��ѡ��ɾ����ʽ��" << endl;
	 cout<< "\t\t1��������ɾ��" << endl;
	cout<< "\t\t2����ѧ��ɾ����" << endl;
	cin >> x;
	switch (x)
	{
	case 1: {
		cout << "������Ҫɾ����ѧ�����֣�" << endl;
		cin >> m_name;
		if (s1 = FindItem(m_name)) {
			q=s1->next;
			strcpy_s(s2->name, q->name);		//s2�ݴ汻ɾ�ڵ�
			strcpy_s(s2->ID, q->ID);
			s2->CNum = q->CNum;
			s2->EnglishNum = q->EnglishNum;
			s2->MathNum = q->MathNum;
			s2->Sum = q->Sum;
			
			s1->next = q->next;		//�޸�ָ��
			delete q ;
			cout << "\t\tɾ���ɹ���" << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
		else {
			cout << "\t\tû���ҵ�...." << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
	}	break;
	case 2: {
		cout << "������Ҫɾ����ѧ��ѧ�ţ�" << endl;
		cin >> m_ID; 
		
		if (s1 = FindID(m_ID)) {
			q = s1->next;
			//strcpy_s(s2->name, q->name);		//s2�ݴ汻ɾ�ڵ�
			//strcpy_s(s2->ID, q->ID);
			//s2->CNum = q->CNum;
			//s2->EnglishNum = q->EnglishNum;
			//s2->MathNum = q->MathNum;
			//s2->Sum = q->Sum;
			
			s1->next = q->next;		//�޸�ָ��
			delete q;
			cout << "\t\tɾ���ɹ���" << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
		else {
			cout << "\t\tû���ҵ�...." << endl;
			cout << "�밴�����ַ�����....";
			_getch();
		}
	}break;
	}
}

//����
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

//����
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
	cout << "����ɹ�..."<< endl;
	cout << "�밴�����ַ�����....";
	_getch();
}

//ѧ��¼������
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
	cout << "\t\t������ѧ��ѧ�ţ�";
	cin >> ID;
	for (Student *p = head; p != rear; p = p->next) {
		if (!strcmp(p->next->ID, ID)) {
			cout << "��ѧ���Ѵ��ڣ�����������..." << endl;
			cout << "�����������..." << endl;
			_getch();
			return false;
		}
	

	}	cout << "��ѧ�ſ���¼��..." << endl;return true;
}
	