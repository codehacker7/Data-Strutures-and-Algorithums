#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int zero, int one, bool ms, int limit) {
        if (one == 0 && zero == 0) return 1;
        if (dp[zero][one][ms] != -1) return dp[zero][one][ms];

        int ans = 0;
        if (ms == true) { // prev i have taken a 0 and now its time to take a 1
            for (int i = 1; i <= min(limit, one); i++) {
                ans = (ans + solve(zero, one - i, false, limit)) % mod;
            }
        } else {
            for (int i = 1; i <= min(limit, zero); i++) {
                ans = (ans + solve(zero - i, one, true, limit)) % mod;
            }
        }

        return dp[zero][one][ms] = ans % mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        dp.assign(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
        int a = solve(zero, one, true, limit) % mod;
        int b = solve(zero, one, false, limit) % mod;
        return (a + b) % mod;
    }
};
