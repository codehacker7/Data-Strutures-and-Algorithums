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

        if(head == NULL || head->next == NULL){
            return head;
        }

        int length =0;
        ListNode* check = head;

        while(check != NULL){
            check = check->next;
            length++;
        }

        if(length < k){
            return head;
        }
       

        ListNode * prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        int count =0;

       while(curr != NULL && count != k){
             next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
             count++;
        }
        
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};