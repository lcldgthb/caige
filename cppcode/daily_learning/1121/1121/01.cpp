//#define _CRT_SECURE_NO_WARNINGS
//////#include<iostream>
//////#include<algorithm>
//////using namespace std;
//////const int N = 20010;
//////int a[N];
//////int cnt;
//////int main() {
//////    int T;
//////    cin >> T;
//////    while (T--) {
//////        int n;
//////        cin >> n;
//////        int b[n];
//////        for (int i = 0; i < n; i++) {
//////            cin >> a[i];
//////            b[i] = a[i];
//////        }
//////        sort(b, b + n);
//////        for (int i = 0; i < n - 1; i++) {
//////            int x = a[i] + a[i + 1];
//////            if (x % 2 == 1) {
//////                swap(a[i], a[i + 1]);
//////            }
//////        }
//////        for (int i = 0; i < n; i++) {
//////            if (a[i] == b[i])
//////                cnt++;
//////        }
//////        if (cnt == n) {
//////            cout << "Yes" << endl;
//////        }
//////        else cout << "No" << endl;
//////
//////    }
//////    return 0;
////////}
//////#include <iostream>
//////#include <algorithm>
//////using namespace std;
//////const int N = 2e5 + 10;
//////int arr[N];
//////int main()
//////{
//////    int t;
//////    cin >> t;
//////    while (t--)
//////    {
//////        int n;
//////        cin >> n;
//////        for (int i = 0; i < n; i++)
//////        {
//////            cin >> arr[i];
//////        }
//////        sort(arr, arr + n, [](int a, int b) {
//////            if ((a + b) % 2 == 1 && a < b) return true;
//////            return false;
//////            });
//////        //判断是否已经排好序
//////        bool flag = true;
//////        for (int i = 1; i < n; i++)
//////        {
//////            if (arr[i] < arr[i - 1])
//////            {
//////                flag = false;
//////                break;
//////            }
//////        }
//////        if (flag)
//////        {
//////            cout << "Yes" << endl;
//////        }
//////        else
//////        {
//////            cout << "No" << endl;
//////        }
//////    }
//////    return 0;
//////}
////
////#include <iostream>
////#include <algorithm>
////using namespace std;
////const int N = 2e5 + 10;
////int arr[N];
////void popsort()
////{
////    
////}
////int main()
////{
////    int t;
////    cin >> t;
////    while (t--)
////    {
////        int n;
////        cin >> n;
////        for (int i = 0; i < n; i++)
////        {
////            cin >> arr[i];
////        }
////        for (int i = 0; i < n-1; i++)
////        {
////            for (int j = 0; j < n -1- i; j++)
////            {
////                if (arr[j] > arr[j + 1] && (arr[j] + arr[j + 1]) % 2 == 1)
////                {
////                    swap(arr[j], arr[j + 1]);
////                }
////            }
////        }
////        // sort(arr, arr + n,[](int a, int b) {
////        //     if((a+b)%2==1&&a<b) return true;
////        //     return false;
////        // });
////        //判断是否已经排好序
////        bool flag = true;
////        for (int i = 1; i < n; i++)
////        {
////            if (arr[i] < arr[i - 1])
////            {
////                flag = false;
////                break;
////            }
////        }
////        if (flag)
////        {
////            cout << "Yes" << endl;
////        }
////        else
////        {
////            cout << "No" << endl;
////        }
////    }
////    return 0;
////}
//
//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 2e5 + 10;
//int arr[N];
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//        int ji = -1;
//        int  ou = 0;
//        for (int i = 0; i < n; i++)
//            cin >> arr[i];
//        for (int i = 0; i < n; i++)
//        {
//            if (arr[i] % 2)
//            {
//                if (arr[i] < ji)
//                {
//                    cout << "No" << endl;
//                    break;
//                }
//                else
//                    ji = arr[i];
//            }
//            else
//            {
//                if (arr[i] < ou)
//                {
//                    cout << "No" << endl;
//                    break;
//                }
//                else
//                    ou = arr[i];
//            }
//        }
//        cout << "Yes" << endl;
//    }
//    return 0;
//}
////const int N = 2e5 + 10;
////int a[N];
////bool compare(int a, int b)
////{
////    if ((a + b) % 2 == 1)
////        return a < b;
////    else return a > b;
////}
////int main()
////{
////    int t;
////    cin >> t;
////    while (t--)
////    {
////        int n;
////        cin >> n;
////        for (int i = 0; i < n; i++)
////            cin >> a[i];
////        sort(a, a + n, compare);
////        //判断是否排序成功
////        for (int i = 0; i < n; i++)
////        {
////            if (a[i] != i + 1)
////            {
////                cout << "No" << endl;
////                return 0;
////            }
////        }
////        cout << "Yes" << endl;
////    }
////    
////    return 0;
////}
////int main()
////{
////    int t;
////    cin >> t;
////    while (t--)
////    {
////        int n;
////        cin >> n;
////        for (int i = 0; i < n; i++)
////        {
////            cin >> arr[i];
////        }
////        myquicksort(0, n - 1);
////        // sort(arr, arr + n,[](int a, int b) {
////        //     if((a+b)%2==1&&a<b) return true;
////        //     return false;
////        // });
////        bool flag = true;
////        for (int i = 1; i < n; i++)
////        {
////            if (arr[i] < arr[i - 1])
////            {
////                flag = false;
////                break;
////            }
////        }
////        if (flag)
////        {
////            cout << "Yes" << endl;
////        }
////        else
////        {
////            cout << "No" << endl;
////        }
////    }
////    return 0;
////}