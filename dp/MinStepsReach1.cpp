#include <iostream>

/*
brute force
using namespace std;
 
int countways(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + countways(n / 2);
    else
        return 1 + min(countways(n - 1),
                       countways(n + 1));
}
 
// Driver code
int main()
{
    int n = 15;
 
    cout << countways(n) << "\n";
 
    return 0;
}

*/

int minimizeOperations(int N) {
    int operations = 0;

    while (N != 1) {
        if (N % 2 == 0) {
            N /= 2;
        } else {
            // Check if decrementing or incrementing leads to a number divisible by 4
            if ((N - 1) % 4 == 0 || N == 3) {
                N--;
            } else {
                N++;
            }
        }
        operations++;
    }

    return operations;
}

int main() {
    int N;
    std::cin >> N;

    int result = minimizeOperations(N);

    std::cout << result << std::endl;

    return 0;
}


