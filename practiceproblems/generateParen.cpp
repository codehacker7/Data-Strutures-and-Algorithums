#include<iostream>
using namespace std;

void generateParentheses(int n,int open,int close,char arr[],int index){

    if(index == 2*n){
        arr[index] = '\0';
        cout<<arr<<endl;
        return;
    }


    if(open < n){
        arr[index] = '(';
        generateParentheses(n,open+1,close,arr,index+1);
    }
    if(close < open){
         arr[index] = ')';
         generateParentheses(n,open,close+1,arr,index+1);
    }
}

int main(){

    int n = 2;
    char arr[100];
    generateParentheses(n,0,0,arr,0);
}