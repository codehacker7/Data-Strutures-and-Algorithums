#include<iostream>
#include<stack>
using namespace std;

bool isEqual(string s,string t){

    stack<char> st;


    for(int i=0;i<s.length();i++){

        if(s[i] != '#'){
            st.push(s[i]);
        }
        else {
            st.pop();
        }

    }

    string ans = "";
    string ans1= "";

    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }

    for(int i=0;i<t.length();i++){

        if(t[i] != '#'){
            st.push(t[i]);
        }
        else {
            st.pop();
        }

    }

       while(!st.empty()){
        ans1 = ans1 + st.top();
        st.pop();
    }

    if(ans.length() != ans1.length()){
        return false;
    }

    else{

        for(int i=0;i<ans.length();i++){
            if(ans[i] != ans1[i]){
                return false;
            }
        }
    }

    return true;


}


int main(){

    string S,T;
    cin>>S>>T;

    if(isEqual(S,T)){
        cout<<"true";
    }else{
        cout<<"false";
    }


    return 0;
}