#include<iostream>
using namespace std;

void generateParenthesis(char *a, int n, int open, int close, int index) {
    if (index == 2 * n) {
        a[index] = '\0';
        cout << a << endl; // Print the generated combination
        return;
    }

    if (open < n) {
        a[index] = '(';
        generateParenthesis(a, n, open + 1, close, index + 1);
    }

    if (close < open) {
        a[index] = ')';
        generateParenthesis(a, n, open, close + 1, index + 1);
    }
}

int main() {
    int n = 2;
    char a[100];
    generateParenthesis(a, n, 0, 0, 0); // Call the generateParenthesis function
    return 0; // Return 0 to indicate successful program execution
}
