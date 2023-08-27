#include<iostream>
using namespace std;

int upperbound(int *arr,int target,int size){
	int low =0;
	int high = size - 1;
	int ans = -1;
	while(low <= high){

		int mid = (low+high)/2;

		if(arr[mid] == target){
			ans = mid;
			low = mid +1;

		} else if(arr[mid] > target){
				high = mid - 1;
		}
		else{
			low = mid+1;
		}
	}

	return ans;

	
}


int lowerbound(int *arr,int target,int size){


	int low =0;
	int high = size - 1;
	int ans = -1;
	while(low <= high){

		int mid = (low+high)/2;

		if(arr[mid]>=target){
			high = mid -1;
			if(arr[mid] == target){
				ans = mid;
			}

		}
		else{
			low = mid+1;
		}
	}

	return ans;


}


int main() {
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int numberofqueries;
	cin>>numberofqueries;


	while(numberofqueries--){

		int target;
		cin>>target;


		int lower = lowerbound(arr,target,n);
		int upper = upperbound(arr,target,n);
		cout<<lower<<" "<<upper;
		cout<<endl;



	}



	return 0;
}