#include<iostream>
using namespace std;

int main(){



    string s = "ABCBCCBBB";
    int k = 2;
    int maxfreq =0 , l =0,r =0,maxlen;
    int freq[26] = {};

    int n = s.length();

    while(r < n){
        //check if we can include
        if(   freq[ s[r] - 'A'] == maxfreq ){

                 freq[ s[r] - 'A']++;
                 maxfreq = max(maxfreq,freq[s[r]-'A']);
                 r++;
                maxLen = max(maxLen,r-l);

        }
        else if( freq[ s[r] - 'A'] != maxfreq  && k>0){

         freq[ s[r] - 'A']++;
          maxfreq = max(maxfreq,freq[s[r]-'A']);
          k--;
          r++;
          maxLen = max(maxLen,r-l);
    }
    else {
        //reduce size of window

        //element reduced is max freq element

        if(  freq[s[l] - 'A'] == maxfreq  ){


            freq[s[l] - 'A']--;
            maxfreq--;
            l++;
        } else{
                  freq[s[l] - 'A']--;
                  l++;
                  k++;


        }

    }
    }

    cout<<maxLen;




    return 0;

}