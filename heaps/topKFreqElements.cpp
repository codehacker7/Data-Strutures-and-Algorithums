class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq; // i want to make a max heap   
        map<int,int> mp;//this mp is going to store freq with element

        for(int i=0;i<nums.size();i++){
            int element = nums[i];
            mp[element]++;
        }
        
        for(auto p:mp){
            int element = p.first;
            int freq = p.second;

            pq.push({freq,element});
        }

        int count =0;
        vector<int> ans;
        
        while(count < k){
            pair p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            count++;
        }

        return ans;



    }
};