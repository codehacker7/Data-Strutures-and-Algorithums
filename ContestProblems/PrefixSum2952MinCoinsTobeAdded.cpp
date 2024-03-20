class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
       
        int n = coins.size();
        long long prefixSum = 0;
        int id = 0;
        int addedCoins = 0;
        
        
        for(int i = 1; i <= target; i++){
            //check if you can form the sum
            if(id < n && coins[id] == i){
                prefixSum += coins[id];
                id++;
            }else if(id < n && coins[id] < i && prefixSum + coins[id] >= i){
                    prefixSum += coins[id];
                    id++;
                
            }else{ //coins[id] > i
                if(prefixSum >= i){
                    // i = prefixSum; // optimize
                    continue;
                }
                prefixSum += i;
                addedCoins++;
            }
           
        }
            
        return addedCoins;
        
    }
};