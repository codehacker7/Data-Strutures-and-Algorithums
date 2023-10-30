int kDistinctChars(int k, string &str)
{
    // Write your code here
    int l=0;
    int r=0;
    int maxLen =0;
    int freq[26] = {0};
    int n = str.length();
    int uniquechar =0;

    while(r < n){

        char ch = str[r];

        if(freq[ch - 'a'] == 0){
            uniquechar++;
        }
        r++;
        freq[ch - 'a']++;

        while(uniquechar > k){
            char ch1 = str[l];
            if(freq[ch1 - 'a'] == 1){
                uniquechar--;
            }
            freq[ch1 - 'a']--;
            l++;

        }

        if(uniquechar <= k){
            maxLen = max(maxLen,r-l);
        }


    }

    return maxLen;
}
