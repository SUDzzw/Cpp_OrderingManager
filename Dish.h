#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Dish
{
public:
    int D_id;//��Ʒ���
    string D_name;  //����
    string D_feature;//��ɫ
    double D_price;  //�۸�
    int beChosed_Num;
    int count;
    Dish* next;//ָ����һ��Dish���
    //���캯��
    Dish(int id,string name,string feature,double price);
    //��������
    ~Dish();
    // չʾ��ǰ��Ʒ��Ϣ
    void ShowDish();
};
