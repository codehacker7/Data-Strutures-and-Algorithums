#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1); // Initialize the result vector with -1
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }

        if (i < n) {
            if (!st.empty()) {
                nge[i] = st.top();
            }
        }
        // if(i < n){
        //   if(st.empty()){
        //    nge[i] = -1;
        //    st.push(arr2[i]);
        // }else{
        //     nge[i] = st.top();
        //     st.push(arr2[i]);
        // }
        // }

        st.push(nums[i % n]);
    }

    return nge;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElements(nums);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
