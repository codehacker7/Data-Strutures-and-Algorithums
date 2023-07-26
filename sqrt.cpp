#include<iostream>
using namespace std;


int mySqrt(int x) {

        if(x==0){
            return 0;
        }

       long long int low = 1;
       long long int high = x;
        int ans = 1;


        while(low <= high){

             long long int mid = (low+high)/2;
             

             if(  (mid * mid ) <= x   ) {
                ans = mid;
                 low = mid +1;
             }  else{
                 high = mid -1;
             }


        }

        return ans;

        
        
    }


double morePrecision(double integerpart,double check){

     double x =0.1;
            
        for(int i=1;i<=4;i++){

           
            while( (integerpart+x)*(integerpart+x) <= check){
                integerpart += x;
                cout<<"Integer "<<integerpart<<endl;
            }
               x = x/10;


        }

      

        return integerpart;


}



    



    int main(){

        int temp = mySqrt(35);

        double ans = morePrecision(temp,35);
        

        cout<<ans<<endl;


    }