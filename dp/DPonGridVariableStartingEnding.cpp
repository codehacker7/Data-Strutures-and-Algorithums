#include <bits/stdc++.h> 

using namespace std;

int f(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (col < 0 || col >= matrix[0].size()) {
        return -1e8;
    }

    if (row == 0) {
        return matrix[0][col];
    }

    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    int up = matrix[row][col] + f(row - 1, col, matrix, dp);
    int ld = matrix[row][col] + f(row - 1, col - 1, matrix, dp);
    int rd = matrix[row][col] + f(row - 1, col + 1, matrix, dp);

    return dp[row][col] = max(up, max(ld, rd));
}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table

    int maxi = -1e8;

    for (int j = 0; j < m; j++) {
        maxi = max(maxi, f(n - 1, j, matrix, dp));
    }
    return maxi;
}
