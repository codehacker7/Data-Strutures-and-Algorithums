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
        LinkedList right = BSTtoLL(root->left);
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