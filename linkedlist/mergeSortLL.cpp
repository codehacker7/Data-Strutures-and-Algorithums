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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode* newHead;

        if (l1->val < l2->val) {
            newHead = l1;
            newHead->next = mergeTwoLists(l1->next, l2);
        } else {
            newHead = l2;
            newHead->next = mergeTwoLists(l1, l2->next);
        }

        return newHead;
    }

    ListNode* findMiddle(ListNode* head) {
        // if (!head || !head->next) {
        //     return head;
        // }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};