#include<iostream>
using namespace std;

bool isPossible(int giventime,int arr[],int totalpranthasOrdered,int size){

        int numberofpranthas = 0;
        int timetaken =0;

        for(int i=0;i<size;i++){

            int count = 1;
            int time = 0;

           while(time <= giventime){

                if( time + (count* arr[i]) <= giventime){
                   

                    time = time + (count*arr[i]);
                     numberofpranthas++;
                    count++;


                }
                else{
                    break;
                }

           }

       

  }

  if(numberofpranthas < totalpranthasOrdered){
    return false;
  }
  else{
    return true;
  }
            

}







int main(){

    int numberofpranthas;
    cin>>numberofpranthas;


    int numberofcooks;
    cin>>numberofcooks;

    int arr[numberofcooks];
    for(int i=0;i<numberofcooks;i++){
        cin>>arr[i];
    }
    
    int ans =0;
	int low = 1; 
	int high = 1e8;
	// the above below applies the concept of bianry search
	while(low<=high){

		int mid = low + (high - low)/2;
		
		if(isPossible(mid,arr,numberofpranthas,numberofcooks)){
			high = mid -1;
		}
		else{
			low = mid +1;
		}


	}

	cout<<low<<endl;

	// this code applies the concept of linear search

    // for(int i=0; i<=1e8;i++){

    //     if(isPossible(i,arr,numberofpranthas,numberofcooks)){
    //         ans =i;
    //         break;
    //     }


    // }

    // cout<<ans<<endl;


    return 0;

