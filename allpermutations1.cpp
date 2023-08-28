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
 bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};

        for(int i = 0; i < s1.length(); i++){
            freq[s1[i] - 'a']++;
        }

        int n = s1.length();

        int i = 0;
        int j = 0;

        int freq2[26] = {0};

        while(j < s2.length()) {
            freq2[s2[j] - 'a']++;

            if (j - i + 1 == n) {
                int ct = 0;
                for(int k = 0; k < 26; k++) {
                    if (freq2[k] == freq[k]) {
                        ct++;
                    }
                }

                if (ct == 26) {
                    return true;
                } else {
                    freq2[s2[i] - 'a']--;
                    i++;
                }
            }
            

            j++;
        }

        return false;
    }


int main(){

    string str = "abc";

    int  length = str.length();

      allPermutations(str,0,length);


    return 0;
}