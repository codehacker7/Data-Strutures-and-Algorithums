
class Solution{
  public:
   void allsubstrings(string s, vector<string> &subseq, int index, int n, string ans) {
    if (index == n) {
        subseq.push_back(ans);
        return;
    }
    allsubstrings(s, subseq, index + 1, n, ans);
    ans += s[index];
    allsubstrings(s, subseq, index + 1, n, ans);
}

bool checkPalindrome(string temp) {
    int l = 0;
    int r = temp.length() - 1;
    while (l < r) {
        if (temp[l] != temp[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int minimumNumberOfDeletions(string S) {
    int n = S.length();
    vector<string> subseq;
    allsubstrings(S, subseq, 0, n, "");

    int maxLen = INT_MIN;
    for (int i = 0; i < subseq.size(); i++) { // Changed from subseq.length() to subseq.size()
        string temp = subseq[i];
        if (checkPalindrome(temp)) {
            maxLen = max(maxLen, static_cast<int>(temp.length()));
        }
    }

    return n - maxLen; // Changed from abs(maxLen - S.length()) to (n - maxLen)
}
};