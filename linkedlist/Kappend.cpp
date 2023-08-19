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



int main() {

	int numberOfElements;
	cin>>numberOfElements;


	int element;
	cin>>element;
	Node* head = new Node(element);

	Node* temp = head;

	for(int i=1;i<numberOfElements;i++){
		cin>>element;
		temp->next = new Node(element);
		temp = temp->next;
	}

	int k;
	cin>>k;
	if (k >= numberOfElements) {
        k = k % numberOfElements;
    }


	Node *ahead = head;

	k--;

	while(k){
		ahead = ahead->next;
		k--;
	}

	temp = head;

	while(ahead->next != NULL && ahead->next->next != NULL){
		ahead = ahead->next;
		temp = temp->next;
	}
	
   Node* newhead = temp->next;
	temp->next = NULL;
	ahead->next->next = head;
	head = newhead;
		
	

	temp = head;
	while(temp!= NULL){
		cout<<temp->val<<" ";
		 Node* toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}


	

	return 0;
}