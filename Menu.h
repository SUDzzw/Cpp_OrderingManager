#pragma once
#include<fstream>
#define FILENAME "Menu.txt"
#include"Dish.h"

class Menu
{
public:
	int D_num;//��Ʒ����
	int Add_num;// �����Ʒ��Ŀ
	//�ļ����ڱ�־
	bool fileExist;
	Dish* head;//��Ʒ��ͷָ��
	//���캯��
	Menu();
	//��������
	~Menu();
	//�˵�չʾ
	void ShowMenu();
	//��Ӳ�Ʒ
	void Add_Dish();
	//��������
	void saveDish();
	//��ʼ������
	void Init_DishList();    
	//ɾ����Ʒ
	void Del_Dish();
	//��ȡ��Ʒ����
	int Get_DishNum();
	//��ʼ���ļ�״̬�ж�
	bool FileState();
	//���Ҳ�Ʒ��Ϣ
	void Search_Dish();
	//�޸Ĳ�Ʒ��Ϣ
	void Mol_Dish();
	//��Ʒ��Ϣ����
	void Sort_Dish();
	////��Ʒ�������������ϲ������㷨��
	Dish* merge(Dish* left, Dish* right, bool ascending, bool byPrice);
	Dish* getMiddle(Dish* head);
	Dish* mergeSort(Dish* head, bool ascending, bool byPrice);
	//��Ʒ��Ϣ����
	void Destory_Dish();
};