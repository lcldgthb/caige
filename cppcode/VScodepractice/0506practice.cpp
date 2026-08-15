#include<iostream>
using namespace std;
int main()
{
    //栈和队列
    //栈：后进先出（LIFO）
    //队列：先进先出（FIFO）
    //栈和队列的实现：数组、链表、双端队列等
    //栈的实现
    //用数组实现栈：使用一个数组来存储栈中的元素，使用一个变量来记录栈顶元素的位置；用链表实现栈：使用一个链表来存储栈中的元素，使用一个指针来记录栈顶元素的位置；用双端队列实现栈：使用一个双端队列来存储栈中的元素，使用一个指针来记录栈顶元素的位置；
    
    //队列的实现
    //栈和队列的操作：入栈、出栈、获取栈顶元素、判断栈是否为空等；入队、出队、获取队头元素、获取队尾元素、判断队列是否为空等
    //栈和队列的时间复杂度：栈的push和pop操作的时间复杂度为O(1)，队列的push和pop操作的时间复杂度为O(1)
    //栈和队列的区别：栈只能在一端进行插入和删除操作，而队列可以在两端进行插入和删除操作
    //栈的基本操作：push、pop、top、empty
    //队列的基本操作：push、pop、front、back、empty
    //栈的应用：函数调用、括号匹配、表达式求值等
    //队列的应用：任务调度、广度优先搜索等


    return 0;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    typedef struct ListNode listnode;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        return NULL;
        listnode*fast=head;
        listnode*slow=head;
        while(n--)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        return head->next;
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
       slow->next=slow->next->next;
       return head;
    }
};