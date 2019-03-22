#ifndef _HAIR_H_
#define _HAIR_H_

#include <string>
using std::string;

class Hair
{
	private:
		string proj;
		int price;
	public:
		Hair(){}
        Hair(const string&, const int&);
       ~Hair(){}
       
        string GetProj();
        int GetPrice();
        
        bool SetProj(const string&);
        bool SetPrice(const int&);
};

#endif
