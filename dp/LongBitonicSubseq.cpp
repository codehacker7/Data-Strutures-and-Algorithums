#include<iostream>
#include<vector>
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n, 1);

    for (int j = 1; j < n; j++) {
        for (int k = j - 1; k >= 0; k--) {
            if (arr[j] > arr[k]) {
                dp1[j] = max(dp1[j], dp1[k] + 1);
            }
        }
    }

    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int prev = n - 1; prev > i; prev--) {
            if (arr[prev] < arr[i]) {
                dp2[i] = max(dp2[i], dp2[prev] + 1);
            }
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

int main() {
    int arr1[] = {1, 11, 2, 10, 4, 5, 2, 1};
    vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    cout << longestBitonicSequence(vec1, vec1.size()) << endl; // Output: 6

    int arr2[] = {12, 11, 40, 5, 3, 1};
    vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    cout << longestBitonicSequence(vec2, vec2.size()) << endl; // Output: 5

    int arr3[] = {80, 60, 30, 40, 20, 10};
    vector<int> vec3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
    cout << longestBitonicSequence(vec3, vec3.size()) << endl; // Output: 5

    return 0;
}
