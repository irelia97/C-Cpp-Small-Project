#ifndef _IDIOM_H_
#define _IDIOM_H_

#include <string>
using std::string;	//	使用 string类的域名空间 

class Idiom
{
	private:
		string idiom;
		string hint;
	public:
		Idiom(string _idiom, string _hint):idiom(_idiom),hint(_hint){}
		Idiom(){}
	   ~Idiom(){}
	    string GetIdiom();		//获取成语 
	    string GetFriHint();	//一级提示 
	    string GetSecHint();	//二级提示 
	    string GetThiHint();	//三级提示 
};

#endif
	
