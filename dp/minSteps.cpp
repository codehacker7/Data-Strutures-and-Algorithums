#include<iostream>
using namespace std;

int topDown(int n,int *dp){

    if(n == 1) {
     dp[n]=0; //Returnn se phele Store
     return 0;
    }
    if(dp[n] != -1){ //Calculate se pehle check
        return dp[n];
    }
    int op1,op2,op3;
    op1 = op2=op3 = INT_MAX;

    op1 = topDown(n-1,dp);

    if(n%2 == 0){
        op2 = topDown(n/2,dp);
    }
    if(n%3 == 0){
          op3 = topDown(n/3,dp);
    }

   int x =  min(op1,min(op2,op3))+1;
   dp[n] = x;
   return x;


}


int bottomUp(int n) {
	vector<int> dp(n + 1);

	dp[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		int op1, op2, op3;
		op1 = op2 = op3 = INT_MAX;

		op1 = dp[i - 1];
		if (i % 2 == 0) op2 = dp[i / 2];
		if (i % 3 == 0) op3 = dp[i / 3];
		dp[i] = min(op1, min(op2, op3)) + 1;
	}

	for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
	cout << endl;
	return dp[n];

}

int main(){

    int n;
    cin>>n;
    int dp[1000];

    for(int i=0;i<1000;i++){
        dp[i] = -1;
    }

    cout << topDown(n,dp)<<endl;
}