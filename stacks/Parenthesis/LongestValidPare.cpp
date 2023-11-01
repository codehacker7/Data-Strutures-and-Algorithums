//this is inspired by valid parenthesis logic

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxi = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (!st.empty() && st.top() >= 0 && s[st.top()] == '(' && ch == ')') {
                st.pop();
            } else {
                st.push(i);
            }
        }

        // Now, the stack contains indices of invalid parentheses.
        int end = s.length();
        while (!st.empty()) {
            int start = st.top();
            st.pop();
            maxi = max(maxi, end - start - 1);  
            end = start; 
        }
        //to account for the lastpart
        return max(maxi, end); // Return the maximum of maxi and end.
    }
};
