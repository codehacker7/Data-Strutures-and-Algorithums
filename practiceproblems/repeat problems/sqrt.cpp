#include<iostream>
using namespace std;


void decimalPart(double ans,double number){

    double decimal = 0.1;

    
    for(int i=0;i<1000;i++){

        while(true){
            double val = ans + decimal;
         

            if( ( val * val) <= number ){
                ans = ans + decimal;
                val = ans;
            }else{
                break;
            }

        }

       

        decimal = decimal/10;
    }

    cout<<"sqrt of integer is "<<ans<<endl;

}

void sqrt(int number){
    int ans = -1;
    for(int i=1;i<=number;i++){
        if( (i*i) <= number){
            ans = i;
        }
        else{
            break;
        }
    }

   decimalPart(ans,number);

}

int main(){

    int number;
    cout<<"Enter the number: "<<endl;
    cin>>number;

     sqrt(number);

   
}