 int calculate(string s) {
        stack<int> st;
        int currnum = 0;
        char prevOperator = '+';

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                currnum = currnum * 10 + (ch - '0');
            }

            if (ch == '+' || ch == '-' || ch == '*' || ch == '/'  || i == s.length() - 1) {
                if (prevOperator == '+') {
                    st.push(currnum);
                } else if (prevOperator == '-') {
                    st.push(-currnum);
                } else if (prevOperator == '*') {
                    int number = st.top();
                    st.pop();
                    st.push(number * currnum);
                } else if (prevOperator == '/') {
                    int number = st.top();
                    st.pop();
                    st.push(number / currnum);
                }

                currnum = 0;
                prevOperator = ch;
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }