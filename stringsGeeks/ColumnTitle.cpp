class Solution {
public:
    string convertToTitle(int columnNumber) {

        string ans = "";
        while(columnNumber > 0){
            int rem = (columnNumber - 1)%26;

            ans = static_cast<char>(rem + 'A') +  ans;

            columnNumber = (columnNumber - 1)/26;

        }
        return ans;
        
    }
};