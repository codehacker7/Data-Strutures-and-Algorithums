class Solution {
public:
    int operationsHelper(vector<int>& nums, int start, int end, int sum, bool isStart,vector<vector<int>> &dp) {
        if (end - start + 1 < 2) return 0;
        if (start >= end) {
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int op1 = 0, op2 = 0, op3 = 0;

        if (isStart) {
            int localsum = nums[start] + nums[start + 1];
            int ans = operationsHelper(nums, start + 2, end, localsum, false,dp);
            op1 = 1 + ans;

            localsum = nums[start] + nums[end];
            ans = operationsHelper(nums, start + 1, end - 1, localsum, false,dp);
            op2 = 1 + ans;

            localsum = nums[end - 1] + nums[end];
            int ans2 = operationsHelper(nums, start, end - 2, localsum, false,dp);
            op3 = 1 + ans2;
        } else {
            int localsum = nums[start] + nums[start + 1];
            if (sum == localsum) {
                op1 = 1 + operationsHelper(nums, start + 2, end, localsum, false,dp);
            }

            localsum = nums[start] + nums[end];
            if (sum == localsum) {
                op2 = 1 + operationsHelper(nums, start + 1, end - 1, localsum, false,dp);
            }

            localsum = nums[end - 1] + nums[end];
            if (sum == localsum) {
                op3 = 1 + operationsHelper(nums, start, end - 2, localsum, false,dp);
            }
        }

        return dp[start][end] = max({op1, op2, op3});
    }

    int maxOperations(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
    
        
        vector<vector<int>> dp(2001, vector<int>(2001, -1));

        return operationsHelper(nums, start, end, 0, true,dp);
    }
};
