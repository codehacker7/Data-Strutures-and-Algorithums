class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l =0;
        int r= 1;
        int n = prices.size();

        int maxP = 0;

        while(r < n){

            if(prices[l] > prices[r]){
                l = r;
            }else{
                maxP = max(maxP,prices[r]-prices[l]);
            }
            r++;

        }
        return maxP;
        
    }
};\