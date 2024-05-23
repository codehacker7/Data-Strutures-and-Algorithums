  vector<int> badIndex;
        int n = nums.size();
        
        vector<int> prefSum(n,0);
        
        for(int i = 1; i < n; i++){
            prefSum[i] = prefSum[i-1];
            if(nums[i-1] % 2 == nums[i] % 2){
                prefSum[i]++;
            }
        }
        
        int qn = queries.size();
        
        vector<bool> ans(qn,true);
        if(n == 1) return ans;
        
        
        for(int i = 0; i < qn; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            
            int count = prefSum[v] - prefSum[u];
            
            ans[i] = (count >= 1)? false: true;
        }
        
        return ans;
        
        
        