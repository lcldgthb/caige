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
/*
class Solution {
    typedef struct ListNode listnode;
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
        return NULL;
        if(head->next==NULL)
        return head;
        listnode*phead=(listnode*)malloc(sizeof(listnode));
        phead->next=head;
        listnode*pre=phead;
        listnode*cur1=head;
        listnode*cur2=head->next;
        listnode*ret=head->next;
        while(cur1&&cur2)
        {
            
                pre->next=cur2;
                cur1->next=cur2->next;
                cur2->next=cur1;
            
            cur1=cur1->next;
            if(cur1!=NULL)
            cur2=cur1->next;
            pre=pre->next->next;
        }
        return ret;
    }
};
*/