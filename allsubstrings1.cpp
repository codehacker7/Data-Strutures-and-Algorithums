#include <iostream>
using namespace std;


void allSubstrings(string s, int index,string output,int length){

    if(index == length){
        cout<<output<<endl;
        return;
    }

    allSubstrings(s,index+1,output,length);
    output += s[index];
    allSubstrings(s,index+1,output,length);


}


int main(){


    string s ="abc";
    allSubstrings(s,0,"",s.length());


}