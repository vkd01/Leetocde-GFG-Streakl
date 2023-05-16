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
    ListNode* swapPairs(ListNode* head) {
    
        if(head == NULL or head->next == NULL) return head;
        
        ListNode *next = head->next, *curr = head, *prev = NULL;
        
        ListNode*ans = head->next;
        
 while (curr!= NULL and next != NULL) {
            if (prev)
                prev->next = next;
            curr->next = next->next;
            next->next = curr;
            prev = curr;
            curr = curr->next;
            if (curr)
                next = curr->next;
        }
        
     
        
        
        
        return ans;
    }
};