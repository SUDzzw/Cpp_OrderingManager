#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Dish
{
public:
    int D_id;//菜品编号
    string D_name;  //名称
    string D_feature;//特色
    double D_price;  //价格
    int beChosed_Num;
    int count;
    Dish* next;//指向下一个Dish结点
    //构造函数
    Dish(int id,string name,string feature,double price);
    //析构函数
    ~Dish();
    // 展示当前菜品信息
    void ShowDish();
};
