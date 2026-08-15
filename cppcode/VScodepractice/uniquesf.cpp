#include<iostream>
#include<unordered_map>
    //  滑动窗口
using namespace std;
const int N=1e6+10;
int arr[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        unordered_map<int,int>mp;
        int left=0,right=0;
        int len=0;
        for(right=0;right<n;right++)
        {
            mp[arr[right]]++;
            if(mp[arr[right]]==1)
            {
                len=max(len,right-left+1);
            }
            else
            {
                while(mp[arr[right]]>1)
                {
                    mp[arr[left]]--;
                    if(mp[arr[left]]==0)
                    mp.erase(arr[left]);
                    left++;
                }
            }
        }
        cout<<len<<endl;
    }
    return 0;
}