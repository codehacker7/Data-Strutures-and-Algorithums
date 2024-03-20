#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int>& a, vector<vector<int>>& memo) {
    if (i > j) return 0;
    if (memo[i][j] != -1) return memo[i][j]; // If already computed, return the stored result

    int maxi = INT_MIN;

    for (int ind = i; ind <= j; ind++) {
        int cost = a[i - 1] * a[ind] * a[j + 1] + f(ind - 1, j, a, memo) + f(ind + 1, j, a, memo);
        maxi = max(maxi, cost);
    }

    memo[i][j] = maxi; // Store the computed result in the memoization table
    return maxi;
}

int maxCoins(vector<int>& a) {
    a.push_back(1);
    a.insert(a.begin(), 1);
    int n = a.size();

    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1)); // Initialize memoization table with -1

    return f(1, n, a, memo);
}
