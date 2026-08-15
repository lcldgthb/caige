#include<iostream>
using namespace std;
const int N=1e5;
int arr[N];
int main()
{   
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int ret=0;
    int cur=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            cur++;
        }
        else
        {
            
            ret=max(ret,cur);
            cur=1;
        }
    }
    ret=max(ret,cur);
    cout<<ret<<endl;
    return 0;
}