class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            if (visited[it] == 0)
            {
                dfs(it, visited, adj, st);
            }
        }

        st.push(node);
    }

    void dfs3(int node, vector<int> &visited, vector<int> adjT[])
    {
        visited[node] = 1;

        for (auto it : adjT[node])
        {
            if (visited[it] == 0)
            {
                dfs3(it, visited, adjT);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, visited, adj, st);
            }
        }

        vector<int> adjT[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto it : adj[i])
            {
                // i -> it
                // need to reverse
                adjT[it].push_back(i);
            }
        }

        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (visited[node] == 0)
            {
                scc++;
                dfs3(node, visited, adjT);
            }
        }

        return scc;
    }
};
