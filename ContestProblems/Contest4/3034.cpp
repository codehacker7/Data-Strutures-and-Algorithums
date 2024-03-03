#include <vector>

class Solution {
public:
    int countMatchingSubarrays(std::vector<int>& nums, std::vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size() + 1;
        
        int iterator = 0;
        int count = 0;
        
        while(iterator + m - 1 < n){
            int i = iterator;
            int j = i + m - 1;
            
            bool check = true;
            for(int loop = 0; loop < m - 1; loop++){
                if(pattern[loop] == 1 && nums[i + loop + 1] > nums[i + loop]){
                    continue;
                } else if(pattern[loop] == 0 && nums[i + loop] == nums[i + loop + 1]){
                    continue;
                } else if(pattern[loop] == -1 && nums[i + loop] > nums[i + loop + 1]){
                   continue;
                }else{
                    check = false;
                    break;
                }
            }
            
            if(check){
                count++;
            }
            
            iterator++;
        }
        return count;
    }
};
