#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> dp;

int solve(int plates, int floors) {
    if (floors == 0 || floors == 1) {
        return floors;
    }
    if (plates == 1) {
        return floors;
    }

    if (dp[plates][floors] != -1) {
        return dp[plates][floors];
    }

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++) {
        int temp = 1 + max(solve(plates - 1, k - 1), solve(plates, floors - k));
        mn = min(mn, temp);
    }

    return dp[plates][floors] = mn;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int plates, floors;
        cin >> plates >> floors;

        dp.assign(plates + 1, vector<int>(floors + 1, -1)); // Initialize 2D array with -1

        int result = solve(plates, floors);
        cout << result << endl;
    }

    return 0;
}
