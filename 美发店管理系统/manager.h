#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "cusAndworker.h"
#include <vector>
using namespace std;

class Manager
{
	private:
		vector<Worker>   worker;
		vector<Customer> customer;
	public:
		Manager(){Menu();}
	   ~Manager(){}
	    
	    Customer* GetNewCustomer(const string&);
	    Worker*   GetNewWorker(const string&);
	    
	    bool Add();    
	    bool Del();
	    bool Mdf();
	    bool Find();
	    vector<Customer>::iterator FindCus(const string&);
		vector<Worker>::iterator   FindWor(const string&);
			   
	    void Menu();
	    bool Input();
	    bool OutPut();
	    void Print();
};

#endif
