#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 90;
const int MAX_STATE = 2;

long long dp[MAX_N][MAX_STATE];

long long solve(int N, int i, bool is1, vector<string> &ans, string temp) {
    if (i == N) {
        ans.push_back(temp);
        return 1;
    }

    if (dp[i][is1] != -1) {
        // Return the memoized result if available
        return dp[i][is1];
    }

    long long count = 0;
    if (is1) {
        count += solve(N, i + 1, false, ans, temp + "0");
    } else {
        count += solve(N, i + 1, false, ans, temp + "0");
        count += solve(N, i + 1, true, ans, temp + "1");
    }

    // Memoize the result
    dp[i][is1] = count;

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> ans;

        // Initialize memoization table with -1
        for (int i = 0; i < MAX_N; ++i) {
            for (int j = 0; j < MAX_STATE; ++j) {
                dp[i][j] = -1;
            }
        }

        long long result = solve(n, 0, false, ans, "");

        cout << result << endl;
    }

    return 0;
}
