/*
1
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;int right=0;
        int sum=nums[0];
        int ret=0x3f3f3f3f;
        while(right<nums.size()&&left<=right)
        {
            if(sum<target)
            {
                right++;
                if(right<nums.size())
                sum+=nums[right];
            }
            else
            {
                ret=min(ret,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return ret==0x3f3f3f3f?0:ret;
    }
};
2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        //哈希表
        //数组来标记有没有出现过
        int arr[128];
      int left=0;int right=0;
      int len=0;
      while(left<=right&&right<s.size())
      {
        if(arr[s[right]]==0)
        {
            arr[s[right]]++;
            right++;
            len=max(len,right-left);//先加加，在求的长度，所以，不用加1
        }
        else
        {
            arr[s[left]]--;
            left++;
        }
      }
      return len;
    }
};
3
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //窗口维护的是区间内0的个数
        int left=0;
        int right=0;
        int n=0;
        int retlen=0;
        while(right<nums.size())
        {
            if(nums[right]==1)
            {
                retlen=max(retlen,right-left+1);
            }
            else
            {
                n++;
                if(n<=k)
                {
                    retlen=max(retlen,right-left+1);
                }
                else
                {
                    while(n>k)
                    {
                        if(nums[left]==0)
                        {
                            n--;
                        }
                        left++;
                        //n维护的是这个区间里面0的个数，所以，当nums【left】是0的时候，也要++
                    }
                    retlen=max(retlen,right-left+1);
                }
            }
              right++;
        }
        return retlen;
    }
};
4
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //翻转问题
        //转换成求区间和为sum-x的最大区间;
        int left=0,right=0;
        int sum=0;
        for(auto it:nums)sum+=it;
        int target=sum-x;
        if(target<0)
        return -1;
        if(target==0)
        return nums.size();
        int tmp=0;
        int len=0;
        while(right<nums.size())
        {
           tmp+=nums[right];
            while(tmp>target)
            {
                tmp-=nums[left];
                left++;
            }
               if(tmp==target)
           {
            len=max(len,right-left+1);
           }
           right++;
          
        }
        if(len==0)
        return -1;
        int ret=nums.size()-len;

        return ret;
    }
};
5
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //最长子数组
        //条件：里面仅含有两种元素
        int left=0, right=0;
      unordered_map<int,int>mp;
      int len=0;
      while(right<fruits.size())
      {
        mp[fruits[right]]++;
        while(mp.size()==3)
        {
            mp[fruits[left]]--;
            if(mp[fruits[left]]==0)
            mp.erase(fruits[left]);
            left++;
        }
        if(mp.size()==2)
        {
            len=max(len,right-left+1);
        }
        right++;
      }
      if(mp.size()==1)
      return fruits.size();
      return len;
    }
};
6
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26]={0};
        for(auto it:p)hash1[it-'a']++;
        vector<int>ret;
        int hash2[26]={0};
        //count记录有效字符的个数。
        for(int left=0,right=0,count=0;right<s.size();right++)
        {
            hash2[s[right]-'a']++;
            if(hash2[s[right]-'a']<=hash1[s[right]-'a'])
            {
                count++;
            }
            if(right-left+1>p.size())
            {
                if(hash2[s[left]-'a']<=hash1[s[left]-'a'])
                {
                    count--;
                }
                 hash2[s[left]-'a']--;
                    left++;
            }
            //隐含前提，right-left+1==p.size了
            if(count==p.size())
            {
                ret.push_back(left);
            }
        }
        return ret;

    }
};
7
class Solution {
    string gets(int j,int n,string s)
    {
        string tmp="";
           while(n--)
           {
            tmp+=s[j++];
           }
            return tmp;
    }
   
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words[0].size();
        unordered_map<string,int>mp1;
        for(auto it:words)mp1[it]++;
      
        vector<int>ret;
        for(int m=0;m<n;m++)
        {
              unordered_map<string,int>mp2;
            for(int left=m,right=m,count=0;right+n<=s.size();right+=n)//不敢想，不敢想，把right<=s.size()-n;改为right+n<=s.size();就能过
        {
            string tmp=s.substr(right,n);
            mp2[tmp]++;
            if(mp2[tmp]<=mp1[tmp])
            {
                count++;
            }
            if((right-left+n)>(words.size()*n))
            {
                string tmp2=gets(left,n,s);
                if(mp2[tmp2]<=mp1[tmp2])
                {
                    count--;
                }
                mp2[tmp2]--;
                  if(mp2[tmp2] == 0) mp2.erase(tmp2);
                left+=n;
            }
            if(count==words.size())
            {
                ret.push_back(left);
            }
        }
        }
        
        return ret;
    }
};


*/