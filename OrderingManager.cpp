#include<iostream>
#include"OrderingManager.h"
//构造函数
OrderingManager::OrderingManager()
{

}
//注册函数
void OrderingManager::ManagerRegis()
{
    cout << "请输入管理员账号：" << endl;
    cin >> this->manager.ID;
    cout << "请输入管理员密码：" << endl;
    cin >> this->manager.password;
    cout << "注册成功！" << endl;
    manager.accountExist = true;
    // 将管理员账号信息保存在文件中
    ofstream ofs(FILENAME2, ios::out);
    if (!ofs.is_open()) 
    {
        cout << "注册失败" << endl;
        return;
    }

    ofs << this->manager.ID << " "
        << this->manager.password << endl;

    ofs.close();
    system("pause");
    system("cls");
}

void OrderingManager::ManagerLogin()
{
    ifstream ifs(FILENAME2, ios::in); // 打开文件以读取管理员账号信息
    if (!ifs.is_open()) {
        cout << "尚未注册管理员" << endl;
        system("pause");
        system("cls");

        return;
    }

    string storedID;
    string storedPassword;
    ifs >> storedID >> storedPassword; // 从文件中读取管理员账号和密码
    //文件存在但数据为空
    if (storedID.empty() || storedPassword.empty()) {
        cout << "无管理员账号数据" << endl;
        system("pause");
        system("cls");

        return;
    }
    ifs.close();

    string id;
    string password;
    cout << "请输入管理员账号：" << endl;
    cin >> id;
    cout << "请输入管理员密码：" << endl;
    cin >> password;

    if (id == storedID && password == storedPassword)
    {
        system("cls");
        cout << "登录成功!" << endl;
        this->ManageUI();
    }
    else
    {
        cout << "账号或密码错误" << endl;
    }
    system("pause");
    system("cls");
}
//管理功能界面
void OrderingManager::ManageUI()
{
    while (true)
    {
        cout << "1.菜单管理" << endl;
        cout << "2.餐桌管理" << endl;
        cout << "3.订单管理" << endl;
        cout << "4.员工管理" << endl;
        cout << "5.资金管理" << endl;
        cout << "6.退出程序" << endl;
        cout << "请选择：" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            system("cls");
            this->ManageMenu();
        }
        else if (choice == 4)
        {
            system("cls");
            this->ManageWaiter();
        }
        else
        {
            break;
        }
    }
}
//管理菜单接口
void OrderingManager::ManageMenu()
{
    int choice;

    while (true)
    {
        cout << "1.添加菜品" << endl;
        cout << "2.打印菜单" << endl;
        cout << "3.删除菜品" << endl;
        cout << "4.查找菜品" << endl;
        cout << "5.修改菜品" << endl;
        cout << "6.菜品排序" << endl;
        cout << "7.清空菜品" << endl;
        cout << "8.退出菜单管理" << endl;

        cout << "请输入选择：" << endl;
        cin >> choice;

        if (choice == 1)
        {
            this->manager.menu.Add_Dish();
        }
        else if (choice == 2)
        {
            this->manager.menu.ShowMenu();
        }
        else if (choice == 3)
        {
            this->manager.menu.Del_Dish();
        }
        else if (choice == 4)
        {
            this->manager.menu.Search_Dish();
        }
        else if (choice == 5)
        {
            this->manager.menu.Mol_Dish();
        }
        else if (choice == 6)
        {
            this->manager.menu.Sort_Dish();
        }
        else if (choice == 7)
        {
            this->manager.menu.Destory_Dish();
        }
        else if (choice == 8)
            break;
        else
        {
            cout << "无效选择，请重试。" << endl;
            system("cls");
        }
    }
    system("pause");
    system("cls");
}
//员工登录函数
void OrderingManager::WaiterLogin()
{
    ifstream ifs(FILENAME3, ios::in); // 打开文件以读取员工账号信息
    if (!ifs.is_open()) 
    {
        cout << "无服务员信息！" << endl;
        return;
    }

    string storedID;
    ifs >> storedID; // 从文件中读取员工账号
    //文件存在但数据为空
    if (storedID.empty())
    {
        cout << "服务员信息为空！" << endl;
        return;
    }
    ifs.close();

    string id;
    cout << "请输入员工ID：" << endl;
    cin >> id;

    bool idExists = false;

    // 打开文件以读取员工信息
    ifstream ifs2(FILENAME3, ios::in);
    if (!ifs2.is_open()) {
        cout << "无法打开文件或文件不存在..." << endl;
        return;
    }

    string storedID2;
    string storedName;
    int storedExp;

    while (ifs2 >> storedID2 >> storedName >> storedExp)
    {
        if (id == storedID2) // 如果找到匹配的ID
        {
            idExists = true;
            break;
        }
    }

    ifs.close();

    if (idExists)
    {
        system("cls");
        cout << "登录成功!" << endl;
        this->SimpleUI();
    }
    else
    {
        cout << "ID错误" << endl;
    }
    system("pause");
    system("cls");
}

//员工权限界面
void OrderingManager::SimpleUI()
{
    int choice;

    while (true)
    {
        cout << "1.菜单管理" << endl;
        cout << "2.餐桌管理" << endl;
        cout << "3.订单管理" << endl;
        cout << "4.退出系统" << endl;

        cout << "请输入选择：" << endl;
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            this->SimpleMenu();
        }
        else if (choice == 2)
        {
            //this->manager.menu.Search_Dish();
        }
        else if (choice == 3)
        {
            //this->ma
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "无效选择，请重试。" << endl;
            system("cls");
        }
    }
    system("pause");
    system("cls");
}
//员工管理接口函数
void OrderingManager::ManageWaiter()
{
    int choice;

    while (true)
    {
        cout << "1.添加员工信息" << endl;
        cout << "2.查看员工信息" << endl;
        cout << "3.删除员工信息" << endl;
        cout << "4.查找员工信息" << endl;
        cout << "5.修改员工信息" << endl;
        cout << "6.员工信息排序" << endl;
        cout << "7.清空员工信息" << endl;
        cout << "8.退出员工管理" << endl;

        cout << "请输入选择：" << endl;
        cin >> choice;

        if (choice == 1)
        {
            this->manager.Add_Waiter();
        }
        else if (choice == 2)
        {
            this->manager.ShowWaiter();
        }
        else if (choice == 3)
        {
            this->manager.Del_Waiter();
        }
        else if (choice == 4)
        {
            this->manager.Search_Waiter();
        }
        else if (choice == 5)
        {
            this->manager.Mol_Waiter();
        }
        else if (choice == 6)
        {
            this->manager.Sort_Waiter();
        }
        else if (choice == 7)
        {
            this->manager.Destory_Waiter();
        }
        else if (choice == 8)
            break;
        else
        {
            cout << "无效选择，请重试。" << endl;
            system("cls");
        }
    }
    system("pause");
    system("cls");
}
//员工菜单接口
void OrderingManager::SimpleMenu()
{
    int choice;

    while (true)
    {
        cout << "1.打印菜单" << endl;
        cout << "2.查找菜品" << endl;
        cout << "3.退出菜单管理" << endl;

        cout << "请输入选择：" << endl;
        cin >> choice;

        if (choice == 1)
        {
            this->manager.menu.ShowMenu();
        }
        else if (choice == 2)
        {
            this->manager.menu.Search_Dish();
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "无效选择，请重试。" << endl;
            system("cls");
        }
    }
    system("pause");
    system("cls");
}
void OrderingManager::Destroy_ManagerAccount()
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
                ofstream ofs(FILENAME2, ios::trunc);
                ofs.close();
                
                cout << "管理员账号数据销毁成功！" << endl;
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
        cout << "*****无管理员数据*****" << endl;
    }
    system("pause");
    system("cls");
}
//初始化文件状态判断
bool OrderingManager::FileState()
{
    ifstream ifs(FILENAME2, ios::in); // 打开文件并读取
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
