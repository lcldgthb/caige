/*
//最大盛水体积
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int h=min(height[l],height[r]);
        int ret=h*(r-l);
        while(l<r)
        {
            if(height[l]<height[r])
            {
                int ll=l+1;
                while(height[ll]<height[l]&&ll<r)
                {
                    ll++;
                }
                l=ll;
                int v=(r-l)*min(height[l],height[r]);
                ret=max(v,ret);
            }else
            {
                int rr=r-1;
                while(height[rr]<height[r]&&rr>l)
                {
                    rr--;
                }
                r=rr;
                 int v=(r-l)*min(height[l],height[r]);
                ret=max(v,ret);
            }
        }
        return ret;
    }
};
//有效三角形的个数
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int l=0,r=nums.size();
        int ret=0;
        sort(nums.begin(),nums.end());
        for(int j=nums.size()-1;j>=2;j--)
        {
            l=0;r=j-1;
            while(l<r)
            {
                if(nums[l]+nums[r]>nums[j])
                {
                    ret+=(r-l);
                    r--;
                }else
                {
                    l++;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        vector<int> ret;
        int left=0;
        int right=price.size()-1;
        while(left<right)
        {
            if(price[left]+price[right]>target)
            {
                right--;
            }
            else if(price[left]+price[right]<target)
            {
                left++;
            }
            else
            {
                ret.push_back(price[left]);
                ret.push_back(price[right]);
                return ret;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
       sort(nums.begin(),nums.end());
       vector<vector<int>> ret;
       for(int i=nums.size()-1;i>=2;)
       {
            if(nums[i]<0)
            break;
            int left=0;
            int right=i-1;
            while(left<right)
            {
                if(nums[left]+nums[right]+nums[i]>0)
                {
                     right--;
                   
                }
               
            else if(nums[left]+nums[right]+nums[i]<0)
                {
                    left++;
                }   
            else
                {
                vector<int>tmp;
                tmp.push_back(nums[left]);
                 tmp.push_back(nums[right]);
                  tmp.push_back(nums[i]);
                ret.push_back(tmp);
               left++;
                right--;
                  while(nums[right]==nums[right+1]&&right>left)
                     {
                        right--;
                     }
                    while(nums[left]==nums[left-1]&&left<right)
                    {
                        left++;
                    }
                 }
            }
           i--;
            while(nums[i]==nums[i+1]&&i>=2)i--;
       } 
       //o（N*N）
       return ret;
    }
};



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<vector<int>>ret;
       int i=0;int j=0;
       for( i=0;i<n-3;)
       {
        for(j=i+1;j<n-2;)
        {
            if(nums[i]+nums[j]>=target)
            break;
            int left=j+1;
            int right=n-1;
            
            while(left<right)
            {
                int sum=nums[left]+nums[right]+nums[i]+nums[j];
                 if(sum>target)right--;
            else if(sum<target)left++;
            else{
                ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                right--;
                left++;
                while(nums[left]==nums[left-1]&&left<right)left++;
                while(nums[right]==nums[right+1]&&left<right)right--;
                  }
            }
            j++;
            while(nums[j]==nums[j-1]&&j<n-2)j++;
        }
        i++;
        while(nums[i]==nums[i-1]&&i<n-3)i++;
       }
       return ret;
    }
};
*/