public:
    int longestKSubstr(string s, int k) {
    // your code here
    int l =0;
    int r =0;
    int maxLen =-1;
    int freq[26] = {0};
    int n = s.length();
    int uniquechar = 0;
    
    while(r < n){
        char ch = s[r];
        if(freq[ch - 'a'] == 0 && uniquechar <= k){
            freq[ch - 'a']++;
            r++;
            uniquechar++;
        } else if(freq[ch - 'a'] !=0){
             freq[ch - 'a']++;
             r++;
            
        }
        
        while(uniquechar > k){
             char ch1 = s[l];
             
             freq[ch1 - 'a']--;
             if(freq[ch1 - 'a'] == 0){
                 uniquechar--;
             }
             l++;
        }
        
        if(uniquechar == k){
            maxLen = max(maxLen,r-l);
        }
        
        
    }
    
    return maxLen;
    
    }