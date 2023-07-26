#include<iostream>
using namespace std;

void allPermutations(string s,int index,int length){

    // base case

    if(index == length){
        cout<<s<<endl;
        return;
    }
    
    for(int i=index;i<length;i++){
        swap(s[index],s[i]);
        allPermutations(s,index+1,length);

    }

    //a b c 


}


int main(){

    string str = "abc";

    int  length = str.length();

      allPermutations(str,0,length);


    return 0;
}