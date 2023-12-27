class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> freq;

        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        int count = 1;

        while(count <= k){
            int maxi = INT_MIN;
            int finalelement = INT_MIN;
            for(auto i: freq){
                int element = i.first;
                int freq = i.second;
                if(freq > maxi){
                    maxi = freq;
                    finalelement = element;
                }   
            }

            ans.push_back(finalelement);
            auto it = freq.find(finalelement);
            freq.erase(finalelement);

            count++;

        }

        return ans;

          
        
    }
};