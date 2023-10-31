
class Solution {
public:
    long long int solve(string s,int k){
         long long int n = s.length();
        long long int freq[26] = {0};
        
        long long int left = 0;
        long long int totalCount = 0;
        long long int currentUniqueChars = 0;
        long long int right =0;
        
            while(right < n){
       
            if (freq[s[right] - 'a'] == 0) {
                currentUniqueChars++;
            }
            freq[s[right] - 'a']++;

            while (currentUniqueChars > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    currentUniqueChars--;
                }
                left++;
            }

            totalCount += (right - left + 1);
            right++;
            
        }

        return totalCount;
        
    }

    long long int substrCount(string s, int k) {
        long long int ans = solve(s,k) - solve(s,k-1);
        return ans;
        
       
    }
};