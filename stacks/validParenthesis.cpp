#include<iostream>
#include<stack>

using namespace std;

bool isValid(string str){

    stack<char> st;

    for(int i=0;i<str.length();i++){
        
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            st.push(str[i]);
        }
        else if(!st.empty() && st.top() == '(' && str[i] == ')'){
            st.pop();
            continue;
        }
        else if(!st.empty() && st.top() == '{' && str[i] == '}'){
    
            st.pop();
            continue;
        }
        else if(!st.empty() && st.top() == '[' && str[i] == ']'){
            st.pop();
            continue;
        }else{
            return false;
        }
    }

    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
    

}


int main(){

    string str ;
    cin>>str;


    if(isValid(str)){
        cout<<"true"<<endl;
    }else{
         cout<<"false"<<endl;
    }




}