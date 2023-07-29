#include<iostream>
using namespace std;



int main(){

    int arr[] = {2,2,4,6,6,9,9};
    int target = 2;
    int ans = -1;
    int n = sizeof(arr)/sizeof(int);


    int lo = 0;
    int hi = n-1;
    while(lo <= hi){

        int mid = (lo+hi)/2;

        if(arr[mid] <= target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;

        }


    }
    cout<<lo<<endl;
    
    //upper bound > target

    // if you know upper bound to get last occ of target you can do upper bound - 1 also





}