#include<iostream>
using namespace std;

class Node{
public:
	//val
	int val;

	//pointer
	// next pointer points to another node / forward node in the list
	Node * next=NULL;

	//constructor
	Node(int v, Node * ptr = NULL){
		val = v;
		next = ptr;
	}
};
Node* middleNode(Node* head) {

    Node *slow = head, *fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
	// while (head && head->next) {
	//     slow = slow->next;
	//     head = head->next->next;
	// }
	return slow;
    }

int lengthOfLL(Node * head){
	if(head == NULL) return 0;
	int ct = 0;
	while(head!=NULL){
		head = head->next;
		ct++;
	}
	return ct;
}

void sortList(Node* head) {


        int n = LL(head);
        
    for(int i=0;i<n-1;i++){
        for(ListNode* j=head;j->next!=NULL;j=j->next){
            
            if(((*j).val) > (j->next->val)){
                swap((*j).val,j->next->val);
            }
        
        }
    }


 }

 Node* mergeSortLinkedList(Node* head){

	if(head == NULL || head->next == NULL) return head;

	Node* mid = middleNode(head);

	Node* temp = mid->next;
	mid->next = NULL;
	mid = temp;
	
	Node* l1 = mergeSortLinkedList(head);
	Node* l2 = mergeSortLinkedList(mid);

	return merge2sortedLinkedList(l1,l2);




 }

 Node* merge2sortedLinkedList(Node* head1,Node* head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;


	Node* newHead = NULL;

	if(head1->val < head2->val){
		newHead = head1;
	    newHead->next = merge2sortedLinkedList(head1->next,head2);
	}
	else{
		newHead = head2;
		newHead->next = merge2sortedLinkedList(head1,head2->next);

	}

	return newHead;

}


bool isCyclic(Node* l1, Node* l2){

	Node* slow = head, *fast = head;

	while(fast!= NULL && fast->next != NULL){
		
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			return true;
		}

	}

	return false;




}


void breakCycle(Node* & head){

Node* slow = head, *fast = head;

	while(fast!= NULL && fast->next != NULL){
		
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}

	}
	slow = head;

	while(slow->next != fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	cout<<"Cycle starts at "<<slow->next->val <<endl;
	fast->next = NULL; /*THIS WILL BREAK THE CYCLE IN HERE*/

}

 Node* reverseLLRec(Node*  curr, Node*  prev){

        if(curr == NULL){
            return prev;
        }

        Node* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
        return helper(curr,prev);

         

}


 
void removeNthFromEnd(Node* head, int n) {
      
        ListNode* a = head;
        ListNode* b = head;

        n--;
        while(n){
            b = b->next;
            n--;
        }
       
        // cout<<b->val<<endl;

        while(b->next!=NULL){ // take care of b->next here !-= NULL
         
            a = a->next;
            b = b->next;
        }

		cout<< a->val << endl;

        
    

    }

void deleteAtTail(Node* &head, Node* &tail){

    if(head == NULL) return;

    if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{

        int l = lengthOfLL(head);
        int ct =1;
        Node *curr = head;
        while(ct<l-1){
            curr = curr->next;
            ct++;
            // 2 1          6       4           5
            //   curr       curr    curr        curr
            //    2           3     4           
        }
        curr->next = NULL;
        delete tail;
        tail = curr;
        return;
         
    }




}

void insertAtHead(Node* &head, Node * &tail, int val){
	if(head == NULL){
	// if(head == NULL and tail == NULL)
		// Node n1(val); // won't work because as soon as function call gets over it will get destroyed so we have to create node 
		//dynamically
		Node * n1 = new Node(val);
		head = n1;
		tail = n1;
	}
	else{
		Node * n1 = new Node(val);
		n1->next = head; // creating link , inserting at head
		head = n1; //changing head pointer
	}
}

void insertAtTail(Node* &head, Node * &tail, int val){
	if(head == NULL){
	// if(head == NULL and tail == NULL)
		// Node n1(val); // won't work because as soon as function call gets over it will get destroyed so we have to create node 
		//dynamically
		Node * n1 = new Node(val);
		head = n1;
		tail = n1;
	}
	else{
		Node * n1 = new Node(val);
		tail->next = n1;
		tail = n1;
	}
}

void insertAtAnyPos(Node* &head, Node * &tail, int val, int pos){
	if(pos == 0){
		insertAtHead(head, tail, val);
		return;
	}
	else if(pos>=lengthOfLL(head)){
		insertAtTail(head, tail, val);
		return;
	}
	else{
		Node * n1 = new Node(val); // node created
		//now travel to the postn
		Node * cur = head;
		int mvCtr = pos-1;
		while(mvCtr>0){
			cur = cur->next;
			mvCtr--;
		}
		n1->next = cur->next;
		cur->next = n1;
		return;
	}
}

void deleteAtHead(Node * &head, Node * &tail){
	if(head == NULL) return;
	else if(head == tail){
		delete head; //node delete
		head = NULL;
		tail = NULL;
		return ;
	}
	else{
		Node * temp = head->next;
		head->next = NULL; // link destroy
		delete head; // node mem free
		head = temp; // updating new head
		return;
	}
}

void linearSearchLL(Node * head, int etf){
	if(head == NULL){
		cout<<"LL is empty"<<endl;
		return;
	}
	int i = 0;

	while(head != NULL){
		if(head->val == etf){
			cout<<"Element Found at Pos "<<i<<endl;
			return;
		}
		head = head->next;
		i++;
	}
	return;
}

void printLL(Node * head){
	if(head == NULL) return ; //LL is empty

	while(head!=NULL){
		cout<<head->val<<'\t';
		head = head->next;
	}
	cout<<endl;
}

void printLLRec(Node * head){
	if(head == NULL) {
		cout<<endl;
		return;
	}
	cout<<head->val<<'\t';
	printLLRec(head->next);
}

int main(){
	// Node n1(10);
	// Node n2(20);
	// //lets link these nodes
	// n1.next = &n2;
	// cout<<n1.val<<endl<<n2.val<<endl;
	// cout<<n1.next<<endl<<(&n2)<<endl;
	// //syntax 1 for referencing n2's value via n1 pointer
	// cout<<(*(n1.next)).val<<endl;

	// //syntax 2 is arrow operator
	// cout<<n1.next->val<<endl;

	Node * head = NULL; //it will keep track of head of the linked list
	Node * tail = NULL; // it will keep track of the tail of the linked list

	insertAtHead(head, tail, 1); //1
	insertAtHead(head, tail, 2); // 2->1
	insertAtHead(head, tail, 3); // 3->2->1
	
	printLL(head);

	insertAtTail(head, tail, 4); //3->2->1->4
	insertAtTail(head, tail, 5); //3->2->1->4->5

	printLLRec(head);

	// insertAtAnyPos(head, tail, val, pos) --> val to insert at pos 'pos' 
	insertAtAnyPos(head, tail, 6, 3); // 3->2->1->6->4->5 //0 based indexing
	printLL(head);

	deleteAtHead(head, tail);
	printLL(head);

	linearSearchLL(head, 4);

	return 0;
}