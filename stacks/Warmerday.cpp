#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(int arr[], int n) {
    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() &&  arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            result[i] = 0;
        } else {
            result[i] = st.top() - i;
        }

        st.push(i);
    }

    return result;
}

int main() {
    int number;
    cin >> number;

    int arr[number];
    for (int i = 0; i < number; i++) {
        cin >> arr[i];
    }

    vector<int> ans = nextGreater(arr, number);

    for (int value : ans) {
        cout << value << " ";
    }

    return 0;
}
