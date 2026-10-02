#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{

	int i = 1;
	while (i <= 10000)
	{
		if (i % 2)
			cout << "if numbers==" << i << ";printf(\"是偶数\");" << endl;
		else 
			cout << "if numbers==" << i << ";printf(\"是奇数\");" << endl;
		i++;
	}
	return 0;
}
