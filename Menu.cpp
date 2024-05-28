#include"Menu.h"
//���캯��
Menu::Menu()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���Զ��ļ�
	if (!ifs.is_open())
	{
		cout << "��������Ϊ��..." << endl;
		//��ʼ����Ʒ��Ϊ��
		this->D_num = 0;
		//ͷָ����Ϊ��
		this->head = NULL;
		//�ļ�������
		this->fileExist = false;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "������..." << endl;
		//��ʼ����Ʒ��Ϊ��
		this->D_num = 0;
		//ͷָ����Ϊ��
		this->head = NULL;
		//�ļ�����
		this->fileExist = true;
		ifs.close();
		return;
	}
	//3.�ļ������������ݣ����ļ��ж�ȡ��¼������
	int num = this->Get_DishNum();
	//cout << "���ݳ�ʼ����..." << endl;
	//cout << "��ǰ���в�Ʒ����Ϊ��" << num << endl;
	this->D_num = num;//��������  
	this->Init_DishList();
	//����
	
}
//��������
Menu::~Menu()
{
	// �ͷ������е����нڵ�
	while (head) 
	{
		Dish* temp = head;
		head = head->next;
		delete temp;
	}
}
//�˵�չʾ
void Menu::ShowMenu()
{
	bool fileState = FileState();
	if (fileState)
	{
		Dish* pCurrent = head;
		cout << "********************************���ղ˵�************************************" << endl;
		while (pCurrent)
		{
			cout << "* ��Ʒ���: " << setw(4) << pCurrent->D_id
				<< "  ��Ʒ����: " << setw(8) << pCurrent->D_name
				<< "  ��Ʒ��ɫ: " << setw(8) << pCurrent->D_feature
				<< "  ��Ʒ�۸�: " << setw(4) << pCurrent->D_price << "�� *" << endl;
			pCurrent = pCurrent->next;
		}
		cout << "****************************************************************************" << endl;
	}
	else
	{
		cout << "*****�޲�Ʒ����*****" << endl;
	}
	system("pause");
	system("cls");
}
//��Ӳ�Ʒ
void Menu::Add_Dish()
{
	cout << "������Ҫ��Ӳ�Ʒ��������" << endl;
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
			cout << "�������" << i + 1 << "���²�Ʒ��ţ�" << endl;
			cin >> id;
			//����id�Ƿ����
			if (head != NULL && head->D_id == id)
			{
				cout << "�˱���Ѵ��ڣ����������룡" << endl;
				id_Exits = 0;
				i--;
			}
			else
			{
				// ���������ҵ�Ҫ���ҵĽڵ�
				Dish* pCurrent = head;
				Dish* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->D_id != id)
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
				cout << "�������" << i + 1 << "���²�Ʒ���ƣ�" << endl;
				cin >> name;
				cout << "�������" << i + 1 << "���²�Ʒ��ɫ��" << endl;
				cin >> feature;
				cout << "�������" << i + 1 << "���²�Ʒ�۸�" << endl;
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
//��ȡ��Ʒ����
int Menu::Get_DishNum()
{
	ifstream ifs;
	int num = 0;
	int id;
	string name;
	string feature;
	double price;
	ifs.open(FILENAME, ios::in);//�򿪲����ļ�
	while (ifs >> id && ifs >> name && ifs >> feature&&ifs>>price)
	{
		//ͳ������
		num++;
	}

	return num;
}
void Menu::Init_DishList()
{
	ifstream ifs(FILENAME, ios::in); // ���ļ�����ȡ
	if (!ifs.is_open()) {
		cout << "�޷����ļ����ļ�������..." << endl;
		return;
	}

	int id;
	string name;
	string feature;
	double price;

	while (ifs >> id >> name >> feature >> price) {
		// ����һ���µĲ�Ʒ����
		Dish* newDish = new Dish(id, name, feature, price);

		// ����Ʒ������ӵ�������
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
//��ʼ���ļ�״̬�ж�
bool Menu::FileState() 
{
	ifstream ifs(FILENAME, ios::in); // ���ļ�����ȡ
	if (!ifs.is_open()) {
		cout << "�޷����ļ����ļ�������..." << endl;
		return false;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "������..." << endl;
		//�ļ�����
		this->fileExist = true;
		ifs.close();
		return false;
	}
	return true;
}

//��������
void Menu::saveDish() 
{
	ofstream ofs(FILENAME, ios::out); // ���ļ���д������
	if (!ofs.is_open()) 
	{
		cout << "�޲�Ʒ����" << endl;
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
//ɾ����Ʒ
void Menu::Del_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		int id;
		cout << "������Ҫɾ���Ĳ�Ʒ��ţ�" << endl;
		cin >> id;
		// ���ͷ�ڵ��Ƿ���Ҫɾ���Ľڵ�
		if (head != NULL && head->D_id == id)
		{
			Dish* temp = head;
			head = head->next;
			delete temp;
			D_num--;
			cout << "��Ʒɾ���ɹ�!" << endl;
		}
		else
		{
			// ���������ҵ�Ҫɾ���Ľڵ�
			Dish* pCurrent = head;
			Dish* pPrevious = NULL;
			while (pCurrent != NULL && pCurrent->D_id != id)
			{
				pPrevious = pCurrent;
				pCurrent = pCurrent->next;
			}

			// ����ҵ��˽ڵ�
			if (pCurrent != NULL)
			{
				pPrevious->next = pCurrent->next;
				delete pCurrent;
				D_num--;
				cout << "��Ʒɾ���ɹ�!" << endl;
			}
			else
			{
				cout << "δ�ҵ����Ϊ " << id << " �Ĳ�Ʒ��" << endl;
			}
		}

		// ���浱ǰ�����ļ�
		this->saveDish();

	}
	else
	{
		cout << "*****�޲�Ʒ����*****" << endl;
	}
	system("pause");
	system("cls");
}
//���Ҳ�Ʒ��Ϣ
void Menu::Search_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		int id;
		string name;
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1.����Ʒ��Ų��ң�" << endl;
		cout << "2.����Ʒ���Ʋ��ң�" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			cout << "��������Ҳ�Ʒ��ţ�" << endl;
			cin >> id;
			// ���ͷ�ڵ��Ƿ���Ҫ���ҵĽڵ�
			if (head != NULL && head->D_id == id)
			{
				head->ShowDish();
			}
			else
			{
				// ���������ҵ�Ҫ���ҵĽڵ�
				Dish* pCurrent = head;
				Dish* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->D_id != id)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// ����ҵ��˽ڵ�
				if (pCurrent != NULL)
				{
					pCurrent->ShowDish();
				}
				else
				{
					cout << "δ�ҵ����Ϊ " << id << " �Ĳ�Ʒ��" << endl;
				}
			}
		}
		else if (choice == 2)
		{
			cout << "��������Ҳ�Ʒ���ƣ�" << endl;
			cin >> name;
			// ���ͷ�ڵ��Ƿ���Ҫ���ҵĽڵ�
			if (head != NULL && head->D_name == name)
			{
				cout << "���Ҳ�Ʒ��ϢΪ��" << endl;
				head->ShowDish();
			}
			else
			{
				// ���������ҵ�Ҫ���ҵĽڵ�
				Dish* pCurrent = head;
				Dish* pPrevious = NULL;
				while (pCurrent != NULL && pCurrent->D_name != name)
				{
					pPrevious = pCurrent;
					pCurrent = pCurrent->next;
				}

				// ����ҵ��˽ڵ�
				if (pCurrent != NULL)
				{
					cout << "���Ҳ�Ʒ��ϢΪ��" << endl;
					pCurrent->ShowDish();
				}
				else
				{
					cout << "δ�ҵ�����Ϊ " <<  name  << " �Ĳ�Ʒ��" << endl;
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
		cout << "*****�޲�Ʒ����*****" << endl;
	}
	system("pause");
	system("cls");
}
//�޸Ĳ�Ʒ��Ϣ
void Menu::Mol_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		int id;
		cout << "�������޸Ĳ�Ʒ��ţ�" << endl;
		cin >> id;

		int new_id;
		string new_name;
		string new_feature;
		double new_price;

		// ���ͷ�ڵ��Ƿ���Ҫ�޸ĵĽڵ�
		if (head != NULL && head->D_id == id)
		{
			cout << "�������µĲ�Ʒ��ţ�" << endl;
			cin >> new_id;
			cout << "�������µĲ�Ʒ���ƣ�" << endl;
			cin >> new_name;
			cout << "�������µĲ�Ʒ��ɫ��" << endl;
			cin >> new_feature;
			cout << "�������µĲ�Ʒ�۸�" << endl;
			cin >> new_price;

			head->D_id = new_id;
			head->D_name = new_name;
			head->D_feature = new_feature;
			head->D_price = new_price;

			cout << "��Ʒ��� " << id << " �޸ĳɹ���" << endl;
		}
		else
		{
			// ���������ҵ�Ҫ�޸ĵĽڵ�
			Dish* pCurrent = head;
			while (pCurrent != NULL && pCurrent->D_id != id)
			{
				pCurrent = pCurrent->next;
			}

			// ����ҵ��˽ڵ�
			if (pCurrent != NULL)
			{
				cout << "�������µĲ�Ʒ��ţ�" << endl;
				cin >> new_id;
				cout << "�������µĲ�Ʒ���ƣ�" << endl;
				cin >> new_name;
				cout << "�������µĲ�Ʒ��ɫ��" << endl;
				cin >> new_feature;
				cout << "�������µĲ�Ʒ�۸�" << endl;
				cin >> new_price;

				pCurrent->D_id = new_id;
				pCurrent->D_name = new_name;
				pCurrent->D_feature = new_feature;
				pCurrent->D_price = new_price;

				cout << "��Ʒ��� " << id << " �޸ĳɹ���" << endl;
			}
			else
			{
				cout << "δ�ҵ����Ϊ " << id << " �Ĳ�Ʒ��" << endl;
			}
		}
		this->saveDish();
	}
	else
	{
		cout << "*****�޲�Ʒ����*****" << endl;
	}
	system("pause");
	system("cls");
}
//��Ʒ��Ϣ����
void Menu::Sort_Dish()
{
	bool fileState = FileState();
	if (fileState)
	{
		cout << "��ѡ���Ʒ����ʽ��" << endl;
		cout << "1.��Ʒ�����������" << endl;
		cout << "2.��Ʒ��Ž�������" << endl;
		cout << "3.��Ʒ�۸���������" << endl;
		cout << "4.��Ʒ�۸�������" << endl;
		int choice;
		cin >> choice;

		bool ascending = true;//�������־
		bool byPrice = false;//�Ƿ񰴼۸������־

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
			cout << "��������ȷ��ѡ��" << endl;
			return;
		}

		head = mergeSort(head, ascending, byPrice);
		cout << "�������!" << endl;
		cout << "�˵��������£�" << endl;
		this->ShowMenu();
		this->saveDish();
	}
	else
	{
		cout << "*****�޲�Ʒ����*****" << endl;
	}
	system("pause");
	system("cls");
}

//��Ʒ�������������ϲ������㷨��
//�ϲ�����
Dish* Menu::merge(Dish* left, Dish* right, bool ascending, bool byPrice) 
{	
	//�ж����ҽ���Ƿ�Ϊ��
	if (!left) 
		return right;
	if (!right) 
		return left;

	Dish* result = NULL;

	if (ascending) //����
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
	else //����
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
//�ҵ��м���
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
//ִ�кϲ�����
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
//��Ʒ��Ϣ����
void Menu::Destory_Dish()
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
				ofstream ofs(FILENAME, ios::trunc);
				ofs.close();
				while (this->head)
				{
					Dish* temp = head;
					head = head->next;
					delete temp;
				}
				cout << "��Ʒ�������ٳɹ���" << endl;
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
		cout << "*****�޲�Ʒ����*****" << endl;
	}
	system("pause");
	system("cls");
}
