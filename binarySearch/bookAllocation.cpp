#include <climits>
#include <vector>
#include <iostream>
using namespace std;

bool isSolution(int target, int B, vector<int>& A, int n) {
    int numberofstudents = 1;
    int pages = 0;
    for (int i = 0; i < n; i++) {
        // if (A[i] > target) {
        //     return false;
        // }
        if (pages + A[i] <= target) {
            pages += A[i];
        } else {
            numberofstudents++;
            pages = A[i];
        }
    }
    return numberofstudents <= B;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int numberofbooks, B;
        cin >> numberofbooks >> B;

        vector<int> A(numberofbooks);

        for (int i = 0; i < numberofbooks; i++) {
            cin >> A[i];
        }

        int n = A.size();
        if (B > n) {
            cout << -1 << endl;
            continue;
        }

        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(A[i], maxi);
            sum += A[i];
        }
        int low = maxi;
        int high = sum;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (isSolution(mid, B, A, n)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << low << endl;
    }
    return 0;
}