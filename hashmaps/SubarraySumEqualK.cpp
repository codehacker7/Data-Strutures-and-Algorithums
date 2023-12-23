class Solution {
public:
    int subarraySumEqualsK(vector<int>& nums, int k) {


        unordered_map<int,int> prefixSumcount;


 prefixSumcount[0] = 1; // this is being pushed so that if nums[i] - k == 0 then we are able to get something

        int sum =0;
        int answer =0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
// this is the sum that we are looking for that we can choop off in order to recieve the required sum
            int requiredSum = sum - k;

            if(prefixSumcount.find(requiredSum) != prefixSumcount.end()){
                answer = answer + prefixSumcount[requiredSum];
                prefixSumcount[sum]++;
            }else{
                  prefixSumcount[sum]++;
            }
        }

        return answer;

        
    }
};