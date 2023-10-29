lass Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> vec1(num1.size());
        vector<int> vec2(num2.size());

        for (int i = 0; i < num1.size(); i++) {
            char ch = num1[i];
            int number = ch - '0';
            vec1[i] = number;
        }
        for (int i = 0; i < num2.size(); i++) {  // Corrected to use num2.size()
            char ch = num2[i];
            int number = ch - '0';
            vec2[i] = number;
        }

        int i = 0;
        int j = 0;
        int carry = 0;
        int sum = 0;
        string ans = "";

        while (i < vec1.size() || j < vec2.size()) {
            int digit1 = (i < vec1.size() ? vec1[i] : 0);
            int digit2 = (j < vec2.size() ? vec2[j] : 0);
            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            ans = to_string(sum % 10) + ans;
            i++;
            j++;
        }

        while (carry) {
            ans = to_string(carry) + ans;
            carry = carry / 10;
        }

        return ans;
    }
};
