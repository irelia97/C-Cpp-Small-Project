#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

//	图书类 
class Book
{
	private:
		string name;	//书本名字 
		string bno;		//书本编号
		string type;
		double price;
		bool tag; 
	public:
	   ~Book() {}	
		Book() {}	
		Book(string nm, string no, string tp, double pri):name(nm),bno(no),type(tp),price(pri),tag(true) {}
		
		const string& getName() { return name; }
		const string& getBno() { return bno; } 
		const string& getType(){ return type;}
		const double& getPrice()  { return price;}
		bool getTag() { return tag; }
		void setTag(bool flag) { tag = flag; }
};

//	学生类	
class Student
{
	private:
		string name;		//学生姓名 
		string sno;			//学生学号 
		string psw;			//登录密码 
		vector<Book> bro;	//借书记录
	public:
	   ~Student() {}	
		Student() {}
		Student(string nm, string no, string pw):name(nm),sno(no),psw(pw) {}
		
		const string& getName() { return name; }
		const string& getSno() { return sno; }
		const string& getPsw() { return psw; }
		vector<Book>& getBro() { return bro; }
};

//	图书馆类 
class Library
{
	private:
		string  name;			//馆名 
		Student user;			//当前用户 
		vector<Book> store;		//图书存储
		vector<Student> stu;	//学生存储 
	public:
	   ~Library() {}	
		Library(string nm);		
		const string& getName() { return name; }
		
		void Register();		//学生注册 
		bool Login(); 			//登录 
		void Menu1();			//登录界面
		
		void Menu2();			//功能界面 
		void storeList();		//图书馆库存清单 
		void broList();			//用户借书清单 
	
		bool findBook(); 		//查找图书 
		void delBook();			//删除图书 
		void addBook();			//新建图书 		
		void broBook();			//借书 
		void retBook();			//还书 
};

const string libraryName = "中山桥一霸图书馆";		 
		
int main()
{
	Library l1(libraryName); 	
	return 0;
}

Library::Library(string nm):name(nm)
{
	//	学生中有默认一个管理员成员 
	Student admin("Admin", "000001", "123456");
	stu.push_back(admin);
	Menu1();
}

void Library::Register()
{
	string sno, name, psw;
	cout << "-----------------图书馆学生信息注册-----------------\n\n";
	cout << "请输入学号：";
	cin  >> sno;
	
	//	检查学号是否被注册 
	for(vector<Student>::iterator it = stu.begin(); it != stu.end(); ++it)
	{
		if( (*it).getSno() == sno ){
			cout << "此学号已经注册！\n";
			return;
		}
	}		
	
	cout << "请输入密码：";
	cin  >>  psw;
	cout << "请输入姓名：";
	cin  >> name;
	stu.push_back( Student(name, sno, psw) ); 
	cout << "\n\n注册成功！\n\n";		
}

bool Library::Login()
{	
	cout << "-------------------" << name << "登录界面-------------------\n\n";	
	string sno, psw;
	cout << "学号：";
	cin  >> sno;
	cout << "密码：";
	cin  >> psw; 
	
	for(vector<Student>::iterator it = stu.begin(); it != stu.end(); ++it)
	{
		if( (*it).getSno()==sno && (*it).getPsw()==psw )	//学号与密码均正确
		{
			user = *it;
			cout << "登陆成功！\n\n";
			return true;
		}
		if( (*it).getSno()==sno && (*it).getPsw()!=psw )	//密码不正确
		{
			cout << "密码错误！\n\n";
			return false;
		}
	}
	cout << "无此账号！\n\n"; 
	return false;		  	
}

void Library::Menu1()
{
	int  index = 0;
	bool flag = true;
	do{
		system("cls");
		cout << "-------------------欢迎来到" << name << "-------------------\n\n";
		cout << "1. 学生注册\n2. 登录\n3. 离开\n\n";
		cout << "管理员账号：000001   管理员密码：123456\n"; 
		cout << "------------------------------------------------------------\n\n";
		cout << "请选择功能：";
		
		cin  >> index;
		system("cls");		
		switch(index)
		{
			case 1:
				Register(); 
				break;
			case 2:
				if( Login() )
				{
					Menu2();
				}
				break;
			case 3:
				flag = false; 
				cout << "即将退出！下次再见！\n\n";
				break;
			default:
				cout << "输入有误！请重新输入！";
				cin.clear();	//cin重设为有效状态 
				cin.sync();		//清空输入流 
				break;
		}
		system("pause");
	}while(flag);
}

void Library::Menu2()
{
	int  index = 0;
	bool flag = true;
	do{
		system("cls");
		cout << "-------------------" << user.getName() << "您好，欢迎您使用该系统-------------------\n\n";
		cout << "您当前的状态是";
		if( user.getSno() == "000001" ){
			cout << "管理员\n\n";
		}else{
			cout << "用户\n\n";
		}
		
		cout << "1. 新建图书\n2. 删除图书\n3. 查找图书\n4. 借阅图书\n";
		cout << "5. 归还图书\n6. 图书清单\n7. 借阅清单\n8. 注销\n\n";
		cout << "------------------------------------------------------------\n\n";
		cout << "请选择功能：";
		
		cin  >> index;
		system("cls");		
		switch(index)
		{
			case 1:
				addBook();
				break;
			case 2:
				delBook();
				break;
			case 3:
				findBook();
				break;
			case 4:
				broBook();
				break;
			case 5:
				retBook();
				break;
			case 6:
				storeList();
				break;
			case 7:
				broList();
				break;		
			case 8:
				flag = false;
				break;			
			default:
				cout << "输入有误！请重新输入！";
				cin.clear();
				cin.sync();
				break;
		}
		system("pause");
	}while(flag);		
}

void Library::storeList()	
{
	cout << "图书书名        图书编号        图书种类        单价    状态\n";
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		cout << setiosflags(ios::left)
			 << setw(16) << (*it).getName()
			 << setw(16) << (*it).getBno()
			 << setw(16) << (*it).getType()
			 << setw(8) << (*it).getPrice();
		if( (*it).getTag() == true ){
			cout << setw(4) << "未借" << endl;
		}else{
			cout << setw(4) << "已借" << endl;
		}
	}
}
void Library::broList()			 
{
	vector<Book> bro = user.getBro();
	
	cout << "图书书名        图书编号        图书种类        单价\n";	
	for(vector<Book>::iterator it = bro.begin(); it != bro.end(); ++it)
	{
		cout << setiosflags(ios::left)
			 << setw(16) << (*it).getName()
			 << setw(16) << (*it).getBno()
			 << setw(16) << (*it).getType() << endl;

	}	
}

bool Library::findBook()
{
	cout << "--------------------------图书查找--------------------------\n\n"; 
	string bno;
	cout << "请输入要查找图书的编号：";
	cin  >> bno;
	 
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		if( (*it).getBno() == bno ){
			cout << "《" << (*it).getName() << "》 " << bno << endl;	//打印信息 
			return true;
		}
	}
	cout << "查无此书！\n\n"; 
	return false;
}

void Library::delBook()
{
	if( user.getSno() != "000001" ){
		cout << "只有管理员能进行此操作！";
		return;
	}
	cout << "--------------------------图书删除--------------------------\n\n"; 	
	string bno;
	cout << "请输入要删除图书的编号：";
	cin  >> bno;	
						
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		if( (*it).getBno() == bno ){
			store.erase(it);	//	删除 
			return;
		}
	}
	cout << "查无此书！\n\n";
}			

void Library::addBook()
{
	if( user.getSno() != "000001" ){
		cout << "只有管理员能进行此操作！";
		return;
	}
	cout << "--------------------------图书添加--------------------------\n\n"; 	
	string name, bno, tp;
	double pri;
	cout << "请输入新添图书的书名：";
	cin  >> name;
	cout << "请输入新添图书的编号：";
	cin  >> bno;
	cout << "请输入新添图书的种类：";
	cin  >> tp;
	cout << "请输入新添图书的单价：";
	cin  >> pri;
	
	//	判断单价是否输入错误 
	if( !cin.bad() ){
		cout << "输入有误！\n\n"; 
		cin.clear();
		cin.sync();
		return;
	}	
	store.push_back( Book(name,bno,tp,pri) );
	cout << "新建图书成功！\n\n";
}

void Library::broBook()
{
	cout << "--------------------------图书借阅--------------------------\n\n"; 
	string bno;
	cout << "请输入要借阅图书的编号：";
	cin  >> bno;
	 
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		if( (*it).getBno() == bno ){
			if( (*it).getTag() == false ){
				cout << "此书已被借出！\n\n";
				return;
			}
			(*it).setTag(false);	//	标记为借出状态 
			( user.getBro() ).push_back(*it);
			cout << (*it).getName() << " " << bno << endl;	//打印信息 
			cout << "借阅成功！\n"; 
			return;
		}
	}
	cout << "查无此书！\n\n";			
}
	
void Library::retBook()
{
	cout << "--------------------------图书归还--------------------------\n\n"; 
	string bno;
	cout << "请输入要归还图书的编号：";
	cin  >> bno;
	
	vector<Book> bro = user.getBro();
	for(vector<Book>::iterator it = bro.begin(); it != bro.end(); ++it)
	{
		if( (*it).getBno() == bno )
		{
			//	首先图书馆借阅记录变更为未借出 
			for(vector<Book>::iterator x = store.begin(); x != store.end(); ++x){
				if( (*x).getBno() == bno ){
					(*x).setTag(true);
					break;
				}
			} 
			bro.erase(it);		//	再删除该学生此书的借书记录 
			cout << (*it).getName() << " " << bno << " ";	//打印信息 
			cout << "归还成功！\n\n"; 
			return;
		}
	}
	cout << "您的借书记录中无此书信息！\n\n"; 
}
