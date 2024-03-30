#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
         for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {0, src}});
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int totalCost = q.front().second.first;
            int start = q.front().second.second;
            q.pop();
        

            // if(stops > k){. //either uncomoment this or do check in bottom if as shown
            //     continue;
            // }
             

            for(const auto& ngh : adj[start]){
                int neighborCost = ngh.second;
                int neighborCity = ngh.first;

                if ((totalCost + neighborCost < dist[neighborCity]) && (stops <= k)) {
                    dist[neighborCity] = totalCost + neighborCost;
                    q.push({stops + 1, {totalCost + neighborCost, neighborCity}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
