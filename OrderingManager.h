#pragma once
#include<iostream>
#include"Manager.h"
#include"Waiter.h"
#include"Menu.h"
#define FILENAME2 "AccountInfo.txt"
class OrderingManager
{
public:
	//管理员(唯一)
	Manager manager;
	//管理员存在状态
	bool fileExist = false;
	//服务员人数
	int W_num;
	//构造函数
	OrderingManager();

	//管理员注册函数
	void ManagerRegis ();
	//管理员登录函数
	void ManagerLogin();
	//管理功能界面
	void ManageUI();
	//管理菜单接口
	void ManageMenu();
	//初始化文件状态判断
	bool FileState();
	//管理员账号销毁
	void Destroy_ManagerAccount();

	//员工登录函数
	void WaiterLogin();
	//员工管理接口
	void ManageWaiter();
	//员工权限界面
	void SimpleUI();
	//员工菜单接口
	void SimpleMenu();
	
	
};