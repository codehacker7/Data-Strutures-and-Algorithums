#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next = NULL;
    // constructor
    Node(int v = 0, Node* n = NULL) {
        val = v;
        next = n;
    }
};

int main() {
    int number;
    cin >> number;

    int val;
    cin >> val;

    Node* head = new Node(val);
    Node* temp = head;

    for (int i = 1; i < number; i++) {
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }

    temp = head;
    Node* even = NULL;
    Node* evenptr = NULL;
    Node* odd = NULL;
    Node* oddptr = NULL;

    while (temp != NULL) {

        if ((temp->val) % 2 == 0) {

            if (even == NULL) {
                even = temp;
                evenptr = even;
            } else {
                even->next = temp;
                even = even->next;
            }
        } else {

            if (odd == NULL) {
                odd = temp;
                oddptr = odd;
            } else {
                odd->next = temp;
                odd = odd->next;
            }

        }
        temp = temp->next;
    }

    if (oddptr != NULL) {
        odd->next = evenptr;
    } else {
        head = evenptr; // If there are no odd numbers, the head should point to the even numbers.
    }
    if (even != NULL) {
        even->next = NULL; // dont forgot this part
    }

	temp = head;

	while(temp != NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
   
    return 0;
}

