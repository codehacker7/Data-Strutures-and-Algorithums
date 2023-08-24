#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<long long> firstNegativeInWindow(long long A[], long long n, long long k) {
    int i = 0;
    int j = 0;
    queue<long long> q;
    vector<long long> result;

    while (j < n) {
        if (A[j] < 0) {
            q.push(A[j]);
        }

        if (j - i + 1 == k) {
            if (!q.empty()) {
                result.push_back(q.front());
            } else {
                result.push_back(0);
            }

            if (A[i] == q.front()) {
                q.pop();
            }
            i++;
        }

        j++;
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        vector<long long> output = firstNegativeInWindow(A, n, k);

        for (long long num : output) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
