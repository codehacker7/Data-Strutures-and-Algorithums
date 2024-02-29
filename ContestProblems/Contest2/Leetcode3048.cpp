class Solution {
public:
    bool isPossible(vector<int> nums, vector<int> changeIndicesCopy, int s) {
        int n = nums.size();
        vector<int> last(n, -1);
        for (int i = 0; i <= s; i++) {
            last[changeIndicesCopy[i]] = i;
        }
        int completed = 0;
        int power = 0;
        for (int i = 0; i <= s; i++) {
            if (last[changeIndicesCopy[i]] == i) {
                if (nums[changeIndicesCopy[i]] > power) return false;
                power -= nums[changeIndicesCopy[i]];
                completed++;
            } else {
                power++;
            }
        }
        return completed == n;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int m = changeIndices.size();

        // Create a copy of changeIndices
        vector<int> changeIndicesCopy(changeIndices.begin(), changeIndices.end());
        for (auto& el : changeIndicesCopy) {
            el--;
        }

        int low = 0;
        int high = m - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(nums, changeIndicesCopy, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans == -1 ? -1 : ans + 1;
    }
};
