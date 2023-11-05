class Solution {
public:
    int kadens(vector<int>& nums){
        int currsum =0;
        int maxi = INT_MIN;

        for(int i=0;i<nums.size();i++){
            currsum = currsum + nums[i];
            maxi = max(currsum,maxi);

            if(currsum < 0) currsum =0;
        }

        return maxi;
    }
      int kadens2(vector<int>& nums){
           int currsum =0;
           int mini = INT_MAX;

        for(int i=0;i<nums.size();i++){
            currsum = currsum + nums[i];

            if(currsum > nums[i]){
                currsum = nums[i];
            }
            
            mini = min(currsum,mini);
            
        }

        return mini;
    }
   



    int maxSubarraySumCircular(vector<int>& nums) {

        int totalsum =0;
        for(int i=0;i<nums.size();i++){
            totalsum = totalsum + nums[i];
        }

        int maxsum = kadens(nums);
        int minsum = kadens2(nums);//minimum sum subbary

        

        int circularmaxsum = totalsum - minsum;

        if(maxsum > 0){

        return max(circularmaxsum,maxsum);
        }else{
            return maxsum;
        }
    }
};