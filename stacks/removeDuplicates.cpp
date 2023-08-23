#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;

string removeDuplicates(string s){

    stack<char> st;
    //abbcc

    for(int i=0;i<s.length();i++){

        if(st.empty()){
            st.push(s[i]);
        }
        else if(st.top() == s[i]){
            continue;
        } else{
            st.push(s[i]);
        }
    }

    string str = "";
    while(!st.empty()){
        str = str + st.top();
        st.pop();
    }

    int i=0;
    int j = str.length()-1;

    while(i < j){
        swap(str[i],str[j]);
        i++;
        j--;
    }

    return str;


}


int main(){
    string s;
    cin>>s;

    sort(s.begin(),s.end());

    string str = removeDuplicates(s);
    cout<<str<<endl;

}