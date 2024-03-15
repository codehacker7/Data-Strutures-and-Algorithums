class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int el = nums[0];
        int ct = 0;
        int min_val = el;

        for(int i = 0; i < n; i++){
            if(nums[i] == el){
                ct++;
            }
            if(nums[i] %el != 0){
                min_val = min(min_val,nums[i]%el);
            }
        }

        if(min_val != el || ct == 1){
            return 1;
        }

        return (ct + 1)/2;

        
    }
};