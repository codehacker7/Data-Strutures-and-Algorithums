#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int> &s,int t){
    if(s.empty()){
        s.push(t);
        return;
    }
    int t2 = s.top();
    s.pop();
    insertAtBottom(s,t);
    s.push(t2);
}   


void reverseStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int t = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,t);

}


int main(){


    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}