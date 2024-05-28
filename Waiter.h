#pragma once
#include"User.h"
#include"Dish.h"
#include"Menu.h"
class Waiter :public User
{
public:
	//员工姓名
	string W_name;
	//服务次数
	int experience;
	//指向下一个员工结点
	Waiter* next;
	//构造函数
	Waiter(string id,string name, int exp);
	//显示服务员信息
	void showInfo();
};