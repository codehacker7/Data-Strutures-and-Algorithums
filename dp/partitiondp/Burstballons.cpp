class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>> &dp){

        if(i > j) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxi = INT_MIN;
        for(int k = i; k <= j; k++){
            int cost = nums[i-1] * nums[j+1] * nums[k] + f(i,k-1,nums,dp) + f(k+1,j,nums,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(1000,vector<int>(1000,-1));
        return f(1,n,nums,dp);
    }
};