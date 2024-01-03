#include <vector>

class Solution {
public:
    int f(int T, const vector<int>& a, int index, vector<vector<int>>& dp) {
        if (T == 0) {
            return 1;
        }
        if (dp[index][T] != -1) {
            return dp[index][T];
        }

        int take = 0;

        for (int i = index; i < a.size(); i++) {
            if (T >= a[i]) {
                take += f(T - a[i], a, i, dp);  // include the current coin
            }
        }

        dp[index][T] = take + nonTake;

        return dp[index][T];
    }

    int change(int value, vector<int>& denominations) {
        int n = denominations.size();

        // Initialize the 2D vector with -1
        vector<vector<int>> dp(n + 1, vector<int>(value + 1, -1));

        return f(value, denominations, 0, dp);
    }
};
