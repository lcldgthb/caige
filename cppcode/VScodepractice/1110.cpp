#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
/*
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，
表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；
输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，
所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
测试用例保证输出的长度不会超过 105。
*/
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string res;
        stack<int> num;
        string temp;
        int n=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                n=n*10+s[i]-'0';
            }
            else if(s[i]=='[')
            {
                num.push(n);
                st.push(res);
                res="";
                n=0;
            }
            else if(s[i]==']')
            {
                string t=st.top();
                st.pop();
                int k=num.top();
                num.pop();
                for(int j=0;j<k;j++)
                    t+=res;
                res=t;
            }
            else
            {
                res+=s[i];
            }
        }
        return res;
    }
};

int main()
{
   
    return 0;
}