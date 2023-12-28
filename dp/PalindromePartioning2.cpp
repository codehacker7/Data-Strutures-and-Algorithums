class Solution {
public:
    bool isPalindrome(int i, int j, string &str) {
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCutHelper(int i, int n, string &str, vector<int> &dp) {
        if (i == n) return 0;

        if (dp[i] != -1) {
            return dp[i];
        }

        int minCuts = INT_MAX;

        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                int cuts = 1 + minCutHelper(j + 1, n, str, dp);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i] = minCuts;
    }

    int minCut(string str) {
        int n = str.length();
        vector<int> dp(n, -1);

        return minCutHelper(0, n, str, dp) -1;
    }
};
