//s2->s1

//cant change string s2

int editDistance(string s1,int n,string s2,int m,int dp[][100]){

    //base case

    if(n == 0) return dp[n][m] = m;
    if(m == 0) return dp[n][m] = n;


    //recursive case
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = editDistance(s1,n-1,s2,m-1);
    }else{
        return dp[n][m] =  
        min(
            editDistance(s1,n-1,s2,m),
            min(
                editDistance(s1,n,s2,m-1),
                editDistance(s1,n-1,s2,m-1)
            )
        )+1;
    }

}

int bottomUp(string s1,string s2){

    int m = s1.size();
    int n = s2.size();

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){

            if(i == 0 && j==0 ){
                dp[i][j] = 0;
            }

            else if(i == 0){
                dp[i][j] = j;
            }

             else if(j == 0){
                dp[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            
            else{
             dp[i][j] = min(
                    editDistance(s1,n-1,s2,m),
                    min(
                        editDistance(s1,n,s2,m-1),
                        editDistance(s1,n-1,s2,m-1)
                    )
                )+1;
            }




        }
    }
}