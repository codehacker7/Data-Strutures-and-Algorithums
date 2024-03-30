// Recursive function to find the maximum sum after partitioning.
int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();

    // Base case: If the current index is equal to the size of the array, return 0.
    if (ind == n) return 0;

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + maxSumAfterPartitioning(j + 1, num, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}