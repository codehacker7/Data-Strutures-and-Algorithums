struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> result;

    if (root == NULL) {
        return result;
    }

    queue<pair<Node*, int>> q;
    map<int, int> nodes; // level to node value mapping

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();

        Node* front = p.first;
        int level = p.second;

        // Update the condition for left view
        if (nodes.find(level) == nodes.end()) {
            nodes[level] = front->data;
        }

        if (front->left != NULL) {
            q.push({front->left, level + 1});
        }
        if (front->right != NULL) {
            q.push({front->right, level + 1});
        }
    }

    // Populate the result vector from the nodes map
    for (auto i : nodes) {
        result.push_back(i.second);
    }

    return result;
   // Your code here
}