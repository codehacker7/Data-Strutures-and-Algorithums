class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        
        //if the sum of the 2 minimum elements in the array is more than target then it is not possible
        
        int n = nums.size();
        int count = 0;
        
        long long arrSum = 0;
        
        for(int i = 0; i < n ; i++){
            arrSum += nums[i];
        }
        
        if(target % arrSum == 0){
            return (target/arrSum) * n;
        }
        
        
        if(target > arrSum){
            count = (target/arrSum) * n;
            target %= arrSum;
        }
        
        int ans = INT_MAX;
        int l = 0;
        int r = 0;
        long long currSum = 0;
        
        while(r < 2* n){
            currSum += nums[r % n];
            
            while(l <= r && currSum > target){
                currSum -= nums[l%n];
                l++;
            }
            
            if(currSum == target){
                ans = min(ans,r-l+1);
            }
            
            r++;
            
        }
        
        
        if(ans == INT_MAX) return -1;
        
        return count + ans;
        
        
    }
};