#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(int n) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}
ListNode* middleLL(ListNode* head){
        ListNode* slow = head, *fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;

        while(current != NULL){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* middle = middleLL(head);
        ListNode* secondHalf = reverseLL(middle->next);
        middle->next = NULL;

        ListNode* p1 = head;
        ListNode* p2 = secondHalf;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }

	int main() {
    int n;
    cin >> n;

    ListNode* head = createLinkedList(n);

    // Call the isPalindrome function here and print the result
    bool result = isPalindrome(head);
    cout << (result ? "true" : "false") << endl;

    return 0;
}