/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {


        if(root == NULL){
            return NULL;
        }

       
       
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);

         if (root->val == target && root->left == nullptr && root->right == nullptr) {
            // Node is a leaf with the target value, so we remove it
            return nullptr;
        }

        
        
        return root;
    }
};