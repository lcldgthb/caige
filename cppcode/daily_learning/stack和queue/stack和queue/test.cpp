#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Stack.h"
#include"Queue.h"
#include"priority_queue.h"

namespace caige
{
	
	void test01()
	{
		priority_queue<int> pq1;
		pq1.push(1);
		pq1.push(4);
		pq1.push(2);
		pq1.push(3);
		while (!pq1.empty())
		{
			cout << pq1.top() << " ";
			pq1.pop();
		}
		cout << endl;
		
	}
	void teststack()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		cout << st.top();
		st.pop();
		cout << st.top();
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;

	}
	void testqueue()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);
		cout << q.front() << " " << q.back();
		q.pop();
		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
	}
}
int main()
{
	//caige::test01();
	//caige::teststack();
	caige::testqueue();
	return 0;
}