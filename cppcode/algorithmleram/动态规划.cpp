/*

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        //dp[i][0]表示第i个选红色的时候的最优解
        //dp[i][0]=min(dp[i-1][1],dp[i-1][2])+cost[i][0]
        int n=costs.size();
        vector<vector<int>> dp(n,vector<int>(3));
        //初始化
        dp[0][0]=costs[0][0];
        dp[0][1]=costs[0][1];
        dp[0][2]=costs[0][2];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+costs[i][0];
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+costs[i][1];
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+costs[i][2];
        }
        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>arr(10010);
        for(auto it:nums)arr[it]++;
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=i*arr[i];
        }
        vector<int>dp(10010);
        //dp[i]=max(dp[i-1],dp[i-2]+arr[i])
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[arr.size()-1];
    }
};
class Solution {
public:
    int massage(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        //dp[i]表示前i个里面最优解
        //dp[i]要么不接受这个，继承dp[i-1]
        //接受第i个，那么只能接受第i-2个。dp[i]=dp[i-2]+nums[i]
        //初始化，dp[0]和dp[1]
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];

    }
};
class Solution {
public:
    int rob1(vector<int>& nums,int l,int r)
    {
        int n=r-l+1;
        if(n==0)return 0;
        if(n==1)return nums[l];
        if(n==2)return max(nums[l],nums[l+1]);
        vector<int>dp(n);
        dp[0]=nums[l];
        dp[1]=max(nums[l],nums[l+1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[l+i]);
        }
        return dp[n-1];

    }
    int rob(vector<int>& nums) {
        
        int n=nums.size()-1;
        if(n==0)return nums[0];
        if(n==1)return max(nums[0],nums[1]);
        

        return max(rob1(nums,0,n-1),rob1(nums,1,n));
    }
};

*/