#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        return helper(arr, sum, 0, dp);
    }

private:

    bool helper(vector<int>& arr, int sum, int index, vector<vector<int>>& dp) {
        if (index == arr.size()) {
            return sum == 0;
        }

        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }

        bool take = false;
        if (arr[index] <= sum) {
            take = helper(arr, sum - arr[index], index + 1, dp);
        }

        bool notTake = helper(arr, sum, index + 1, dp);

        return dp[index][sum] = take || notTake;
    }
};

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution solution;
    bool result = solution.isSubsetSum(arr, sum);

    if (result) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
