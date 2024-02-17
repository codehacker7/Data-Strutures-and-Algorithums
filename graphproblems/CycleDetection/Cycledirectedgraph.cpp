    bool dfsCheck(int node,vector<int> adj[],int vis[],int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        
        for(auto it:adj[node]){
            //when the node is not visited
            if(vis[it] == 0){
                if(dfsCheck(it,adj,vis,pathVis)){
                     return true;   
                }
            }
            
            //if the node has not been previously visited
            //but 
            else if(vis[it] == 1 && pathVis[it] == 1){
                return true;
        }
        }
        
        
        pathVis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i =0;i < V;i++){
            if(vis[i] == false){
                if(dfsCheck(i,adj,vis,pathVis) == true){
                    return true;
                }
            }
        }
        
        return false;
        
        
    }