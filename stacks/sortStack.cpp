#include <iostream>
#include <stack>

using namespace std;

void helper(stack<int> &s, int elem) {
    if (s.empty() || elem <= s.top()) {
        s.push(elem);
        return;
    }

    int t = s.top();
    s.pop();
    helper(s, elem);
    s.push(t);
}



void sortStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }

    int t = s.top();
    s.pop();
    sortStack(s);
    helper(s, t);
}

int main(){

    stack<int> st;
    st.push(3);st.push(5);st.push(1);st.push(2);st.push(4);
   
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();        
    }
}