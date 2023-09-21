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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;

        }

        for(int i=0;i<n-1;i++){
            ListNode* p = NULL;
            ListNode* curr = head;
            ListNode* n;

            while(curr != NULL && curr->next != NULL){
                n = curr->next;
                if(curr->val > n->val){
                    
                     if(p == NULL){
                       curr->next = n->next;
                       n->next = curr;
                       head = n;
                       p =n;
                   }else{
                        p->next = n;
                        curr->next = n->next;
                        n->next = curr;
                        p = n;
                   } 
                }else{
                    p =curr;
                    curr=n;
                }
            }

        }

        return head;
        
    }
};