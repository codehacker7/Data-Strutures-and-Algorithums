class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();

        map<int, int> mp;
        int count = 0;
        while (j < n) {
            int element = nums[j];
            mp[element]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    auto it = mp.find(nums[i]);
                    mp.erase(it);
                }
                i++; // Increment i to avoid infinite loop
            }

            count += (j - i) + 1;

            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
