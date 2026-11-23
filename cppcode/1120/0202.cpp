#include<iostream>
using namespace std;
#include<algorithm>
/*


体育课上，
𝑛
n 名同学排成一列，每人佩戴一个编号，编号恰好构成 
1
∼
𝑛
1∼n 的一个排列。体育老师要求大家最终按编号从小到大重新排列。
但排队有一个奇怪的规则：每次只能选择相邻的两名同学交换位置，并且只有当两人编号之和为奇数时，这次交换才被允许。
请判断能否通过若干次交换，将队伍调整为 
1
,
2
,
3
,
…
,
𝑛
1,2,3,…,n 的顺序。
长度为n的排列：n个数，其中1到n每个数只出现一次
*/
const int N=2e5+10;
bool compare(int a,int b)
{
    if((a+b)%2==1)
        return a<b;
    else return a>b;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,compare);
   //判断是否排序成功
    for(int i=0;i<n;i++)
    {
        if(a[i]!=i+1)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}