//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<math.h>
//#include<cmath>
//#include<algorithm>
//#include<cstdlib>
//#include<numeric>
//using namespace std;
//long long gcd(long long a, long long b) 
//{
//	while (b != 0) {
//		long long temp = a % b;
//		a = b;
//		b = temp;
//	}
//	return a;
//}
//
//int main()
//{
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		long long c = 0,a=0,b=0;
//		cin >> c;
//		if (c % 2)
//		{
//			a = c / 2;
//			b = a + 1;
//		}
//		else
//		{
//			a = c / 2 + 1;
//			b = c / 2 - 1;
//		}
//		long long ta = a;
//		long long tb = b;
//		while (a)
//		{
//			if (gcd(a,b)==1)
//			{
//				cout << (long long)a * (long long)b << endl;
//				break;
//			}
//			else {
//				a--;
//				b++;
//			}
//		}
//		if(a==0)
//		cout << ta / gcd(ta, tb) * tb << endl;
//	}
//	return 0;
//}