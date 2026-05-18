/*


*/
//记得用long long
//给的数是从1开始，所以，前缀和不用特殊处理
#include <iostream>
using namespace std;
const int N=1e5+10;
long long arr[N];//arr[i]表示前i个数的和，包括第i个数。
int main() {
   int n,m;
   cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         long long  x;
        cin>>x;
        arr[i]=arr[i-1]+x;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
}
// 64 位输出请用 printf("%lld")
/*

 class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //由于题目要求不允许使用除法，所以，我们只能分别求出nums[i]前面的乘积和后面的乘积再相乘
         int n=nums.size();
        vector<int>f(n);
        vector<int>g(n);
        f[0]=1;g[n-1]=1;
        for(int i=1;i<n;i++)
        f[i]=f[i-1]*nums[i-1];
        for(int i=n-2;i>=0;i--)
        g[i]=g[i+1]*nums[i+1];
        vector<int>answer;
        for(int i=0;i<n;i++)
        answer.push_back(f[i]*g[i]);
        return answer;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //前缀和和后缀和数组
        //注意小标要从1开始
        //f[n]g[n]表示的含义也和之前的有点不一样
        //这里表示f[n]前面的数的和，不包括自己
        int n=nums.size();
        vector<int>f(n);
        vector<int>g(n);
        for(int i=1;i<n;i++)
        f[i]=f[i-1]+nums[i-1];
        for(int i=n-2;i>=0;i--)
        g[i]=g[i+1]+nums[i+1];
        for(int i=0;i<n;i++)
         if(f[i]==g[i])
         return i;
         return -1;
    }
};

*/