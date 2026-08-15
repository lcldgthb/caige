/*

vector<int> ji;
        ji.resize(nums.size()+1);
        vector<int> ao;
        ao.resize(nums.size()+1);
        for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]%2==0)
                {
                    ao[i]=ao[i+1]+1;
                }
                else
                    ji[i]
            }
                   
*/
#include<iostream>
#include<vector>
using namespace std;
/*
int main()
{
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    int j=0;
    int ao=0;
for(auto it=nums.end()-1;it!=nums.begin();it--)
            {
                if(*it%2==1)
                {
                    j++;
                    *it=ao;
                }else
                {
                    ao++;
                    *it=j;
                }
            }
    return 0;
}
*/
/*
//统计下标的相反奇偶性得分
int main()
{

    class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
       int j=0;
        int ao=0;
        for(auto it=nums.end()-1;it>=nums.begin();it--)
            {
                if(*it%2==1)
                {
                    j++;
                    *it=ao;
                }else
                {
                    ao++;
                    *it=j;
                }
            }
        return nums;
    }
};
    return 0;
}
    
   int reversen(int n)
{
    int m=0;
    while(n)
        {
            m*=10;
            m+=(n%10);
            n/=10;
        }
    return m;
}
   int main()
 {
cout<<reversen(123)<<endl;
    return 0;
 }
 //数与其逆序数的范围内质数的和
 //解法一：暴力法
 class Solution {
    vector<int> prime;
    //vector<bool> b{1000+1,true};
    bool b[1001];
    // 构造函数：初始化数组全为 true
    
    void findprime()
    {
        for(int i=0;i<=1001;i++)
            b[i]=true;
        //
        b[0]=b[1]=false;
        for(int i=2;i<=1000;i++)
            {
                if(b[i])
                {
                    prime.push_back(i);
                }
                for(int j=0;j<prime.size();j++)
                    {
                        if(i*prime[j]>1000)
                            break;
                        b[i*prime[j]]=false;
                        if(i%prime[j]==0)
                            break;
                    }
            }
    }
int reversen(int n)
{
    int m=0;
    while(n)
        {
            m*=10;
            m+=(n%10);
            n/=10;
        }
    return m;
}
    bool isprime(int i)
    {
        if(i<2)
            return false;
        for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                    return false;
            }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int ret=0;
        int m=reversen(n);
        int l=max(m,n);
        int r=min(m,n);
        for(int i=r;i<=l;i++)
            {
                if(isprime(i))
                    ret+=i;
            }
        return ret;
    }
};©leetcode
//解法二：线性筛
class Solution {
    vector<int> prime;
    //vector<bool> b{1000+1,true};
    bool b[1001];
    // 构造函数：初始化数组全为 true
    
    void findprime()
    {
        for(int i=0;i<=1001;i++)
            b[i]=true;
        //
        b[0]=b[1]=false;
        for(int i=2;i<=1000;i++)
            {
                if(b[i])
                {
                    prime.push_back(i);
                }
                for(int j=0;j<prime.size();j++)
                    {
                        if(i*prime[j]>1000)
                            break;
                        b[i*prime[j]]=false;
                        if(i%prime[j]==0)
                            break;
                    }
            }
    }
int reversen(int n)
{
    int m=0;
    while(n)
        {
            m*=10;
            m+=(n%10);
            n/=10;
        }
    return m;
}
    bool isprime(int i)
    {
        if(i<2)
            return false;
        
        return b[i];
    }
public:
    int sumOfPrimesInRange(int n) {
        findprime();
        int ret=0;
        int m=reversen(n);
        int l=max(m,n);
        int r=min(m,n);
        for(int i=r;i<=l;i++)
            {
                if(isprime(i))
                    ret+=i;
            }
        return ret;
    }
};©leetcode
 */