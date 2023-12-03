#include<iostream>
using namespace std;


int topDown(int *a,int l,int r,int day,int dp[][100]){

    if(l > r){
        dp[l][r] = 0;
        return 0;
    }

    if(dp[l][r] != -1){
        return dp[l][r];
    }


    int op1 = a[l] *day + bottomUp(a,l+1,r,day+1);
    int op2 = a[r] *day + bottomUp(a,l,r-1,day+1);

    dp[l][r] = max(op1,op2);
    return max(op1,op2);

}


int bottomUp(int *a,int n){
   
   int dp[100][100] = {0};

    for(int i=0;i<n;i++){
        dp[i][i] = a[i] * n; // at this stage the day is equal to n because all the bottles are sold
    }

    for(int l=n-2;l>=0;l--){
        for(int r=l+1;r<n;r++){
            int day = N-r+l;
            int op1 = a[l] * day + dp[l+1][r];
            int op2 = a[r] * day + dp[l][r-1];

            dp[l][r] = max(op1,op2);
        }
    }

    return dp[0][n-1];



}


int main(){

  	int a[] = {2, 3, 5, 1, 4};
	int n = sizeof(a) / sizeof(int);
	int dp[100][100];

	memset(dp, -1, sizeof dp);

	cout << topDown(a, 0, n - 1, 1) << endl;


    return 0;
}