class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.length();
        vector<int> freq(128, 0); // Use a vector for frequency

        int maxLen = 0;

        while (r < n) {
            char ch = s[r];

            if (freq[ch] == 0) {
                freq[ch]++;
                maxLen = max(maxLen, r - l + 1);
                r++;
            } else {
                char ch1 = s[l];
                freq[ch1]--;
                l++;
            }
        }

        return maxLen;
    }
};
