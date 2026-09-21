#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{

	return 0;
}
/*
class Solution {
public:
    string removeDuplicates(string s) {
        string  st;
        for(auto e:s)
        {
            if(st.size())
            {
                char top=st.back();
                if(st.back()==e)
                st.pop_back();
                else
                st.push_back(e);
            }
            else
            st.push_back(e);
        }
        return st;
    }
};

*/