#pragma once
#include<fstream>
#define FILENAME "Menu.txt"
#include"Dish.h"

class Menu
{
public:
	int D_num;//菜品总量
	int Add_num;// 新添菜品数目
	//文件存在标志
	bool fileExist;
	Dish* head;//菜品的头指针
	//构造函数
	Menu();
	//析构函数
	~Menu();
	//菜单展示
	void ShowMenu();
	//添加菜品
	void Add_Dish();
	//保存数据
	void saveDish();
	//初始化链表
	void Init_DishList();    
	//删除菜品
	void Del_Dish();
	//获取菜品数量
	int Get_DishNum();
	//初始化文件状态判断
	bool FileState();
	//查找菜品信息
	void Search_Dish();
	//修改菜品信息
	void Mol_Dish();
	//菜品信息排序
	void Sort_Dish();
	////菜品排序辅助函数（合并排序算法）
	Dish* merge(Dish* left, Dish* right, bool ascending, bool byPrice);
	Dish* getMiddle(Dish* head);
	Dish* mergeSort(Dish* head, bool ascending, bool byPrice);
	//菜品信息销毁
	void Destory_Dish();
};