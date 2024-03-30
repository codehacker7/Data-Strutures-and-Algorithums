#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K); // Corrected: Initialize adjacency list with size K
        for (int i = 0; i < N - 1; i++) {
            string first = dict[i];
            string second = dict[i + 1];
            int length = min(first.length(), second.length());
            for (int j = 0; j < length; j++) {
                if (first[j] != second[j]) {
                    adj[first[j] - 'a'].push_back(second[j] - 'a');
                    break; // Corrected: Break once difference is found
                }
            }
        }

        vector<int> indegree(K, 0); // Corrected: Size should be K
        for (auto& edges : adj) { // Corrected: Use reference in the loop
            for (auto& v : edges) { // Corrected: Use reference in the loop
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++) { // Corrected: Loop through K
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);
            for (auto ngh : adj[front]) { // Corrected: Use reference in the loop
                indegree[ngh]--;
                if (indegree[ngh] == 0) {
                    q.push(ngh);
                }
            }
        }

        string order;
        for (int i = 0; i < K; i++) { // Convert integers to characters
            order += char('a' + topo[i]);
        }
        return order;
    }
};