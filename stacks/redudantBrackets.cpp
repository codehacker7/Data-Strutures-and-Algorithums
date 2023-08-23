#include <bits/stdc++.h>
#include <stack> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;


    for(int i=0;i<s.length();i++){

        char ch = s[i];

        if (ch == '(' || ch=='+' || ch=='-' || ch=='*' || ch=='/') {
          st.push(ch);
        }
        else{

            if(ch==')'){
              bool isRedudant = true;
              
                

              while(st.top()!='('){
                    if(st.top() =='-' || st.top() == '+' || st.top() =='*' || st.top() =='/'){
                        isRedudant = false;
                    }
                    st.pop();
                  
                }

                if(isRedudant){
                  return true;
                }
              
                st.pop();
                
          
              }
            }
            
        }

        return false;


            
    }





