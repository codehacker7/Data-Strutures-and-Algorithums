#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        st.push(i);
    }
    
    while (st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if (M[a][b] == 1) {
            st.push(b);
        }
        else {
            st.push(a);
        }
    }
    
    int pc = st.top();
    
    for (int i = 0; i < n; i++) {
        if (i != pc && (M[i][pc] == 0 || M[pc][i] == 1)) {
            return -1;
        }
    }
    
    return pc;
}

int main() {
    
    return 0;
}
