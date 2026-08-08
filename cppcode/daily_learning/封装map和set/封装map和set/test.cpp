#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

//#include"RBTree.h"
//#include"AVLTree.h"

//void TestRBTree1()
//{
//	RBTree<int, int> t;
//	// 常规的测试用例
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	// 特殊的带有双旋场景的测试用例
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//	for (auto e : a)
//	{
//		t.Insert({ e, e });
//	}
//
//	t.InOrder();
//	cout << t.IsBalance() << endl;
//}
//
//void TestTree2()
//{
//	const int N = 10000000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand() + i);
//	}
//
//	size_t begin2 = clock();
//	AVLTree<int, int> t;
//	for (auto e : v)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	size_t end2 = clock();
//
//	size_t begin22 = clock();
//	RBTree<int, int> rbt;
//	for (auto e : v)
//	{
//		rbt.Insert(make_pair(e, e));
//	}
//	size_t end22 = clock();
//
//	cout << "AVL Insert:" << end2 - begin2 << endl;
//	cout << "RB Insert:" << end22 - begin22 << endl;
//
//	cout <<"AVL IsBalance:"<< t.IsBalanceTree() << endl;
//	cout << "RB IsBalance:" << rbt.IsBalance() << endl;
//
//
//	cout << "AVL Height:" << t.Height() << endl;
//	cout << "AVL Size:" << t.Size() << endl;
//
//	cout << "RB Height:" << rbt.Height() << endl;
//	cout << "RB Size:" << rbt.Size() << endl;
//
//	size_t begin1 = clock();
//	// 确定在的值
//	for (auto e : v)
//	{
//		t.Find(e);
//	}
//	// 随机值
//	/*for (size_t i = 0; i < N; i++)
//	{
//		t.Find((rand() + i));
//	}*/
//	size_t end1 = clock();
//	cout << "AVL Find:" << end1 - begin1 << endl;
//
//	size_t begin11 = clock();
//	// 确定在的值
//	for (auto e : v)
//	{
//		rbt.Find(e);
//	}
//	// 随机值
//	/*for (size_t i = 0; i < N; i++)
//	{
//		t.Find((rand() + i));
//	}*/
//	size_t end11 = clock();
//	cout << "RB Find:" << end11 - begin11 << endl;
//}
//
//int main()
//{
//	TestTree2();
//
//	return 0;
//}

#include"myset.h"
#include"mymap.h"


void Print(const caige::set<int>& s)
{
	caige::set<int>::const_iterator it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	caige::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	caige::set<int>::iterator sit = s.begin();
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	Print(s);


	caige::map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });

	//dict["left"] = "左边，剩余";
	//dict["insert"] = "插入";
	//dict["string"];

	caige::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 不能修改first，可以修改second
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}
