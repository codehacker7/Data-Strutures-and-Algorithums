#include<iostream>
#include<vector>
using namespace std;

int main() {
    int arr[] = {25, 0, 50, 0, 0, 0, 0, 15, 0, 0, 45};
            //   0   1  2  3  4   5 6   7  8  9    10
   int arr[] = {40,50,0,0,0,0,0,10,12};
    //     0  1  2 3 4 5 6  7  8

    int bird = 4;

    int n = sizeof(arr) / sizeof(int);
    vector<int> left;
    vector<int> right;
    vector<int> finalans;

    for (int i = bird + 1; i < n; i++) {
        if (arr[i] != 0) {
            right.push_back(i);
        }
    }

    for (int i = bird - 1; i >= 0; i--) {
        if (arr[i] != 0) {
            left.push_back(i);
        }
    }

    int sum = 0;

    int rightindex = 0;
    int leftindex = 0;
    for (int i = 0; i < n; i++) {
        if (rightindex < right.size()) {
            sum += arr[right[rightindex]];
            finalans.push_back(right[rightindex]);
            rightindex++;
        }

        if (sum >= 100) {
            break;
        }

        if (leftindex < left.size()) {
            sum += arr[left[leftindex]];
            finalans.push_back(left[leftindex]);
            leftindex++;
        }

        if (sum >= 100) {
            break;
        }
    }

    for (int i = 0; i < finalans.size(); i++) {
        cout << finalans[i] << endl;
    }

    return 0;
}
