#include"Menu.h"
//构造函数
Menu::Menu()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//尝试读文件
	if (!ifs.is_open())
	{
		cout << "数据载体为空..." << endl;
		//初始化菜品数为零
		this->D_num = 0;
		//头指针置为空
		this->head = NULL;
		//文件不存在
		this->fileExist = false;
		ifs.close();
		return;
	}
	//2.文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "无数据..." << endl;
		//初始化菜品数为零
		this->D_num = 0;
		//头指针置为空
		this->head = NULL;
		//文件存在
		this->fileExist = true;
		ifs.close();
		return;
	}
	//3.文件存在且有数据，从文件中读取并录入链表
	int num = this->Get_DishNum();
	//cout << "数据初始化中..." << endl;
	//cout << "当前已有菜品数量为：" << num << endl;
	this->D_num = num;//更新数量  
	this->Init_DishList();
	//测试
	
}
//析构函数
Menu::~Menu()
{
	// 释放链表中的所有节点
	while (head) 
	{
		Dish* temp = head;
		head = head->next;
		delete temp;
	}
}
//菜单展示
void Menu::ShowMenu()
{
	bool fileState = FileState();
	if (fileState)
	{
		Dish* pCurrent = head;
		cout << "********************************今日菜单************************************" << endl;
		while (pCurrent)
		{
			cout << "* 菜品编号: " << setw(4) << pCurrent->D_id
				<< "  菜品名称: " << setw(8) << pCurrent->D_name
				<< "  菜品特色: " << setw(8) << pCurrent->D_feature
				<< "  菜品价格: " << setw(4) << pCurrent->D_price << "￥ *" << endl;
			pCurrent = pCurrent->next;
		}
		cout << "****************************************************************************" << endl;
	}
	else
	{
		cout << "*****无菜品数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//添加菜品
void Menu::Add_Dish()
{
	cout << "请输入要添加菜品的数量：" << endl;
	cin >> Add_num;

	if (Add_num > 0)
	{
		D_num += Add_num;
		for (int i = 0; i < Add_num; i++)
		{
			int id;
			string name;
			string feature;
			double price;
			int id_Exits = 1;
			cout << "请输入第" << i + 1 << "个新菜品编号：" << endl;
			cin >> id;
			//检查该id是否存在
			if (head != NULL && head->D_id == id)
			{
				cout << "此编号已存在，请重新输入！" << endl;
				id_Exits = 0;
				i--;
			}
			else
			{
				// 遍历链表找到要查找的节点
				Dish* pCurrent = head;
				Dish* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->D_id != id)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// 如果找到了节点
				if (pCurrent != NULL)
				{
					cout << "此编号已存在，请重新输入！" << endl;
					id_Exits = 0;
					i--;
				}
			}
			if (id_Exits)
			{
				cout << "请输入第" << i + 1 << "个新菜品名称：" << endl;
				cin >> name;
				cout << "请输入第" << i + 1 << "个新菜品特色：" << endl;
				cin >> feature;
				cout << "请输入第" << i + 1 << "个新菜品价格：" << endl;
				cin >> price;
				Dish* newDish = new Dish(id, name, feature, price);

				if (head == NULL)
				{
					head = newDish;
				}
				else
				{
					Dish* pCurrent = head;
					while (pCurrent->next != NULL)
					{
						pCurrent = pCurrent->next;
					}
					pCurrent->next = newDish;
					//newDish->next = NULL;  			}
				}
			}
		}
	}
	this->saveDish();
	system("pause");
	system("cls");
}
//获取菜品数量
int Menu::Get_DishNum()
{
	ifstream ifs;
	int num = 0;
	int id;
	string name;
	string feature;
	double price;
	ifs.open(FILENAME, ios::in);//打开并读文件
	while (ifs >> id && ifs >> name && ifs >> feature&&ifs>>price)
	{
		//统计人数
		num++;
	}

	return num;
}
void Menu::Init_DishList()
{
	ifstream ifs(FILENAME, ios::in); // 打开文件并读取
	if (!ifs.is_open()) {
		cout << "无法打开文件或文件不存在..." << endl;
		return;
	}

	int id;
	string name;
	string feature;
	double price;

	while (ifs >> id >> name >> feature >> price) {
		// 创建一个新的菜品对象
		Dish* newDish = new Dish(id, name, feature, price);

		// 将菜品对象添加到链表中
		if (head == NULL) {
			head = newDish;
		}
		else {
			Dish* pCurrent = head;
			while (pCurrent->next != NULL) {
				pCurrent = pCurrent->next;
			}
			pCurrent->next = newDish;
		}
	}

	ifs.close();
}
//初始化文件状态判断
bool Menu::FileState() 
{
	ifstream ifs(FILENAME, ios::in); // 打开文件并读取
	if (!ifs.is_open()) {
		cout << "无法打开文件或文件不存在..." << endl;
		return false;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "无数据..." << endl;
		//文件存在
		this->fileExist = true;
		ifs.close();
		return false;
	}
	return true;
}

//保存数据
void Menu::saveDish() 
{
	ofstream ofs(FILENAME, ios::out); // 打开文件以写入数据
	if (!ofs.is_open()) 
	{
		cout << "无菜品数据" << endl;
		return;
	}

	Dish* pCurrent = head;
	while (pCurrent) 
	{
		ofs << pCurrent->D_id << " " << pCurrent->D_name << " " << pCurrent->D_feature << " " << pCurrent->D_price << endl;
		pCurrent = pCurrent->next;
	}

	ofs.close();
}
//删除菜品
void Menu::Del_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		int id;
		cout << "请输入要删除的菜品编号：" << endl;
		cin >> id;
		// 检查头节点是否是要删除的节点
		if (head != NULL && head->D_id == id)
		{
			Dish* temp = head;
			head = head->next;
			delete temp;
			D_num--;
			cout << "菜品删除成功!" << endl;
		}
		else
		{
			// 遍历链表找到要删除的节点
			Dish* pCurrent = head;
			Dish* pPrevious = NULL;
			while (pCurrent != NULL && pCurrent->D_id != id)
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->next;
			}

			// 如果找到了节点
			if (pCurrent != NULL)
			{
				pPrevious->next = pCurrent->next;
				delete pCurrent;
				D_num--;
				cout << "菜品删除成功!" << endl;
			}
			else
			{
				cout << "未找到编号为 " << id << " 的菜品。" << endl;
			}
		}

		// 保存当前链表到文件
		this->saveDish();

	}
	else
	{
		cout << "*****无菜品数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//查找菜品信息
void Menu::Search_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		int id;
		string name;
		cout << "请选择查找方式：" << endl;
		cout << "1.按菜品编号查找：" << endl;
		cout << "2.按菜品名称查找：" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入查找菜品编号：" << endl;
			cin >> id;
			// 检查头节点是否是要查找的节点
			if (head != NULL && head->D_id == id)
			{
				head->ShowDish();
			}
			else
			{
				// 遍历链表找到要查找的节点
				Dish* pCurrent = head;
				Dish* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->D_id != id)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// 如果找到了节点
				if (pCurrent != NULL)
				{
					pCurrent->ShowDish();
				}
				else
				{
					cout << "未找到编号为 " << id << " 的菜品。" << endl;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "请输入查找菜品名称：" << endl;
			cin >> name;
			// 检查头节点是否是要查找的节点
			if (head != NULL && head->D_name == name)
			{
				cout << "查找菜品信息为：" << endl;
				head->ShowDish();
			}
			else
			{
				// 遍历链表找到要查找的节点
				Dish* pCurrent = head;
				Dish* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->D_name != name)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// 如果找到了节点
				if (pCurrent != NULL)
				{
					cout << "查找菜品信息为：" << endl;
					pCurrent->ShowDish();
				}
				else
				{
					cout << "未找到名称为 " <<  name  << " 的菜品。" << endl;
				}
			}
		}
		else
		{
			cout << "请输入正确选择！" << endl;
		}

	}
	else
	{
		cout << "*****无菜品数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//修改菜品信息
void Menu::Mol_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		int id;
		cout << "请输入修改菜品编号：" << endl;
		cin >> id;

		int new_id;
		string new_name;
		string new_feature;
		double new_price;

		// 检查头节点是否是要修改的节点
		if (head != NULL && head->D_id == id)
		{
			cout << "请输入新的菜品编号：" << endl;
			cin >> new_id;
			cout << "请输入新的菜品名称：" << endl;
			cin >> new_name;
			cout << "请输入新的菜品特色：" << endl;
			cin >> new_feature;
			cout << "请输入新的菜品价格：" << endl;
			cin >> new_price;

			head->D_id = new_id;
			head->D_name = new_name;
			head->D_feature = new_feature;
			head->D_price = new_price;

			cout << "菜品编号 " << id << " 修改成功。" << endl;
		}
		else
		{
			// 遍历链表找到要修改的节点
			Dish* pCurrent = head;
			while (pCurrent != NULL && pCurrent->D_id != id)
			{
				pCurrent = pCurrent->next;
			}

			// 如果找到了节点
			if (pCurrent != NULL)
			{
				cout << "请输入新的菜品编号：" << endl;
				cin >> new_id;
				cout << "请输入新的菜品名称：" << endl;
				cin >> new_name;
				cout << "请输入新的菜品特色：" << endl;
				cin >> new_feature;
				cout << "请输入新的菜品价格：" << endl;
				cin >> new_price;

				pCurrent->D_id = new_id;
				pCurrent->D_name = new_name;
				pCurrent->D_feature = new_feature;
				pCurrent->D_price = new_price;

				cout << "菜品编号 " << id << " 修改成功。" << endl;
			}
			else
			{
				cout << "未找到编号为 " << id << " 的菜品。" << endl;
			}
		}
		this->saveDish();
	}
	else
	{
		cout << "*****无菜品数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//菜品信息排序
void Menu::Sort_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		cout << "请选择菜品排序方式：" << endl;
		cout << "1.菜品编号升序排序" << endl;
		cout << "2.菜品编号降序排序" << endl;
		cout << "3.菜品价格升序排序" << endl;
		cout << "4.菜品价格降序排序" << endl;
		int choice;
		cin >> choice;

		bool ascending = true;//升降序标志
		bool byPrice = false;//是否按价格排序标志

		switch (choice)
		{
		case 1:
			ascending = true;
			byPrice = false;
			break;
		case 2:
			ascending = false;
			byPrice = false;
			break;
		case 3:
			ascending = true;
			byPrice = true;
			break;
		case 4:
			ascending = false;
			byPrice = true;
			break;
		default:
			cout << "请输入正确的选择！" << endl;
			return;
		}

		head = mergeSort(head, ascending, byPrice);
		cout << "排序完成!" << endl;
		cout << "菜单更新如下：" << endl;
		this->ShowMenu();
		this->saveDish();
	}
	else
	{
		cout << "*****无菜品数据*****" << endl;
	}
	system("pause");
	system("cls");
}

//菜品排序辅助函数（合并排序算法）
//合并排序
Dish* Menu::merge(Dish* left, Dish* right, bool ascending, bool byPrice) 
{	
	//判断左右结点是否为空
	if (!left) 
		return right;
	if (!right) 
		return left;

	Dish* result = NULL;

	if (ascending) //升序
	{
		if ((byPrice && left->D_price <= right->D_price) || (!byPrice && left->D_id <= right->D_id)) 
		{
			result = left;
			result->next = merge(left->next, right, ascending, byPrice);
		}
		else 
		{
			result = right;
			result->next = merge(left, right->next, ascending, byPrice);
		}
	}
	else //降序
	{
		if ((byPrice && left->D_price >= right->D_price) || (!byPrice && left->D_id >= right->D_id)) 
		{
			result = left;
			result->next = merge(left->next, right, ascending, byPrice);
		}
		else 
		{
			result = right;
			result->next = merge(left, right->next, ascending, byPrice);
		}
	}

	return result;
}
//找到中间结点
Dish* Menu::getMiddle(Dish* head) 
{
	if (!head) 
		return head;

	Dish* slow = head;
	Dish* fast = head->next;

	while (fast != NULL) 
	{
		fast = fast->next;
		if (fast != NULL) 
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}
//执行合并排序
Dish* Menu::mergeSort(Dish* head, bool ascending, bool byPrice) 
{
	if (!head || !head->next) 
		return head;

	Dish* middle = getMiddle(head);
	Dish* nextOfMiddle = middle->next;
	middle->next = NULL;

	Dish* left = mergeSort(head, ascending, byPrice);
	Dish* right = mergeSort(nextOfMiddle, ascending, byPrice);

	return merge(left, right, ascending, byPrice);
}
//菜品信息销毁
void Menu::Destory_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		cout << "确认销毁？" << endl;
		cout << "1.确认" << endl;
		cout << "2.取消" << endl;
		int choice1;
		int choice2;
		cin >> choice1;
		if (choice1 == 1)
		{
			cout << "请再次确认！" << endl;
			cout << "1.确认" << endl;
			cout << "2.取消" << endl;
			cin >> choice2;
			if (choice2 == 1)
			{
				ofstream ofs(FILENAME, ios::trunc);
				ofs.close();
				while (this->head)
				{
					Dish* temp = head;
					head = head->next;
					delete temp;
				}
				cout << "菜品数据销毁成功！" << endl;
			}
			else
			{
				cout << "取消成功！" << endl;
			}
		}
		else
		{
			cout << "取消成功！" << endl;
		}
	}
	else
	{
		cout << "*****无菜品数据*****" << endl;
	}
	system("pause");
	system("cls");
}
