class Solution {
public: 

    int helper(vector<int>& coins, int amount,vector<int>& dp){


        if(amount == 0){
            dp[amount] =0;
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }


        int finalans = INT_MAX;
        for(int i=0;i<coins.size();i++){

            if(amount >= coins[i]){
                int smallAmount = amount - coins[i];
                int ans = helper(coins,smallAmount,dp);
                if(ans != INT_MAX){
                finalans = min(finalans,ans + 1);
                }
            }

            
        }

        dp[amount] = finalans;
        return finalans;

    }


    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1,-1);

        int maxi = helper(coins,amount,dp);

        if(maxi == INT_MAX){
            return -1;
        }

        return maxi;


        
    }
};