class Solution {
public:
    bool checkIfPangram(string sentence) {

        int freq[26] = {0};
        int upperfreq[26] ={0};
        
        for(int i=0;i<sentence.size();i++){

            char ch = sentence[i];

            if('a' <= ch && ch <='z'){
                freq[ch-'a']++;
            }else{
                upperfreq[ch-'A']++;
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i] == 0 && upperfreq[i] == 0){
                return false;
            }
        }
        return true;
    }
};