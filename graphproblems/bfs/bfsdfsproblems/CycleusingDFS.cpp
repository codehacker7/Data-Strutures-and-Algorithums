bool dfs(int node, int parent, vector<int>& visited, vector<int> adj[]) {
        visited[node] = 1;
        for (auto adjacentNode : adj[node]) {
            if (visited[adjacentNode] == 0) {
                if (dfs(adjacentNode, node, visited, adj)) {
                    return true;
                }
            } else if (adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(i, -1, vis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }