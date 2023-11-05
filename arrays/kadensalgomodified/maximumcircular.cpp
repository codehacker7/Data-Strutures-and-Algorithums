//brute force
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

    void rotate(vector<int>& nums,int k){

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());

    }



    int maxSubarraySumCircular(vector<int>& nums) {

        int sum = kadens(nums);
        int maximumsum = sum;

        for(int i=0;i<nums.size();i++){
            rotate(nums,1);
            int newsum = kadens(nums);
            maximumsum = max(maximumsum,newsum);

        }
        return maximumsum;
        
    }
};