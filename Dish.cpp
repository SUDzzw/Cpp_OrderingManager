#include"Dish.h"
//���캯��
Dish::Dish(int id, string name, string feature, double price)
{
	this->D_id = id;
	this->D_name = name;
	this->D_feature = feature;
	this->D_price = price;
	this->count = 0;
	next = NULL;
}
//��������
Dish::~Dish()
{

}
// չʾ��ǰ��Ʒ��Ϣ
void Dish::ShowDish()
{
	cout << "* ��Ʒ���: " << setw(4) << this->D_id
		<< "  ��Ʒ����: " << setw(8) << this->D_name
		<< "  ��Ʒ��ɫ: " << setw(8) << this->D_feature
		<< "  ��Ʒ�۸�: " << setw(4) << this->D_price << "�� *" << endl;
}