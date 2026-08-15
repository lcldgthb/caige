#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 10;
long long  arr[N];
long long brr[N];
long long crr[N];
long long index[N];
long long post[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		long long bsret = 0;
		for (int i = 0; i < n; i++)cin >> arr[i];
		for (int i = 0; i < n; i++)cin >> brr[i];
		for (int i = 0; i < n; i++)cin >> crr[i];
		for (int i = 0; i < n; i++)index[i] = i;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= brr[i])
			{
				bsret += crr[i];
				arr[i] = 0;
				brr[i] = 0;
				crr[i] = 0;
			}
		}
		/*while (q--)
		{
			int x;
			cin >> x;
			long long maxx = 0;
			for (int i = 0; i < n; i++)
			{
				if (x >= brr[i] && arr[i] < brr[i])
				{
					maxx =max(maxx, crr[i]);
				}
			}
			cout << bsret + maxx << endl;
		}*/
		
		sort(index, index + n, [&](long long a, long long b)
			{
				return brr[a] < brr[b];
			});
		post[0] = crr[index[0]];
		for (int i = 1; i <n; i++)
		{
			post[i] = max(post[i - 1], crr[index[i]]);
		}
		//for (int i = 0; i < n; i++)cout << index[i] << "  ";
		while (q--)
		{
			long long x;
			cin >> x;
			long long l = 0, r = n-1;
			while (l < r)
			{
				long long mid = (r +l) / 2 + 1;
				if (brr[index[mid]] <= x)
					l = mid;
				else
					r = mid - 1;
			}

			long long maxx = 0;
			if (brr[index[l]] <= x)
			{
				maxx = post[l];
			}
			cout << bsret + maxx << endl;
		}
		
	}
	return 0;
}