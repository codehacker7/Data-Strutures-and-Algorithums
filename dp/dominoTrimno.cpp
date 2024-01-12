class Solution {
public:
    int numTilings(int n) {

        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        const int MOD = 1e9 + 7;

        long long dp[n+1];
        dp[0] = 0;
        dp[1] = 1;  // there is just 1 way to tile this if the board is 2*1;
        dp[2] = 2;  // there are 2 ways to tile if the board is 2*2
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            dp[i] = (2 * dp[i-1] % MOD + dp[i-3]) % MOD;
        }
        return static_cast<int>(dp[n]);
    }
};
