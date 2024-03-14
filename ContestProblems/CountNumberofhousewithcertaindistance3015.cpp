class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {

        vector<vector<int>> graph(n+1,vector<int>(n+1,1e6));

        for(int i = 1; i <= n;i++){
            graph[i][i+1] = 1;
            graph[i+1][i] = 1;
        }
        graph[x][y] = 1;

        for(int via = 1; via <= n; via++){
            for(int i = 1; i <=n ;i++){
                for(int j = 1; j<=n;j++){
                    graph[i][j] = min(graph[i][j],graph[i][via] + graph[via][j]);
                }
            }
        }

    vector<int> ans(n,0);
     for(int i = 1; i <=n ;i++){
                for(int j = 1; j<=n;j++){
                        if(i == j) continue;

                        int val = graph[i][j];
                        ans[val-1]++;
                }
     }



    }