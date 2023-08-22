  #include<iostream>
  #include<vector>
  #include<stack>
  using namespace std;

  
 int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && (heights[st.top()] >= heights[i])) {
            left[i] = st.top();
            st.pop();
        }
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && (heights[st.top()] >= heights[i])) {
            st.pop();
        }
        right[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }

    int max_area = 0;
    for (int i = 0; i < n; i++) {
        int new_area = (right[i] - left[i] + 1) * heights[i];
        max_area = max(max_area, new_area);
    }

    return max_area;
}