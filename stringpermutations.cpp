#include<iostream>
using namespace std;


void allPermutations(string s,int index,int length){

    if(index == length){
        cout<<s<<endl;
        return;
    }

    for(int i=index;i<length;i++){
        swap(s[index],s[i]);
        allPermutations(s,index+1,length);
        swap(s[index],s[i]);
    }

}

int main(){
    string s = "abc";

    int n = s.length();

    allPermutations(s,0,n);


    return 0;
}