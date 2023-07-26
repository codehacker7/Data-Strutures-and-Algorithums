#include<iostream>
using namespace std;


void allPermutations(char s[],int index,int n){

    if(index == n){
        cout<<s<<endl;
        return;
    }
   
    // allPermutations(s,index+1);
 
    
    // swap(s[index],s[index+1]);
    // allPermutations(s,index+1);
  
  
    // swap(s[index],s[index+2]);
    // allPermutations(s,index+1);

    for(int i=index;i<n;i++){
        swap(s[i],s[index]);
        allPermutations(s,index+1,n);
        swap(s[i],s[index]);

    }

    

}

int length(char str[]){

    int i=0;
    while(str[i]!='\0'){
            i++;
    }
    return i;
}   


int main(){

    char str[] = "abc";
    int n = length(str);
    allPermutations(str,0,n);


    return 0;
}