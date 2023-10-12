class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int target = 0;
        vector<vector<int>> triplets;

        for(int i=0;i<nums.size();i++){
            
            if(i > 0){
                if(nums[i] == nums[i-1]){
                    continue;
                }
            }

            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
            int val = nums[i] + nums[j] + nums[k];

            if(val < target){
                j++;
            }else if(val > target){ 
                k--;
            }else{
                vector<int> answer = {nums[i],nums[j],nums[k]};
                triplets.push_back(answer);
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]){
                    j++;
                }
                while(j < k && nums[k] == nums[k+1]){
                    k--;
                }
            }
            }
        }

        return triplets;
        
    }
};