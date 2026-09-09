#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int ret = 0;
	int flag = 1;
	int i = 1;
	while(i<=k)
	{
		for (int j = 1; j <= flag; j++)
		{
			if (i > k)
				break;
			
			ret += flag;
			i++;
		}
		flag++;
	}
	cout << ret << endl;
	/*int k;
	cin >> k;
	int i = 1;
	long long ret = 0;
	int n = 1;
	while (i <= k)
	{

		for (int j = 1; j <= n; j++)
		{
			if (i > k)
				break;
			ret += n;
			i++;

		}
		n++;
	}
	cout << ret;*/
	return 0;
}