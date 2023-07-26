#include<iostream>
using namespace std;

void allsubstrings(string s,int n,int index,string ouptput){

    if(index == n){
        cout<<ouptput<<endl;
        return;

    }

    allsubstrings(s,n,index+1,ouptput);
    ouptput+=s[index];
    allsubstrings(s,n,index+1,ouptput);
}

void allsubstrings2(char output[],int n,int index,int index2,string s){

    if(index == n){
        cout<<output<<endl;
        return;
    }

    allsubstrings2(output,n,index+1,index2,s);
    output[index2] = s[index];
    allsubstrings2(output,n,index+1,index2+1,s);
    output[index2] = '\0';
}

int main(){

    string s ="abc";
    string ouptput ="";
    int length = s.length();

    char output[length];
    for(int i=0;i<length;i++){
        output[i] = '\0';
    }

    // allsubstrings(s,length,0,ouptput);

    allsubstrings2(output,length,0,0,s);


    return 0;
}