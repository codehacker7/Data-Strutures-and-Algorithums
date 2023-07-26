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
    cout<<"Enter the number of pranthas";
    cin>>numberofpranthas;


    int numberofcooks;
     cout<<"Enter the number of cooks";
    cin>>numberofcooks;

    cout<<"Enter array elements";
    int arr[numberofcooks];
    for(int i=0;i<numberofcooks;i++){
        cin>>arr[i];
    }
    
    int ans =0;
    for(int i=0; i<=1e8;i++){

        if(isPossible(i,arr,numberofpranthas,numberofcooks)){
            ans =i;
            break;
        }


    }

    cout<<"Answer is "<<ans<<endl;


    return 0;



}