#include<iostream>
using namespace std;

class Node{
	public:
	int val;
	Node* next;
		Node(int val,Node* next = NULL){
			this->val = val;
			this->next = next;
		}

};


Node *intersectionOfTwoLinkedLists(Node *headA, Node *headB)
{

    if(headA == NULL || headB == NULL) return NULL;

    Node* a = headA;
    Node* b = headB;

    while(a != b){

        a = a == NULL? headB:a->next;
        b = b == NULL? headA:b->next;
    }

    return a;
    /*Code here*/
}