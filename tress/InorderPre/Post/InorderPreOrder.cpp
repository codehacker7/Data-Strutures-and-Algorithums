class Solution {
public:
    TreeNode* TreeCreate(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inStart, int inEnd) {
        if (preIdx >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inIdx = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                inIdx = i;
                break;
            }
        }
        
        root->left = TreeCreate(preorder, inorder, preIdx, inStart, inIdx - 1);
        root->right = TreeCreate(preorder, inorder, preIdx, inIdx + 1, inEnd);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return TreeCreate(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};
