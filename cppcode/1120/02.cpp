#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int arr[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ji=-1;
        int  ou=0;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2)
            {
                if(arr[i]<ji)
                {
                    cout<<"No"<<endl;
                    flag=1;
                    break;
                }
                else 
                ji=arr[i];
            }
            else 
            {
                if(arr[i]<ou)
                {
                    cout<<"No"<<endl;
                    flag=1;
                    break;
                }
                else 
                ou=arr[i];
            }
        }
        if(flag==0)
        cout<<"Yes"<<endl;
    }
    return 0;
}

// void popsort()
// {
//     for (int i = 0; i < N - 1; i++)
//     {
//         for (int j = 0; j < N - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1] && (arr[j] + arr[j + 1]) % 2 == 1)
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }
// void myquicksort(int l, int r)
// {
//     if (l >= r)
//         return;
//     int i = l, j = r;
//     int p = arr[l];
//     while (i < j)
//     {
//         while (i < j && arr[j] >= p)
//             j--;
//         if (i < j && (arr[i] + arr[j]) % 2 == 1)
//             swap(arr[i], arr[j]);
//         while (i < j && arr[i] <= p)
//             i++;
//         if (i < j && (arr[i] + arr[j]) % 2 == 1)
//             swap(arr[i], arr[j]);
//     }
//     myquicksort(l, i - 1);
//     myquicksort(i + 1, r);
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         myquicksort(0, n - 1);
//         // sort(arr, arr + n,[](int a, int b) {
//         //     if((a+b)%2==1&&a<b) return true;
//         //     return false;
//         // });
//         bool flag = true;
//         for (int i = 1; i < n; i++)
//         {
//             if (arr[i] < arr[i - 1])
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//         {
//             cout << "Yes" << endl;
//         }
//         else
//         {
//             cout << "No" << endl;
//         }
//     }
//     return 0;
// }