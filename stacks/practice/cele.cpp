#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int celebrityOptimized(vector<vector<int>>& M, int n) {

    int ans = -1;

    stack<int> st;

    for(int i=0;i<n;i++){   
        //we assume that i is celebrity intially lets say 0 is celebrity
        st.push(i);
    }



    while(st.size() > 1){

        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(M[a][b] == 1){
            st.push(b);
        }
        else{
           st.push(a);
        }


    }


    if(!st.empty()){

        int potenialCelebrity = st.top();
    // check row that this guy knows no one
    for(int i=0;i<n;i++){

        if( i != potenialCelebrity && M[potenialCelebrity][i] == 1){
            return -1;
        }
    }
    //check if this guy is known by everyone
     for(int i=0;i<n;i++){

        if( i != potenialCelebrity && M[i][potenialCelebrity] == 0){
            return -1;
        }
    }

    return potenialCelebrity;



    }

    return -1;




}

int celebrity(vector<vector<int>>& M, int n) {

    int ans = -1;

    for(int i=0;i<n;i++){   
        //we assume that i is celebrity intially lets say 0 is celebrity
        bool flag = true;
        for(int j=0;j<n;j++){
            if(i !=j && M[i][j] == 1){
                flag = false;
            }
        }


        for(int j=0;j<n;j++){
             if(i !=j && M[j][i] == 0){
               flag = false;
            }
        }

        if(flag){
        ans = i;
        break;
        }
        
    }
    return ans;



}
int main(){


}