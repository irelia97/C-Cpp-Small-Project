#ifndef _IDIOM_H_
#define _IDIOM_H_

#include <string>
using std::string;	//	ʹ�� string��������ռ� 

class Idiom
{
	private:
		string idiom;
		string hint;
	public:
		Idiom(string _idiom, string _hint):idiom(_idiom),hint(_hint){}
		Idiom(){}
	   ~Idiom(){}
	    string GetIdiom();		//��ȡ���� 
	    string GetFriHint();	//һ����ʾ 
	    string GetSecHint();	//������ʾ 
	    string GetThiHint();	//������ʾ 
};

#endif
	
