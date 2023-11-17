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

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int> dp(nums.size(),-1);
        vector<int> dp1(nums.size(),-1);
        return max(solve(nums,0,n-1,dp),solve(nums,1,n,dp1));

        
    }
};