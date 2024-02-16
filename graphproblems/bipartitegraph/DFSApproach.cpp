public:
    bool check(int node,int col,vector<int>adj[],int color[]){
        
        color[node] = col;
	   
	       for(auto it:adj[node]){
	           //if the adj node is yet not colored give opposite color of the node
	           if(color[it] == -1){
	               if(check(it,1-col,adj,color) == false){
	                   return false;
	               }
	           }
	           else if(color[it] == color[node]){
	               return false;
	           }
	       }
	       return true;
	     
	}
	
	
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	     int color[V];
	     for(int i =0;i< V;i++){
	        color[i] = -1;
	    }
	    
	    for(int i =0;i<V;i++){
	        if(color[i] == -1){
	            if(check(i,0,adj,color) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}