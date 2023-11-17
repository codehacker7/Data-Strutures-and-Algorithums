class Solution {
public:
    int solve(vector<int> nums,int i,int  n,vector<int> &dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

         
        int take=nums[i]+solve(nums,i+2,n,dp);
        int notTake= 0 + solve(nums,i+1,n,dp);

        dp[i]=max(take,notTake); 

        return max(take,notTake);
    }
    int rob(vector<int>& nums) {
         
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,nums.size(),dp) ;
    }
};