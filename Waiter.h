#pragma once
#include"User.h"
#include"Dish.h"
#include"Menu.h"
class Waiter :public User
{
public:
	//Ա������
	string W_name;
	//�������
	int experience;
	//ָ����һ��Ա�����
	Waiter* next;
	//���캯��
	Waiter(string id,string name, int exp);
	//��ʾ����Ա��Ϣ
	void showInfo();
};