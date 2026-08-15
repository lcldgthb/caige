#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<numeric>
using namespace std;
int main()
{
	int ret = gcd(4, 6);
	int t = 0;
	cin >> t;
	while (t--)
	{
		int c = 0,a=0,b=0;
		cin >> c;
		if (c % 2)
		{
			a = c / 2;
			b = a + 1;
		}
		else
		{
			a = c / 2 + 1;
			b = c / 2 - 1;
		}
		while (a)
		{
			if (ishuzhi(a, b))
			{
				cout << (long long)a * (long long)b << endl;
			}
		}
	}
	return 0;
}