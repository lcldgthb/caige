/*

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //把数放进哈希表里，我们只要找前面有没有出现过target-nums[i];即可
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            return {i,mp[target-nums[i]]};
            mp[nums[i]]=i;
            
        }
       return {0};
    }
};
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size())
        return false;
        unordered_map<char,int>mp1;
       // unordered_map<char,int>mp2;
        for(auto it:s1)mp1[it]++;
        for(auto it:s2)mp1[it]--;
       for(auto it:mp1)
       {
        if(it.second!=0)
    return false;
       }
        return true;

    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums)
        {
            if(st.count(it))
            return true;
            st.insert(it);
        }
        return false;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
                if((i-mp[nums[i]])<=k)
                return true;
                
            }
           mp[nums[i]]=i;
        }
        return false;
    }
};
*/