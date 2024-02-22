class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        if(source.first==destination.first && source.second==destination.second) 
         return 0; 

        
        queue<pair<int,pair<int,int> > > q;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        
        q.push({0,{source.first,source.second}});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i = 0; i < 4;i++){
                int newr = r + dr[i];
                int newcol = c + dc[i];
                if(newr >= 0 && newr < n && newcol >=0 && newcol < m
                    && grid[newr][newcol] == 1 && dis + 1 < dist[newr][newcol]){
                        dist[newr][newcol] = 1 + dis;
                        if(newr == destination.first && newcol == destination.second){
                            return dis+1;
                        }
                        
                        q.push({1+dis,{newr,newcol}});
                    }
           
           
            }
        }
        
        
        return -1;
        
        
        
        
        
    }
};