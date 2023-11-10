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
    int countGoodNodes(TreeNode* root, int maxi) {

       if (root == nullptr) {
            return 0;
        }

        int goodCount = 0;

        if (root->val >= maxi) {
            goodCount++;
            maxi = root->val;
        }

        goodCount += countGoodNodes(root->left, maxi);
        goodCount += countGoodNodes(root->right, maxi);

        return goodCount;
    }

    int goodNodes(TreeNode* root) {

        return countGoodNodes(root, root->val);
        
    }
};