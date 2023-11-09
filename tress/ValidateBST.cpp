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
    bool valid(TreeNode* root,double leftvalue,double rightvalue){

        if(root == NULL){
            return true;
        }
        if(!(root->val > leftvalue && root->val < rightvalue)){
                return false;
        }

        return valid(root->left,leftvalue,root->val) && valid(root->right,root->val,rightvalue);

    }
    bool isValidBST(TreeNode* root) {

        
        double negative_infinity = -std::numeric_limits<double>::infinity();
        double positive_infinity = std::numeric_limits<double>::infinity();


        return valid(root,negative_infinity,positive_infinity);
        
    }
};