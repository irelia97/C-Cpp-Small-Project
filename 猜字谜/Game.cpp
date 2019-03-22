#include <iostream>
#include <fstream>
#include <ctime>
#include "Game.h"
using namespace std;

Game::Game()
{
	if( GetData() )
	{
		Screen();
		Play();	
	}
}

Game::~Game()
{
	cout << "��Ϸ�������´��ټ���" << endl; 
}

void Game::Screen()
{
	/*
	for(auto it = idiom.begin(); it != idiom.end(); ++it)
		cout << it->GetIdiom() << "��" << it->GetFriHint() << endl;
	*/
	for(int i = 0; i < idiom.size(); ++i)
		cout << idiom[i].GetIdiom()	<< "��" << idiom[i].GetFriHint() << endl;
		
	cout << "\n********************************************************\n\n";	
	cout << "���������" << idiom.size() << "��������������ʼ��Ϸ��" << endl;
	cout << "\n********************************************************\n\n";
	cin.get();
	system("cls");
}

bool Game::GetData()
{
	string str, _idiom, _hint;
	ifstream fin("./����.txt");	//	����.exeͬһĿ¼�µ������ļ�
	if(!fin){
		cerr << "���ļ�ʧ�ܣ����鱾�س����ļ���\n";
		return false;
	}
	
	//	���ж�ȡ���Ｐ����� 
	while(fin >> str){
		if(str.size() == 0)
			continue;
		
		_idiom = str.substr(0, 8);	//��ȡ���� 
		_hint  = str.substr(10, str.size()-9);	//��ȡ���� 
		
		Idiom data(_idiom, _hint);	//����һ��������ʵ�� 
		idiom.push_back(data);		//ѹ�������� 
	}
	fin.close();
	
	return true;
}

void Game::Play()
{
	srand( (unsigned)time(NULL) );	//������������� 
	clock_t start_time = clock();	//��¼��Ϸ��ʼʱ�� 
	
	string str;
	int idiom_size = idiom.size();
	
	while(str != "exit"){
		cout << "********************������********************\n";
		cout << "\n\nTips������ exit ���˳���Ϸ\n\n";
		
		int index  = rand()%idiom_size;	//	���������±� [0, idiom.size()-1]
		Idiom data = idiom[index];
		
		index = 1;		//	index��Ϊ��index������ʾ 
		while(str != "exit"){
			switch(index)
			{
				case 1:
					cout << "��ʾ" << index << "��" << data.GetFriHint() << endl;
					break;
				case 2:
					cout << "��ʾ" << index << "����һ������ " << data.GetSecHint() << endl;
					break;			 
				case 3:
					cout << "��ʾ" << index << "��ǰ�������� " << data.GetThiHint() << endl;
					break;
				default:
					cout << "�ǳ��ź�����ʧ����~~\n";
					cout << "���ǣ�" << data.GetIdiom() << endl << endl; 
					system("pause");
					break;
			}
			if(index > 3)	//	ʧ�ܣ�������һ�� 
				break;
									 	
			cout << "��������Ĵ𰸣�"; 
		 	cin  >> str;		 	
		 	if( str == data.GetIdiom() ){
		 		cout << "��ϲ�㣡�ش���ȷ���� \n\n";
		 		system("pause");
		 		break;		//	�ɹ���������һ�� 
		 	}else{
		 		cout << "���������Ŷ~������~���ͣ�\n\n"; 
		 		index++;	//������һ�������ʾ 
		 	}
		 }
		 system("cls");		//��������һ�� 
	}

	clock_t end_time = clock();
	cout << "��һ����Ϸ��"; 
	cout << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC << "��" << endl;
	system("pause");
}
