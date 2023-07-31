#include<iostream>
using namespace std;

bool isSorted(int *arr,int size,int index){

	if(index == size - 1){
		return true;
	}

	if(arr[index] > arr[index+1]){
		return false;
	}

	bool ans = isSorted(arr,size,index+1);

	return ans;

}



int main() {
	int size;
	cin>>size;

	int arr[size];

	for(int i=0;i<size;i++){
		cin >> arr[i];
	}

	bool ans = isSorted(arr,size,0);


	if(ans == 1){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}




	return 0;
}