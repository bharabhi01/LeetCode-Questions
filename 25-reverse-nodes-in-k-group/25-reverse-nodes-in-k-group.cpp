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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy, *pre = dummy, *nex = dummy;
        int listLength = 0;
        
        // Length of the linked list.
        while(curr->next != NULL)
        {
            curr = curr->next;
            listLength++;
        }
        
        while(listLength >= k)
        {
            // Place curr and nex to start and 2nd element respectively.
            curr = pre->next;
            nex = curr->next;
            
            // Crux of the function to reverse the list.
            for(int i = 1; i < k; i++)
            {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            pre = curr;
            listLength -= k;
        }
        
        return dummy->next;
    }
};