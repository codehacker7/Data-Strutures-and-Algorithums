#include <iostream>
#include <stack>
using namespace std;

int main() {

	int heights[] = {7, 2, 3, 4, 1, 6, 4, 5};
                   //0 1  2  3  4  5  6   7
         //exp    0  3   3  3   7  5  7   7
	int n = sizeof(heights) / sizeof(int);
    int left[n];
    int right[n];

    stack<int> st;

    for(int i=n-1;i>=0;i--){

          while(!st.empty() && (heights[st.top()] >= heights[i])){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-1;
            } else{
                right[i] = st.top() -1;
            }
             st.push(i);
        }
        

    
    while(!st.empty()){
        st.pop();
    }

    for(int i=0;i<n;i++){
       
          while(!st.empty() && (heights[st.top()] >= heights[i])){
                st.pop();
            }
            if(st.empty()){
                left[i] = 0;
            } else{
                left[i] = st.top() + 1;
            }
      
            st.push(i);
        }
      
    

   
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
       int area = (right[i]-left[i]+1)*heights[i];
        maxi = max(maxi,area);
    }

    cout<<maxi<<endl;



}