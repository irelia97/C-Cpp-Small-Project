#include <string>
#include "Idiom.h"

string Idiom::GetIdiom()
{
	return this->idiom;
}
	
string Idiom::GetFriHint()
{
	return this->hint;
}
	
string Idiom::GetSecHint()
{
	string str = this->idiom.substr(0,2);
	return str;
}

string Idiom::GetThiHint()
{
	string str = this->idiom.substr(0,4);
	return str;
}
