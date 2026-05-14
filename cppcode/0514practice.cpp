#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    //l两层for循环
    int i=0,j=0;
    for( i=0;i<n;)
    {
        for( j=0;j<n;j++)
        {
            if(a[j]>a[i])
            {
                i++;
            }
        }
    }
    cout<<j-i+1;
    return 0;
}