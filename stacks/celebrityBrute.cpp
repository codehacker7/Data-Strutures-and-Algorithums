int celebrity(vector<vector<int>>& M, int n) {
    // m[c][i] == 0 for celebrity
    for (int c = 0; c < n; c++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (i != c && M[c][i] == 1) {
                flag = false;
            }
        }
       
         for (int i = 0; i < n; i++) {
            if (i != c && M[i][c] == 0) {
                flag = false;
            }
        }
        
        if (flag) {
            return c; // Found a potential celebrity
        }
    }
    
    return -1; // No celebrity found
}
