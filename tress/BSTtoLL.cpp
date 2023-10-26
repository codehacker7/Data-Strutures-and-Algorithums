#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* left, *right; 
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

class LinkedList{
    public:
    node* head;
    node* tail;
}

LinkedList BSTtoLL(node* root) {

    LinkedList l;

    if(root == NULL){
        l.head = NULL;
        l.right = NULL;
        return l;
    }

    if(root->left != NULL && root->right != NULL){ // this means we have both left and right subtree
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);
        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
        return l;

    } else if(root->left != NULL && root->right == NULL){
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    } else if(root->left == NULL && root->right != NULL){
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    } else{
        l.head = l.tail = root;
        return l;
    }
}

void printRange(node* root, int k1, int k2) {
	if (root == NULL) return;

	printRange(root->left, k1, k2);
	if (root->data >= k1 and root->data <= k2) cout << root->data << " ";
	printRange(root->right, k1, k2);
}

class Pair{
    public:
    int height;
    bool isbalanced;
    Pair(){
        height = 0;
        isbalanced = true;
    }
}

Pair checkbalanced(node* root){

    Pair p;
    if(root == NULL){
        return p;
    }

    Pair left = checkbalanced(root->left);
    Pair right = checkbalanced(root->right);

    p.height = left.height + right.height + 1;
    p.isbalanced = left.isbalanced && right.isbalanced && (abs(left.height - right.height)<=1)

    return p;
}

bool isbalanced(node* root){

    if(root == NULL){
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh - rh)<=1) && isbalanced(root->left) && isbalanced(root->left);;
}

node* arrayBalancedBST(int *a, int s, int e) {

    if(s > e){
    	return NULL;
    }

    int m = (s + e) / 2;
	node* root = new node(a[m]);
    root->left = arrayBalancedBST(a,s,m-1);
    root->right = arrayBalancedBST(a,m+1,e);

    return root;

}