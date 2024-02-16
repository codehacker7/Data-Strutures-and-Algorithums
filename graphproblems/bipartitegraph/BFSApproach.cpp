public:
    
    bool check(int start,int V,vector<int>adj[],int color[]){
        
         queue<int> q;
	    q.push(start);
	   
	    color[start] = 1;
	    
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       
	       for(auto it:adj[node]){
	           //if the adj node is yet not colored give opposite color of the node
	           if(color[it] == -1){
	               color[it] = 1 - color[node];
	               q.push(it);
	           }
	           //is the adjancey code having the same color someone did color it on some other
	           //path
	           else if(color[it] == color[node]){
	               return false;
	           }
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
	            if(check(i,V,adj,color) == false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}
    
	   
