#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    
    for(int i=0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
        }
    }
}
}

void bubbleSortRec(int arr[], int n,int i){
    
        if(i == n-1){
            return;
        }
      
      
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
        }
    }
    bubbleSortRec(arr,n,i+1);

}


void bubbleSortPureRec(int arr[], int n,int i,int j){
    
        if(i == n-1){
            return;
        }

        if(j == n-1){
            j=0;
            i = i+1;
        }
      
             if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
        }
    
    bubbleSortPureRec(arr,n,i,j+1);

}






int main(){

    int arr[] = {6,8,3,5,2,1};

    int size = sizeof(arr)/sizeof(arr[0]);


    bubbleSortPureRec(arr,size,0,0);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}