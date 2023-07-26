#include<iostream>
using namespace std;


void towerOfHanoi(char src,char helper,char dest,int n){
    
    if(n ==0){
        return;
    }
    towerOfHanoi(src,dest,helper,n-1); 
    cout<<"Move disk "<<n<<"to rod "<<dest<<endl;
    towerOfHanoi(helper,src,dest,n-1);
}


int main(){

    int n =3;

    char src ='A';
    char helper = 'B';
    char dest = 'C';
    

    towerOfHanoi(src,helper,dest,n);



}