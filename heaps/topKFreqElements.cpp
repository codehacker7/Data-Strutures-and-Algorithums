#include <vector>
#include <map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> freq;
        std::vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

        for (auto i : freq) {
            int element = i.first;
            int frequency = i.second;

            minHeap.push({frequency, element});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }


        return ans;
    }
};
