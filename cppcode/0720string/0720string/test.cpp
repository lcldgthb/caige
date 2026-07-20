#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
using namespace std;
namespace caige
{
	void test01()
	{
		bit::string s;
		cout << s.size() << endl;
		s.push_back('a');
	}
}

int main()
{

	/*string s1("abcd");
	cout << s1 << endl;
	char charr[] = { 'a','b','c','\0'};
	cout << charr << endl;
	printf("%s", charr);
	int arr[] = {1,2,3,4,5};
	cout << arr;*/
	caige::test01();
	
	return 0;
}