class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }

        queue<Node*> q;
        q.push(root);

        queue<Node*> ans;
        ans.push(root);
        ans.push(nullptr);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left) {
                    q.push(front->left);
                    ans.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                    ans.push(front->right);
                }
            }

            ans.push(nullptr);
        }

        while (!ans.empty()) {
            Node* front = ans.front();
            ans.pop();

            if (front == nullptr) {
                continue;
            }

            if (!ans.empty()) {
                front->next = ans.front();
            } else {
                front->next = nullptr;
            }
        }

        return root;
    }
};
