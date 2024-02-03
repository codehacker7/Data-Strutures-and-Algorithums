class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        int mergingIntervalStart = intervals[0][0];
        int mergingIntervalEnd = intervals[0][1];


        vector<vector<int>> ans;

        for(int i = 1; i < intervals.size(); i++) {
            vector<int> currentInterval = intervals[i];
            int newIntervalStart = currentInterval[0];
            int newIntervalEnd = currentInterval[1];

            if (mergingIntervalEnd >= newIntervalStart) {
                mergingIntervalEnd = max(newIntervalEnd,mergingIntervalEnd);
            }else{
                ans.push_back({mergingIntervalStart, mergingIntervalEnd});
                mergingIntervalStart = newIntervalStart;
                mergingIntervalEnd = newIntervalEnd;
            }

        }

        ans.push_back({mergingIntervalStart, mergingIntervalEnd});

        return ans;

        
        
    }
};