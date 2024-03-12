class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxi = 0;
        
        unordered_map<int,int> mp;
        long long ans = 0;
        
        for(auto el : nums){
            maxi = max(maxi,el);
        }
        
        while(j < n){
            mp[nums[j]]++;
            
            while(mp[maxi] >= k){
                ans += (n - j);
                --mp[nums[i]];
                i++;
            }
            j++;
            
        }
        
        return ans;
        
    }
};