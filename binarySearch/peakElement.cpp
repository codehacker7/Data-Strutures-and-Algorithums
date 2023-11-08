#include<iostream>
#include<vector>
using namespace std;
int main () {



		int numberofelements;
		cin>>numberofelements;

		vector<int> nums(numberofelements);

		for(int i=0;i<nums.size();i++){
			cin>>nums[i];
		}

	  int n = nums.size();

        if(n == 1){
            return 0;
        }

        int low = 0;
        int high = n-1;

        while(low <= high){

            int mid = (low + high)/2;

            if(((mid +1) < n) && nums[mid] <  nums[mid+1] ){
                low = mid +1;
            }
            else{
                high = mid -1 ;
            }


        }

		cout<<low<<endl;



	return 0;
}