#include"OrderingManager.h"
#include <iostream>
using namespace std;

int main() 
{
    OrderingManager om;
    //开始前若已注册，则先将信息读入
    ifstream ifs(FILENAME2, ios::in); // 打开文件以读取管理员账号信息
    if (!ifs.is_open()) {
        cout << "尚未注册管理员" << endl;
        //system("cls");

        //return;
    }

    string storedID;
    string storedPassword;
    ifs >> storedID >> storedPassword; // 从文件中读取管理员账号和密码
    //文件存在但数据为空
    if (storedID.empty() || storedPassword.empty()) 
    {
        cout << "无管理员账号数据" << endl;
        //system("cls");
        //return;
    }
    else
    {
        om.manager.accountExist = true;
    }
    ifs.close();
    //测试管理员注册登录功能
    int choice;
    while (true)
    {
        cout << "1.登录" << endl;
        cout << "2.注册" << endl;
        cout << "3.注销" << endl;
        cout << "4.退出" << endl;

        cout << "请输入选择：" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int choice2;
            cout << "选择登入方式：" << endl;
            cout << "1.管理员登入" << endl;
            cout << "2.普通登入" << endl;
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
                cout << "管理员已注册！" << endl;
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

    //测试菜单类功能
   /* Menu menu;
    int choice;

    while (true) {
        cout << "1.添加菜品" << endl;
        cout << "2.打印菜单" << endl;
        cout << "3.删除菜品" <<endl;
        cout << "4.查找菜品" << endl;
        cout << "5.修改菜品" << endl;
        cout << "6.菜品排序" << endl;
        cout << "7.清空菜品" << endl;
        cout << "8.退出程序" << endl;

        cout<<"请输入选择："<<endl;
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
            cout << "无效选择，请重试。" << endl;
            system("cls");
        }
    }*/
    return 0;
}