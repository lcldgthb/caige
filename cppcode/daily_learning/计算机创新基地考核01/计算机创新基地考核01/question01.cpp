//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//int main()
//{
//	long long n;
//	cin >> n;
//	long long x = 0;
//	x = n / 2;
//	long long ret = 0;
//	if (n % 2)
//	{
//		ret = x * (x + 1) + x + 1;
//	}
//	else
//	{
//		ret = x * (x + 1);
//	}
//	cout << ret;
//	return 0;
//}


//
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//void test()
//{
//	int a = -1;
//	cout << abs(a);
//}
//int main()
//{
//	int p, b, n, t;
//	cin >> p >> b >> n >> t;
//	string s;
//	cin >> s;
//	int flag = 1;
//	vector<int> v(n,-1);
//	for (int i = 0; i < n; i++)
//	{
//		v[i] = s[i] - 'A' + b;
//		if (i > 0&&s[i]!=s[i-1])
//		{
//			flag = 0;
//		}
//	}
//	/*for (auto e : v)
//		cout << e << endl;*/
//	string tmp;
//	int time = 0;
//	for (auto e : v)
//	{
//		time += e;
//		tmp+=to_string(abs(e - p));
//	}
//	if (flag == 1 && time == t)
//	{
//		cout << 100;
//	}
//	else
//	{
//
//	
//	tmp += to_string(abs(time - t));
//	//cout << tmp << endl;
//	
//	int size = tmp.size();
//	while (tmp.size()> 2)
//	{
//		int left = 0, right = tmp.size() - 1;
//		string s2 ;
//		while (left <= right)
//		{
//			if (left == right)
//			{
//				s2 += tmp[right];
//				break;
//			}
//			s2 += to_string(((tmp[left++]-'0') +( tmp[right--])-'0') % 10);
//		}
//		tmp = s2;
//		//cout << tmp << endl;
//	}
//	cout << tmp;
//	}
//	/*test();*/
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool issame(string s1, string s2)
{
	return s1 == s2;
}
bool hassamepre(string s1, string s2)
{
	for (int i = 0; i < s2.size(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}
int main()
{
	vector<string> v;
	int n, q;
		cin >> n >> q;
		while (n--)
		{
			string tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		while (q--)
		{
			string s2;
			cin >> s2;
			int c1 = 0, c2 = 0;
			for (auto e : v)
			{
				if (issame(e, s2))
					c1++;
				if (hassamepre(e, s2))
					c2++;

			}
			cout << c1 <<" "<< c2 << endl;
		}
}
//const int N = 1e5+10;
//int arr[N][25];   //arr[i][j]表示第i个节点的j孩子
//bool f[N];        //i号节点是否是结束节点
//void insert(string s)
//{
//	int p = 0;
//	for (int j=0;j<s.size();j++ )
//	{
//		int i = s[j] - 'a';
//		if (arr[p][i])
//		{
//			p = arr[p][i];
//		}
//		else
//		{
//			arr[p][i] = p+1;
//			p = p+1;
//		}
//		if (j == s.size() - 1)
//		{
//			f[j] = true;
//		}
//	}
//
//}
//bool isintree(string s)
//{
//	int p = 0;
//	int c = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		c = s[i] - 'a';
//		if (!arr[p][c])
//			return false;
//		else
//			p = arr[p][c];
//	}
//	
//		return f[p];
//}
//bool pre(string s)
//{
//	int p = 0;
//	int c = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		c = s[i] - 'a';
//		if (!arr[p][c])
//			return false;
//		else
//			p = arr[p][c];
//	}
//
//	return true;
//}
//void test()
//{/*
//	insert("app");
//	insert("ai");
//	insert("blue");
//	cout << isintree("app") << endl;
//	cout << isintree("a") << endl;
//	cout << isintree("blue") << endl;
//	cout << pre("bl") << endl;*/
//}
//int main()
//{
//	//test();
//	int n, q;
//	cin >> n >> q;
//	while (n--)
//	{
//		string tmp;
//		cin >> tmp;
//		insert(tmp);
//	}
//	while (q--)
//	{
//		string s2;
//		cin >> s2;
//		
//	}
//	return 0;
//}
//int main()
//{
//	int n, m, q;
//	cin >> n >> m >> q;
//	vector<int> v(n + 1);
//	for (int i = 1; i <= n; i++)
//		cin >> v[i];
//	vector<int> w(n + 1);
//	for (int i = 1; i <= n; i++)
//		w[i] = v[i] - v[i - 1];
//	/*for (auto e : w)
//		cout << e << ' ';
//	cout << endl;*/
//	while (m--)
//	{
//		int l, r, x;
//		cin >> l >> r >> x;
//		w[l] += x;
//		if(r+1<=n)
//		w[r+1] -= x;
//	}
//	for (int i = 1; i <= n; i++)
//		w[i] = w[i] + w[i - 1];
//	/*for (auto e : w)
//		cout << e << ' ';*/
//	for (int i = 1; i <= n; i++)
//		w[i] = w[i] + w[i - 1];
//	/*for (auto e : w)
//		cout << e << ' ';*/
//	/*cout << endl;*/
//	while (q--)
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << w[b] - w[a - 1] << endl;
//	}
//	return 0;
//}
//int solution(vector<int>v, int k)
//{
//	int left = 0, right = v.size() - 1;
//	int ret = 0;
//	while (left < right)
//	{
//		if ((v[left] + v[right]) == k)
//		{
//			ret++;
//			left++;
//			right--;
//		}
//		else if ((v[left] + v[right]) < k)
//			left++;
//		else
//			right--;
//	}
//	return ret;
//}
//int main()
//{
//	int a, b, c, k;
//	cin >> a >> b >> c >> k;
//	vector<int> x(a, 0);
//	vector<int> y(b, 0);
//	vector<int> z(c, 0);
//	for (int i = 0; i < x.size(); i++)
//		cin >> x[i];
//	for(int i=0;i<y.size();i++)
//		cin >> y[i];
//
//	for(int i=0;i<z.size();i++)
//		cin >> z[i];
//
//
//	cout << solution(x, k) << " "  << solution(y, k) <<" "  << solution(z, k) << " ";
//
//	return 0;
//}
//bool check(int n)
//{
//	int a = n % 10;
//	n /= 10;
//	while (n)
//	{
//
//		int b = n % 10;
//		if (b > a)
//			return false;
//		a = b;
//		n /= 10;
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int flag = 1;
//	for (int i = 10; i <= n; i++)
//	{
//		if (check(i))
//		{
//			flag = 0;
//			cout << i << endl;
//		}
//	}
//	if (flag == 1)
//		cout << -1;
//	return 0;
//}
//int main()
//{
//	int k;
//	cin >> k;
//	int  ret = 1;
//	double sum = 1;
//	while (sum < k)
//	{
//		ret++;
//		sum += (double)(1.0 / ret);
//		
//	}
//	cout << ret;
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
////int main()
////{
////	int n;
////	cin >> n;
////	int flag = 1;
////	for (int i = 10; i <= n; i++)
////	{
////
////	}
////}
//int main()
//{
//	int k;
//	cin >> k;
//	if (k == 1)
//	{
//		cout << 2;
//	}
//	else
//	{
//	int  ret = 1;
//	double sum = 1;
//	while (sum < k)
//	{
//		ret++;
//		sum += (double)(1.0 / ret);
//
//	}
//	cout << ret;
//	}
//	return 0;
//}