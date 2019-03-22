#include "cusAndworker.h"

/* 		  Customer¹Ë¿Í 		*/

Customer::Customer(const string& _card, const string& _name, const string& _sex, const string& _tel)
:cardnum(_card), name(_name), sex(_sex), tel(_tel)
{
	
}

string Customer::GetCardNum()
{
	return cardnum;
}

string Customer::GetName()
{
	return name;
}

string Customer::GetSex()
{
	return sex;
}

string Customer::GetTel()
{
	return tel;
}

bool Customer::SetCardNum(const string& _cardnum)
{
	if(_cardnum.size() == 0)
		return false;
		
	cardnum = _cardnum;
	return true;
}

bool Customer::SetName(const string& _name)
{
	if(_name.size() == 0)
		return false;
		
	name = _name;
	return true;
}

bool Customer::SetSex(const string& _sex)
{
	if(_sex.size() == 0)
		return false;
		
	sex = _sex;
	return true;
}

bool Customer::SetTel(const string& _tel)
{
	if(_tel.size() == 0)
		return false;
		
	tel = _tel;
	return true;
}


/*        WorkerÔ±¹¤        */

Worker::Worker(const string& _num, const string& _name, const string& _sex, 
const string& _tel, const string& _proj, const int& _price)
:num(_num), name(_name), sex(_sex), tel(_tel), pro(_proj, _price)
{

}

string Worker::GetNum()
{
	return num;
}

string Worker::GetName()
{
	return name;
}

string Worker::GetSex()
{
	return sex;
}

string Worker::GetTel()
{
	return tel;
}

Hair& Worker::GetPro()
{
	return pro;
}

bool Worker::SetCardNum(const string& _num)
{
	if(_num.size()==0)
		return false;
		
	num = _num;
	return true;
}

bool Worker::SetName(const string& _name)
{
	if(_name.size() == 0)
		return false;
		
	name = _name;
	return true;
}

bool Worker::SetSex(const string& _sex)
{
	if(_sex.size() == 0)
		return false;
		
	sex = _sex;
	return true;
}

bool Worker::SetTel(const string& _tel)
{
	if(_tel.size() == 0)
		return false;
		
	tel = _tel;
	return true;
}

bool Worker::SetPro(const string& _proj, const int& _price)
{
	if( pro.SetProj(_proj) && pro.SetPrice(_price) )
		return true;
	else
		return false;
}
