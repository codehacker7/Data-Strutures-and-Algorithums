class Solution {
public:
    void createParentMapping(TreeNode* root, TreeNode* target, map<TreeNode*, TreeNode*> &mapping) {
        queue<TreeNode*> q;
        q.push(root);

        mapping[root] = NULL;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left != NULL) {
                q.push(front->left);
                mapping[front->left] = front;
            }

            if (front->right != NULL) {
                q.push(front->right);
                mapping[front->right] = front;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mapping;
        createParentMapping(root, target, mapping);

        queue<TreeNode*> q;
        q.push(target);

        map<TreeNode*, bool> visited;
        vector<int> ans;

        int count = 0;

        while (!q.empty() && count < k) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* front = q.front();
                q.pop();

                visited[front] = true;

                if(count == k){
                    ans.push_back(front->val);
                }

                if (front->left != NULL && visited[front->left] == false) {
                    q.push(front->left);
                    visited[front->left] = true;

                }

                if (front->right != NULL && visited[front->right] == false) {
                    q.push(front->right);
                    visited[front->right] = true;

                    
                }

                if (mapping[front] != NULL && visited[mapping[front]] == false) {
                    q.push(mapping[front]);
                    visited[mapping[front]] = true;

             
                }
            }
            count++;
        }


        while(!q.empty()){
            TreeNode* front= q.front();
            q.pop();
            ans.push_back(front->val);
        }

        return ans;
    }
};
