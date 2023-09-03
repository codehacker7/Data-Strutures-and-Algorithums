#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node * left;
	Node * right;
	Node(int d, Node * l = NULL, Node * r = NULL){
		data = d;
		left = l;
		right = r;
	}
};
class Pair{
    public:
    int diameter;
    int height;
}

Pair diameter2(Node *root){


    Pair p;
    if(root == NULL){
        p.height = -1;
        p.diameter = 0;
        return p;
    }

    Pair pL = diameter2(root->left);
    Pair pR = diameter2(root->right);


    p.height = 1 + max(pL.height,pR.height);
    p.diameter = max((pL.height + pR.height + 2, max(pL.diameter,pR.diameter)));

    return p;
}