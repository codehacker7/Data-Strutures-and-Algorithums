 int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
         vector<int> vis(V,0);
         
         pq.push({0,0});//weight,node
         
         int sum = 0;
         while(!pq.empty()){
             auto it = pq.top();
             pq.pop();
             int node = it.second;
             int wt = it.first;
             
             if(vis[node] == 1){
                 continue;
             }
             vis[node] = 1;
             sum = sum + wt;
             for(auto adjNode : adj[node]){
                 int nodeadj = adjNode[0];
                 int edW =   adjNode[1];
                 
                 if(vis[nodeadj] == 0){
                     pq.push({edW,nodeadj});
                 }
             }
         }
         
         
         return sum;
         
    }