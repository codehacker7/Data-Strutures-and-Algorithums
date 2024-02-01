#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int elementIndex = -1;
        int size = arr.size();
        vector<int> difference(size);

        for(int i = 0;i<arr.size();i++){ 
            int diff = abs(x - arr[i]);
            difference[i] = diff;
        }

        // Use priority queue to store elements based on differences
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < size; i++) {
            int arrayElement = arr[i];
            int arrayDifference = difference[i];
            pq.push({arrayDifference, arrayElement});
        }

        int count = 0;

        vector<int> ans;
        while (count < k) {
            pair<int, int> p = pq.top();
            int arrayElement = p.second;
            ans.push_back(arrayElement);
            count++;
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
