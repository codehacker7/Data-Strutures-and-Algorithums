class Solution {
public:
    bool helper(string& s, string& p, int m, int n, vector<vector<int>>& memo) {
        if (m < 0 && n < 0) return true;
        if (n < 0 && m >= 0) return false;
        if (n >= 0 && m < 0) {
            for (int i = n; i >= 0; i--) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        bool result = false;
        if (s[m] == p[n] || p[n] == '?') {
            result = helper(s, p, m - 1, n - 1, memo);
        } else if (p[n] == '*') {
            bool when_star_does_not_mean_anything = helper(s, p, m, n - 1, memo);
            bool when_star_does_means_something = helper(s, p, m - 1, n, memo);
            result = when_star_does_not_mean_anything || when_star_does_means_something;
        }

        memo[m][n] = result ? 1 : 0;
        return result;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return helper(s, p, m - 1, n - 1, memo);
    }
};