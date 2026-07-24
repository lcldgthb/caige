#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
using namespace std;
namespace caige
{
	void test01()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		for (auto& it : l1)
			cout << it << " ";
		l1.push_front(0);
		l1.push_front(-1);
		l1.push_front(-2);
		cout << endl;
		for (auto& it : l1)
			cout << it << " ";
		l1.pop_back();
		l1.pop_front();
		cout << endl;
		for (auto& it : l1)
			cout << it << " ";


	}
}
int main()
{
	caige::test01();
	return 0;
}