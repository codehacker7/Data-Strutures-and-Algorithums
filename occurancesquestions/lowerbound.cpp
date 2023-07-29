#include<iostream>
using namespace std;

//lower bound is greater than or equal to target

int main(){

    int arr[] = {1,2,4,4,6,9,9};
    int target = 3;
    int n = sizeof(arr)/sizeof(int);


    int lo = 0;
    int hi = n-1;
    while(lo <= hi){

        int mid = (lo+hi)/2;

        if(arr[mid]>=target){
            hi = mid-1;
     }
        else{
            lo = mid +1;

        }


    }


   cout<<lo<<endl;
    





}