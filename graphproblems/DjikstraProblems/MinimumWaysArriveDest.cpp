#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<long long, long long>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> distances(n, LLONG_MAX); // Using long long
        vector<long long> ways(n, 0); // Using long long

        distances[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){

            long long dist = pq.top().first;
            int src = pq.top().second;
            pq.pop();

            for(auto ngh : adj[src]){
                long long ngh_dist = ngh.second;
                int ngh_city = ngh.first;

                if(distances[ngh_city] > dist + ngh_dist){
                    distances[ngh_city] = dist + ngh_dist;
                    ways[ngh_city] = ways[src];
                    pq.push({dist + ngh_dist, ngh_city});
                } else if(distances[ngh_city] == dist + ngh_dist){
                    ways[ngh_city] = (ways[ngh_city] + ways[src]) % (int)(1e9 + 7);
                }
            }
        }

        return ways[n - 1] % (int)(1e9 + 7);
    }
};
