class Solution {
public:
    string intToRoman(int num) {

        vector<string> romanSymbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> romanValues = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";

                for (int i = 0; i < romanSymbols.size(); i++) {
                            while (num >= romanValues[i]) {
                                result += romanSymbols[i];
                                num -= romanValues[i];

                            }
                
                
             }

             return result;

    }
};