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
private:
    int getSize(ListNode *head){
        int ans = 0;
        ListNode *temp = head;
        while(temp!= NULL){
            temp = temp ->next;
            ans++;
        }
        return ans;
    }
public:
    int pairSum(ListNode* head) {
         
        
        int ans = 0;
        
        ListNode *rev = head;
         
        int length = getSize(head);
        
        if(length == 2){
            return head->val + head->next->val;
        }
        
        for(int i = 0;i<length/2-1;i++){
            rev = rev->next;
        }
        
        ListNode *curr = rev->next;
        ListNode * prev = NULL;
        
        while(curr->next != NULL){
            ListNode *next = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = next;
            
        }
        
        curr->next = prev;
        rev->next = curr;
        
        rev = rev->next;
        
        
        while(rev != NULL){
            int temp = head->val + rev->val;
            ans = max(ans,temp);
            
            rev = rev->next;
            head = head->next;
        }
        
        
         
         return ans;
    }
};