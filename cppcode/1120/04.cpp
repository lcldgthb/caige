// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <unordered_set>
// using namespace std;
// const int N = 1024 + 10;
// int a[N];
// struct xuanso
// {
//     int shili=0;
//     bool cn=false;
//     int i=-1;//原始下标
// };
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<xuanso> v;
//     unordered_set<int> b;//存放中国对
//     for (int i = 0; i < n; i++)
//     {
//        xuanso tmp;
//        cin>> tmp.shili;
//        tmp.i=i+1;
//        v.push_back(tmp);
//     }
//     for (int i = 0; i < m; i++)
//     {
//         int x;
//         cin >> x;
//         b.insert(x);
//         v[x-1].cn=true;
//     }
//     int cnt = 0;

//     while (1)
//     {
//          vector<xuanso> a;
//          //比赛
//         for (int i = 0; i < n; i += 2)
//         {
//             if (v[i].shili> v[i + 1].shili)
//             {
//                a.push_back(v[i]);
//                if(v[i+1].cn)
//                b.erase(v[i+1].i);
//             }
//            else if (v[i].shili< v[i + 1].shili)
//             {
//                a.push_back(v[i+1]);
//                 if(v[i].cn)
//                b.erase(v[i].i);
//             }
//             else
//             {
//                if(v[i].cn)
//                a.push_back(v[i]);
//                else
//                a.push_back(v[i+1]);
//             }
//         }
//         cnt++;
//         v=a;
//         if (b.empty())
//         {
//             cout << cnt;
//             break;
//         }
//     }

//     return 0;
// }

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
    int i = -1; // 原始下标
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<xuanso> v;
    unordered_set<int> b; // 存放中国对
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
    int cnt = 1;

    while (v.size() > 1)
    {
        vector<xuanso> a;
        // 比赛
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
        if (b.empty())
        {
            cout << cnt;
            break;
        }
        cnt++;
    }

    return 0;
}