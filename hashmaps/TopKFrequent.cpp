class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> mp;

        for(int i = 0; i < nums.size();i++){
            int element = nums[i];
            mp[element]++;
        }

        priority_queue<pair<int,int> > pq;

        for(auto p : mp){
            auto element = p.first;
            auto frequency = p.second;
            pq.push({frequency,element});
        }
        vector<int> ans;

        int count = 0;
        while(count < k){
            pair p = pq.top();
            int element = p.second;
            ans.push_back(element);
            pq.pop();
            count++;
        }

        return ans;        
    }
};