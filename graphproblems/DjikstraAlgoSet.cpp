{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        set<pair<int,int>> st;
        vector<int> dist(V);
        for(int i = 0; i < V;i++){
            dist[i] = 1e9;
        }
        dist[S] = 0;
        st.insert({0,S});
        
        while(!st.empty()){
            
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};