 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* odd = oddHead;
        ListNode* even = evenHead;

        while(odd != NULL && even != NULL){

            
             if(even != NULL && odd != NULL){
                odd->next = even->next;
                odd = odd->next;
             }


            if(even != NULL && odd != NULL){
                
                even->next = odd->next;
                 even = even->next;
            }

        }
       

        ListNode* temp = oddHead;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = evenHead;

        return oddHead;
        
    }
};