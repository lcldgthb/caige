/*

class Solution {
public:
    bool isUnique(string astr) {
        //哈希表->数组代替->位图
        int n=0;
        for(auto it:astr)
        {
            int i=it-'a';
            if(n&(1<<i))//判断是不是1
            return false;
            else
            n|=(1<<i);//改为1
        }
        return true;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret=0;
        for(int i=0;i<nums.size();i++)
        {
           ret= ret^nums[i];
           ret^=i;
        }
        return ret^nums.size();
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        //模拟加法，
        //哪些位不进位    a^b
        //获取不进位的位组成的数 
        //获取哪些位要进位，再向左移一位  a&b
        //循环加，直到没有进位
        while(b)
        {
            int x=a^b;
            int y=(a&b)<<1;
            a=x;
            b=y;
        }
        return a;
          /*  a=a^b;
            b=(a&b)<<1;
        while(a&b)
        {
            a=a^b;
            b=(a&b)<<1;
        }
        return a;
        
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32]={0};
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                arr[j]=(arr[j]+((nums[i]>>j)&1))%3;
            }
        }
        int ret=0;
        long long  a=1;
        for(int i=0;i<32;i++)
        {
            if(arr[i])
            ret+=a;
            a*=2;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int tmp=0;
        for(auto it:nums)tmp^=it;
        for(int i=1;i<=nums.size()+2;i++)tmp^=i;
        int diff=0;
        while(1)
        {
            if((tmp>>diff)&1)
            break;
            else
            diff++;
        }
        int a=0,b=0;
        for(auto it:nums)
        {
            if((it>>diff)&1)
            a^=it;
            else
            b^=it;
        }
        for(int i=1;i<=nums.size()+2;i++)
        {
            if((i>>diff)&1)
            a^=i;
            else
            b^=i;
        }
        return {a,b};
    }
};
*/