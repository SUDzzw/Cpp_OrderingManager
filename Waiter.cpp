#include"Waiter.h"
Waiter::Waiter(string id,string name,int exp)
{
	this->ID = id;
	this->W_name = name;
	this->user = waiter;
	this->experience = exp;
	next = NULL;
}
void Waiter::showInfo()
{
	cout << "Ա��ID��" << this->ID << endl;
	cout << "Ա��������" << this->W_name << endl;
	cout << "Ա�����飺" << this->experience << endl;
}