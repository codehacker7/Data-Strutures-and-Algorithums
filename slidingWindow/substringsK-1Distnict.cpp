//https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1
class Solution {
public:
    int countOfSubstrings(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.length();
        int freq[26] = {0};
        int uniqueCharcount = 0;
        int count = 0;

        while (r < n) {
            char ch = s[r];

            if (freq[ch - 'a'] == 0) {
                uniqueCharcount++;
            }
            freq[ch - 'a']++;

            if (r - l + 1 == k) { // This is a substring which actually has length equal to k

                if (uniqueCharcount == k-1) {
                    count++;
                } 
                    
                 char ch1 = s[l];
                freq[ch1 - 'a']--;

                if (freq[ch1 - 'a'] == 0) {
                    uniqueCharcount--;
                }
                l++;
            }

            if (r - l + 1 > k) {
                char ch1 = s[l];
                freq[ch1 - 'a']--;

                if (freq[ch1 - 'a'] == 0) {
                    uniqueCharcount--;
                }
                l++;
            }
            r++;
        }

        return count;
    }
};