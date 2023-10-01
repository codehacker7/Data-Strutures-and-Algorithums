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
        int n =0;
        while(temp != NULL){
            n++;
            temp = temp->next;
            
        }

        for(int i=0;i<n;i++){
            // ListNode* p = NULL;
            ListNode* curr = head;
            ListNode* n;
            ListNode* p = NULL;

            while(curr && curr->next){
                n = curr->next;
                if(curr->val > n->val){
                    if(p == NULL){
                        curr->next = n->next;
                        n->next = curr; 
                        p = n;
                        head = n;
                    } else{
                       
                        curr->next = n->next;
                        n->next = curr;
                        p->next = n;
                        p = n;
                    }
                    
                }else{
                    //1->2->3->4
                    p = curr;
                    curr = curr->next;

                }
            } 
        }

        return head;



    }
};