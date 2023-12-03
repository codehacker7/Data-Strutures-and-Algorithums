#include<iostream>
using namespace std;

int lis_len =0;
vector<int> ans;

void LIStopDown(int *a,vector<int> &v,int lv = INT_MAX,int n){

    if(n == 0){
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<<" ";
        // }
        // cout<<endl;

        if(v.size() > lis_len){
            lis_len = v.size();
            ans = v;
        }
        return;
    }

    if(a[n-1] < lv){

        v.push_back(a[n-1]);
        topDown(a,v,a[n-1],n-1);
        v.pop_back();

    }

     topDown(a,v,lv,n-1);

}

// THIS METHODS PRINTS ALL LIS

void printLIS(int *a,int n,int len,int *dp,vector<int> &x,int lv = INT_MAX){
    //base case

    if(n == 0){
        if(len == 0){
            for(int i=x.size()-1;i>=0;i--){
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    //rec case

    if(dp[n-1] == len && a[n-1] < lv){
        x.push_back(a[n-1]);
        printLIS(a,n-1,len-1,dp,x,a[n-1]);
        x.pop_back();

    }
      printLIS(a,n-1,len,dp,x,lv);
}

int lis2(int *a,int n){

    int dp[10000];
    memset(dp,1,sizeof(dp)); /// fill 1 since everyone has atleast 1 length Longest Increasing Subsequence
   
   
     for(int j=1;j<n;j++){

        for(int k=j-1;k>=0;k--){

            if(a[j] > a[k]){ // this is checking if we can add longest inc element or not at the end of LIS
                dp[j] = max(dp[j],dp[k]+1);
             }
        }

    }

    int mx =0; //this is length of longest LIS

    for(int i=0;i<n;i++){

        if(dp[i] > mx){

            mx = dp[i];

        }
    }

    return mx;

}

int main(){



    return 0;
}