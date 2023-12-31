class Solution{
public:
    int dp[100001][3];
    int recurssion(int i,vector<vector<int>> &cost,int prev){
        if(i == cost.size()){
            return 0;
        }
        
        if(prev == -1){
            
            int a1 = cost[i][0] + recurssion(i+1,cost,0);
            int a2 = cost[i][1] + recurssion(i+1,cost,1);
            int a3 = cost[i][2] + recurssion(i+2,cost,2);
            return min(a1,min(a2,a3));
            
        }else if(dp[i][prev] != -1){
                return dp[i][prev];    
        }
       else{
            int ans = INT_MAX;
            for(int j=0;j<=2;j++){
                if(j == prev) continue;
                
                ans = min(cost[i][j] + recurssion(i+1,cost,j));
                
                
            }
            return dp[i][prev] = ans;
        }
    }
    int minCost(int N, vector<int> cost[]) {
        // code here
        return recurssion(0,cost,-1);
    }
};