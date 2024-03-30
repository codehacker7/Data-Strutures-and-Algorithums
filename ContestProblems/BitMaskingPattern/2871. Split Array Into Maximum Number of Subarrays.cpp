class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        
        int totalAnd = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            totalAnd = totalAnd & nums[i];
        }
        if(totalAnd){
            return 1;
        }
        
        int ans = 0;
        int currentAnd = -1;
        for(int i = 0; i < nums.size();i++){
            
            if(currentAnd == -1) currentAnd = nums[i];
            
            else{
                currentAnd = currentAnd & nums[i];
            }
            
            
            if(currentAnd == 0){
                ans++;
                currentAnd = -1;
            }
            
        }
        
        return ans;
        
        
    }
};