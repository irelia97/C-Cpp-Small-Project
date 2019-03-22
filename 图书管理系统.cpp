#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

//	ͼ���� 
class Book
{
	private:
		string name;	//�鱾���� 
		string bno;		//�鱾���
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

//	ѧ����	
class Student
{
	private:
		string name;		//ѧ������ 
		string sno;			//ѧ��ѧ�� 
		string psw;			//��¼���� 
		vector<Book> bro;	//�����¼
	public:
	   ~Student() {}	
		Student() {}
		Student(string nm, string no, string pw):name(nm),sno(no),psw(pw) {}
		
		const string& getName() { return name; }
		const string& getSno() { return sno; }
		const string& getPsw() { return psw; }
		vector<Book>& getBro() { return bro; }
};

//	ͼ����� 
class Library
{
	private:
		string  name;			//���� 
		Student user;			//��ǰ�û� 
		vector<Book> store;		//ͼ��洢
		vector<Student> stu;	//ѧ���洢 
	public:
	   ~Library() {}	
		Library(string nm);		
		const string& getName() { return name; }
		
		void Register();		//ѧ��ע�� 
		bool Login(); 			//��¼ 
		void Menu1();			//��¼����
		
		void Menu2();			//���ܽ��� 
		void storeList();		//ͼ��ݿ���嵥 
		void broList();			//�û������嵥 
	
		bool findBook(); 		//����ͼ�� 
		void delBook();			//ɾ��ͼ�� 
		void addBook();			//�½�ͼ�� 		
		void broBook();			//���� 
		void retBook();			//���� 
};

const string libraryName = "��ɽ��һ��ͼ���";		 
		
int main()
{
	Library l1(libraryName); 	
	return 0;
}

Library::Library(string nm):name(nm)
{
	//	ѧ������Ĭ��һ������Ա��Ա 
	Student admin("Admin", "000001", "123456");
	stu.push_back(admin);
	Menu1();
}

void Library::Register()
{
	string sno, name, psw;
	cout << "-----------------ͼ���ѧ����Ϣע��-----------------\n\n";
	cout << "������ѧ�ţ�";
	cin  >> sno;
	
	//	���ѧ���Ƿ�ע�� 
	for(vector<Student>::iterator it = stu.begin(); it != stu.end(); ++it)
	{
		if( (*it).getSno() == sno ){
			cout << "��ѧ���Ѿ�ע�ᣡ\n";
			return;
		}
	}		
	
	cout << "���������룺";
	cin  >>  psw;
	cout << "������������";
	cin  >> name;
	stu.push_back( Student(name, sno, psw) ); 
	cout << "\n\nע��ɹ���\n\n";		
}

bool Library::Login()
{	
	cout << "-------------------" << name << "��¼����-------------------\n\n";	
	string sno, psw;
	cout << "ѧ�ţ�";
	cin  >> sno;
	cout << "���룺";
	cin  >> psw; 
	
	for(vector<Student>::iterator it = stu.begin(); it != stu.end(); ++it)
	{
		if( (*it).getSno()==sno && (*it).getPsw()==psw )	//ѧ�����������ȷ
		{
			user = *it;
			cout << "��½�ɹ���\n\n";
			return true;
		}
		if( (*it).getSno()==sno && (*it).getPsw()!=psw )	//���벻��ȷ
		{
			cout << "�������\n\n";
			return false;
		}
	}
	cout << "�޴��˺ţ�\n\n"; 
	return false;		  	
}

void Library::Menu1()
{
	int  index = 0;
	bool flag = true;
	do{
		system("cls");
		cout << "-------------------��ӭ����" << name << "-------------------\n\n";
		cout << "1. ѧ��ע��\n2. ��¼\n3. �뿪\n\n";
		cout << "����Ա�˺ţ�000001   ����Ա���룺123456\n"; 
		cout << "------------------------------------------------------------\n\n";
		cout << "��ѡ���ܣ�";
		
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
				cout << "�����˳����´��ټ���\n\n";
				break;
			default:
				cout << "�����������������룡";
				cin.clear();	//cin����Ϊ��Ч״̬ 
				cin.sync();		//��������� 
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
		cout << "-------------------" << user.getName() << "���ã���ӭ��ʹ�ø�ϵͳ-------------------\n\n";
		cout << "����ǰ��״̬��";
		if( user.getSno() == "000001" ){
			cout << "����Ա\n\n";
		}else{
			cout << "�û�\n\n";
		}
		
		cout << "1. �½�ͼ��\n2. ɾ��ͼ��\n3. ����ͼ��\n4. ����ͼ��\n";
		cout << "5. �黹ͼ��\n6. ͼ���嵥\n7. �����嵥\n8. ע��\n\n";
		cout << "------------------------------------------------------------\n\n";
		cout << "��ѡ���ܣ�";
		
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
				cout << "�����������������룡";
				cin.clear();
				cin.sync();
				break;
		}
		system("pause");
	}while(flag);		
}

void Library::storeList()	
{
	cout << "ͼ������        ͼ����        ͼ������        ����    ״̬\n";
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		cout << setiosflags(ios::left)
			 << setw(16) << (*it).getName()
			 << setw(16) << (*it).getBno()
			 << setw(16) << (*it).getType()
			 << setw(8) << (*it).getPrice();
		if( (*it).getTag() == true ){
			cout << setw(4) << "δ��" << endl;
		}else{
			cout << setw(4) << "�ѽ�" << endl;
		}
	}
}
void Library::broList()			 
{
	vector<Book> bro = user.getBro();
	
	cout << "ͼ������        ͼ����        ͼ������        ����\n";	
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
	cout << "--------------------------ͼ�����--------------------------\n\n"; 
	string bno;
	cout << "������Ҫ����ͼ��ı�ţ�";
	cin  >> bno;
	 
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		if( (*it).getBno() == bno ){
			cout << "��" << (*it).getName() << "�� " << bno << endl;	//��ӡ��Ϣ 
			return true;
		}
	}
	cout << "���޴��飡\n\n"; 
	return false;
}

void Library::delBook()
{
	if( user.getSno() != "000001" ){
		cout << "ֻ�й���Ա�ܽ��д˲�����";
		return;
	}
	cout << "--------------------------ͼ��ɾ��--------------------------\n\n"; 	
	string bno;
	cout << "������Ҫɾ��ͼ��ı�ţ�";
	cin  >> bno;	
						
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		if( (*it).getBno() == bno ){
			store.erase(it);	//	ɾ�� 
			return;
		}
	}
	cout << "���޴��飡\n\n";
}			

void Library::addBook()
{
	if( user.getSno() != "000001" ){
		cout << "ֻ�й���Ա�ܽ��д˲�����";
		return;
	}
	cout << "--------------------------ͼ�����--------------------------\n\n"; 	
	string name, bno, tp;
	double pri;
	cout << "����������ͼ���������";
	cin  >> name;
	cout << "����������ͼ��ı�ţ�";
	cin  >> bno;
	cout << "����������ͼ������ࣺ";
	cin  >> tp;
	cout << "����������ͼ��ĵ��ۣ�";
	cin  >> pri;
	
	//	�жϵ����Ƿ�������� 
	if( !cin.bad() ){
		cout << "��������\n\n"; 
		cin.clear();
		cin.sync();
		return;
	}	
	store.push_back( Book(name,bno,tp,pri) );
	cout << "�½�ͼ��ɹ���\n\n";
}

void Library::broBook()
{
	cout << "--------------------------ͼ�����--------------------------\n\n"; 
	string bno;
	cout << "������Ҫ����ͼ��ı�ţ�";
	cin  >> bno;
	 
	for(vector<Book>::iterator it = store.begin(); it != store.end(); ++it)
	{
		if( (*it).getBno() == bno ){
			if( (*it).getTag() == false ){
				cout << "�����ѱ������\n\n";
				return;
			}
			(*it).setTag(false);	//	���Ϊ���״̬ 
			( user.getBro() ).push_back(*it);
			cout << (*it).getName() << " " << bno << endl;	//��ӡ��Ϣ 
			cout << "���ĳɹ���\n"; 
			return;
		}
	}
	cout << "���޴��飡\n\n";			
}
	
void Library::retBook()
{
	cout << "--------------------------ͼ��黹--------------------------\n\n"; 
	string bno;
	cout << "������Ҫ�黹ͼ��ı�ţ�";
	cin  >> bno;
	
	vector<Book> bro = user.getBro();
	for(vector<Book>::iterator it = bro.begin(); it != bro.end(); ++it)
	{
		if( (*it).getBno() == bno )
		{
			//	����ͼ��ݽ��ļ�¼���Ϊδ��� 
			for(vector<Book>::iterator x = store.begin(); x != store.end(); ++x){
				if( (*x).getBno() == bno ){
					(*x).setTag(true);
					break;
				}
			} 
			bro.erase(it);		//	��ɾ����ѧ������Ľ����¼ 
			cout << (*it).getName() << " " << bno << " ";	//��ӡ��Ϣ 
			cout << "�黹�ɹ���\n\n"; 
			return;
		}
	}
	cout << "���Ľ����¼���޴�����Ϣ��\n\n"; 
}
