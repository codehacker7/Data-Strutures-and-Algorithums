class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) {
            return 0; // An empty needle is always found at index 0.
        }

        int l = 0;
        int r = 0;
        string temp = "";
        int ans = -1;

        if (haystack == needle) {
            return l; 
        }

        while (r < n) {
            char ch = haystack[r];
             temp += ch;
            if (temp.length() == m) {
                if (temp == needle) {
                    return l; // Found the needle, return the starting index.
                } else {
                    temp = temp.substr(1);
                    l++;
                }
            }

           
            r++;
        }
      
        return ans;
    }
};
