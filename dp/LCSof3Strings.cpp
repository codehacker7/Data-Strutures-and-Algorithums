int solve(string A, string B, string C, int n1, int n2, int n3, int dp[100][100][100]) {

    if (n1 == 0 || n2 == 0 || n3 == 0) {
        return dp[n1][n2][n3] = 0;
    }

    if (dp[n1][n2][n3] != -1) {
        return dp[n1][n2][n3];
    }

    if (A[n1 - 1] == B[n2 - 1] && B[n2 - 1] == C[n3 - 1]) {
        return dp[n1][n2][n3] = 1 + solve(A, B, C, n1 - 1, n2 - 1, n3 - 1, dp);
    } else {
        return dp[n1][n2][n3] = max(
            solve(A, B, C, n1 - 1, n2, n3, dp),
            max(solve(A, B, C, n1, n2 - 1, n3, dp),
                solve(A, B, C, n1, n2, n3 - 1, dp)));
    }
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
    int dp[100][100][100];
    memset(dp, -1, sizeof(dp));
    return solve(A, B, C, n1, n2, n3, dp);
}