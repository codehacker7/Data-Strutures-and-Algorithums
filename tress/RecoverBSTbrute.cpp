class Solution {
public:
    vector<int> inorder;
    int index = 0;

    void calculateInorder(TreeNode* root){
        if(root == nullptr){
            return;
        }

        calculateInorder(root->left);
        inorder.push_back(root->val);
        calculateInorder(root->right);
    }

    void finalRecover(TreeNode*& root){
        if(root == nullptr){
            return;
        }
        finalRecover(root->left);
        root->val = inorder[index++];
        finalRecover(root->right);
    }

    void recoverTree(TreeNode* root) {
        calculateInorder(root);
        sort(inorder.begin(), inorder.end());
        index = 0;
        finalRecover(root);
    }
};