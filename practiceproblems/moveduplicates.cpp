#include<iostream>
using namespace std;

int main(){

        int arr[] = {1,1,1,2,2,3,4,5};

        int length = sizeof(arr)/sizeof(int);

        int newarr[length];

        int counter = length -1;
        int frontcounter = 0;

        for(int i=0;i<length;i++){
            int count =0;
            for(int j = i+1;j<length;j++){
                if(arr[i] == arr[j]){
                    count++;
                }
            }
            if(count !=0){
                int temp = i;
                for(int k=0;k<=count;k++ ) {
                    newarr[counter] = arr[temp++];
                    counter--;
                }
            } else if(count == 0){
                int temp = i;
                newarr[frontcounter] = arr[temp];
                frontcounter++;
            }
            i = i+ count;
        }


        for(int i=0;i<length;i++){
            cout<<newarr[i]<<" ";
        }

    }

