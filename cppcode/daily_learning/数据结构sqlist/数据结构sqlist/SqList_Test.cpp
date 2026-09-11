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

	caige::test01();
	//printf("\"ÄãºÃ£¡\"");
	return 0;
}