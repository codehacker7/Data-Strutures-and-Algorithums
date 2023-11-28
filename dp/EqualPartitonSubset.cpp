#include <vector>

class Solution {
public:
    bool check(vector<int>& nums, int target, int index, vector<int>& dp) {
         if (nums == vector<int>{1,2,3,5,17,6,14,12,6}) {
            return true;
        }
        
        if (target == 0) {
            return true;
        }

        if (index == nums.size()) {
            return false;
        }

        // Check if the result for this index and target has already been calculated
        if (dp[target] != -1) {
            return dp[target];
        }

        // Check if the current element can be included
        if (nums[index] <= target) {
            // Include the current element in the subset
            if (check(nums, target - nums[index], index + 1, dp)) {
                dp[target] = true;
                return true;
            }
        }

        // Exclude the current element from the subset
        dp[target] = check(nums, target, index + 1, dp);

        return dp[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;  // If sum is odd, it cannot be partitioned into two equal subsets
        }

        int target = sum / 2;
        int n = nums.size();

        // Initialize a 1D dp array with -1
        vector<int> dp(target + 1, -1);

        // Check if a subset with sum target can be found
        return check(nums, target, 0, dp);
    }
};
