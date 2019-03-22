#include "hair.h"

Hair::Hair(const string& _proj, const int& _price)
:proj(_proj), price(_price)
{
	
}

string Hair::GetProj()
{
	return proj;
}

int Hair::GetPrice()
{
	return price;
}

bool Hair::SetProj(const string& _proj)
{
	if(_proj.size() == 0)
		return false;
		
	proj = _proj;
	return true;
}

bool Hair::SetPrice(const int& _price)
{
	if(_price <= 0)
		return false;
		
	price = _price;
	return true;
}
