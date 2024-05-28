#pragma once
#include"User.h"
#include"Dish.h"
#include"Menu.h"
#include"Waiter.h"
#define FILENAME3 "WaiterList.txt"
class Manager :public User
{
private:
	const int M_num = 1;//������һ��������
public:
	//�˺Ŵ��ڱ�־
	bool accountExist = false;
	//Ա���ļ����ڱ�־
	bool WaiterFileExist = false;
	//Ա������
	int W_num;
	//Ա������
	int add_num;
	//Ա��ͷָ��
	Waiter* head;
	//����Ա����˵����Ȩ��
	Menu menu;
	//���캯��
	Manager();
	//Ա������
	//1.���Ա��
	void Add_Waiter();
	//Ա��һ��
	void ShowWaiter();
	//��������
	void saveWaiter();
	//��ʼ������
	void Init_WaiterList();
	//ɾ��Ա��
	void Del_Waiter();
	//��ȡԱ������
	int Get_WaiterNum();
	//��ʼ���ļ�״̬�ж�
	bool FileState();
	//����Ա����Ϣ
	void Search_Waiter();
	//�޸�Ա����Ϣ
	void Mol_Waiter();
	//Ա����Ϣ����
	void Sort_Waiter();
	Waiter* mergeSort(Waiter* head, bool ascending);
	Waiter* merge(Waiter* left, Waiter* right, bool ascending);
	Waiter* getMiddle(Waiter* head);
	//Ա����Ϣ����
	void Destory_Waiter();
};