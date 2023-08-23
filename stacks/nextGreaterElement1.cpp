#include<iostream>
using namespace std;

int[] nextGreaterElement(int arr2[],int n){

    int nge[size];

    stack<int> st;

    for(int i=n-1;i>=0;i--){

        while(!st.empty() && st.top() <= arr2[i]){
            st.pop();
        }

        if(st.empty()){
           nge[i] = -1;
           st.push(arr2[i]);
        }else{
            nge[i] = st.top();
            st.push(arr2[i]);
        }
    }

    return nge;
    
}

int main(){

    int n1;
    cin>>n1;

    int n2;
    cin>>n2;

    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
     for(int i=0;i<n1;i++){
        cin>>arr2[i];
    }

    int nge[] = nextGreaterElement(arr2,n2);

    int indexs[n1];

    int count =0;
    int count1 =0;
    while(count != n1){
        int elem = arr1[count];

        for(int i=0;i<n2;i++){
            if(arr2[i] == elem){
                indexs[count1++] = i;
            }
        }
        count++;
    }

    for(int i=0;i<n1;i++){
        int index = indexs[i];
        cout<<nge[index]<<" ";
    }

      
    }



