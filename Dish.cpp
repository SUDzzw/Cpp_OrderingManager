#include"Dish.h"
//构造函数
Dish::Dish(int id, string name, string feature, double price)
{
	this->D_id = id;
	this->D_name = name;
	this->D_feature = feature;
	this->D_price = price;
	this->count = 0;
	next = NULL;
}
//析构函数
Dish::~Dish()
{

}
// 展示当前菜品信息
void Dish::ShowDish()
{
	cout << "* 菜品编号: " << setw(4) << this->D_id
		<< "  菜品名称: " << setw(8) << this->D_name
		<< "  菜品特色: " << setw(8) << this->D_feature
		<< "  菜品价格: " << setw(4) << this->D_price << "￥ *" << endl;
}