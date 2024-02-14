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


        // if we are able to get minimum sum subarray then we can easily find maximum sum subaarray by using

        // SUM = MINIMUMSUM + MAXIMUM SUM
        //MAXIMUM SUM = TOTALSUM  - MINIMUMSUM

        

        int circularmaxsum = totalsum - minsum;

        /*
        NOW AN EDGE CASE WHERE ARR = [-1,-1,-1]
        SUM = -3
        MINSUM = -3
        MAXSUM = -1
       
        CIRCULAR SUM = -3-(-3)  = 0
        BUT THERE IS NO SUBAARY WHICH HAS 0 SUM SO CHECK IF (MAXUM > 0  )
        
        */


        if(maxsum > 0){

        return max(circularmaxsum,maxsum);
        }else{
            return maxsum;
        }
    }
};