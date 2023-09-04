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

int height(TreeNode* root){
        if(root == NULL){
            return -1;
        }
        int lH = height(root->left);
        int rH = height(root->right);

        return max(lH,rH)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        
        int ans = lh + rh + 2;
        int ans1 = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));

        return max(ans,ans1);
    }