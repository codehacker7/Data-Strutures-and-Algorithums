  bool detect(int src, vector<int> adj[], bool vis[]) {
    vis[src] = true;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty()) {
        int elem = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto x : adj[elem]) {
            if (!vis[x]) {
                vis[x] = true;
                q.push({x, elem});
            } else if (parent != x) {
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    bool vis[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}