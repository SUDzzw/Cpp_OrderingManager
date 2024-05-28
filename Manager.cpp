#include"Manager.h"

//���캯��
Manager::Manager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME3, ios::in);//���Զ��ļ�
	if (!ifs.is_open())
	{
		cout << "��������Ϊ��..." << endl;
		this->W_num = 0;
		//ͷָ����Ϊ��
		this->head = NULL;
		//�ļ�������
		this->WaiterFileExist = false;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "������..." << endl;
		this->W_num = 0;
		//ͷָ����Ϊ��
		this->head = NULL;
		//�ļ�����
		this->WaiterFileExist = true;
		ifs.close();
		return;
	}
	//3.�ļ������������ݣ����ļ��ж�ȡ��¼������
	int num = Get_WaiterNum();
	this->W_num = num;//��������  
	this->Init_WaiterList();
	//this->ID = id;
	this->password = password;
	user = manager;
	//Debug
	//cout << "���ݳ�ʼ����..." << endl;
	//cout << "��ǰ����Ա������Ϊ��" << num << endl;
}
//1.���Ա��
void Manager::Add_Waiter()
{
	cout << "������Ҫ���Ա����������" << endl;
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
			cout << "�������" << i + 1 << "����Ա��ID��" << endl;
			cin >> id;
			//����id�Ƿ����
			if (head != NULL && head->ID == id)
			{
				cout << "��ID�Ѵ��ڣ����������룡" << endl;
				id_Exits = 0;
				i--;
			}
			else
			{
				// ���������ҵ�Ҫ���ҵĽڵ�
				Waiter* pCurrent = head;
				Waiter* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->ID != id)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// ����ҵ��˽ڵ�
				if (pCurrent != NULL)
				{
					cout << "�˱���Ѵ��ڣ����������룡" << endl;
					id_Exits = 0;
					i--;
				}
			}
			if (id_Exits)
			{
				cout << "�������" << i + 1 << "����Ա�����ƣ�" << endl;
				cin >> name;
				cout << "�������" << i + 1 << "����Ա�����飺" << endl;
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
	ifs.open(FILENAME, ios::in);//�򿪲����ļ�
	while (ifs >> id &&ifs>>name&& ifs >> exp)
	{
		//ͳ������
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
		cout << "*******************Ա����Ϣ*********************" << endl;
		while (pCurrent)
		{
			cout << "* Ա��ID: " << setw(4) << pCurrent->ID
				<< "  Ա������: " << setw(8) << pCurrent->W_name
				<< "  Ա������: " << setw(4) << pCurrent->experience<< " *" << endl;
			pCurrent = pCurrent->next;
		}
		cout << "************************************************" << endl;
	}
	else
	{
		cout << "*****��Ա������*****" << endl;
	}
	system("pause");
	system("cls");
}
//��������
void Manager::saveWaiter()
{
	ofstream ofs(FILENAME3, ios::out); // ���ļ���д������
	if (!ofs.is_open())
	{
		cout << "��Ա������" << endl;
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
//��ʼ������
void Manager::Init_WaiterList()
{
	ifstream ifs(FILENAME3, ios::in); // ���ļ�����ȡ
	if (!ifs.is_open()) {
		cout << "�޷����ļ����ļ�������..." << endl;
		return;
	}

	string id;
	string name;
	int exp;
	while (ifs >> id >> name >> exp ) 
	{
		// ����һ���µ�Ա������
		Waiter* newWaiter = new Waiter(id, name, exp);

		// ��Ա��������ӵ�������
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
//ɾ��Ա��
void Manager::Del_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		string id;
		cout << "������Ҫɾ����Ա����ţ�" << endl;
		cin >> id;
		// ���ͷ�ڵ��Ƿ���Ҫɾ���Ľڵ�
		if (head != NULL && head->ID == id)
		{
			Waiter* temp = head;
			head = head->next;
			delete temp;
			W_num--;
			cout << "Ա����Ϣɾ���ɹ�!" << endl;
		}
		else
		{
			// ���������ҵ�Ҫɾ���Ľڵ�
			Waiter* pCurrent = head;
			Waiter* pPrevious = NULL;
			while (pCurrent != NULL && pCurrent->ID != id)
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->next;
			}

			// ����ҵ��˽ڵ�
			if (pCurrent != NULL)
			{
				pPrevious->next = pCurrent->next;
				delete pCurrent;
				W_num--;
				cout << "Ա����Ϣɾ���ɹ�!" << endl;
			}
			else
			{
				cout << "δ�ҵ����Ϊ " << id << " �Ĳ�Ʒ��" << endl;
			}
		}

		// ���浱ǰ�����ļ�
		this->saveWaiter();
	}
	else
	{
		cout << "*****��Ա������*****" << endl;
	}
	system("pause");
	system("cls");
}
//��ʼ���ļ�״̬�ж�
bool Manager::FileState()
{
	ifstream ifs(FILENAME3, ios::in); // ���ļ�����ȡ
	if (!ifs.is_open()) {
		cout << "�޷����ļ����ļ�������..." << endl;
		return false;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "������..." << endl;
		//�ļ�����
		this->WaiterFileExist = true;
		ifs.close();
		return false;
	}
	return true;
}
//����Ա����Ϣ
void Manager::Search_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		string id;
		string name;
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1.��Ա��ID���ң�" << endl;
		cout << "2.��Ա���������ң�" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "���������Ա��ID��" << endl;
			cin >> id;
			// ���ͷ�ڵ��Ƿ���Ҫ���ҵĽڵ�
			if (head != NULL && head->ID == id)
			{
				head->showInfo();
			}
			else
			{
				// ���������ҵ�Ҫ���ҵĽڵ�
				Waiter* pCurrent = head;
				Waiter* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->ID != id)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// ����ҵ��˽ڵ�
				if (pCurrent != NULL)
				{
					pCurrent->showInfo();
				}
				else
				{
					cout << "δ�ҵ�IDΪ " << id << " ��Ա����" << endl;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "���������Ա��������" << endl;
			cin >> name;
			// ���ͷ�ڵ��Ƿ���Ҫ���ҵĽڵ�
			if (head != NULL && head->W_name == name)
			{
				cout << "����Ա����ϢΪ��" << endl;
				head->showInfo();
			}
			else
			{
				// ���������ҵ�Ҫ���ҵĽڵ�
				Waiter* pCurrent = head;
				Waiter* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->W_name != name)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// ����ҵ��˽ڵ�
				if (pCurrent != NULL)
				{
					cout << "����Ա����ϢΪ��" << endl;
					pCurrent->showInfo();
				}
				else
				{
					cout << "δ�ҵ�����Ϊ " << name << " ��Ա����" << endl;
				}
			}
		}
		else
		{
			cout << "��������ȷѡ��" << endl;
		}

	}
	else
	{
		cout << "*****��Ա������*****" << endl;
	}
	system("pause");
	system("cls");
}
//�޸�Ա����Ϣ
void Manager::Mol_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		string id;
		cout << "�������޸�Ա��ID��" << endl;
		cin >> id;

		string new_id;
		string new_name;
		int exp;


		// ���ͷ�ڵ��Ƿ���Ҫ�޸ĵĽڵ�
		if (head != NULL && head->ID == id)
		{
			cout << "�������µ�Ա��ID��" << endl;
			cin >> new_id;
			cout << "�������µ�Ա��������" << endl;
			cin >> new_name;
			cout << "�������µ�Ա�����飺" << endl;
			cin >> exp;

			head->ID = new_id;
			head->W_name = new_name;
			head->experience = exp;  

			cout << "Ա�� " << id << " ��Ϣ�޸ĳɹ���" << endl;
		}
		else
		{
			// ���������ҵ�Ҫ�޸ĵĽڵ�
			Waiter* pCurrent = head;
			while (pCurrent != NULL && pCurrent->ID != id)
			{
				pCurrent = pCurrent->next;
			}

			// ����ҵ��˽ڵ�
			if (pCurrent != NULL)
			{
				cout << "�������µ�Ա��ID��" << endl;
				cin >> new_id;
				cout << "�������µ�Ա��������" << endl;
				cin >> new_name;
				cout << "�������µ�Ա�����飺" << endl;
				cin >> exp;

				pCurrent->ID = new_id;
				pCurrent->W_name = new_name;
				pCurrent->experience = exp;

				cout << "Ա�� " << id << " ��Ϣ�޸ĳɹ���" << endl;
			}
			else
			{
				cout << "δ�ҵ�IDΪ " << id << " ��Ա����" << endl;
			}
		}
		this->saveWaiter();
	}
	else
	{
		cout << "*****��Ա������*****" << endl;
	}
	system("pause");
	system("cls");
}
//Ա����Ϣ����
void Manager::Destory_Waiter()
{
	bool fileState = FileState();
	if (fileState)
	{
		cout << "ȷ�����٣�" << endl;
		cout << "1.ȷ��" << endl;
		cout << "2.ȡ��" << endl;
		int choice1;
		int choice2;
		cin >> choice1;
		if (choice1 == 1)
		{
			cout << "���ٴ�ȷ�ϣ�" << endl;
			cout << "1.ȷ��" << endl;
			cout << "2.ȡ��" << endl;
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
				cout << "Ա���������ٳɹ���" << endl;
			}
			else
			{
				cout << "ȡ���ɹ���" << endl;
			}
		}
		else
		{
			cout << "ȡ���ɹ���" << endl;
		}
	}
	else
	{
		cout << "*****��Ա������*****" << endl;
	}
	system("pause");
	system("cls");
}
//����������
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
			cout << "��ѡ��Ա����Ϣ����ʽ��" << endl;
			cout << "1.Ա��������������" << endl;
			cout << "2.Ա�����齵������" << endl;
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
				cout << "��������ȷ��ѡ��" << endl;
				return;
			}

			head = mergeSort(head, ascending);
			cout << "�������!" << endl;
			cout << "Ա����Ϣ�������£�" << endl;
			this->ShowWaiter();
			this->saveWaiter();
		}
	}
