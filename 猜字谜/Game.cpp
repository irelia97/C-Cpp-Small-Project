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
	cout << "游戏结束！下次再见！" << endl; 
}

void Game::Screen()
{
	/*
	for(auto it = idiom.begin(); it != idiom.end(); ++it)
		cout << it->GetIdiom() << "：" << it->GetFriHint() << endl;
	*/
	for(int i = 0; i < idiom.size(); ++i)
		cout << idiom[i].GetIdiom()	<< "：" << idiom[i].GetFriHint() << endl;
		
	cout << "\n********************************************************\n\n";	
	cout << "请熟记以上" << idiom.size() << "个成语，按任意键开始游戏！" << endl;
	cout << "\n********************************************************\n\n";
	cin.get();
	system("cls");
}

bool Game::GetData()
{
	string str, _idiom, _hint;
	ifstream fin("./成语.txt");	//	打开与.exe同一目录下的数据文件
	if(!fin){
		cerr << "打开文件失败！请检查本地成语文件！\n";
		return false;
	}
	
	//	逐行读取成语及其解释 
	while(fin >> str){
		if(str.size() == 0)
			continue;
		
		_idiom = str.substr(0, 8);	//获取成语 
		_hint  = str.substr(10, str.size()-9);	//获取解释 
		
		Idiom data(_idiom, _hint);	//创建一个成语类实例 
		idiom.push_back(data);		//压入容器中 
	}
	fin.close();
	
	return true;
}

void Game::Play()
{
	srand( (unsigned)time(NULL) );	//产生随机数种子 
	clock_t start_time = clock();	//记录游戏开始时间 
	
	string str;
	int idiom_size = idiom.size();
	
	while(str != "exit"){
		cout << "********************猜字谜********************\n";
		cout << "\n\nTips：输入 exit 可退出游戏\n\n";
		
		int index  = rand()%idiom_size;	//	产生容器下标 [0, idiom.size()-1]
		Idiom data = idiom[index];
		
		index = 1;		//	index变为第index级别提示 
		while(str != "exit"){
			switch(index)
			{
				case 1:
					cout << "提示" << index << "：" << data.GetFriHint() << endl;
					break;
				case 2:
					cout << "提示" << index << "：第一个字是 " << data.GetSecHint() << endl;
					break;			 
				case 3:
					cout << "提示" << index << "：前两个字是 " << data.GetThiHint() << endl;
					break;
				default:
					cout << "非常遗憾，你失败了~~\n";
					cout << "答案是：" << data.GetIdiom() << endl << endl; 
					system("pause");
					break;
			}
			if(index > 3)	//	失败，进行下一题 
				break;
									 	
			cout << "请输入你的答案："; 
		 	cin  >> str;		 	
		 	if( str == data.GetIdiom() ){
		 		cout << "恭喜你！回答正确！！ \n\n";
		 		system("pause");
		 		break;		//	成功，进行下一题 
		 	}else{
		 		cout << "不是这个答案哦~再想想~加油！\n\n"; 
		 		index++;	//进行下一级别的提示 
		 	}
		 }
		 system("cls");		//清屏，下一题 
	}

	clock_t end_time = clock();
	cout << "您一共游戏了"; 
	cout << static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC << "秒" << endl;
	system("pause");
}
