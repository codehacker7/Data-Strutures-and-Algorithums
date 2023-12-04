class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp1;
        vector<int> ans;

        for(int i=0;i<nums1.size();i++){
            int element = nums1[i];
            mp1[element]++;
        }

        for(int i=0;i<nums2.size();i++){
            int element = nums2[i];
            if(mp1.find(element) != mp1.end()){
                 
                 if(mp1[element] > 0){
                    mp1[element]--;
                    ans.push_back(nums2[i]);
                 }

            }

        }

        return ans;
        
    }
};