class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {


        set<int> st1;
        vector<int> ans;

        for(int i=0;i<nums1.size();i++){
            st1.insert(nums1[i]);
        }


        for(int i=0;i<nums2.size();i++){
            if(st1.find(nums2[i]) != st1.end()){
                ans.push_back(nums2[i]);
                st1.erase(nums2[i]);
            }   
        }

        return ans;
        
    }
};