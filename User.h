#pragma once
#include<iostream>
#include<string>

//�����û����Ȩ�޵ȼ�Ϊ����
enum UserRank {waiter,manager};

using namespace std;
class User
{
public:
	//�û�ID
	string ID;
	//�û�����
	string password;
	//�û�Ȩ��
	UserRank user;
};