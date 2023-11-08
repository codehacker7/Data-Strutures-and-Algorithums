#include<iostream>
#include<vector>
using namespace std;


void multiply(int *arr,int &arrsize,int x){

	int carry =0;

	for(int i=0;i<arrsize;i++){
		int product = arr[i] * x + carry;
		arr[i] = product%10;//4
		carry = product/10;//2
}
    while(carry){

            arr[arrsize] = carry%10;
            carry = carry /10;
            arrsize++;
    }
}


int main() {

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
	

	return 0;

}
