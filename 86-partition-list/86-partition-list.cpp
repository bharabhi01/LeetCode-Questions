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
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* first = NULL;
        ListNode* second = head;
        while(second && second->val < x){
            first = second;
            second = second->next;
        }
        ListNode* temp = second;
        while(temp && temp->next){
            if(temp->next->val < x){
                if(first){
                    first->next = temp->next;
                    first = first->next;
                }
                else{
                    first = temp->next;
                    head = first;
                }
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        if(first) first->next = second;
        return head;
    }
};