//#define _CRT_SECURE_NO_WARNINGS
//#include"list.h"
//using namespace std;
//namespace caige
//{
//	void test01()
//	{
//		list<int> l1;
//		l1.push_back(1);
//		l1.push_back(2);
//		l1.push_back(3);
//		l1.push_back(4);
//		l1.push_back(5);
//		for (auto& it : l1)
//			cout << it << " ";
//		l1.push_front(0);
//		l1.push_front(-1);
//		l1.push_front(-2);
//		cout << endl;
//		for (auto& it : l1)
//			cout << it << " ";
//		l1.pop_back();
//		l1.pop_front();
//		cout << endl;
//		for (auto& it : l1)
//			cout << it << " ";
//
//
//	}
//}
//int main()
//{
//	caige::test01();
//	return 0;
//}
#include <iostream>
#include"list.h"
using namespace std;

struct AA
{
    int _a1 = 1;
    int _a2 = 2;
};

//--------------------------------------------------
// test1：push_back、push_front、遍历
//--------------------------------------------------
void test_list1()
{
    cout << "========== test_list1 ==========" << endl;

    caige::list<int> lt;

    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);

    for (auto e : lt)
        cout << e << " ";
    cout << endl;

    lt.push_front(0);

    for (auto e : lt)
        cout << e << " ";
    cout << endl << endl;
}

//--------------------------------------------------
// test2：insert、erase
//--------------------------------------------------
void test_list2()
{
    cout << "========== test_list2 ==========" << endl;

    caige::list<int> lt = { 1,2,3,4 };

    auto it = lt.begin();
    ++it;

    lt.insert(it, 100);

    for (auto e : lt)
        cout << e << " ";
    cout << endl;

    it = lt.begin();
    ++it;

    lt.erase(it);

    for (auto e : lt)
        cout << e << " ";
    cout << endl << endl;
}

//--------------------------------------------------
// test3：连续erase（经典）
//--------------------------------------------------
void test_list3()
{
    cout << "========== test_list3 ==========" << endl;

    caige::list<int> lt = { 1,2,3,4,5,6,7,8 };

    auto it = lt.begin();

    while (it != lt.end())
    {
        if (*it % 2 == 0)
        {
            it = lt.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (auto e : lt)
        cout << e << " ";
    cout << endl << endl;
}

//--------------------------------------------------
// test4：拷贝构造
//--------------------------------------------------
void test_list4()
{
    cout << "========== test_list4 ==========" << endl;

    caige::list<int> lt1 = { 1,2,3,4 };

    caige::list<int> lt2(lt1);

    lt2.push_back(100);

    cout << "lt1:" << endl;
    for (auto e : lt1)
        cout << e << " ";
    cout << endl;

    cout << "lt2:" << endl;
    for (auto e : lt2)
        cout << e << " ";
    cout << endl << endl;
}

//--------------------------------------------------
// test5：operator=
//--------------------------------------------------
void test_list5()
{
    cout << "========== test_list5 ==========" << endl;

    caige::list<int> lt1 = { 1,2,3 };

    caige::list<int> lt2 = { 10,20,30 };

    lt1 = lt2;

    lt2.push_back(100);

    cout << "lt1:" << endl;
    for (auto e : lt1)
        cout << e << " ";
    cout << endl;

    cout << "lt2:" << endl;
    for (auto e : lt2)
        cout << e << " ";
    cout << endl << endl;
}

//--------------------------------------------------
// test6：clear
//--------------------------------------------------
void test_list6()
{
    cout << "========== test_list6 ==========" << endl;

    caige::list<int> lt = { 1,2,3,4,5 };

    lt.clear();

    cout << "size = " << lt.size() << endl;
    cout << "empty = " << lt.empty() << endl;

    lt.push_back(100);

    for (auto e : lt)
        cout << e << " ";
    cout << endl << endl;
}

//--------------------------------------------------
// test7：initializer_list
//--------------------------------------------------
void test_list7()
{
    cout << "========== test_list7 ==========" << endl;

    caige::list<int> lt =
    {
        1,2,3,4,5
    };

    for (auto e : lt)
        cout << e << " ";

    cout << endl << endl;
}

//--------------------------------------------------
// test8：const_iterator
//--------------------------------------------------
void print(const caige::list<int>& lt)
{
    for (auto e : lt)
        cout << e << " ";

    cout << endl;
}

void test_list8()
{
    cout << "========== test_list8 ==========" << endl;

    caige::list<int> lt = { 1,2,3,4 };

    print(lt);

    cout << endl;
}

//--------------------------------------------------
// test9：operator->
//--------------------------------------------------
void test_list9()
{
    cout << "========== test_list9 ==========" << endl;

    caige::list<AA> lt;

    lt.push_back(AA());
    lt.push_back(AA());

    auto it = lt.begin();

    while (it != lt.end())
    {
        cout << it->_a1 << " " << it->_a2 << endl;
        ++it;
    }

    cout << endl;
}

//--------------------------------------------------
// test10：压力测试
//--------------------------------------------------
void test_list10()
{
    cout << "========== test_list10 ==========" << endl;

    caige::list<int> lt;

    for (int i = 0; i < 10000; i++)
        lt.push_back(i);

    for (int i = 0; i < 5000; i++)
        lt.pop_front();

    for (int i = 0; i < 5000; i++)
        lt.pop_back();

    cout << "size = " << lt.size() << endl;
    cout << "empty = " << lt.empty() << endl;

    cout << endl;
}

//--------------------------------------------------
// 总测试入口
//--------------------------------------------------
void test_list()
{
    test_list1();
    test_list2();
    test_list3();
    test_list4();
    test_list5();
    test_list6();
    test_list7();
    test_list8();
    test_list9();
    test_list10();
}