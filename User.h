#pragma once
#include<iostream>
#include<string>

//设置用户类的权限等级为两极
enum UserRank {waiter,manager};

using namespace std;
class User
{
public:
	//用户ID
	string ID;
	//用户密码
	string password;
	//用户权限
	UserRank user;
};