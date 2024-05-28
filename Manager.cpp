#include"Manager.h"

//构造函数
Manager::Manager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME3, ios::in);//尝试读文件
	if (!ifs.is_open())
	{
		cout << "数据载体为空..." << endl;
		this->W_num = 0;
		//头指针置为空
		this->head = NULL;
		//文件不存在
		this->WaiterFileExist = false;
		ifs.close();
		return;
	}
	//2.文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "无数据..." << endl;
		this->W_num = 0;
		//头指针置为空
		this->head = NULL;
		//文件存在
		this->WaiterFileExist = true;
		ifs.close();
		return;
	}
	//3.文件存在且有数据，从文件中读取并录入链表
	int num = Get_WaiterNum();
	this->W_num = num;//更新数量  
	this->Init_WaiterList();
	//this->ID = id;
	this->password = password;
	user = manager;
	//Debug
	//cout << "数据初始化中..." << endl;
	//cout << "当前已有员工数量为：" << num << endl;
}
//1.添加员工
void Manager::Add_Waiter()
{
	cout << "请输入要添加员工的数量：" << endl;
	cin >> add_num;

	if (add_num > 0)
	{
		W_num += add_num;
		for (int i = 0; i < add_num; i++)
		{
			string id;
			string name;
			int exp;
			int id_Exits = 1;
			cout << "请输入第" << i + 1 << "个新员工ID：" << endl;
			cin >> id;
			//检查该id是否存在
			if (head != NULL && head->ID == id)
			{
				cout << "此ID已存在，请重新输入！" << endl;
				id_Exits = 0;
				i--;
			}
			else
			{
				// 遍历链表找到要查找的节点
				Waiter* pCurrent = head;
				Waiter* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->ID != id)
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
				cout << "请输入第" << i + 1 << "个新员工名称：" << endl;
				cin >> name;
				cout << "请输入第" << i + 1 << "个新员工经验：" << endl;
				cin >> exp;
				Waiter* newWaiter = new Waiter (id,name,exp);

				if (head == NULL)
				{
					head = newWaiter;
				}
				else
				{
					Waiter* pCurrent = head;
					while (pCurrent->next != NULL)
					{
						pCurrent = pCurrent->next;
					}
					pCurrent->next = newWaiter;
					//newDish->next = NULL;  			}
				}
			}
		}
	}
	this->saveWaiter();
	system("pause");
	system("cls");
}
int Manager::Get_WaiterNum()
{
	ifstream ifs;
	int num = 0;
	string id;
	string name;
	int exp;
	ifs.open(FILENAME, ios::in);//打开并读文件
	while (ifs >> id &&ifs>>name&& ifs >> exp)
	{
		//统计人数
		num++;
	}

	return num;
}
void Manager::ShowWaiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		Waiter* pCurrent = head;
		cout << "*******************员工信息*********************" << endl;
		while (pCurrent)
		{
			cout << "* 员工ID: " << setw(4) << pCurrent->ID
				<< "  员工姓名: " << setw(8) << pCurrent->W_name
				<< "  员工经验: " << setw(4) << pCurrent->experience<< " *" << endl;
			pCurrent = pCurrent->next;
		}
		cout << "************************************************" << endl;
	}
	else
	{
		cout << "*****无员工数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//保存数据
void Manager::saveWaiter()
{
	ofstream ofs(FILENAME3, ios::out); // 打开文件以写入数据
	if (!ofs.is_open())
	{
		cout << "无员工数据" << endl;
		return;
	}

	Waiter* pCurrent = head;
	while (pCurrent)
	{
		ofs << pCurrent->ID << " " << pCurrent->W_name << " " << pCurrent->experience <<endl;
		pCurrent = pCurrent->next;
	}

	ofs.close();
}
//初始化链表
void Manager::Init_WaiterList()
{
	ifstream ifs(FILENAME3, ios::in); // 打开文件并读取
	if (!ifs.is_open()) {
		cout << "无法打开文件或文件不存在..." << endl;
		return;
	}

	string id;
	string name;
	int exp;
	while (ifs >> id >> name >> exp ) 
	{
		// 创建一个新的员工对象
		Waiter* newWaiter = new Waiter(id, name, exp);

		// 将员工对象添加到链表中
		if (head == NULL) {
			head = newWaiter;
		}
		else {
			Waiter* pCurrent = head;
			while (pCurrent->next != NULL)
			{
				pCurrent = pCurrent->next;
			}
			pCurrent->next = newWaiter;
		}
	}

	ifs.close();
}
//删除员工
void Manager::Del_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		string id;
		cout << "请输入要删除的员工编号：" << endl;
		cin >> id;
		// 检查头节点是否是要删除的节点
		if (head != NULL && head->ID == id)
		{
			Waiter* temp = head;
			head = head->next;
			delete temp;
			W_num--;
			cout << "员工信息删除成功!" << endl;
		}
		else
		{
			// 遍历链表找到要删除的节点
			Waiter* pCurrent = head;
			Waiter* pPrevious = NULL;
			while (pCurrent != NULL && pCurrent->ID != id)
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->next;
			}

			// 如果找到了节点
			if (pCurrent != NULL)
			{
				pPrevious->next = pCurrent->next;
				delete pCurrent;
				W_num--;
				cout << "员工信息删除成功!" << endl;
			}
			else
			{
				cout << "未找到编号为 " << id << " 的菜品。" << endl;
			}
		}

		// 保存当前链表到文件
		this->saveWaiter();
	}
	else
	{
		cout << "*****无员工数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//初始化文件状态判断
bool Manager::FileState()
{
	ifstream ifs(FILENAME3, ios::in); // 打开文件并读取
	if (!ifs.is_open()) {
		cout << "无法打开文件或文件不存在..." << endl;
		return false;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "无数据..." << endl;
		//文件存在
		this->WaiterFileExist = true;
		ifs.close();
		return false;
	}
	return true;
}
//查找员工信息
void Manager::Search_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		string id;
		string name;
		cout << "请选择查找方式：" << endl;
		cout << "1.按员工ID查找：" << endl;
		cout << "2.按员工姓名查找：" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "请输入查找员工ID：" << endl;
			cin >> id;
			// 检查头节点是否是要查找的节点
			if (head != NULL && head->ID == id)
			{
				head->showInfo();
			}
			else
			{
				// 遍历链表找到要查找的节点
				Waiter* pCurrent = head;
				Waiter* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->ID != id)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// 如果找到了节点
				if (pCurrent != NULL)
				{
					pCurrent->showInfo();
				}
				else
				{
					cout << "未找到ID为 " << id << " 的员工。" << endl;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "请输入查找员工姓名：" << endl;
			cin >> name;
			// 检查头节点是否是要查找的节点
			if (head != NULL && head->W_name == name)
			{
				cout << "查找员工信息为：" << endl;
				head->showInfo();
			}
			else
			{
				// 遍历链表找到要查找的节点
				Waiter* pCurrent = head;
				Waiter* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->W_name != name)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// 如果找到了节点
				if (pCurrent != NULL)
				{
					cout << "查找员工信息为：" << endl;
					pCurrent->showInfo();
				}
				else
				{
					cout << "未找到姓名为 " << name << " 的员工。" << endl;
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
		cout << "*****无员工数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//修改员工信息
void Manager::Mol_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		string id;
		cout << "请输入修改员工ID：" << endl;
		cin >> id;

		string new_id;
		string new_name;
		int exp;


		// 检查头节点是否是要修改的节点
		if (head != NULL && head->ID == id)
		{
			cout << "请输入新的员工ID：" << endl;
			cin >> new_id;
			cout << "请输入新的员工姓名：" << endl;
			cin >> new_name;
			cout << "请输入新的员工经验：" << endl;
			cin >> exp;

			head->ID = new_id;
			head->W_name = new_name;
			head->experience = exp;  

			cout << "员工 " << id << " 信息修改成功。" << endl;
		}
		else
		{
			// 遍历链表找到要修改的节点
			Waiter* pCurrent = head;
			while (pCurrent != NULL && pCurrent->ID != id)
			{
				pCurrent = pCurrent->next;
			}

			// 如果找到了节点
			if (pCurrent != NULL)
			{
				cout << "请输入新的员工ID：" << endl;
				cin >> new_id;
				cout << "请输入新的员工姓名：" << endl;
				cin >> new_name;
				cout << "请输入新的员工经验：" << endl;
				cin >> exp;

				pCurrent->ID = new_id;
				pCurrent->W_name = new_name;
				pCurrent->experience = exp;

				cout << "员工 " << id << " 信息修改成功。" << endl;
			}
			else
			{
				cout << "未找到ID为 " << id << " 的员工。" << endl;
			}
		}
		this->saveWaiter();
	}
	else
	{
		cout << "*****无员工数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//员工信息销毁
void Manager::Destory_Waiter()
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
				ofstream ofs(FILENAME3, ios::trunc);
				ofs.close();
				while (this->head)
				{
					Waiter* temp = head;
					head = head->next;
					delete temp;
				}
				cout << "员工数据销毁成功！" << endl;
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
		cout << "*****无员工数据*****" << endl;
	}
	system("pause");
	system("cls");
}
//排序辅助函数
	Waiter* Manager::mergeSort(Waiter * head, bool ascending) 
	{
		if (!head || !head->next) 
		{
			return head;
		}
		Waiter* middle = getMiddle(head);
		Waiter* nextOfMiddle = middle->next;
		middle->next = NULL;

		Waiter* left = mergeSort(head, ascending);
		Waiter* right = mergeSort(nextOfMiddle, ascending);

		return merge(left, right, ascending);
	}

	Waiter* Manager::merge(Waiter * left, Waiter * right, bool ascending) 
	{
		if (!left) return right;
		if (!right) return left;

		Waiter* result = NULL;
		if ((ascending && left->experience <= right->experience) || (!ascending && left->experience >= right->experience)) 
		{
			result = left;
			result->next = merge(left->next, right, ascending);
		}
		else 
		{
			result = right;
			result->next = merge(left, right->next, ascending);
		}
		return result;
	}

	Waiter* Manager::getMiddle(Waiter * head) 
	{
		if (!head) return head;
		Waiter* slow = head;
		Waiter* fast = head->next;
		while (fast && fast->next) 
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	void Manager::Sort_Waiter() 
	{
		bool fileState = FileState();
		if (fileState) 
		{
			cout << "请选择员工信息排序方式：" << endl;
			cout << "1.员工经验升序排序" << endl;
			cout << "2.员工经验降序排序" << endl;
			int choice;
			cin >> choice;

			bool ascending = true;

			switch (choice) 
			{
			case 1:
				ascending = true;
				break;
			case 2:
				ascending = false;
				break;
			default:
				cout << "请输入正确的选择！" << endl;
				return;
			}

			head = mergeSort(head, ascending);
			cout << "排序完成!" << endl;
			cout << "员工信息更新如下：" << endl;
			this->ShowWaiter();
			this->saveWaiter();
		}
	}
