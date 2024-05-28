#pragma once
#include"User.h"
#include"Dish.h"
#include"Menu.h"
#include"Waiter.h"
#define FILENAME3 "WaiterList.txt"
class Manager :public User
{
private:
	const int M_num = 1;//仅存在一个管理者
public:
	//账号存在标志
	bool accountExist = false;
	//员工文件存在标志
	bool WaiterFileExist = false;
	//员工数量
	int W_num;
	//员工数量
	int add_num;
	//员工头指针
	Waiter* head;
	//管理员管理菜单类的权限
	Menu menu;
	//构造函数
	Manager();
	//员工管理
	//1.添加员工
	void Add_Waiter();
	//员工一览
	void ShowWaiter();
	//保存数据
	void saveWaiter();
	//初始化链表
	void Init_WaiterList();
	//删除员工
	void Del_Waiter();
	//获取员工数量
	int Get_WaiterNum();
	//初始化文件状态判断
	bool FileState();
	//查找员工信息
	void Search_Waiter();
	//修改员工信息
	void Mol_Waiter();
	//员工信息排序
	void Sort_Waiter();
	Waiter* mergeSort(Waiter* head, bool ascending);
	Waiter* merge(Waiter* left, Waiter* right, bool ascending);
	Waiter* getMiddle(Waiter* head);
	//员工信息销毁
	void Destory_Waiter();
};