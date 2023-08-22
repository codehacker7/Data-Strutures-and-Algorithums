#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int calculateScore(vector<string>& ops) {
    stack<int> stack;
    for (string& op : ops) {
        if (op == "C") {
            stack.pop();
        } else if (op == "D") {
            stack.push(2 * stack.top());
        } else if (op == "+") {
            int top1 = stack.top();
            stack.pop();
            int top2 = stack.top();
            stack.push(top1);
            stack.push(top1 + top2);
        } else {
            stack.push(stoi(op));
        }
    }
    
    int totalScore = 0;
    while (!stack.empty()) {
        totalScore += stack.top();
        stack.pop();
    }
    
    return totalScore;
}

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        std::cin >> N;

        std::vector<std::string> ops(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> ops[i];
        }

        int totalScore = calculateScore(ops);
        std::cout << totalScore << std::endl;
    }

    return 0;
}
