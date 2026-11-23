#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
const int N = 1024 + 10;
int a[N];
struct xuanso
{
    int shili = 0;
    bool cn = false;
    int i = -1;//原始下标
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<xuanso> v;
    unordered_set<int> b;//存放中国对
    for (int i = 0; i < n; i++)
    {
        xuanso tmp;
        cin >> tmp.shili;
        tmp.i = i + 1;
        v.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
        v[x - 1].cn = true;
    }
    int cnt = 0;
    
    while (v.size()>1)
    {
        cnt++;
        cout << "第" << cnt << "次比赛: 共 "<<v.size() << endl;
        for (auto e : v)
            cout <<"初始下标："<<e.i << "实力： " << e.shili << " 是中国： " << e.cn << endl;
        vector<xuanso> a;
        //比赛
        for (int i = 0; i < v.size() - 1; i += 2)
        {
            if (v[i].shili > v[i + 1].shili)
            {
                a.push_back(v[i]);
                if (v[i + 1].cn)
                    b.erase(v[i + 1].i);
            }
            else if (v[i].shili < v[i + 1].shili)
            {
                a.push_back(v[i + 1]);
                if (v[i].cn)
                    b.erase(v[i].i);
            }
            else
            {
                if (v[i].cn)
                    a.push_back(v[i]);
                else
                    a.push_back(v[i + 1]);
            }
        }
      
        v = a;
        cout << "v.size: " << v.size()<<endl;
        if (b.empty())
        {
            cout <<"v.size: "<<v.size() << "这是第" << cnt;
            break;
        }

    }

    return 0;
}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//const int N = 1024 + 10;
//int a[N];
//struct xuanso
//{
//    int shili = 0;
//    bool cn = false;
//    int i = -1;
//};
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<xuanso> v;
//    unordered_set<int> b;
//    //
//    for (int i = 0; i < n; i++)
//    {
//        xuanso tmp;
//        cin >> tmp.shili;
//        tmp.i = i + 1;
//        v.push_back(tmp);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int x;
//        cin >> x;
//        b.insert(x);
//        v[x - 1].cn = true;
//    }
//    int cnt = 0;
//
//    while (1)
//    {
//        vector<xuanso> a;
//        for (int i = 0; i < n; i += 2)
//        {
//            if (v[i].shili > v[i + 1].shili)
//            {
//                a.push_back(v[i]);
//            }
//            else if (v[i].shili < v[i + 1].shili)
//            {
//                a.push_back(v[i + 1]);
//            }
//            else
//            {
//                if (v[i].cn)
//                    a.push_back(v[i]);
//                else
//                    a.push_back(v[i + 1]);
//            }
//        }
//        cnt++;
//        v = a;
//        for (auto p : b)
//        {
//            if (v[p].cn == 0)
//            {
//                b.erase(p);
//            }
//        }
//        if (b.empty())
//        {
//            cout << cnt;
//            break;
//        }
//    }
//
//    return 0;
//}