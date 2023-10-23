#include<iostream>
using namespace std;


void printnumbers(string n,bool firstDigit,string s){

    if(s.length() > n.length()){
        return;
    }

    if(firstDigit == false){
        if(stoi(s) < stoi(n)){
          cout<<s<<" ";
        }
    }

    int start = firstDigit?1:0;

    for(int i=start;i<10;i++){
        char num = i+'0';
        s = s+num;
        printnumbers(n,false,s);
        s = s.substr(0,s.length()-1);
    }


}

int main(){
    printnumbers("22",true,"");
}