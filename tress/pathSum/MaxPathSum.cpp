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
    int maxSum;
    int helper(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);
        int root_included = left + right + root->val;

        int left_right_comparison = max(left,right) + root->val;

        int just_root = root->val;

        maxSum = max({maxSum,root_included,left_right_comparison,just_root});

        return max(left_right_comparison,just_root);


    }

    int maxPathSum(TreeNode* root) {

         maxSum = INT_MIN;

         helper(root);

         return maxSum;
        
    }
};