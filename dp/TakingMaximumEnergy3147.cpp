class Solution {
public:

    int solve(vector<int>& energy, int idx, int k, vector<int> &memo){

        if(idx >= energy.size()){
            return 0;
        }
        if(memo[idx] != INT_MIN) return memo[idx];

        int ans = energy[idx] + solve(energy,idx+k,k,memo);

        return memo[idx] = ans;
    }

    int maximumEnergy(vector<int>& energy, int k) {
        
         int n = energy.size();
        int ans = INT_MIN;

         vector<int> memo(n, INT_MIN);

        for(int i = 0; i < n; i++){
           ans = max(ans, solve(energy, i, k, memo));
        }

        return ans;

    }
};