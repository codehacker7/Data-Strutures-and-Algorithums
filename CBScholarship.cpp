#include<iostream>
using namespace std;

bool isPossible(long long mid,long long m,long long x,long long y,int n){


    return ((M - mid*x) + (n - mid)*y) >= 0;
}



int main(){

    // int numberofstudents = 5; //n
    // int numberofcoupns = 10;  //m
    // int requiredcoups = 2;  //x
    // int badstudents = 1;   //y

    long long int n,m,x,y;
    cin>>n>>m>>x>>y;

    int lo =1 , hi = n;
    int ans = 0;

    while(lo <= hi){


        long long int mid = (lo + hi)/2;

        if(isPossible(mid,m,x,y,n)){
            ans = mid;
            lo = mid +1;
        }
        else{
            hi = mid -1;
        }
    }




    return 0;

}