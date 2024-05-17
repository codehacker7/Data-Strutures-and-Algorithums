class Solution {
public:

    vector<vector<int>> dp;
    int solve(int j, int keep,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(j >= m) return 0;

        if(dp[j][keep] != -1){
            return dp[j][keep];
        }

        int minAns = INT_MAX;
        int cost = 0;

        for(int i =0; i < n; i++){
            if(grid[i][j] != keep){
                cost++;
            }
        }

        for(int option = 0; option <= 9; option++){
            if(option == keep) continue;
            minAns = min(minAns, cost + solve(j+1,option,grid));
        }


        return dp[j][keep] = minAns;



    }

    int minimumOperations(vector<vector<int>>& grid) {
        int minAns = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        dp = vector<vector<int>>(m,vector<int>(10,-1));

        for(int keep = 0; keep <= 9; keep++){
            minAns = min(minAns,solve(0,keep,grid));
        }
        return minAns;
    }
};