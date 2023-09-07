#include<iostream>
using namespace std;

int multiply(int *arr,int arrsize,int val){
    int carry = 0;

    for(int i=0;i<arrsize;i++){
        int product = arr[i] * val + carry;
        carry = product/10;
        arr[i] = product%10;  
    }
    while(carry){
        arr[arrsize] = carry;
        carry = carry/10;
        arrsize++;
    }
}


int main(){

    cout<<"Enter the number: "<<endl;
    int number;
    cin>>number;

    int arr[100000];
    arr[0] = 1;
    int arrsize = 1;

    for(int i=2;i<=number;i++){
        multiply(arr,arrsize,i);
    }
    for(int i = arrsize-1;i>=0;i--){
		cout<<arr[i];
	}
	cout<<endl;

}