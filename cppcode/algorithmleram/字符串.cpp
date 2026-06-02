#include<iostream>
using namespace std;
int main()
{
    return 0;
}
/*
class Solution {
    //动态规划
public:
bool iscommon(string& s,int left,int right)
{
    for(int i=left+1;i<right;i++)
    {
        if(s[i]!=s[i-1])
        return false;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n=s.size();
        int arr[n];//arr[i]表示以i结尾的最长序列。
        arr[0]=1;
        for(int i=1;i<n;i++)
        {
            if(i-1-arr[i-1]>=0&&s[i-1-arr[i-1]]==s[i])
            {
                arr[i]=arr[i-1]+2;
            }else if(i-1-arr[i-1]>=0&&s[i-1-arr[i-1]]!=s[i])
            {
                if(s[i]!=s[i+1])
                arr[i]=1;
                if(iscommon(s,i-arr[i],i))
                arr[i]=arr[i-1]+1;
            }
            else 
            {
                arr[i]=1;
            }
        }
        pair<int,int> tmp={0,arr[0]};
        for(int i=1;i<n;i++)
        {
           if(arr[i]>tmp.second) 
           tmp={i,arr[i]};
        }
        string ret;
        ret=s.substr(tmp.first-tmp.second,tmp.second);
        return ret;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int right=0,left=0;
        int n=s.size();
        vector<vector<int>> ret(n,vector<int>(3));
        for(int i=0;i<s.size();i++)
        {
            left=right=i;
            while(left>=0&&right<n)
            {
                if(s[left]!=s[right])
                break;
                left--;
                right++;
            }
            left++;
            right--;
            ret[i][0]=left;
            ret[i][1]=right;
            ret[i][2]=right-left+1;
            left=i;right=i+1;
             while(left>=0&&right<n)
            {
                if(s[left]!=s[right])
                break;
                left--;
                right++;
            }
            left++;
            right--;
            if(right-left+1>ret[i][2])
            {
                ret[i][0]=left;
                ret[i][1]=right;
                ret[i][2]=right-left+1;
            }

        }
        int maxx=0;
        for(int i=0;i<n;i++)
        if(ret[i][2]>ret[maxx][2])
        maxx=i;
        return s.substr(ret[maxx][0],ret[maxx][2]);
    }
};

class Solution {
public:
      string towlong(string a,string b)
      {
        int i=0;
        string ret;
        for(i=0;i<a.size()&&i<b.size();i++)
        {
            if(a[i]!=b[i])
            return ret;
            else 
            ret.push_back(a[i]);
        }
        return ret;
      }
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if(strs.size()==1)
        return strs[0];
        ret=towlong(strs[0],strs[1]);
        for(auto it:strs)
        {
            ret=towlong(ret,it);
        }
        return ret;
    }
};
*/