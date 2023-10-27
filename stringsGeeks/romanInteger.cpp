class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int prevValue = 0;  // Initialize a variable to keep track of the previous value

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            int value;

            switch (ch) {
                case 'I':
                    value = 1;
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'X':
                    value = 10;
                    break;
                case 'L':
                    value = 50;
                    break;
                case 'C':
                    value = 100;
                    break;
                case 'D':
                    value = 500;
                    break;
                case 'M':
                    value = 1000;
                    break;
                default:
                    return -1;  // Invalid character in the input
            }

            if (value > prevValue) {
                ans += (value -  2*prevValue); //very important
            } else {
                ans += value;  // Otherwise, add it to the result
            }

            prevValue = value;  // Update the previous value
        }

        return ans;
    }
};
