#include"OrderingManager.h"
#include <iostream>
using namespace std;

int main() 
{
    OrderingManager om;
    //��ʼǰ����ע�ᣬ���Ƚ���Ϣ����
    ifstream ifs(FILENAME2, ios::in); // ���ļ��Զ�ȡ����Ա�˺���Ϣ
    if (!ifs.is_open()) {
        cout << "��δע�����Ա" << endl;
        //system("cls");

        //return;
    }

    string storedID;
    string storedPassword;
    ifs >> storedID >> storedPassword; // ���ļ��ж�ȡ����Ա�˺ź�����
    //�ļ����ڵ�����Ϊ��
    if (storedID.empty() || storedPassword.empty()) 
    {
        cout << "�޹���Ա�˺�����" << endl;
        //system("cls");
        //return;
    }
    else
    {
        om.manager.accountExist = true;
    }
    ifs.close();
    //���Թ���Աע���¼����
    int choice;
    while (true)
    {
        cout << "1.��¼" << endl;
        cout << "2.ע��" << endl;
        cout << "3.ע��" << endl;
        cout << "4.�˳�" << endl;

        cout << "������ѡ��" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int choice2;
            cout << "ѡ����뷽ʽ��" << endl;
            cout << "1.����Ա����" << endl;
            cout << "2.��ͨ����" << endl;
            cin >> choice2;
            if (choice2 == 1)
            {
                om.ManagerLogin();
            }
            else if(choice2 == 2)
            {
                om.WaiterLogin();
            }
        }
        else if (choice == 2)
        {
            if (om.manager.accountExist)
            {
                cout << "����Ա��ע�ᣡ" << endl;
                system("pause");
                system("cls");
            }
            else
            om.ManagerRegis();
        }
        else if (choice == 3)
        {
            om.Destroy_ManagerAccount();
        }
        else if (choice == 4)
        {

            break;
        }
    }

    //���Բ˵��๦��
   /* Menu menu;
    int choice;

    while (true) {
        cout << "1.��Ӳ�Ʒ" << endl;
        cout << "2.��ӡ�˵�" << endl;
        cout << "3.ɾ����Ʒ" <<endl;
        cout << "4.���Ҳ�Ʒ" << endl;
        cout << "5.�޸Ĳ�Ʒ" << endl;
        cout << "6.��Ʒ����" << endl;
        cout << "7.��ղ�Ʒ" << endl;
        cout << "8.�˳�����" << endl;

        cout<<"������ѡ��"<<endl;
        cin >> choice;

        if (choice == 1)
        {
            menu.Add_Dish();
        }
        else if (choice == 2)
        {
            menu.ShowMenu();
        }
        else if (choice == 3)
        {
            menu.Del_Dish();
        }
        else if (choice == 4)
        {
            menu.Search_Dish();
        }
        else if (choice == 5)
        {
            menu.Mol_Dish();
        }
        else if (choice == 6)
        {
            menu.Sort_Dish();
        }
        else if (choice == 7)
        {
            menu.Destory_Dish();
        }
        else if (choice == 8)
            break;
        else 
        {
            cout << "��Чѡ�������ԡ�" << endl;
            system("cls");
        }
    }*/
    return 0;
}