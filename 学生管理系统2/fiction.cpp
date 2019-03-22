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
		cout << "------------学生成绩管理系统------------\n\n";
		cout << "1. 查询\n2. 添加\n3. 修改信息\n4. 修改成绩\n5. 删除\n6. 保存\n7. 名单\n0. 退出\n\n";
		cout << "当前有学生" << Student::num << "人\n"; 
		cout << "----------------------------------------\n\n";
		
		cout << "请输入功能模块："; 
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
				printf("输入错误！！\n");
				system("pause");
		}
	}
	system("pause");
}
	

void PrintList(const STU *head)
{
	STU *p = head->next;
	
	cout << "学号             姓名       宿舍       电话       课程名       课程得分\n\n"; 
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
	
	cout << "请输入查询的学生学号：";
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
	
	cout << "请输入学生的信息：\n";
	cout << "学号：";   cin >> sno;
	cout << "姓名：";   cin >> sname;
	cout << "宿舍：";   cin >> room;
	cout << "电话：";   cin >> tel;
	cout << "课程名称："; cin >> course;
	cout << "课程得分："; cin >> score;
	STU *newStu = new STU(sno, sname, room, tel, course, score);
	p->next = newStu;
	
	cout << "录入成功！！\n\n";
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
	cout << "查无此人!\n\n";
	system("pause");
	return NULL;
}

void ModifyStuInf(const STU *head)
{
	STU *p;
	string  _sno, _sname, _room, _tel;
	cout << "请输入要修改信息的学生学号：";
	cin  >> _sno; 
	
	if( (p=FindSno(head, _sno)) == NULL )
		return ; 
	
	cout << "查找结果如下：\n";	
	p->PrintInf();	
	cout << "新学号："; cin >> _sno; p->NewSno(_sno);
	cout << "新姓名："; cin >> _sname; p->NewName(_sname);
	cout << "新宿舍："; cin >> _room; p->NewRoom(_room);
	cout << "新电话："; cin >> _tel; p->NewTel(_tel);
	
	cout << "修改成功！\n\n";
	system("pause");
}

void ModifyStuSco(const STU *head)
{
	STU *p;
	int score;
	string _sno;
	cout << "请输入要修改成绩的学生学号：";
	cin  >> _sno; 
	
	if( (p=FindSno(head, _sno)) == NULL )
		return ; 
	
	cout << "查找结果如下：\n";	
	p->PrintInf();	
	cout << "新成绩："; cin >> score; p->GetSco().NewScore(score);
	cout << "修改成功！\n\n";
	system("pause");
}
	 	 	 	 
void DeleteStu(STU *head)
{
	string sno;	
	cout << "请输入要删除成绩的学生学号：";
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
 			cout << "删除成功！！\n";			
			break;
		}
		p = p->next;
	}
	if(p->next == NULL)
		cout << "查无此人!!\n";
		 
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
	cout << "已输出至txt！\n\n"; 
	system("pause");
}

