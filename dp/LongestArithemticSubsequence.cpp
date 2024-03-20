class Solution {
public:
    int t[1001][1003];
    int solve(int index,int diff,vector<int>& nums){

        if(index >= nums.size()){
            return 0;
        }        

        if(t[index][diff + 501] != -1){
            return t[index][diff + 501];
        }

        int maxi = 0;
        for(int j = index + 1; j < nums.size(); j++){
            int local_diff = nums[j] - nums[index];
           
            if(local_diff == diff){
                maxi = max(maxi,1 + solve(j,local_diff,nums));
            }

        }
        return t[index][diff + 501] = maxi;
    }

    int longestArithSeqLength(vector<int>& nums) {


        memset(t,-1,sizeof(t));

        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int diff = nums[j] - nums[i];
                ans = max(ans,2+solve(j,diff,nums));
            }
        }

        return ans;
        
    }
};