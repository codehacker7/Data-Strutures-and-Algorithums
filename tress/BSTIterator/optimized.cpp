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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {

        while(root != NULL){
            st.push(root);
            if(root->left != NULL){
                root = root->left;
            }else{
                root = NULL;
            }
        }
       
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(node->right){
            st.push(node->right);
            TreeNode* right = node->right;

        while (right->left != NULL) {
            st.push(right->left);
            right = right->left;
        }

        }

        return node->val;
        
    }
    
    bool hasNext() {

        return !st.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */