#include<iostream>
#include<algorithm>
using namespace std;
const int N=55;
int arr[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>arr[i];
    int ret=INT_MAX;
    sort(arr,arr+m);

    for(int i=n-1;i<m;i++)
    {
        int tmp=arr[i]-arr[i-n+1];
        ret=min(ret,tmp);
    }
    cout<<ret<<endl;
    return 0;
}