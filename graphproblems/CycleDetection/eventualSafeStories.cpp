class Solution {
  public:
    bool dfsCheck(int node,vector<int> adj[],int vis[],int pathVis[],int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto it:adj[node]){
            //when the node is not visited
            if(vis[it] == 0){
                if(dfsCheck(it,adj,vis,pathVis,check)){
                     return true;   
                }
            }
            
            //if the node has not been previously visited
            //but 
            else if(vis[it] == 1 && pathVis[it] == 1){
                return true;
        }
  }
        
         check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
          int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safenodes;
        
        for(int i =0;i < V;i++){
            if(vis[i] == false){
                if(dfsCheck(i,adj,vis,pathVis,check) == true){
                   
                }
            }
        }
        
        for(int i = 0; i< V;i++){
            if(check[i] == 1){
                safenodes.push_back(i);
            }
        }
        
        return safenodes;
        
    }
};