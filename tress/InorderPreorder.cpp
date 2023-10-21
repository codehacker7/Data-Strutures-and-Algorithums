#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

int pre[] = {8, 10, 1, 6, 3, 14 };
int k = 0;

node* TreeCreate(int *in, int s, int e) {

    if(s > e){
        return NULL;
    }
    node* root = new node(pre[k++]);
    int idx = -1;
    for(int i=s;i<=e;i++){
        if(in[i] == root->data){
            idx = i;
            break;
        }
    }
    root->left = TreeCreate(in,s,idx-1);
    root->right = TreeCreate(in,idx+1,e);

    return root;
}

void mirror(node* root) {
	if (!root) {
		return;
	}

	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}