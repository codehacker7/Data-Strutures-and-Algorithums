#include<iostream>
using namespace std;

int knapsack(int *price,int *weight,int n,int cap,int dp[][100]){

    if(n == 0 || cap == 0){
        
        return dp[n][cap] = 0;
    }

    if(dp[n][cap] != -1){
        return dp[n][cap];
    }


    int op1,op2 = INT_MIN;

    if(cap >= weight[n-1]){

         op1 = price[n-1] + knapsack(price,weight,n-1,cap - weight[n-1]);
    }

    op2 = knapsack(price,weight,n-1);

    return dp[n][cap] = max(op1,op2);


}


int bottomUp(int *price,int *weight,int n,int cap){
    int dp[][100] = {0};

    // not starting from 0,0 since if number of items are 0 or if capacity is 0 then you cannot really afford to put anything because either you do not have number of items or the capacity is 0
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++){

            int op1,op2 = INT_MIN;
            
            if(j >= weight[i-1]){ // that means bag does have capacity so steal 

                op1 = weight[i-1] + dp[i-1][cap-weight[i-1]];

            }

            op2 = dp[i-1][cap];
            dp[n][cap] = max(op1,op2);
        
        
        
        }
    }
    return dp[n][cap];
}


int main() {

	int price[] = {2, 3, 3, 5};
	int weight[] = {1, 2, 4, 3};
	int cap = 5;

	int dp[100][100];
	memset(dp, -1, sizeof dp);

	cout << knapsack(price, weight, 4, 5, dp) << endl;
	cout << bottomUp(price, weight, 4, 5) << endl;

	return 0;
}