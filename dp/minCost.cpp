#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int minCostToBuyOrangesHelper(int idx, int requiredWeight, vector<vector<int>>& dp, const int* cost, int n)
{
    
    if (requiredWeight == 0)
        return 0;

    if (idx == n || idx + 1 > requiredWeight)
        return INT_MAX;

    if (dp[idx][requiredWeight] != -1)
        return dp[idx][requiredWeight];

    // int aheadCost, finalCost = INT_MAX;

int op1 = INT_MAX, op2 = INT_MAX;

    if (cost[idx] == -1)
    {
        op2 = minCostToBuyOrangesHelper(idx + 1, requiredWeight, dp, cost, n);
    }
    else
    {
        op1 = minCostToBuyOrangesHelper(idx, requiredWeight - (idx + 1), dp, cost, n);
        if (op1 != INT_MAX)
        {
            op1 = cost[idx] + op1;
        }

        op2 = minCostToBuyOrangesHelper(idx + 1, requiredWeight, dp, cost, n);
    }

    int ans = min(op1,op2);
    dp[idx][requiredWeight] =ans ;

    return ans;
}

int minCostToBuyOranges(const int* cost, int n, int w)
{
    
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));

    int minCost = minCostToBuyOrangesHelper(0, w, dp, cost, n);

    if (minCost == INT_MAX)
    {
        return -1;
    }

    return minCost;
}
