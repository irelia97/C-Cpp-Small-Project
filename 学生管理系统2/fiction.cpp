#include <iostream>
#include <fstream>
#include <cstdlib>
#include "stu.h"
#include "fiction.h"
using namespace std;

void Menu()
{
	int index = 0, flag = 0;
	STU *head = new STU();

	while(flag == 0)
	{
		system("cls");
		cout << "------------ѧ���ɼ�����ϵͳ------------\n\n";
		cout << "1. ��ѯ\n2. ���\n3. �޸���Ϣ\n4. �޸ĳɼ�\n5. ɾ��\n6. ����\n7. ����\n0. �˳�\n\n";
		cout << "��ǰ��ѧ��" << Student::num << "��\n"; 
		cout << "----------------------------------------\n\n";
		
		cout << "�����빦��ģ�飺"; 
		cin >> index;
		
		system("cls");
		switch(index)
		{
			case 0:
				flag = 1;
				break;
			case 1:
				Find(head);
				break;
			case 2:
				AddStu(head);
				break;
			case 3:
				ModifyStuInf(head);
				break;
			case 4:
				ModifyStuSco(head);
				break;
			case 5:
				DeleteStu(head);
				break;
			case 6:
				SaveToTxt(head);
				break;
			case 7:
				PrintList(head);
				break;		
			default:
				printf("������󣡣�\n");
				system("pause");
		}
	}
	system("pause");
}
	

void PrintList(const STU *head)
{
	STU *p = head->next;
	
	cout << "ѧ��             ����       ����       �绰       �γ���       �γ̵÷�\n\n"; 
	while(p != NULL)
	{
		p->PrintInf();
		p = p->next;
	}
	system("pause");
}

void Find(const STU *head)
{
	string sno;
	STU *p;
	
	cout << "�������ѯ��ѧ��ѧ�ţ�";
	cin  >> sno;	
	if( (p=FindSno(head, sno)) == NULL )
		return ;
	else
		p->PrintInf();
	system("pause");
}

void AddStu(STU *head)
{
	STU *p = head;
	
	while(p->next != NULL)
		p = p->next;
	
	string sno, sname, room, tel, course;
	int score;	
	
	cout << "������ѧ������Ϣ��\n";
	cout << "ѧ�ţ�";   cin >> sno;
	cout << "������";   cin >> sname;
	cout << "���᣺";   cin >> room;
	cout << "�绰��";   cin >> tel;
	cout << "�γ����ƣ�"; cin >> course;
	cout << "�γ̵÷֣�"; cin >> score;
	STU *newStu = new STU(sno, sname, room, tel, course, score);
	p->next = newStu;
	
	cout << "¼��ɹ�����\n\n";
	system("pause");
}

STU* FindSno(const STU *head, string &_sno)
{
	STU *p = head->next;
	while( p != NULL)
	{
		if( _sno == p->GetSno() )
			return p;
		p = p->next;
	}
	cout << "���޴���!\n\n";
	system("pause");
	return NULL;
}

void ModifyStuInf(const STU *head)
{
	STU *p;
	string  _sno, _sname, _room, _tel;
	cout << "������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�";
	cin  >> _sno; 
	
	if( (p=FindSno(head, _sno)) == NULL )
		return ; 
	
	cout << "���ҽ�����£�\n";	
	p->PrintInf();	
	cout << "��ѧ�ţ�"; cin >> _sno; p->NewSno(_sno);
	cout << "��������"; cin >> _sname; p->NewName(_sname);
	cout << "�����᣺"; cin >> _room; p->NewRoom(_room);
	cout << "�µ绰��"; cin >> _tel; p->NewTel(_tel);
	
	cout << "�޸ĳɹ���\n\n";
	system("pause");
}

void ModifyStuSco(const STU *head)
{
	STU *p;
	int score;
	string _sno;
	cout << "������Ҫ�޸ĳɼ���ѧ��ѧ�ţ�";
	cin  >> _sno; 
	
	if( (p=FindSno(head, _sno)) == NULL )
		return ; 
	
	cout << "���ҽ�����£�\n";	
	p->PrintInf();	
	cout << "�³ɼ���"; cin >> score; p->GetSco().NewScore(score);
	cout << "�޸ĳɹ���\n\n";
	system("pause");
}
	 	 	 	 
void DeleteStu(STU *head)
{
	string sno;	
	cout << "������Ҫɾ���ɼ���ѧ��ѧ�ţ�";
	cin  >> sno;  	
	
	STU *p, *pre;
	p = head;
	while( p->next != NULL)
	{
		if( sno == p->next->GetSno() )
		{
			pre = p;
			p = p->next;
			
			pre->next = p->next;
			delete p;
 			cout << "ɾ���ɹ�����\n";			
			break;
		}
		p = p->next;
	}
	if(p->next == NULL)
		cout << "���޴���!!\n";
		 
	system("pause");
}

void SaveToTxt(const STU *head)
{
	ofstream fout("data.txt");
	
	STU *p = head->next;
	while(p != NULL)
	{
		fout << p->GetSno() << "   " << p->GetSname() << "    "
		     << p->GetRoom() << "    " << p->GetTel() << "    "
		     << p->GetSco().GetCourseName()  << "    "
		     << p->GetSco().GetCourseScore() << endl;
		p = p->next;     
	}
	cout << "�������txt��\n\n"; 
	system("pause");
}

