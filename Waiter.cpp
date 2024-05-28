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
	cout << "员工ID：" << this->ID << endl;
	cout << "员工姓名：" << this->W_name << endl;
	cout << "员工经验：" << this->experience << endl;
}