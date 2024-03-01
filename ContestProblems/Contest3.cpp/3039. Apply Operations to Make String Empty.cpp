class Solution {
public:
    string lastNonEmptyString(string s) {
        
        map<char,int> mp;
        int maxFreq = 0;
        for(int i =0;i<s.length();i++){
            char ch = s[i];
            mp[ch]++;
            maxFreq = max(maxFreq,mp[ch]);
        }
         
        map<char,int> mp1;
        string ans = "";
        for(int i = 0;i < s.length();i++){
             char ch = s[i];
            mp1[ch]++;
            if(mp1[ch] == maxFreq){
                ans = ans + ch;
            }
        }
        return ans;
         
    }
};