#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "manager.h"

Customer* Manager::GetNewCustomer(const string &cardnum)
{
	cout << "检查无误！该卡号可以使用！\n\n"; 
	
	string name, sex, tel;
	cout << "请输入顾客姓名："; 
	cin  >> name;
	cout << "请输入顾客性别：";
	cin  >> sex;
	cout << "请输入顾客电话：";
	cin  >> tel;
	
	Customer *p = new Customer(cardnum, name, sex, tel); 
	cout << "\n顾客信息录入成功！\n";		 
	return p;
}

Worker* Manager::GetNewWorker(const string &num)
{
	cout << "检查无误！该卡号可以使用！\n\n"; 
	
	string name, sex, tel, proj;
	int price;
	cout << "请输入员工姓名："; 
	cin  >> name;
	cout << "请输入员工性别：";
	cin  >> sex;
	cout << "请输入员工电话：";
	cin  >> tel;
	cout << "请输入员工美发项目：";
	cin  >> proj;
	cout << "请输入员工服务价格：";
	cin  >> price; 
	
	Worker *p = new Worker(num, name, sex, tel, proj, price); 
	cout << "\n员工信息录入成功！\n"; 
	return p;	
}

bool Manager::Add()
{
	int index = 0;
	cout << "1. 顾客\n2. 员工\n\n请选择添加信息的类别：";
	cin  >> index;
	
	string num;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;
	switch(index)
	{
		case 1:
			cout << "请输入新顾客的会员卡号：";
			cin  >> num;
			
			it1 = FindCus(num);
			if( it1 == customer.end() )
			{
				Customer *p = GetNewCustomer(num);
				customer.push_back(*p);
				return true;
			}
			else
			{
				cout << "错误！该卡号已经存在！\n\n";
				break;
			}
		case 2:
			cout << "请输入新员工的卡号：";
			cin  >> num;
			
			it2 = FindWor(num);
			if( it2 == worker.end() )
			{
				Worker *p = GetNewWorker(num);
				worker.push_back(*p);
				return true;
			}
			else
			{
				cout << "错误！该卡号已经存在！\n\n";
				break;
			}
		default:
			cout << "错误！请检查输入!\n\n";
			break;	
	}
	return false;
}
	
bool Manager::Del()
{
	int index = 0;
	cout << "1. 顾客\n2. 员工\n\n请选择删除信息的类别：";
	cin  >> index;
	
	string num;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;	
	switch(index)
	{
		case 1:
			cout << "请输入要删除的顾客的卡号：";
			cin  >> num;
			
			it1 = FindCus(num);
			if( it1 != customer.end() )
			{
				customer.erase(it1);
				return true;
			}
			else
			{
				cout << "错误！该卡号不存在！\n\n";
				break;
			}
		case 2:
			cout << "请输入要删除的员工的卡号：";
			cin  >> num;
			
			it2 = FindWor(num);
			if( it2 != worker.end() )
			{
				worker.erase(it2);
				return true;
			}
			else
			{
				cout << "错误！该卡号不存在！\n\n";
				break;
			}
		default:
			cout << "错误！请检查输入!\n\n";
			cin.clear();
			break;
	}
	return false;
}

bool Manager::Mdf()
{
	int index = 0;
	cout << "1. 顾客\n2. 员工\n\n请选择修改信息的类别：";
	cin  >> index;
	
	string num, name, sex, tel, proj;
	int price;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;	
	switch(index)
	{
		case 1:
			cout << "请输入要修改的顾客的卡号：";
			cin  >> num;
			
			it1 = FindCus(num);
			if( it1 != customer.end() )
			{
				cout << "请输入新的顾客姓名："; 
				cin  >> name;
				it1->SetName(name);
				cout << "请输入新的顾客性别：";
				cin  >> sex;
				it1->SetSex(sex);
				cout << "请输入新的顾客电话：";
				cin  >> tel;
				it1->SetTel(tel);
				return true;
			}
			else
			{
				cout << "错误！该卡号不存在！\n\n";
				break;
			}
		case 2:
			cout << "请输入要修改的员工的卡号：";
			cin  >> num;
			
			it2 = FindWor(num);
			if( it2 != worker.end() )
			{
				cout << "请输入新的员工姓名："; 
				cin  >> name;
				it2->SetName(name);
				cout << "请输入新的员工性别：";
				cin  >> sex;
				it2->SetSex(sex);
				cout << "请输入新的员工电话：";
				cin  >> tel;
				it2->SetTel(tel);
				cout << "请输入新的员工美发项目：";
				cin  >> proj;
				cout << "请输入新的员工服务价格：";
				cin  >> price;	
				it2->SetPro(proj, price);	
				return true;
			}
			else
			{
				cout << "错误！该卡号不存在！\n\n";
				break;
			}
		default:
			cout << "错误！请检查输入!\n\n";
			cin.clear();
			break;
	}
	return false;	
}

bool Manager::Find()
{
	int index = 0;
	cout << "1. 顾客\n2. 员工\n\n请选择修改信息的类别：";
	cin  >> index;
	
	string num;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;
	switch(index)
	{
		case 1:
			cout << "请输入要查询的顾客卡号：";
			cin  >> num; 
			
			it1 = FindCus(num);
			if(it1 != customer.end())
			{
				cout << "卡号\t姓名\t性别\t电话\n";
				cout << it1->GetCardNum() << "\t" <<it1->GetName() << "\t"
					 << it1->GetSex() << "\t" << it1->GetTel() << endl;
				return true;  
			}
			else
				cout << "错误！该卡号不存在！\n\n";
			break;
		case 2:
			cout << "请输入要查询的员工卡号：";
			cin  >> num; 
			
			it2 = FindWor(num);
			if(it2 != worker.end())
			{
				cout << "卡号\t姓名\t性别\t电话\t服务\t价格\n";
				cout << it2->GetNum() << "\t" <<it2->GetName() << "\t"
					 << it2->GetSex() << "\t" << it2->GetTel() << "\t"
					 << (it2->GetPro()).GetProj() << "\t" << (it2->GetPro()).GetPrice() << endl;
				return true;	 
			}
			else
				cout << "错误！该卡号不存在！\n\n";
		default:
			cin.clear();		
	}
	return false;
}

vector<Customer>::iterator Manager::FindCus(const string &cardnum)
{
	vector<Customer>::iterator it;
	for(it = customer.begin(); it != customer.end(); ++it)
	{
		if(	it->GetCardNum() == cardnum )
		{
			cout << "查找成功！\n\n"; 
			break;
		}
	}
	return it;
}

vector<Worker>::iterator Manager::FindWor(const string &num)
{
	vector<Worker>::iterator it;
	for(it = worker.begin(); it != worker.end(); ++it)
	{
		if(	it->GetNum() == num )
		{
			cout << "查找成功！\n\n";
			break;
		}
	}
	return it;	
}

void Manager::Menu()
{
	Input();
	int index = 10;
	do{
		system("cls");
		cout << "--------------------美发店管理系统--------------------\n\n";
		cout << "1. 添加\n2. 删除\n3. 修改\n4. 查询\n5. 名单\n6. 保存\n7. 退出\n\n"; 
		
		cout << "当前共有会员：" << customer.size() << "人，";
		cout << "员工：" << worker.size() << "人\n"; 
		cout << "------------------------------------------------------\n\n";
		
		cout << "请输入您要进行的操作：";
		cin  >> index;
		system("cls");
		switch(index)
		{
			case 1:
				if( Add() )
					cout << "添加成功！\n\n";
				else
					cout << "添加失败！\n\n";
				system("pause");
				break;
			case 2:
				if( Del() )
					cout << "删除成功！\n\n";
				else
					cout << "删除失败！\n\n";
				system("pause");
				break;
			case 3:
				if( Mdf() )
					cout << "修改成功！\n\n";
				else
					cout << "修改失败！\n\n";
				system("pause");
				break;
			case 4:
				if( Find() )
					cout << "查找成功！\n\n";
				else
					cout << "查找失败！\n\n";
				system("pause");	
				break;	
			case 5:
				Print();
				system("pause");
				break;
			case 6:
				if ( OutPut() )
					cout << "更新成功！\n\n";
				else
					cout << "更新失败！\n\n";
				system("pause"); 
				break;
			case 7:
				exit(0);
			default:
				break;			 
		}
		cin.clear();
		cin.sync();
	}while(true);	
}

bool Manager::Input()
{
	ifstream fin;
	string num, name, sex, tel, proj;
	int price;
	
	fin.open("./customer_data.txt");
	if( !fin.is_open() )
		return false;
	
	while(fin>>num>>name>>sex>>tel)
	{
		Customer cus(num, name, sex, tel);
		customer.push_back(cus);
	}
	fin.close();
	
	fin.open("./worker_data.txt");
	if( !fin.is_open() )
		return false;
	while(fin>>num>>name>>sex>>tel>>proj>>price)
	{
		Worker wo(num, name, sex, tel, proj, price);
		worker.push_back(wo);
	}
	fin.close();
	
	return true;	
}

bool Manager::OutPut()
{
	ofstream fout;
	
	fout.open("./customer_data.txt");
	if( !fout.is_open() )
		return false;
	
	for(int i = 0; i < customer.size(); ++i)
		fout << customer[i].GetCardNum() << " " << customer[i].GetName() << " "
		     << customer[i].GetSex() << " " << customer[i].GetTel() << "\n";
	fout.close();
	
	fout.open("./worker_data.txt");
	if( !fout.is_open() )
		return false;
	for(int i = 0; i < worker.size(); ++i)
		fout << worker[i].GetNum() << " " << worker[i].GetName() << " "
		     << worker[i].GetSex() << " " << worker[i].GetTel() << " "
		     << (worker[i].GetPro()).GetProj() << " "<< (worker[i].GetPro()).GetPrice() << "\n";
	fout.close();
	
	return true;	
}

void Manager::Print()
{
	cout << "--------------------------顾客------------------------------------\n\n";
	cout << "卡号\t姓名\t    性别\t电话\n";	
	
	vector<Customer>::iterator it1;
	for(it1 = customer.begin(); it1 != customer.end(); ++it1)
		cout << it1->GetCardNum() << "\t" <<it1->GetName() << "\t    "
	 		 << it1->GetSex() << "\t\t" << it1->GetTel() << endl;
	
	cout << "\n\n\n";
	cout << "--------------------------员工------------------------------------\n\n";
	cout << "卡号\t姓名\t    性别\t电话\t        服务\t价格\n"; 
	vector<Worker>::iterator   it2;
	for(it2 = worker.begin(); it2 != worker.end(); ++it2)		  	
		cout << it2->GetNum() << "\t" <<it2->GetName() << "\t    "
			 << it2->GetSex() << "\t\t" << it2->GetTel() << "\t\t"
			 << (it2->GetPro()).GetProj() << "\t" << (it2->GetPro()).GetPrice() << endl;
	cout << "\n\n------------------------------------------------------------------\n\n";		 
}
