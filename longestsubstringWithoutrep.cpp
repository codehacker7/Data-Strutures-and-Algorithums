#include<iostream>
using namespace std;


int main(){

    string s = "abcabcbb";

    int freq[128] = {};


    int l =0;int r=0;

    int maxLen =0;

    int n = s.length();


    while(r < n){

        if(freq[ s[r] - '\0'] == 0){
            freq[ s[r] - '\0']++;
            maxLen = max(maxLen,r-l);
            r++;
        }
        else {
           freq[ s[r] - '\0']--;
           l++;
        }



    }



    return 0;

}