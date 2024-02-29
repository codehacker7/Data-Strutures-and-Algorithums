class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
         std::unordered_map<int, int> num_map;
        for (int num : nums) {
            if (++num_map[num] > 2) return false;
        }
        return true;
        
    }
};