#include <iostream>
#include <unordered_set>

using namespace std;

int sumOflength(int *arr, int n);

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << sumOflength(arr, n) << endl;
    return 0;
}

int sumOflength(int *arr, int n) {
    unordered_set<int> s;
    int j = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && s.find(arr[j]) == s.end()) {
            s.insert(arr[j]);
            j++;
        }
        ans = (ans + ((j - i) * (j - i + 1) / 2));
        s.erase(arr[i]);
    }
    return ans;
}
