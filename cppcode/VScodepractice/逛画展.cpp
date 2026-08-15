#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
const int N=1e6+10;
int arr[N];
int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //  滑动窗口
    int left=0,right=0;
    int re=1e9;
    vector<int>ret;
    for(right=0;right<n;right++)
    {
        mp[arr[right]]++;
            while(mp.size()==m)
            {
                if(right-left+1<re)
                {
                    re=right-left+1;
                   ret.clear();
                    ret.push_back(left);
                    ret.push_back(right);

                mp[arr[left]]--;
                if(mp[arr[left]]==0)
                mp.erase(arr[left]);
                left++;
            }
        
    }
    for(int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<" ";
    }
    return 0;
   
}