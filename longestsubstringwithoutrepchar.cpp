#include<iostream>
using namespace std;


int main(){

    string s = "abcadcbb";

    int n = s.length();


    int l=0,r=0,maxlen =0;


    int freq[128] = {};

    while(r<n){

        //check whether you can include this char or nor

        if( freq[s[r] - '\0'] == 0    ){

            // can include
            freq[ s[r] - '\0']++;

            r++;
            maxlen = max(r-l,maxlen);
            
        }else{

            freq[   s[l] -'\0']--;
            l++;


        }


    }

    cout<<maxlen<<endl;





    return 0;
}