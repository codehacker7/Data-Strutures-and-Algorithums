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

void bubbleSort(int * arr){

    int length = 5;

    for(int i=0;i<length-1;i++){
        for(int j=0;j<length -1 - i;j++){

            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]); 
                }

        }
    }


}

void bubbleSortLL(Node *head){
    Node* temp = head;
    int length =0;
    while(temp != NULL){
        temp = temp->next;
        ct++;
    }

    for(int i=0;i<length-1;i++){
        for(Node* j =head;j->next != NULL;j = j->next){
            if(j->val > j->next->val){
                  swap(j->val,j->next->val); 
            }
        }

    }

}

int main(){

    int arr[] = {5,1,4,3,2};
    bubbleSort(arr);
      for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i];
    }

}