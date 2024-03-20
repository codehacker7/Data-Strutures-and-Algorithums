class Solution {
public:
    long long dp[100003];
    long long solve(int ind,vector<int>&nums,int &k)
    {
        //if you are the last index or second last index or 3rd last index there is nothing to change after that subarray so you can only return the change needed to make the last 3 size subarray beautiful.
        if(ind >= nums.size()-3) return max(0,k-nums[ind]);

        if(dp[ind] != -1) return dp[ind];

        //if you change the ind then it will take care of the subararay {ind,ind+1,ind+2} but you have to beautify {ind+1,ind+2,ind+3} subarray so to beautify that subarray you can change ind+1,or ind+2,or ind+3 , whichever change will give you min cost this cost will be added to cost to change of ind beacuse you have to modify ind to make beautiful the subsrray {ind,ind+1,ind+2} and this will be returned as a ans.
        long long ch1 = max(0,k-nums[ind]) + solve(ind+1,nums,k);
        long long ch2 = max(0,k-nums[ind]) + solve(ind+2,nums,k);
        long long ch3 = max(0,k-nums[ind]) + solve(ind+3,nums,k);

        return dp[ind] = min({ch1,ch2,ch3});
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));

        //you can make the 1st 3 size subarray beautiful by changing 0th or 1st or 2nd index, which ever will give you min cost will be your answer.
        long long ch1 = solve(0,nums,k);
        long long ch2 = solve(1,nums,k);
        long long ch3 = solve(2,nums,k);
    
        return min({ch1,ch2,ch3});
    }
};