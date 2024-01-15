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
 class Pair{
    public:
     int amount_without_roberry;
     int amount_with_robbery;
 };
class Solution {
public:

    Pair helper(TreeNode* root) {
    if (root == nullptr) {
        Pair p;
        p.amount_without_roberry = 0;
        p.amount_with_robbery = 0;
        return p;  // Return the created Pair
    }

    Pair p;
    Pair left = helper(root->left);
    Pair right = helper(root->right);

    int leftmax = max(left.amount_without_roberry, left.amount_with_robbery);
    int rightmax = max(right.amount_without_roberry, right.amount_with_robbery);

    p.amount_with_robbery = root->val + left.amount_without_roberry + right.amount_without_roberry;
    p.amount_without_roberry = leftmax + rightmax;

    return p;
}


    int rob(TreeNode* root) {
        Pair p = helper(root);

        return max(p.amount_without_roberry,p.amount_with_robbery);
        
        
    }
};