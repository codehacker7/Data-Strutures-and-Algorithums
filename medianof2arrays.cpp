#include<iostream>
#include<climits>
using namespace std;

float median(int arr1[],int arr2[],int n1, int n2){


    if(n1 > n2){

        return median(arr2,arr1,n2,n1);

    }

    int low =0;
    int high = n1;

    int m = (n1+n2)/2;

    while(low <= high){

        //lets assume for pos1 till middle element , the elements which are lying are from first array
        int pos1 = (low+high)/2;

        int pos2 = m - pos1;



            //LH                        //RH
    //    1 2 13               |        6 8
                        //     5th     12 13
    //  4     7


    int l1 = (pos1 ==0)? -1 : arr1[pos1-1];
    int l2 =  (pos2 == 0)? -1 : arr2[pos2-1];


    int r1 = (pos1 == n1)? INT_MAX : arr1[pos1];
    int r2 = (pos2 == n2)? INT_MAX : arr2[pos2];


    if(l1 <= r2 && l2 <= r1){

        //we can calculate the median 
        //now we need to see whether the number of elements is even or odd

        if((n1+n2)%2==0){
            //this means number of elements is even
            float median = (max(l1,l2) + min(r1,r2))/2.0;

            return median;
        }
        else{
            return max(l1,l2);
        }


    }

    else if(l1 > r2){
        high = pos1 -1 ;

    }
    else{
        low = pos1 +1;

    }


    }

    return 0.0;



}



int main(){

int arr1[] = {1,2,3,5};
int arr2[] = {4,6,7,9,11,13};

int n1 = sizeof(arr1)/sizeof(int), n2 = sizeof(arr2)/sizeof(int);


cout<<median(arr1,arr2,n1,n2)<<endl;






}