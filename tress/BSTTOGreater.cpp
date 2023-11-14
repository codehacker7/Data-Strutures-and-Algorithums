class Solution {
public:
    int currSum =0;

    void dfs(TreeNode*& root){
        if(root == NULL){
            return ;
        }

        dfs(root->right);
        root->val += currSum;
        currSum = root->val;
        dfs(root->left);

    }

    TreeNode* bstToGst(TreeNode* root) {

        if(root == NULL){
            return root;
        }

        dfs(root);

        return root;
        
    }   
};