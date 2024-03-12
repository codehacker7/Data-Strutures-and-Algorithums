#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> getGoodIndices(std::vector<std::vector<int>>& variables, int target) {
        
        int n = variables.size();
        std::vector<int> ans;
        for(int row = 0; row < n; row++){
             int a = variables[row][0];
             int b = variables[row][1];
             int c = variables[row][2];
             int m = variables[row][3];
            
            int u = 1;
            for(int i = 0; i < b;i++){
                u = (u * a)%10;
            }
            int v = u;
            u = 1;
            for(int i = 0; i < c;i++){
                u = (u * v) %m;
            }

            if(u == target){
                ans.push_back(row);
            }
        }
        
        return ans;
    }
};
