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
        vector<int> v;
        ListNode * temp = head;
        
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        vector<int> taken(v.size(), - 1);
        
        while(true){
            
            bool found = false;
            for(int i = 0;i<v.size();i++){
                if(v[i]<x and taken[i] == -1){
                    temp->val = v[i];
                    temp = temp->next;
                    taken[i] = 1;
                    found = true;
                    break;
                }
            }
            if(!found) break;
           
        }
        
        for(int i = 0;i<v.size();i++){
            if(taken[i] == -1){
                temp->val = v[i];
                temp = temp->next;
            }
        }
        
        return head;
    }
};