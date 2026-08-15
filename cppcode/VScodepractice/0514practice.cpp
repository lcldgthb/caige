#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
// int main()
// {
//     //怎么快速注释，
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)cin>>a[i];
//     sort(a,a+n);
//     //l两层for循环
//     int i=0,j=0;
//     for( j=0;j<n;j++)
//     {
//         if(a[j]>a[i])
//         {
//             i++;
//         }
//     }
//     // for( i=0;i<n;)
//     // {
//     //     for( j=0;j<n;j++)
//     //     {
//     //         if(a[j]>a[i])
//     //         {
//     //             i++;
//     //         }
//     //     }
//     // }
//     cout<<j-i;
//     return 0;
// }
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    sort(a,a+N);
    cout<<a[N-1];
        return 0;
}