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
    ListNode* merge(ListNode* List1, ListNode* List2)
    {
        ListNode dummy(0);
        
        ListNode* curr = &dummy;
        
        while(List1 != NULL && List2 != NULL)
        {
            if(List1->val < List2->val)
            {
                curr->next = List1;
                List1 = List1->next;
            }
            else
            {
                curr->next = List2;
                List2 = List2->next;
            }
            
            curr = curr->next;
        }
        
        if(List1 != NULL)
            curr->next = List1;
        else
            curr->next = List2;
        
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
        
    }
};