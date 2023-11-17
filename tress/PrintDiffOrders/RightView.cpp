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

    void printRightView(TreeNode* root, vector<int>& ans){
        queue<pair<TreeNode*, int>> q; // Specify the types for the pair

        map<int, int> nodes; // Let us say this is a map of level, values

        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* front = p.first;
            int level = p.second;

            if(front != NULL){
            nodes[level] = front->val;

            if (front->left != NULL) {
                q.push({front->left, level + 1});
            }
            if (front->right != NULL) {
                q.push({front->right, level + 1});
            }
        }
    }

        for (auto i : nodes) {
            ans.push_back(i.second);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        printRightView(root, ans);
        return ans;
    }
};
