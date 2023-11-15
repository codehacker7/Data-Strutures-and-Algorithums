class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int s, int e, int& k) {
        if (s > e || k < 0) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[k--]);

        int index = -1;

        for (int i = s; i <= e; i++) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        root->right = build(inorder, postorder, index + 1, e, k);
        root->left = build(inorder, postorder, s, index - 1, k);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int k = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, k);
    }
};
