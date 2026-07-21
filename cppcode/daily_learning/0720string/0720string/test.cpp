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
		bit::string s1("abcdefg");
		s1.push_back('h');
		for (auto it : s1)
		{
			cout << it << ' ';
		}
		cout << endl;
		s1.insert(1, 'a');
		cout << s1.c_str() << endl;
		s1 += "caige";
		cout << s1.c_str() << endl;
		cout<<s1.find('c')<<endl;

		cout << s1.substr(s1.find("cai")) << endl;
		s1.erase(3, 1);
		cout << s1 << endl;

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