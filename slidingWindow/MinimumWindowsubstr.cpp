class Solution {
public:
    string minWindow(string s, string t) {
        int freqT[128] = {0};
        int freqS[128] = {0};

        for (int i = 0; i < t.length(); i++) {
            char ch = t[i];
            freqT[ch]++; // Use the character itself as an index
        }

        int l = 0;
        int r = 0;
        int size = INT_MAX;
        int n = s.length();
        string ans = "";
        bool check = true;

        while (r < n) {
            char ch = s[r];
            freqS[ch]++;

            for (int i = 0; i < 128; i++) {
                if (freqT[i] != 0 && freqS[i] < freqT[i]) {
                    check = false;
                    break;
                }
            }

            while (l <= r && check) {
                int currentsize = r - l + 1;
                if (currentsize < size) {
                    size = currentsize; // Update the minimum size
                    ans = s.substr(l, r - l + 1);
                }
                char ch1 = s[l];

                freqS[ch1]--;

                if (freqT[ch1] > 0 && freqS[ch1] < freqT[ch1]) {
                    check = false;
                }
                l++;
            }

            r++;
            check = true; // Reset check after finding a valid substring
        }

        return ans;
    }
};
