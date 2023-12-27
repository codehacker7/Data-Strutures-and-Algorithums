class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int farthest =0;
        
        int checkI =0;
        int jumps = 0;

        for(int i=0;i < n -1;i++){

            farthest = max(farthest, i + nums[i]);

            if(i == checkI){
                jumps++;
                checkI = farthest;
            }

        }

        return jumps;
        
    }
};