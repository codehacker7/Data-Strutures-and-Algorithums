class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> prefixsum(n,0);
        prefixsum[0] = nums[0];
        
        for(int i = 1; i < n ; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }
        
        unordered_map<int,int> mp;
        
        mp[nums[0]] = 0;
        
        int ans = INT_MIN;
        for(int j = 1; j < n ;j++){
            int exp1 = nums[j] + k;
            int exp2 = nums[j] - k;
            
            
            if(mp.find(exp1) != mp.end()){
                ans = max(ans,prefixsum[j]- mp[exp1]);
            }
            
            if(mp.find(exp2) != mp.end()){
                ans = max(ans,prefixsum[j]- mp[exp2]);
            }
            
            if(mp.find(nums[j]) != mp.end()){
                mp[nums[j]] = min(mp[nums[j]],prefixsum[j-1]);
            }else{
                mp[nums[j]] = prefixsum[j-1];
            }
            
            
            
        }
        
        return (ans == INT_MIN?0:ans);
        
        
        
    }
};