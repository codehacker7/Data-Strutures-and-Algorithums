#include <climits>
#include <vector>
#include <iostream>
using namespace std;

bool isSolution(long long target, int B, vector<int>& A, int n) {
    int numberofstudents = 1;
    long long pages = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > target) {
            return false;
        }
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
    int numberofpainters, N;
    cin >> numberofpainters >> N;

    vector<int> boards(N);

    for (int i = 0; i < N; i++) {
        cin >> boards[i];
    }

    // Binary search to find the minimum time required
    long long low = 0, high = 0;
    for (int i = 0; i < N; i++) {
        high += boards[i];
        low = max(static_cast<long long>(boards[i]), low);
    }

    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (isSolution(mid, numberofpainters, boards, N)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;

    return 0;
}