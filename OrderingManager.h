#pragma once
#include<iostream>
#include"Manager.h"
#include"Waiter.h"
#include"Menu.h"
#define FILENAME2 "AccountInfo.txt"
class OrderingManager
{
public:
	//����Ա(Ψһ)
	Manager manager;
	//����Ա����״̬
	bool fileExist = false;
	//����Ա����
	int W_num;
	//���캯��
	OrderingManager();

	//����Աע�ắ��
	void ManagerRegis ();
	//����Ա��¼����
	void ManagerLogin();
	//�����ܽ���
	void ManageUI();
	//����˵��ӿ�
	void ManageMenu();
	//��ʼ���ļ�״̬�ж�
	bool FileState();
	//����Ա�˺�����
	void Destroy_ManagerAccount();

	//Ա����¼����
	void WaiterLogin();
	//Ա������ӿ�
	void ManageWaiter();
	//Ա��Ȩ�޽���
	void SimpleUI();
	//Ա���˵��ӿ�
	void SimpleMenu();
	
	
};