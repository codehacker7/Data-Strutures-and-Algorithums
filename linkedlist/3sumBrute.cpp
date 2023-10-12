class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int target = 0;
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            set<int> hashset;
            
            for(int j=i+1;j<n;j++){

                int third = -(nums[i] + nums[j]) + target;

                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
        
    }
};