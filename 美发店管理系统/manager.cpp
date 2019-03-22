#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "manager.h"

Customer* Manager::GetNewCustomer(const string &cardnum)
{
	cout << "������󣡸ÿ��ſ���ʹ�ã�\n\n"; 
	
	string name, sex, tel;
	cout << "������˿�������"; 
	cin  >> name;
	cout << "������˿��Ա�";
	cin  >> sex;
	cout << "������˿͵绰��";
	cin  >> tel;
	
	Customer *p = new Customer(cardnum, name, sex, tel); 
	cout << "\n�˿���Ϣ¼��ɹ���\n";		 
	return p;
}

Worker* Manager::GetNewWorker(const string &num)
{
	cout << "������󣡸ÿ��ſ���ʹ�ã�\n\n"; 
	
	string name, sex, tel, proj;
	int price;
	cout << "������Ա��������"; 
	cin  >> name;
	cout << "������Ա���Ա�";
	cin  >> sex;
	cout << "������Ա���绰��";
	cin  >> tel;
	cout << "������Ա��������Ŀ��";
	cin  >> proj;
	cout << "������Ա������۸�";
	cin  >> price; 
	
	Worker *p = new Worker(num, name, sex, tel, proj, price); 
	cout << "\nԱ����Ϣ¼��ɹ���\n"; 
	return p;	
}

bool Manager::Add()
{
	int index = 0;
	cout << "1. �˿�\n2. Ա��\n\n��ѡ�������Ϣ�����";
	cin  >> index;
	
	string num;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;
	switch(index)
	{
		case 1:
			cout << "�������¹˿͵Ļ�Ա���ţ�";
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
				cout << "���󣡸ÿ����Ѿ����ڣ�\n\n";
				break;
			}
		case 2:
			cout << "��������Ա���Ŀ��ţ�";
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
				cout << "���󣡸ÿ����Ѿ����ڣ�\n\n";
				break;
			}
		default:
			cout << "������������!\n\n";
			break;	
	}
	return false;
}
	
bool Manager::Del()
{
	int index = 0;
	cout << "1. �˿�\n2. Ա��\n\n��ѡ��ɾ����Ϣ�����";
	cin  >> index;
	
	string num;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;	
	switch(index)
	{
		case 1:
			cout << "������Ҫɾ���Ĺ˿͵Ŀ��ţ�";
			cin  >> num;
			
			it1 = FindCus(num);
			if( it1 != customer.end() )
			{
				customer.erase(it1);
				return true;
			}
			else
			{
				cout << "���󣡸ÿ��Ų����ڣ�\n\n";
				break;
			}
		case 2:
			cout << "������Ҫɾ����Ա���Ŀ��ţ�";
			cin  >> num;
			
			it2 = FindWor(num);
			if( it2 != worker.end() )
			{
				worker.erase(it2);
				return true;
			}
			else
			{
				cout << "���󣡸ÿ��Ų����ڣ�\n\n";
				break;
			}
		default:
			cout << "������������!\n\n";
			cin.clear();
			break;
	}
	return false;
}

bool Manager::Mdf()
{
	int index = 0;
	cout << "1. �˿�\n2. Ա��\n\n��ѡ���޸���Ϣ�����";
	cin  >> index;
	
	string num, name, sex, tel, proj;
	int price;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;	
	switch(index)
	{
		case 1:
			cout << "������Ҫ�޸ĵĹ˿͵Ŀ��ţ�";
			cin  >> num;
			
			it1 = FindCus(num);
			if( it1 != customer.end() )
			{
				cout << "�������µĹ˿�������"; 
				cin  >> name;
				it1->SetName(name);
				cout << "�������µĹ˿��Ա�";
				cin  >> sex;
				it1->SetSex(sex);
				cout << "�������µĹ˿͵绰��";
				cin  >> tel;
				it1->SetTel(tel);
				return true;
			}
			else
			{
				cout << "���󣡸ÿ��Ų����ڣ�\n\n";
				break;
			}
		case 2:
			cout << "������Ҫ�޸ĵ�Ա���Ŀ��ţ�";
			cin  >> num;
			
			it2 = FindWor(num);
			if( it2 != worker.end() )
			{
				cout << "�������µ�Ա��������"; 
				cin  >> name;
				it2->SetName(name);
				cout << "�������µ�Ա���Ա�";
				cin  >> sex;
				it2->SetSex(sex);
				cout << "�������µ�Ա���绰��";
				cin  >> tel;
				it2->SetTel(tel);
				cout << "�������µ�Ա��������Ŀ��";
				cin  >> proj;
				cout << "�������µ�Ա������۸�";
				cin  >> price;	
				it2->SetPro(proj, price);	
				return true;
			}
			else
			{
				cout << "���󣡸ÿ��Ų����ڣ�\n\n";
				break;
			}
		default:
			cout << "������������!\n\n";
			cin.clear();
			break;
	}
	return false;	
}

bool Manager::Find()
{
	int index = 0;
	cout << "1. �˿�\n2. Ա��\n\n��ѡ���޸���Ϣ�����";
	cin  >> index;
	
	string num;
	vector<Customer>::iterator it1;
	vector<Worker>::iterator   it2;
	switch(index)
	{
		case 1:
			cout << "������Ҫ��ѯ�Ĺ˿Ϳ��ţ�";
			cin  >> num; 
			
			it1 = FindCus(num);
			if(it1 != customer.end())
			{
				cout << "����\t����\t�Ա�\t�绰\n";
				cout << it1->GetCardNum() << "\t" <<it1->GetName() << "\t"
					 << it1->GetSex() << "\t" << it1->GetTel() << endl;
				return true;  
			}
			else
				cout << "���󣡸ÿ��Ų����ڣ�\n\n";
			break;
		case 2:
			cout << "������Ҫ��ѯ��Ա�����ţ�";
			cin  >> num; 
			
			it2 = FindWor(num);
			if(it2 != worker.end())
			{
				cout << "����\t����\t�Ա�\t�绰\t����\t�۸�\n";
				cout << it2->GetNum() << "\t" <<it2->GetName() << "\t"
					 << it2->GetSex() << "\t" << it2->GetTel() << "\t"
					 << (it2->GetPro()).GetProj() << "\t" << (it2->GetPro()).GetPrice() << endl;
				return true;	 
			}
			else
				cout << "���󣡸ÿ��Ų����ڣ�\n\n";
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
			cout << "���ҳɹ���\n\n"; 
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
			cout << "���ҳɹ���\n\n";
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
		cout << "--------------------���������ϵͳ--------------------\n\n";
		cout << "1. ���\n2. ɾ��\n3. �޸�\n4. ��ѯ\n5. ����\n6. ����\n7. �˳�\n\n"; 
		
		cout << "��ǰ���л�Ա��" << customer.size() << "�ˣ�";
		cout << "Ա����" << worker.size() << "��\n"; 
		cout << "------------------------------------------------------\n\n";
		
		cout << "��������Ҫ���еĲ�����";
		cin  >> index;
		system("cls");
		switch(index)
		{
			case 1:
				if( Add() )
					cout << "��ӳɹ���\n\n";
				else
					cout << "���ʧ�ܣ�\n\n";
				system("pause");
				break;
			case 2:
				if( Del() )
					cout << "ɾ���ɹ���\n\n";
				else
					cout << "ɾ��ʧ�ܣ�\n\n";
				system("pause");
				break;
			case 3:
				if( Mdf() )
					cout << "�޸ĳɹ���\n\n";
				else
					cout << "�޸�ʧ�ܣ�\n\n";
				system("pause");
				break;
			case 4:
				if( Find() )
					cout << "���ҳɹ���\n\n";
				else
					cout << "����ʧ�ܣ�\n\n";
				system("pause");	
				break;	
			case 5:
				Print();
				system("pause");
				break;
			case 6:
				if ( OutPut() )
					cout << "���³ɹ���\n\n";
				else
					cout << "����ʧ�ܣ�\n\n";
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
	cout << "--------------------------�˿�------------------------------------\n\n";
	cout << "����\t����\t    �Ա�\t�绰\n";	
	
	vector<Customer>::iterator it1;
	for(it1 = customer.begin(); it1 != customer.end(); ++it1)
		cout << it1->GetCardNum() << "\t" <<it1->GetName() << "\t    "
	 		 << it1->GetSex() << "\t\t" << it1->GetTel() << endl;
	
	cout << "\n\n\n";
	cout << "--------------------------Ա��------------------------------------\n\n";
	cout << "����\t����\t    �Ա�\t�绰\t        ����\t�۸�\n"; 
	vector<Worker>::iterator   it2;
	for(it2 = worker.begin(); it2 != worker.end(); ++it2)		  	
		cout << it2->GetNum() << "\t" <<it2->GetName() << "\t    "
			 << it2->GetSex() << "\t\t" << it2->GetTel() << "\t\t"
			 << (it2->GetPro()).GetProj() << "\t" << (it2->GetPro()).GetPrice() << endl;
	cout << "\n\n------------------------------------------------------------------\n\n";		 
}
