#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack<int> afterState(int number[],int size){
    stack<int> st;

    for(int i=0;i<size;i++){

        if(number[i] >=0){
            st.push(number[i]);
        }else{

            while(!st.empty() && st.top() > 0 && st.top() < abs(number[i])){
                st.pop();            
            }

            if(st.empty() || st.top() < 0){
                st.push(number[i]); // no collision will occur in this case
            }
            else if(!st.empty() && st.top() == abs(number[i])){
                st.pop();
            }

        }
        
    }
    return st;

   
}


int main(){

    int number;
    cin>>number;

    int arr[number];

    for(int i=0;i<number;i++){
        cin>>arr[i];
    }

    stack<int> st = afterState(arr,number);

    vector<int> answer(st.size());

    for(int i=st.size()-1;i>=0;i--){
        answer[i] = st.top();
        st.pop();
    }

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    
}