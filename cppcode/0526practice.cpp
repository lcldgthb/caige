//合并果子
#include<iostream>
#include <queue>
using namespace std;
const int N=1e4+10;
int a[N];
int main()
{
int n;
cin>>n;
long long ret=0;
//小根堆
priority_queue<int,vector<int>,greater<int>> q;//这里是小根堆，默认是大根堆，所以需要greater<int>来改变比较方式

for(int i=0;i<n;i++)
{
    int x;
    cin>>x;
    q.push(x);
}
while(q.size()>1)
{
    int x=q.top();q.pop();
    int y=q.top();q.pop();
    ret+=x+y;
    q.push(x+y);
}
cout<<ret<<endl;
    return 0;
}