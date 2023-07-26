#include<iostream>
using namespace std;


int main(){


    string s = "ABCBCCBBB";
    int k =2,maxfreq=0,l=0,r=0,maxlen=0;

    int freq[26] = {0};

    int n = s.length();

    while(r<n){

        //check if we can include

        if( freq[s[r]-'A'] == maxfreq)  {

            freq[s[r]-'A']++;

            maxfreq = max(maxfreq,freq[s[r]-'A']);
            r++;
            maxlen = max(maxlen,r-l);


        } else if(   freq[s[r]-'A']  != maxfreq && k > 0   ){
            freq[s[r]-'A']++;

                maxfreq = max(maxfreq,freq[s[r]-'A']);

                k--;
                r++;
                maxlen = max(maxlen,r-l);
                 
    }
    else{

        //reduce size of window from left
        //element removed is maxfreq element

        if(  freq[s[l]-'A'] == maxfreq  ){
            freq[s[l]-'A'] --;
            maxfreq--;
            l++;
        }else{
                 freq[s[l]-'A'] --;
                 l++;
                 k++;


        }
    }
    }



    cout<<maxlen<<endl;




    return 0;
}