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
    int currsum =0;
    void  fillPathSum(TreeNode* root, int targetSum,  vector<vector<int>>& ans,vector<int> temp){

        if(root == NULL){
            return;
        }
        temp.push_back(root->val);
        currsum = currsum + root->val;

       if (root->left == nullptr && root->right == nullptr && targetSum == currsum) {
            ans.push_back(temp);
        }

         fillPathSum(root->left, targetSum, ans, temp);
         fillPathSum(root->right,targetSum , ans, temp);
         temp.pop_back();
         currsum -= root->val;


    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

      vector<vector<int>> ans;

      vector<int> temp;

      fillPathSum(root,targetSum,ans,temp);

      return ans;

        
    }
};