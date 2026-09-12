#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"
namespace caige
{
	void test01()
	{
		SqList<int> a1;
		a1.insert(0,1);
		a1.insert(1,1);
		a1.insert(2,1);
		a1.insert(3,1);
		a1.print();
	}
}
int main()
{

	/*caige::test01();*/
	//printf("\"你好！\"");
	//测试顺序表基本操作
	caige::SqList<int> list;
	cout << "=== 测试插入操作 ===" << endl;
	//头部插入
	list.insert(0, 1);
	//尾部插入
	list.insert(1, 3);
	//中间插入
	list.insert(1, 2);
	list.print();

	cout << "\n=== 测试获取长度与判空 ===" << endl;
	cout << "当前线性表长度：" << list.size() << endl;
	cout << "线性表是否为空：" << (list.emptry() ? "是" : "否") << endl;

	cout << "\n=== 测试按位置获取元素、按元素找位置 ===" << endl;
	cout << "位置1的元素为：" << list.get(1) << endl;
	cout << "元素2的位置为：" << list.pos(2) << endl;
	cout << "元素4的位置为：" << list.pos(4) << "（值等于表长表示未找到）" << endl;

	cout << "\n=== 测试删除操作 ===" << endl;
	list.deletei(1);
	list.print();

	cout << "\n=== 重新添加元素测试排序 ===" << endl;
	list.insert(0, 5);
	list.insert(1, 2);
	list.insert(2, 7);
	list.insert(3, 1);
	cout << "排序前：";
	list.print();
	list.sort();
	cout << "排序后：";
	list.print();

	return 0;
}