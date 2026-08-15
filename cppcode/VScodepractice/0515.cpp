#include<iostream>
using namespace std;
int main()
{
    return 0;
}
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       int n=nums.size();
       vector<int> index (n);
       for(int i=0;i<n;i++)index[i]=i;
       sort(index.begin(),index.end(),[&](int a,int b){
        return nums[a]<nums[b];
       });
        vector<int>ret;
        int left=0,right=n-1;
        while(left<right)
        {
            int sum=nums[index[left]]+nums[index[right]];
            if(sum>target)
            {
                right--;
            }
            else if(sum<target)
            {
                left++;
            }
            else{
                ret.push_back(index[left]);
                ret.push_back(index[right]);
                break;
            }
        }
        return ret;
    }
        \addtogroup
        class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            auto it =mp.find(target-nums[i]);
            if(it!=mp.end())
            {
                return {i,it->second};
            }
            mp[nums[i]]=i;
        }
        return {0};
    }
};
};



*/