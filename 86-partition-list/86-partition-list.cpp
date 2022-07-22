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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(10), *l2 = new ListNode(10), *t1 = l1, *t2 = l2;
        
        while(head)
        {
            if(head->val < x)
            {
                t1->next = head;
                t1 = t1->next;
            }
            else
            {
                t2->next = head;
                t2 = t2->next;
            }
            head = head->next;
        }
        
        t1->next = t2->next = nullptr;
        l1 = l1->next;
        l2 = l2->next;
        
        if(!l1) 
            return l2;
        if(!l2) 
            return l1;
        
        t1->next = l2;
        
        return l1;
    }
};