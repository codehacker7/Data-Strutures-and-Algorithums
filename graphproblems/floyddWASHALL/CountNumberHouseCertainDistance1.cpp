class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> graph(n+1,vector<int>(n+1,1e9));

        for(int i = 1; i < n; i++){
            graph[i][i+1] = 1;
            graph[i+1][i] = 1;
           
        }

        if(x != y){
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        
        for(int k = 1;k <=n;k++){
            for(int i = 1; i <= n;i++){
                for(int j = 1; j <= n;j++){
                    if(i == j) graph[i][j] = 0;
                    else graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
                }
            }
        }

        unordered_map<int,int> mp;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <=n;j++){
                if(i == j) continue;

                mp[graph[i][j]]++;
            }
        }

        vector<int> ans(n);

        for(int i = 0; i < n;i++){
            ans[i] = mp[i+1];
        }

        return ans;

    }
};