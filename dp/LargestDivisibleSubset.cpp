#include <vector>
#include <algorithm>

class Solution {
public:
    void solve(int idx, std::vector<int>& nums, std::vector<int>& result, std::vector<int>& temp, int prev, std::vector<std::vector<int>>& dp) {
        if (idx == nums.size()) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        }

        // If already computed, return
        if (dp[idx][prev] != -1) {
            return;
        }

        if (prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            solve(idx + 1, nums, result, temp, nums[idx], dp);
            temp.pop_back();
        }
        solve(idx + 1, nums, result, temp, prev, dp);

        // Store the result in DP table
        dp[idx][prev] = result.size();
    }

    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> prevIdx(n,-1);

        int maxL = 1;
        int last_chosen_index = 0;
        for(int i = 1;i < n;i++){
            for(int j = i-1;j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                         dp[i] = max(dp[i],dp[j] + 1);
                         prevIdx[i] = j;
                    }
                    if(dp[i] > maxL){
                        maxL = dp[i];
                        last_chosen_index = i;
                    }
                   
                }
            }
        }



       vector<int> result;

       while(last_chosen_index != -1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prevIdx[last_chosen_index];
       }

       return result;

    }
};
