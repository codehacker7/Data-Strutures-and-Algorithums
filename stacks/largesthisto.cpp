int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> leftextension(n);

        stack<int> st;
        for(int i=0;i<n;i++){
              while(!st.empty() && heights[st.top()] >= heights[i]){
                  st.pop();
         }
         leftextension[i] = st.empty() ? 0 : st.top() + 1;
          st.push(i);
    }
           
    while (!st.empty()) {
        st.pop();
    }
   
    vector<int> rightextension(n);
   
    for(int i= n-1;i>=0;i--){
        
    while(!st.empty() && heights[st.top()] >= heights[i]){
          st.pop();
        }
        
        rightextension[i] = st.empty()? n-1: st.top() -1;
        st.push(i);
    }



  int maxarea = INT_MIN;
   
     for(int i = 0; i < n; i++) {
    int breadth = (rightextension[i] - leftextension[i] + 1) * heights[i];
    maxarea = max(maxarea, breadth);
}

return maxarea;

}