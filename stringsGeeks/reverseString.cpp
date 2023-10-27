class Solution {
public:
    string reverseWords(string s) {
        int i = s.length() - 1;
        string finalans = "";
        string temp = "";

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0) {
            if (s[i] != ' ') {
                temp = s[i] + temp;
            } else if (s[i] == ' ' && temp != "") {
                finalans = finalans + temp + ' ';
                temp = "";
            }
            i--;
        }

        if(!temp.empty()){
            finalans = finalans + temp;
        }else{
            finalans.pop_back(); // remove leading whitespaces
        }

        // Handle the last word if it's not followed by a space.
     
        return finalans;
    }
};
