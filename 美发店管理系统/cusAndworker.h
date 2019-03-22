#ifndef _CUSANDWORKER_H_
#define _CUSANDWORKER_H_

#include "hair.h"
using std::string;

class Customer
{
	private:
		string cardnum;
		string name;
		string sex;	
		string tel;
	public:
		Customer(){}
		Customer(const string&, const string&, const string&, const string&);
	   ~Customer(){}
	   
	    string GetCardNum();
	    string GetName();
	    string GetSex();
	    string GetTel();
	    
	    bool SetCardNum(const string&);
	    bool SetName(const string&);
	    bool SetSex(const string&);
	    bool SetTel(const string&);		
};


class Worker
{
	private:
		string num;
		string name;
		string sex;	
		string tel;
		Hair   pro;
	public:
		Worker(){}
		Worker(const string&, const string&, const string&, 
		const string&, const string&, const int&);
	   ~Worker(){}
	   
	    string GetNum();
	    string GetName();
	    string GetSex();
	    string GetTel();
	    Hair&  GetPro();
	    
	    bool SetCardNum(const string&);
	    bool SetName(const string&);
	    bool SetSex(const string&);
	    bool SetTel(const string&);
	    bool SetPro(const string&, const int&);
};

#endif
